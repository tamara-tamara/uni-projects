import java.util.Scanner;

public class URI1533 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        while (true) {
            int n = input.nextInt();
            if (n == 0) {
                break;
            }
            int[] num = new int[n];
            int max = Integer.MIN_VALUE;
            for (int i = 0; i < n; ++i) {
                num[i] = input.nextInt();
                if (num[i] > max) {
                    max = num[i];
                }
            }
            int secondSus = Integer.MIN_VALUE;
            int posOfSus = 0;
            for (int i = 0; i < n; ++i) {
                if (num[i] > secondSus && num[i] != max) {
                    secondSus = num[i];
                    posOfSus = i;
                }
            }
            System.out.println(posOfSus + 1);

        }
    }
}
