import java.util.Scanner;

public class URI1300 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        while (input.hasNextInt()) {
            double degree = input.nextDouble();
            if (((int) degree) % 6 == 0) {
                System.out.println("Y");
            } else {
                System.out.println("N");
            }
        }
    }
}
