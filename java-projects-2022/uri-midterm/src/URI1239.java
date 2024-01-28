import java.util.Scanner;

public class URI1239 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        while (input.hasNextLine()) {
            String sentence = input.nextLine();
            boolean isFirstUnderScore = true;
            boolean isFirstAsterisk = true;
            for (int i = 0; i < sentence.length(); ++i) {
                char sign = sentence.charAt(i);
                if (sign == '_' && isFirstUnderScore) {
                    System.out.print("<i>");
                    isFirstUnderScore = false;
                } else if (sign == '*' && isFirstAsterisk) {
                    System.out.print("<b>");
                    isFirstAsterisk = false;
                } else if (sign == '_') {
                    System.out.print("</i>");
                    isFirstUnderScore = true;
                } else if (sign == '*') {
                    System.out.print("</b>");
                    isFirstAsterisk = true;
                } else {
                    System.out.print(sentence.charAt(i));
                }
            }
            System.out.println();
        }
    }
}
