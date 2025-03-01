package collisionengine;

public class Point
{
    public int x, y, z;
    public Point() { this(0,0,0); }
    public Point(int[] array) { this(array[0], array[1], array[2]); }
    public Point(int argx, int argy, int argz)
    {
        x = argx;
        y = argy;
        z = argz;
    }
    public void add(int argx, int argy, int argz)
    {
        x += argx;
        y += argy;
        z += argz;
    }
    public static void main(String[] args)
    {
        RectPrism r = new RectPrism(1,1,1);
    }
}