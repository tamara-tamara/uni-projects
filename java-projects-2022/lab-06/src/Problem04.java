
import java.util.Scanner;

public class Problem04 {
    public static void main(String[] args) {
        Shape[] shapes = {
                new Rectangle(10, 10, 100, 100),
                new Rectangle(400, 400, 100, 100),

                new Circle(500, 10, 100),
                new Circle(800, 800, 100),

                new Cross(200, 600, 10, 50)
        };
        Scanner scanner = new Scanner(System.in);
        boolean shouldExit = false;
        do {
            System.out.print("cmd: ");
            var command = scanner.next();
            switch (command) {
                case "click":
                    int mouseX, mouseY;
                    System.out.print("x: ");
                    mouseX = scanner.nextInt();
                    System.out.print("y: ");
                    mouseY = scanner.nextInt();
                    for (var shape : shapes) {
                        if (shape.areCoordsInside(mouseX, mouseY)) {
                            shape.present();
                        }
                    }
                    break;
                case "present":
                    for (var shape : shapes) {
                        shape.present();
                    }
                    break;
                case "move":
                    System.out.print("x1: ");
                    int mouseX1 = scanner.nextInt();
                    System.out.print("y1: ");
                    int mouseY1 = scanner.nextInt();
                    System.out.print("x2: ");
                    int mouseX2 = scanner.nextInt();
                    System.out.print("y2: ");
                    int mouseY2 = scanner.nextInt();
                    for (int i = shapes.length - 1; i >= 0; i--) {
                        var shape = shapes[i];
                        if (shape.areCoordsInside(mouseX1, mouseY1)) {
                            shape.move(mouseX1, mouseY1, mouseX2, mouseY2);
                        }
                    }
                    break;
                case "stop":
                    shouldExit = true;
                    break;
            }

        } while (!shouldExit);
    }

}




