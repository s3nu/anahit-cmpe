package collisionengine;

import java.lang.String;

public class CollisionEngine
{
    public CollisionEngine(int xdim, int ydim, int zdim)
    {
        environment = new int[xdim][ydim][zdim];
    }
    int[][][] environment;
    int[] objectNumbers;
    String[] objectNames;
    ThreeDObjects ThreeDobjs = new ThreeDObjects();
    //hashtable of actions?

    public boolean detectCollisionAtPoint(ThreeDObjects.point destination)
    {
        return true;
    }
    
    public void moveObject(ThreeDObjects.ThreeDObject object)
    {
        
    }

    public static void main(String[] args) {
        
        System.out.println("CollisionEngine ... ");
        ThreeDObjects tdobjs = new ThreeDObjects();
        ThreeDObjects.rectPrism r = tdobjs.new rectPrism(1, 2, 3);
        r.move(new ThreeDObjects.point(1,1,1), 1);
        System.out.println(r.objvelocity.dx);
    }

}