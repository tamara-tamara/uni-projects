import java.util.Scanner;

public class URI2694 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        input.nextLine();
        for (int i = 0; i < n; ++i) {
            String line = input.nextLine();
            StringBuilder num = new StringBuilder();
            int total = 0;
            boolean isNum = false;
            for (int j = 0; j < line.length(); ++j) {
                if (Character.isDigit(line.charAt(j))) {
                    num.append(Integer.parseInt(String.valueOf(line.charAt(j))));
                    isNum = true;
                }
                if (Character.isLetter(line.charAt(j)) || j + 1 == line.length()) {
                    if (isNum) {
                        int sum = Integer.parseInt(String.valueOf(num));
                        total += sum;
                    }
                    num.delete(0, line.length());
                    isNum = false;
                }
            }
            System.out.println(total);
        }
    }
}
