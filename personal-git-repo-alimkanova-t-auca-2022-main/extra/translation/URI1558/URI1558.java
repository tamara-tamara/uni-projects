import java.util.Scanner;

public class URI1558 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        while (input.hasNextInt()) {
            boolean isRight = false;
            int num = input.nextInt();
            int maxOfNum = (int) Math.round(Math.sqrt(Math.abs(num)));
            for (int i = 0; i <= maxOfNum; ++i) {
                for (int j = 0; j <= maxOfNum; ++j) {
                    if (Math.pow(i, 2) + Math.pow(j, 2) == num) {
                        isRight = true;
                        break;
                    }
                }
            }
            if (isRight) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}
