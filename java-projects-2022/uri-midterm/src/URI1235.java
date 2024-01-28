import java.util.Scanner;

public class URI1235 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        input.nextLine();
        for (int i = 0; i < n; i++) {
            String sentence = input.nextLine();
            char[] words = new char[sentence.length()];
            int half = (words.length - 1) / 2;
            for (int j = half; j >= 0; --j) {
                System.out.print(sentence.charAt(j));
            }
            for (int k = sentence.length() - 1; k >= sentence.length() / 2; --k) {
                System.out.print(sentence.charAt(k));
            }
            System.out.println();
        }
    }
}
