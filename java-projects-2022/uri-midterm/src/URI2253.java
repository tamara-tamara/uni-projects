import java.util.Scanner;

public class URI2253 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        while (input.hasNextLine()) {
            String password = input.nextLine();
            boolean isValidFor1 = false;
            boolean isValidForLower = false;
            boolean isValidForNumber = false;
            boolean isValidFor2 = true;
            boolean isValidFor3 = false;
            for (int i = 0; i < password.length(); ++i) {
                if (Character.isUpperCase(password.charAt(i))) {
                    isValidFor1 = true;
                }
                if (Character.isLowerCase(password.charAt(i))) {
                    isValidForLower = true;
                }
                if (Character.isDigit(password.charAt(i))) {
                    isValidForNumber = true;
                }
                if (!Character.isLetterOrDigit(password.charAt(i))) {
                    isValidFor2 = false;
                }
                if (password.length() >= 6 && password.length() <= 32) {
                    isValidFor3 = true;
                }
            }
            if (isValidFor1 && isValidForLower && isValidForNumber && isValidFor2 && isValidFor3) {
                System.out.println("Senha valida.");
            } else {
                System.out.println("Senha invalida.");
            }
        }
    }
}
