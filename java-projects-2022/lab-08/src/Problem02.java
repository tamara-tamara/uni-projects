public class Problem02 {
    public static void main(String[] args) {
        try {
            Circle c1 = new Circle(5);
            Circle c2 = new Circle(-5);
            Circle c3 = new Circle(0);

        } catch (IllegalArgumentException e) {
            System.out.println(e);
        }
        System.out.println("Number of objects created: " + Circle.getNumOfObj());
    }
}

class Circle {
    private double radius;
    private static int numOfObj = 0;

    Circle() {
        this(1.0);
    }

    public Circle(double newRadius) {
        setRadius(newRadius);
        numOfObj++;
    }

    public double getRadius() {
        return radius;
    }

    public void setRadius(double newRadius)
            throws IllegalArgumentException {
        if (newRadius >= 0)
            radius = newRadius;
        else
            throw new IllegalArgumentException("Radius cannot be negative.");
    }

    public static int getNumOfObj() {
        return numOfObj;
    }

    public double area() {
        return radius * radius * Math.PI;
    }
}

