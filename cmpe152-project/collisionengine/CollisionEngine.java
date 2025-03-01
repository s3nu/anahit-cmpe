package collisionengine;

import java.lang.String;
import java.util.*;
import javafx.util.*;

public class CollisionEngine
{
    public CollisionEngine(int xdim, int ydim, int zdim)
    {
        environment = new ArrayList<ArrayList<ArrayList<LinkedList<ThreeDObject>>>>();
        for(int x = 0; x<xdim; x++){
            environment.add(new ArrayList<ArrayList<LinkedList<ThreeDObject>>>());
            for(int y = 0; y<ydim; y++){
                environment.get(x).add(new ArrayList<LinkedList<ThreeDObject>>());
                for(int z = 0; z<zdim; z++){
                    environment.get(x).get(y).add(new LinkedList<ThreeDObject>());
                }
            }
        }
        center = new Point(xdim/2, ydim/2, zdim/2);
        collisionMap = new HashMap<Set<ThreeDObject>, Integer>();
        numCollisions = 1;
        engineObjects = new LinkedList<ThreeDObject>();
        moveVelocityMap = new HashMap<Integer, LinkedList<Pair<ThreeDObject, Velocity>>>();
        movePointMap = new HashMap<Integer, LinkedList<Pair<ThreeDObject, Point>>>();
    }
    ArrayList<ArrayList<ArrayList<LinkedList<ThreeDObject>>>> environment;
    Point center;
    int[] objectNumbers;
    String[] objectNames;
    int numCollisions = 0;
    Map<Set<ThreeDObject>, Integer> collisionMap;
    HashMap<Integer, LinkedList<Pair<ThreeDObject, Point>>> movePointMap;
    HashMap<Integer, LinkedList<Pair<ThreeDObject, Velocity>>> moveVelocityMap;
    List<ThreeDObject> engineObjects;
    //hashtable of actions?

    public int[] timestep()
    {
        for(ThreeDObject obj: engineObjects){
            clearObjInEnv(obj);
            obj.timestep();
            addObjInEnv(obj);
        }
        return detectCollisions();
        // handleCollisions();
    }

    public int[] detectCollisions()
    {
        int[] collisions = new int[numCollisions+1];
        //collisions[0] = 1;
        Set<ThreeDObject> collision = new HashSet<ThreeDObject>();

        for(ArrayList<ArrayList<LinkedList<ThreeDObject>>> x: environment){
            for(ArrayList<LinkedList<ThreeDObject>> y: x){
                for(LinkedList<ThreeDObject> z: y){
                    if(z.size()>1){
                        for(ThreeDObject elem: z){
                            collision.add(elem);
                        }
                        collisions[collisionMap.get(collision)] = 1;
                        collision.clear();
                    }
                }
            }
        }

        //actually detect collisions
        return collisions;
    }

    public void addObject(ThreeDObject argobj, Point argPoint)
    {
        argobj.putInEnvironment(argPoint);
        engineObjects.add(argobj);
        
        addObjInEnv(argobj);
    }

    public boolean detectCollisionAtPoint(Point destination)
    {
        return true;
    }

    public void clearObjInEnv(ThreeDObject argobj)
    {
        int linkedlistindex = 0;
        boolean[][][] objectSpace = argobj.getObjectSpace();
        
        for(int x = 0; x<objectSpace.length; x++){
            for(int y = 0; y<objectSpace[0].length; y++){
                for(int z = 0; z<objectSpace[0][0].length; z++){
                    if(objectSpace[x][y][z] == true){
                        linkedlistindex = environment.get(x+center.x+argobj.center.x).get(y+center.y+argobj.center.y).get(z+center.z+argobj.center.z).indexOf(argobj);
                        environment.get(x+center.x+argobj.center.x).get(y+center.y+argobj.center.y).get(z+center.z+argobj.center.z).remove(linkedlistindex);
                    }
                }
            }
        }
    }

    public void addObjInEnv(ThreeDObject argobj)
    {
        boolean[][][] objectSpace = argobj.getObjectSpace();
        
        for(int x = 0; x<objectSpace.length; x++){
            for(int y = 0; y<objectSpace[0].length; y++){
                for(int z = 0; z<objectSpace[0][0].length; z++){
                    if(objectSpace[x][y][z] == true){
                        environment.get(x+center.x+argobj.center.x).get(y+center.y+argobj.center.y).get(z+center.z+argobj.center.z).add(argobj);
                    }
                }
            }
        }
    }
    
    public void moveObject(ThreeDObject argobj, Point argPoint, int argmovetime,int argstarttime)
    {
        Velocity vel = new Velocity(argPoint.x/argmovetime, argPoint.y/argmovetime, argPoint.z/argmovetime);

        Pair<ThreeDObject, Velocity> newPair = new Pair<ThreeDObject, Velocity>(argobj, vel);
        LinkedList<Pair<ThreeDObject, Velocity>> linked = moveVelocityMap.get(argstarttime);
        if(linked == null){
            linked = new LinkedList<Pair<ThreeDObject, Velocity>>();
            moveVelocityMap.put(argstarttime, linked);
        }
        linked.add(newPair);
        
    }

    public void addCollision(ThreeDObject object1, ThreeDObject object2)
    {
        Set<ThreeDObject> objlist = new HashSet<ThreeDObject>();
        objlist.add(object1);
        objlist.add(object2);
        collisionMap.put(objlist, new Integer(numCollisions));
        numCollisions++;
    }

    public int getCollision(ThreeDObject object1, ThreeDObject object2)
    {
        Set<ThreeDObject> objlist = new HashSet<ThreeDObject>();                
        return collisionMap.get(objlist);
    }

    public int getNumCollisionHandles()
    {
        return numCollisions-1;
    }

    public void printStatus()
    {
        int x = environment.size();
        int y = environment.get(0).size();
        int z = environment.get(0).get(0).size();
        System.out.printf("Size of Environment: x = %d, y = %d, z = %d\n", x, y,z);
        System.out.printf("Center of Environment: x = %d, y = %d, z = %d\n\n", center.x, center.y, center.z);
        System.out.printf("Current Object Status:\n");
        for(ThreeDObject obj: engineObjects){
            System.out.print(obj.name);
            System.out.print(" center is at: ");
            obj.printLocation();
            System.out.printf(" and velocity is: dx=%d, dy=%d, dz=%d", obj.objvelocity.dx, obj.objvelocity.dy, obj.objvelocity.dz);
            System.out.println();
        }

        System.out.println("Collisions being handled:");
        System.out.printf("\tNumber of Collisions = %d\n", numCollisions-1);
        // loop over collisions in hashmap?
    }

    public static void main(String[] args) {
        CollisionEngine col = new CollisionEngine(100,100,100);
        Point p = new Point(10,0,0);
        RectPrism rect = new RectPrism(1,2,3);
        col.addObject(rect, p);
        System.out.println(rect.height);
    }
}