import java.util.Scanner;

public class URI1257 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        for (int i = 0; i < n; ++i) {
            int m = input.nextInt();
            int result = 0;
            for (int j = 0; j < m; ++j) {
                String sentence = input.next();
                for (int k = 0; k < sentence.length(); ++k) {
                    int alphabeticOrder = Character.toLowerCase(sentence.charAt(k)) - 'a';
                    result += alphabeticOrder + j + k;
                }
            }
            System.out.println(result);
        }
    }
}
