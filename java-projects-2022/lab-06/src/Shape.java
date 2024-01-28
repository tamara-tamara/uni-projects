class Shape {
    protected int x, y;

    public Shape(int x, int y) {
        this.x = x;
        this.y = y;
    }

    boolean areCoordsInside(int x, int y) {
        return false;
    }

    void present() {
        System.out.println(this);
    }

    void move(int x1, int y1, int x2, int y2) {
        int dx = x2 - x1;
        int dy = y2 - y1;
        x += dx;
        y += dy;
    }

    public String toString() {
        return String.format("Shape: %d, %d", x, y);
    }
}
