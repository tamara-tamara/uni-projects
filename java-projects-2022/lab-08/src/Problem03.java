public class Problem03 {
    public static void main(String[] args) {
        try {
            CircleMyException c1 = new CircleMyException(5);
            CircleMyException c2 = new CircleMyException(-5);
            CircleMyException c3 = new CircleMyException(0);

        } catch (InvalidRadiusException e) {
            System.out.println(e);
        }
        System.out.println("Number of objects created: " + CircleMyException.getNumOfObj());
    }
}

class CircleMyException {
    private double radius;
    private static int numOfObj = 0;

    CircleMyException()
            throws InvalidRadiusException {
        this(1.0);
    }

    public CircleMyException(double newRadius)
            throws InvalidRadiusException {
        setRadius(newRadius);
        numOfObj++;
    }

    public double getRadius() {
        return radius;
    }

    public void setRadius(double newRadius)
            throws InvalidRadiusException {
        if (newRadius >= 0)
            radius = newRadius;
        else
            throw new InvalidRadiusException(newRadius);
    }

    public static int getNumOfObj() {
        return numOfObj;
    }

    public double area() {
        return radius * radius * Math.PI;
    }
}

class InvalidRadiusException extends Exception {
    private double radius;

    public InvalidRadiusException(double radius) {
        super("Invalid radius " + radius);
        this.radius = radius;
    }

    public double getRadius() {
        return radius;
    }
}
