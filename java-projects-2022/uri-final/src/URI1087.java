import java.util.Scanner;

public class URI1087 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        while (true) {
            int x1 = input.nextInt();
            int y1 = input.nextInt();
            int x2 = input.nextInt();
            int y2 = input.nextInt();
            if (x1 == y2 && x1 == x2 && x2 == y1 && x1 == 0) {
                break;
            }
            int absX = Math.abs(x1 - x2);
            int absY = Math.abs(y1 - y2);
            if (x1 == x2 && y1 == y2) {
                System.out.println(0);
            } else if (x1 == x2 || y1 == y2 || absX == absY) {
                System.out.println(1);
            } else {
                System.out.println(2);
            }
        }
    }
}
