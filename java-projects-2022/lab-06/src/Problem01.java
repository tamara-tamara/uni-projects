
import java.util.Scanner;

public class Problem01 {
    public static void main(String[] args) {
        Rectangle[] rectangles = {
                new Rectangle(10, 10, 100, 100),
                new Rectangle(400, 400, 100, 100)

        };
        Scanner scanner = new Scanner(System.in);
        int mouseX, mouseY;
        do {
            System.out.print("x: ");
            mouseX = scanner.nextInt();
            System.out.print("y: ");
            mouseY = scanner.nextInt();
            if (mouseX == -1 && mouseY == -1) {
                break;
            }

            for (var rectangle : rectangles) {
                if (rectangle.areCoordsInside(mouseX, mouseY)) {
                    rectangle.present();
                }
            }
        } while (true);
    }

}
