import java.util.Scanner;

public class URI1632 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        input.nextLine();
        for (int i = 0; i < n; ++i) {
            String password = input.nextLine().toLowerCase();
            char[] word = password.toCharArray();
            int counterOfSpecial = 0;
            int result = 1;
            for (int j = 0; j < password.length(); ++j) {
                if (word[j] == 'a' || word[j] == 'e' || word[j] == 'i' || word[j] == 'o' || word[j] == 's') {
                    counterOfSpecial++;
                } else {
                    result *= 2;
                }
            }
            int finalResult = 0;
            if (counterOfSpecial > 0) {
                finalResult = result * (int) Math.pow(3, counterOfSpecial);
            } else {
                finalResult = result;
            }

            System.out.println(finalResult);

        }
    }
}
