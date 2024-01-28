class Rectangle extends Shape {
    private final int width, height;

    Rectangle(int x, int y, int width, int height) {
        super(x, y);
        this.width = width;
        this.height = height;
        if (width <= 0) {
            throw new IllegalArgumentException("Width should be a positive number.");
        }
        if (height <= 0) {
            throw new IllegalArgumentException("Height should be a positive number.");
        }
    }

    boolean areCoordsInside(int x, int y) {
        return x >= this.x && x <= this.x + width &&
                y >= this.y && y <= this.y + height;
    }

    public String toString() {
        return String.format("Rect: %d, %d, %d, %d", x, y, width, height);
    }
}
