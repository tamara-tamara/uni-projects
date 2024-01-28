package game.models;

import java.awt.*;

public class Field {
    private int width, height;
    private final Color color;
    private Apple apple;

    public Field(int width, int height) {
        this.width = width;
        this.height = height;
        color = Color.green;
        apple = null;
    }

    public Apple getApple() {
        return apple;
    }

    public void setApple(Apple apple) {
        this.apple = apple;
    }

    public void setWidth(int width) {
        this.width = width;

    }

    public void setHeight(int height) {
        this.height = height;
    }

    public Color getColor() {
        return color;
    }

    public int getHeight() {
        return height;
    }

    public int getWidth() {
        return width;
    }

    public boolean areCoordsInside(int x, int y) {
        return x >= 0 && x < width && y >= 0 && y < height;
    }
}
