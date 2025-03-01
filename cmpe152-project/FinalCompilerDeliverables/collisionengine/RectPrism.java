package collisionengine;


public class RectPrism extends ThreeDObject
{
    int height, width, length;

    
    RectPrism(int argHeight, int argWidth, int argLength)
    {
        super();
        height = argHeight;
        width = argWidth;
        length = argLength;
        buildSpace();
    }

    @Override
    void buildSpace() {
        objectSpace = new boolean[width] [height] [length];
        for(boolean[][] twoD: objectSpace){
            for(boolean[] oneD: twoD){
                for(boolean elem: oneD){
                    elem = true;
                }
            }
        }
    }
}