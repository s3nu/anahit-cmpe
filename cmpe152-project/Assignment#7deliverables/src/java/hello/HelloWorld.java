package hello;

public class HelloWorld {
    private static class environment
    {
        static class point
        {
            private int x, y, z;
            public point() { this(0,0,0); }
            public point(int argx, int argy, int argz)
            {
                x = argx;
                y = argy;
                z = argz;
            }
        }
    }
    
    public static void main(String[] args) {
        System.out.println("Hello World!");
        environment.point p = new environment.point(1,2,3);
        System.out.println(p.x);
    }
}