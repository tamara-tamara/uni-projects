public class Turtle {
    int x, y;
    int dx, dy;
    boolean penDown;
    Field turtField;

    Turtle(Field newField) {
        //'this' call should be the first call in a constructor
        //constructor-chaining
        this(newField, 0, 0, 1, 0);
    }

    Turtle(Field newField, int x, int y, int dx, int dy) {
        this.x = x;
        this.y = y;
        this.dx = dx;
        this.dy = dy;

        penDown = false;
        this.turtField = newField;
    }


    void putPenUp() {
        penDown = false;
    }

    void putPenDown() {
        penDown = true;
    }

    void turnRight() {
        int temp = dx;
        dx = -dy;
        dy = temp;
    }

    void turnLeft() {
        int temp = dx;
        dx = dy;
        dy = -temp;
    }

    void move(int steps) {
        for (int i = 0; i < steps; ++i) {
            int nextX = x + dx;
            int nextY = y + dy;
            if (!turtField.areCoordsInsideField(nextX, nextY)) {
                break;
            }
            if (penDown) {
                turtField.markField(x, y);
            }
            x = nextX;
            y = nextY;
        }
    }
}
