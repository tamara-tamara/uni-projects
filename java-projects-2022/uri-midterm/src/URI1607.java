import java.util.Scanner;

public class URI1607 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        for (int i = 0; i < n; ++i) {
            String firstWord = input.next();
            String secondWord = input.next();
            int transformation = 0;
            for (int j = 0; j < firstWord.length(); ++j) {
                int counter = Character.toLowerCase(firstWord.charAt(j)) - 'a';
                int counter2 = Character.toLowerCase(secondWord.charAt(j)) - 'a';
                int gap = counter2 - counter;
                if (gap < 0) {
                    gap += 26;
                }
                transformation += gap;
            }
            System.out.println(transformation);
        }
    }
}
