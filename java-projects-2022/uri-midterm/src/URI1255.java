import java.util.Scanner;

public class URI1255 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        input.nextLine();
        for (int i = 0; i < n; ++i) {
            int max = Integer.MIN_VALUE;
            String sentence = input.nextLine();
            int[] alphabet = new int[26];
            for (int j = 0; j < sentence.length(); ++j) {
                char letter = Character.toLowerCase(sentence.charAt(j));
                if (Character.isLetter(letter)) {
                    alphabet[letter - 'a']++;
                }
            }
            for (int j = 0; j < alphabet.length; ++j) {
                if (alphabet[j] > max) {
                    max = alphabet[j];
                }
            }
            for (int j = 0; j < alphabet.length; ++j) {
                if (alphabet[j] == max) {
                    System.out.print((char) ('a' + j));
                }
            }
            System.out.println();
        }
    }
}
