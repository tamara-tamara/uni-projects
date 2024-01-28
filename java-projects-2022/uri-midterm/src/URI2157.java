import java.util.Scanner;

public class URI2157 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        for (int i = 0; i < n; ++i) {
            int a = input.nextInt();
            int b = input.nextInt();
            for (int j = a; j <= b; ++j) {
                System.out.print(j);
            }
            for (int j = b; j >= a; --j) {
                if (j > 9) {
                    String num = Integer.toString(j);
                    for (int k = num.length() - 1; k >= 0; --k) {
                        System.out.print(num.charAt(k));
                    }
                } else {
                    System.out.print(j);
                }
            }
            System.out.println();
        }
    }
}
