package collisionengine;

abstract class ThreeDObject
    {
        public ThreeDObject()
        {
            initCenter(new Point());
            initVelocity(new Velocity());
        }
        public ThreeDObject(Point argcenter) 
        { 
            initCenter(argcenter); 
            initVelocity(new Velocity());
        }
        
        public ThreeDObject(Velocity argvel)
        {
            initVelocity(argvel);
            initCenter(new Point());
        }
        public ThreeDObject(Point argcenter, Velocity argvel)
        {
            initVelocity(argvel);
            initCenter(argcenter); 
        }
        public void initCenter(Point argcenter)
        {
            center = new Point(argcenter.x, argcenter.y, argcenter.z);
        }
        public void initVelocity(Velocity argvel)
        {
            objvelocity = new Velocity( argvel.dx, argvel.dy, argvel.dz);
        }
        public void putInEnvironment(Point argcenter) 
        {
            center.x = argcenter.x;
            center.y = argcenter.y;
            center.z = argcenter.z;
        }
        //abstract public void move(int argspeed, int argdirection);
        public void move(Point argdest, int argtime)
        {
            objvelocity.dx = (argdest.x - center.x)/argtime;
            objvelocity.dy = (argdest.y - center.y)/argtime;
            objvelocity.dz = (argdest.z - center.z)/argtime;
        }
        public void move(Velocity argvel)
        {
            objvelocity.dx = argvel.dx;
            objvelocity.dy = argvel.dy;
            objvelocity.dz = argvel.dz;
        }
        public void timestep()
        {
            center.x += objvelocity.dx;
            center.y += objvelocity.dy;
            center.z += objvelocity.dz;
        }
        public void rotate(int argDegrees)
        {

        }
        abstract void buildSpace(); 

        public void setName(String argName)
        {
            name = argName;
        }
        public void printLocation()
        {
            System.out.printf("x=%d, y=%d, z=%d", center.x, center.y, center.z);
        }

        public ThreeDObject test1(){
            ThreeDObject t = new ThreeDObject(){
            
                    @Override
                    void buildSpace() {
                        
                    }
            };

            return t;
        }
        public int getx(){ return center.x; }
        public int gety(){ return center.y; }
        public int getz(){ return center.z; }
        public int getdx(){ return objvelocity.dx; }
        public int getdy(){ return objvelocity.dy; }
        public int getdz(){ return objvelocity.dz; }
        public boolean[][][] getObjectSpace() { return objectSpace; }

        public void setx(int argx) { center.x = argx;}
        public void sety(int argy) { center.y = argy;}
        public void setz(int argz) { center.z = argz;}
        public void setdx(int argdx) { objvelocity.dx = argdx;}
        public void setdy(int argdy) { objvelocity.dy = argdy;}
        public void setdz(int argdz) { objvelocity.dz = argdz;}

        Point center;
        //private int moveTime;
        Velocity objvelocity;
        boolean[][][] objectSpace;
        String name = "no name";
    }