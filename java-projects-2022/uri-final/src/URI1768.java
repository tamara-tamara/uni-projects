import java.util.Scanner;

public class URI1768 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        while (input.hasNextInt()) {
            int number = input.nextInt();
            for (int i = 1; i <= (number / 2) + 1; ++i) {
                for (int j = i; j <= number / 2; ++j) {
                    System.out.print(" ");
                }
                int line = 2 * i - 1;
                for (int j = 1; j <= line; ++j) {
                    System.out.print("*");
                }
                System.out.println();
            }
            for (int i = 0; i < number / 2; ++i) {
                System.out.print(" ");
            }
            System.out.println("*");
            for (int i = 0; i < (number / 2) - 1; ++i) {
                System.out.print(" ");
            }
            System.out.println("***");
            System.out.println();

        }
    }
}
