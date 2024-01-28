import java.util.Scanner;

public class URI2154 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        while (input.hasNextInt()) {
            int num = input.nextInt();
            input.nextLine();
            String[] polynomial = input.nextLine().split(" ");
            StringBuilder result = new StringBuilder();
            for (int i = 0; i < num + (num - 1); ++i) {
                int indexOfX = 0;
                int indexOfPower = 0;
                for (int j = 0; j < polynomial[i].length(); ++j) {
                    if (polynomial[i].equals("+")) {
                        break;
                    }
                    if (Character.isLetter(polynomial[i].charAt(j))) {
                        indexOfX = j;
                        indexOfPower = j + 1;
                        break;
                    }
                }
                if (!polynomial[i].equals("+")) {
                    String coefficientInString = polynomial[i].substring(0, indexOfX);
                    String powerInString = polynomial[i].substring(indexOfPower);
                    int power = Integer.parseInt(powerInString);
                    if (power == 1 || indexOfX == polynomial[i].length()) {
                        result.append(Integer.parseInt(coefficientInString));
                    } else {
                        int newCoefficient = Integer.parseInt(coefficientInString) * Integer.parseInt(powerInString);
                        if (power - 1 == 1) {
                            result.append(newCoefficient).append("x");
                        } else {
                            result.append(newCoefficient).append("x").append(power - 1);
                        }
                    }
                    if (i + 1 != num + (num - 1)) {
                        result.append(" + ");
                    }
                }
            }
            System.out.print(result);
            if (num + (num - 1) != polynomial.length) {
                for (int i = num + 1; i < polynomial.length; ++i) {
                    System.out.print(" " + polynomial[i]);
                }
            }
            System.out.println();
        }
    }
}
