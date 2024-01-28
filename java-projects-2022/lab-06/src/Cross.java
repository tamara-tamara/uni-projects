class Cross extends Shape {
    Rectangle r1;
    Rectangle r2;
    final int w;
    final int h;

    public Cross(int x, int y, int aW1, int aW2) {
        super(x, y);
        w = aW1;
        h = aW2;
        r1 = new Rectangle(x - aW2 / 2, y - aW1 / 2, aW2, aW1);
        r2 = new Rectangle(x - aW1 / 2, y - aW2 / 2, aW1, aW2);
        if (w <= 0) {
            throw new IllegalArgumentException("Width should be a positive number.");
        }
        if (h <= 0) {
            throw new IllegalArgumentException("Height should be a positive number.");
        }

    }

    public boolean areCoordsInside(int x, int y) {
        return r1.areCoordsInside(x, y) || r2.areCoordsInside(x, y);
    }

    public String toString() {
        return String.format("Cross: (" + r2 + ")" + ",(" + r1 + ")");
    }
}
