import java.util.Scanner;

public class URI1272 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        input.nextLine();
        for (int i = 0; i < n; ++i) {
            String result = "";
            String s = input.nextLine();
            char[] decode = s.toCharArray();
            int count = 0;
            for (int j = 0; j < s.length(); ++j) {
                if (count == 0 && Character.isLetter(decode[j])) {
                    result += decode[j];
                }
                if (Character.isLetter(decode[j])) {
                    count++;
                }
                if (!(Character.isLetterOrDigit(decode[j]))) {
                    count = 0;
                }
            }
            System.out.println(result);

        }
    }
}
