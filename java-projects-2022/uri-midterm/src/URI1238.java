import java.util.Scanner;

public class URI1238 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        String[] result = new String[n];
        scanner.nextLine();
        for (int i = 0; i < n; ++i) {
            String firstWord = scanner.next();
            String secondWord = scanner.next();
            char[] fChar = firstWord.toCharArray();
            char[] sChar = secondWord.toCharArray();
            int max = Math.max(firstWord.length(), secondWord.length());
            StringBuilder newWord = new StringBuilder();
            for (int j = 0; j < max; ++j) {
                if (j < fChar.length) {
                    newWord.append(fChar[j]);
                }
                if (j < sChar.length) {
                    newWord.append(sChar[j]);
                }
            }
            result[i] = newWord.toString();
        }
        for (int i = 0; i < n; ++i) {
            System.out.println(result[i]);
        }
    }
}
