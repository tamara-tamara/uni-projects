package game.models;

import java.awt.*;
import java.util.ArrayList;

public class Snake {
    public int score;
    private int headIdx;
    private final ArrayList<Point> body;
    private final Color aliveSnake;
    private final Color deadSnake;
    private int dx, dy;
    private boolean dead;
    private Field field;

    public Snake(Field field, int x, int y, int dx, int dy, int size) {
        this.field = field;
        score = 0;
        this.dx = dx;
        this.dy = dy;
        headIdx = 0;
        body = new ArrayList<>();
        for (int i = 0; i < size; ++i) {
            body.add(new Point(x, y));
        }
        dead = false;
        aliveSnake = Color.MAGENTA;
        deadSnake = Color.gray;
    }

    public void turnRight() {
        if (dx != -1) {
            dx = 1;
            dy = 0;
        }
    }

    public void turnLeft() {
        if (dx != 1) {
            dx = -1;
            dy = 0;
        }
    }

    public void turnUp() {
        if (dy != 1) {
            dx = 0;
            dy = -1;
        }
    }

    public void turnDown() {
        if (dy != -1) {
            dx = 0;
            dy = 1;
        }
    }

    public void move() {
        if (dead) {
            return;
        }
        Point head = getHead();
        int nextX = head.x + dx;
        int nextY = head.y + dy;
        if (!field.areCoordsInside(nextX, nextY)) {
            dead = true;
            return;
        }
        Apple apple = field.getApple();
        if (nextX == apple.getX() && nextY == apple.getY()) {
            score++;
            body.add(headIdx, new Point(nextX, nextY));

        } else {
            headIdx = (headIdx + 1) % body.size();
            head = getHead();
            head.x = nextX;
            head.y = nextY;
        }

    }

    private boolean areCoordsInside(int x, int y) {
        for (Point point : body) {
            if (point.x == x && point.y == y) {
                return true;
            }
        }
        return false;
    }

    public void makeNewSnake() {
        body.clear();
        for (int i = 0; i < 3; i++) {
            body.add(new Point(i, 0));
        }
        dx = 1;
        dy = 0;
        dead = false;
    }

    public void setField(Field field) {
        this.field = field;
    }

    public int getScore() {
        return score;
    }

    public Point getHead() {
        return body.get(headIdx);
    }

    public ArrayList<Point> getBody() {
        return body;
    }

    public Color getAliveSnake() {
        return aliveSnake;
    }

    public Color getDeadSnake() {
        return deadSnake;
    }

    public boolean isDead() {
        return dead;
    }
}
