class Circle extends Shape {
    private final int radius;

    Circle(int x, int y, int radius) {
        super(x, y);
        this.radius = radius;
        if (radius < 0) {
            throw new IllegalArgumentException("Radius cannot be negative.");
        }
    }

    public String toString() {
        return String.format("Circle: %d, %d, %d", x, y, radius);
    }

    boolean areCoordsInside(int x, int y) {
        int dx = x - this.x;
        int dy = y - this.y;
        int distance = dx * dx + dy * dy;
        return distance <= radius * radius;
    }
}
