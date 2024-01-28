import java.util.InputMismatchException;
import java.util.Scanner;

public class Problem01 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        boolean canContinue = true;

        do {
            try {
                System.out.print("Enter an integer: ");
                int integer = input.nextInt();
                System.out.println("The number entered is " + integer);
                canContinue = false;
            } catch (InputMismatchException e) {
                System.out.println("Try again. (Incorrect input: an integer is required.)");
                input.nextLine();
            }
        } while (canContinue);
    }
}
