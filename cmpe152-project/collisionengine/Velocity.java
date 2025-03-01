package collisionengine;

public class Velocity
{
    public int dx, dy, dz;
    public Velocity() { this(0,0,0); }
    public Velocity(int argdx, int argdy, int argdz)
    {
        dx = argdx;
        dy = argdy;
        dz = argdz;
    }
    public void add(int argx, int argy, int argz)
    {
        dx += argx;
        dy += argy;
        dz += argz;
    }
}