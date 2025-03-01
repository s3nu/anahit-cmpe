package collisionengine;

public class Cylinder extends ThreeDObject
    {
        int radius, height;
        Cylinder(int argradius, int argheight)
        {
            super();
            radius = argradius;
            height = argheight;
            buildSpace();
        }

        @Override
        void buildSpace(){
            int dist = 0;
            boolean hasSphere = false;
            objectSpace = new boolean[radius*2][height][radius*2];
            for(int x = -radius; x<radius; x++){
                for(int y = -radius; y<radius; y++){
                    for(int z = -radius; z<radius; z++){
                        dist = (int)Math.sqrt(x*x+y*y+z*z);
                        if(dist <= radius) { hasSphere = true;}
                        else {hasSphere = false;}
                        objectSpace[x+radius][y+radius][z+radius] = hasSphere;
                    }
                }
            }
        }
    }