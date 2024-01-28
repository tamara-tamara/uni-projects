import java.util.Scanner;

public class Problem02 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Press Ctrl-Z/D to exit");
        System.out.print("First rational: ");
        while (scan.hasNextLine()) {

            try {
                BigRational result = null;
                int comparing = 0;
                String firstRationalString = scan.nextLine();
                BigRational first = BigRational.parseBigRational(firstRationalString);
                if (!firstRationalString.contains("/")) {
                    throw new NumberFormatException("Incorrect Rational format. " +
                            "Please, enter your rational in form a/b, where a and b are integer numbers.");
                }
                System.out.print("Operator: ");
                String operator = scan.nextLine();
                if (!operator.contains("+") && !operator.contains("-") && !operator.contains("*") && !operator.contains("/") && !operator.contains("=") &&
                        !operator.contains("!=") && !operator.contains("<") && !operator.contains(">") && !operator.contains("<=") && !operator.contains(">=") ||
                        operator.length() > 2 || !operator.contains("=") && !operator.contains("<") && !operator.contains(">") && operator.length() > 1) {
                    throw new NumberFormatException("Invalid operator. Operators such as '+, -, *, /, <, >, =, !=, <=, >=' are acceptable.");
                }
                System.out.print("Second rational: ");
                String secondRationalString = scan.nextLine();
                if (!secondRationalString.contains("/")) {
                    throw new NumberFormatException("Incorrect Rational format. " +
                            "Please, enter your rational in form a/b, where a and b are integer numbers.");
                }
                BigRational second = BigRational.parseBigRational(secondRationalString);
                switch (operator) {
                    case "+" -> result = first.add(second);
                    case "-" -> result = first.subtract(second);
                    case "*" -> result = first.multiply(second);
                    case "/" -> result = first.divide(second);
                    case "<", ">", "<=", ">=", "=", "!=" -> comparing = first.compareTo(second, operator);
                }

                if (result != null) {
                    System.out.println("Result: " + firstRationalString + " " + operator + " " + secondRationalString + " : " + result);
                } else {
                    if (comparing == 0) {
                        System.out.println("Result: " + firstRationalString + " " + operator + " " + secondRationalString + " : true");
                    } else {
                        System.out.println("Result: " + firstRationalString + " " + operator + " " + secondRationalString + " : false");
                    }
                }
                System.out.print("First rational: ");
            } catch (NumberFormatException e) {
                System.err.println("Error: " + e.getMessage() + " Please,try again.");
            } catch (ArithmeticException e) {
                System.err.println("Error: " + e.getMessage() + " Please, try again.");
            }
        }

    }
}