package collisionengine;

public class ThreeDObjects
{
    static class point
    {
        public int x, y, z;
        public point() { this(0,0,0); }
        public point(int[] array) { this(array[0], array[1], array[2]); }
        public point(int argx, int argy, int argz)
        {
            x = argx;
            y = argy;
            z = argz;
        }
    }
    static class velocity
    {
        public int dx, dy, dz;
        public velocity() { this(0,0,0); }
        public velocity(int argdx, int argdy, int argdz)
        {
            dx = argdx;
            dy = argdy;
            dz = argdz;
        }
    }
    abstract class ThreeDObject
    {
        public ThreeDObject()
        {
            initCenter(new point());
            initVelocity(new velocity());
        }
        public ThreeDObject(point argcenter) 
        { 
            initCenter(argcenter); 
            initVelocity(new velocity());
        }
        
        public ThreeDObject(velocity argvel)
        {
            initVelocity(argvel);
            initCenter(new point());
        }
        public ThreeDObject(point argcenter, velocity argvel)
        {
            initVelocity(argvel);
            initCenter(argcenter); 
        }
        public void initCenter(point argcenter)
        {
            center = new point(argcenter.x, argcenter.y, argcenter.z);
        }
        public void initVelocity(velocity argvel)
        {
            objvelocity = new velocity( argvel.dx, argvel.dy, argvel.dz);
        }
        public void putInEnvironment(point argcenter) 
        {
            center.x = argcenter.x;
            center.y = argcenter.y;
            center.z = argcenter.z;
        }
        //abstract public void move(int argspeed, int argdirection);
        public void move(point argdest, int argtime)
        {
            objvelocity.dx = (argdest.x - center.x)/argtime;
            objvelocity.dy = (argdest.y - center.y)/argtime;
            objvelocity.dz = (argdest.z - center.z)/argtime;
        }
        public void move(velocity argvel)
        {
            objvelocity.dx = argvel.dx;
            objvelocity.dy = argvel.dy;
            objvelocity.dz = argvel.dz;
        }
        public void timeStep()
        {
            center.x += objvelocity.dx;
            center.y += objvelocity.dy;
            center.z += objvelocity.dz;
        }
        abstract void buildSpace(); 

        point center;
        //private int moveTime;
        velocity objvelocity;
        Boolean[][][] objectSpace;
    }
    
    class rectPrism extends ThreeDObject
    {
        int height, width, length;

        rectPrism(int argHeight, int argWidth, int argLength)
        {
            super();
            height = argHeight;
            width = argWidth;
            length = argLength;
        }

        @Override
        void buildSpace() {
            objectSpace = new Boolean[width] [height] [length];
            for(Boolean[][] twoD: objectSpace){
                for(Boolean[] oneD: twoD){
                    for(Boolean elem: oneD){
                        elem = true;
                    }
                }
            }
        }
    }

    class sphere extends ThreeDObject
    {
        int radius;

        sphere( int argradius)
        {
            super();
            radius = argradius;
        }

        @Override
        void buildSpace(){
            int dist = 0;
            Boolean hasSphere = false;
            objectSpace = new Boolean[radius*2][radius*2][radius*2];
            for(int x = -radius; x<radius; x++){
                for(int y = -radius; y<radius; y++){
                    for(int z = -radius; z<radius; z++){
                        int dist = sqrt(x*x+y*y+z*z);
                        if(dist <= radius) { hasSphere = true;}
                        else {hasSphere = false;}
                        objectSpace[x+radius][y+radius][z+radius] = hasSphere;
                    }
                }
            }
        }
    }

    class cylinder extends ThreeDObject
    {
        int radius, height;
        cylinder(int argradius, int argheight)
        {
            super();
            radius = argradius;
            height = argheight;
        }

        @Override
        void buildSpace(){
            int dist = 0;
            Boolean hasSphere = false;
                objectSpace = new Boolean[radius*2][height][radius*2];
            for(int x = -radius; x<radius; x++){
                for(int y = -radius; y<radius; y++){
                    for(int z = -radius; z<radius; z++){
                        int dist = sqrt(x*x+y*y+z*z);
                        if(dist <= radius) { hasSphere = true;}
                        else {hasSphere = false;}
                        objectSpace[x+radius][y+radius][z+radius] = hasSphere;
                    }
                }
            }
        }
    }
//WORKON
/*
    class tetrahedron extends ThreeDObject
    {
        private point[] verticies;
        public tetrahedron( point p1, point p2, point p3, point p4)
        {
            super();
            verticies = { p1, p2, p3, p4 }; 
        }
        public void putInEnvironment(point p) {}
    }
*/

    public static void main(String[] args) {
        
        System.out.println("ThreeDObjects ... ");
        ThreeDObjects tdobjs = new ThreeDObjects();
        ThreeDObjects.rectPrism r = tdobjs.new rectPrism(1, 2, 3);
        r.move(new point(1,1,1), 1);
        System.out.println(r.objvelocity.dx);
    }
}