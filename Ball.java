public class Ball
{
	
    public static void main(String[] args)
    {
	Ball ball1 = new Ball();
	Ball ball2 = new Ball(3.5, "red ball");

	System.out.println(ball1.getName());
	System.out.println(ball2.getName());
    }
	
    private double radius;
    private String name;

    public Ball()
    {
	this(0.0, "No Name");
    }
	
    public Ball(double radius, String name)
    {
	this.radius = radius;
	this.name = name;
    }

		
    public double getRadius()
    {
	return radius;
    }
	

    public String getName()
    {
	return name;
    }

    public void setRadius(double radius)
    {
	this.radius = radius;
    }

    public void setName(String name)
    {
	this.name = name;
    }


}
