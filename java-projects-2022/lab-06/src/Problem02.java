
import java.util.Scanner;

public class Problem02 {
    public static void main(String[] args) {
        Rectangle[] rectangles = {
                new Rectangle(10, 10, 100, 100),
                new Rectangle(400, 400, 100, 100)
        };
        Circle[] circles = {
                new Circle(500, 10, 100),
                new Circle(800, 800, 100)
        };
        Scanner scanner = new Scanner(System.in);
        int mouseX, mouseY;
        do {
            System.out.print("x: ");
            mouseX = scanner.nextInt();
            System.out.print("y: ");
            mouseY = scanner.nextInt();
            if (mouseX == 1 && mouseY == 1) {
                break;
            }

            for (var rectangle : rectangles) {
                if (rectangle.areCoordsInside(mouseX, mouseY)) {
                    rectangle.present();
                }
            }

            for (var circle : circles) {
                if (circle.areCoordsInside(mouseX, mouseY)) {
                    circle.present();
                }
            }
        } while (true);
    }
}
