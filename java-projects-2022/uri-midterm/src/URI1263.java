import java.util.Scanner;

public class URI1263 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        while (input.hasNextLine()) {
            String word = input.nextLine();
            String[] words = word.toLowerCase().split(" ");
            int counter = 0;
            String firstWord, firstWord2 = "";
            boolean isAThirdOne = false;
            for (int i = 0; i < words.length - 1; ++i) {
                firstWord = words[i];
                firstWord2 = words[i + 1];
                if (firstWord.charAt(0) == firstWord2.charAt(0) && !isAThirdOne) {
                    counter++;
                    isAThirdOne = true;
                } else if (firstWord.charAt(0) != firstWord2.charAt(0)) {
                    isAThirdOne = false;
                }
            }
            System.out.println(counter);
        }
    }
}
