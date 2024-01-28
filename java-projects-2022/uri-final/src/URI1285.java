import java.util.Scanner;

public class URI1285 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        while (input.hasNextInt()) {
            int n = input.nextInt();
            int m = input.nextInt();
            boolean contains = false;
            int counter = 0;
            for (int i = n; i <= m; ++i) {
                String num = String.valueOf(i);
                char[] numChar = num.toCharArray();
                for (int j = 0; j < num.length(); ++j) {
                    for (int k = j + 1; k < num.length(); ++k) {
                        if (numChar[j] == numChar[k]) {
                            contains = true;
                            break;
                        }
                    }
                }
                if (!contains) {
                    counter++;
                }
                contains = false;
            }
            System.out.println(counter);
        }
    }
}
