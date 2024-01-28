import java.util.Scanner;

public class URI1237 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        while (input.hasNextLine()) {
            String firstSentence = input.nextLine();
            String secondSentence = input.nextLine();
            int longestSubstring = 0;
            for (int i = 0; i < firstSentence.length(); i++) {
                for (int j = i + 1; j <= firstSentence.length(); j++) {
                    if (secondSentence.contains(firstSentence.substring(i, j))) {
                        int length = firstSentence.substring(i, j).length();
                        if (length > longestSubstring) longestSubstring = length;
                    }
                }
            }
            System.out.println(longestSubstring);
        }
    }
}
