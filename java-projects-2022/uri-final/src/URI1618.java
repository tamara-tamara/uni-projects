import java.util.Scanner;

public class URI1618 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        for (int i = 0; i < n; ++i) {
            int[] posX = new int[4];
            int[] posY = new int[4];

            for (int j = 0; j < 4; ++j) {
                posX[j] = input.nextInt();
                posY[j] = input.nextInt();
            }
            int rX = input.nextInt();
            int rY = input.nextInt();
            if (rX < posX[0] || rX > posX[1] || rY < posY[0] || rY > posY[2]) {
                System.out.println(0);
            } else {
                System.out.println(1);
            }

        }
    }
}
