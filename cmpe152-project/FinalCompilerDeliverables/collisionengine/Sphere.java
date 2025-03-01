package collisionengine;

public class Sphere extends ThreeDObject
{
    int radius;

    Sphere( int argradius)
    {
        super();
        radius = argradius;
        buildSpace();
    }

    @Override
    void buildSpace(){
        int dist = 0;
        boolean hasSphere = false;
        objectSpace = new boolean[radius*2][radius*2][radius*2];
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