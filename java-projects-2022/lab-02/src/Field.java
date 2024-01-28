public class Field {
    static final char EMPTY_CELL = '.';
    static final char MARKED_CELL = '*';
    static final char TURTLE_CELL = 'T';
    static final int FIELD_WIDTH = 20;
    static final int FIELD_HEIGHT = 20;
    char[][] field;

    Field() {
        field = new char[FIELD_HEIGHT][FIELD_WIDTH];
        for (int y = 0; y < FIELD_HEIGHT; ++y) {
            for (int x = 0; x < FIELD_WIDTH; ++x) {
                field[y][x] = EMPTY_CELL;
            }
        }
    }

    void displayField(Turtle[] turtles) {
        for (int y = 0; y < FIELD_HEIGHT; ++y) {
            columnLoop:
            for (int x = 0; x < FIELD_WIDTH; ++x) {
                for (Turtle turtle : turtles) {
                    if (x == turtle.x && y == turtle.y) {
                        System.out.print(TURTLE_CELL);
                        continue columnLoop;
                    }
                }
                System.out.print(field[y][x]);
            }
            System.out.println();
        }
    }

    boolean areCoordsInsideField(int x, int y) {
        return x >= 0 && x < FIELD_WIDTH &&
                y >= 0 && y < FIELD_HEIGHT;
    }

    void markField(int x, int y) {
        if (areCoordsInsideField(x, y)) {
            field[y][x] = MARKED_CELL;
        }
    }
}
