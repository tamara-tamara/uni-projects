package game.models;

import java.awt.*;
import java.util.Random;

public class Apple {
    private int x, y;
    private final Color color;
    private final Random random = new Random();

    public Apple(Field field, Snake snake) {

        color = Color.red;
        makeNewApple(field, snake);
    }

    public void makeNewApple(Field field, Snake snake) {
        x = random.nextInt(field.getWidth());
        y = random.nextInt(field.getHeight());

        for (Point body : snake.getBody()) {
            if (x == body.x && y == body.y) {
                makeNewApple(field, snake);
                return;
            }
        }
    }

    public boolean collidedWithSnake(Snake snakes) {
        Point head = snakes.getHead();
        if (head.equals(new Point(x, y))) {
            return true;
        }
        return false;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public Color getColor() {
        return color;
    }
}
