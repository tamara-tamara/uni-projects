import java.util.Scanner;

public class URI1551 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        input.nextLine();
        for (int i = 0; i < n; ++i) {
            String line = input.nextLine().toLowerCase();
            int checker = 0;
            boolean[] alphabet = new boolean[26];
            for (int j = 0; j < line.length(); ++j) {
                char letter = line.charAt(j);
                if (Character.isLetter(letter)) {
                    int position = letter - 'a';
                    alphabet[position] = true;
                }
            }
            for (int j = 0; j < 26; ++j) {
                if (!alphabet[j]) {
                    checker++;
                }
            }
            if (checker == 0) {
                System.out.println("frase completa");
            } else if (checker <= 13) {
                System.out.println("frase quase completa");
            } else {
                System.out.println("frase mal elaborada");
            }
        }
    }
}
