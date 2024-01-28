import java.util.Scanner;

public class URI2242 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String sentence = "";
        while (true) {
            if (input.hasNextLine()) {
                sentence = input.nextLine();
            } else {
                break;
            }
            if (sentence.isEmpty()) {
                break;
            }
            char[] words = sentence.toCharArray();
            String vowels = "";
            boolean isALaugh = true;
            for (int i = 0; i < sentence.length(); ++i) {
                if (words[i] == 'a' || words[i] == 'e' || words[i] == 'i' || words[i] == 'u'
                        || words[i] == 'o') {
                    vowels += words[i];
                }
            }
            for (int i = 0; i < vowels.length() / 2; i++) {
                if (vowels.charAt(i) != vowels.charAt(vowels.length() - 1 - i)) {
                    isALaugh = false;
                    break;
                }
            }
            if (isALaugh) {
                System.out.println("S");
            } else {
                System.out.println("N");
            }

        }
    }
}
