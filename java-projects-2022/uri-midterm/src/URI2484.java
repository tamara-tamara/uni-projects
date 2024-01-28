import java.util.Scanner;

public class URI2484 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        while (input.hasNext()) {
            String word = input.next();
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < word.length(); i++) {
                sb.append(" ".repeat(i));
                for (int j = 0; j < word.length() - i; j++) {
                    sb.append(word.charAt(j));
                    if (j < word.length() - i - 1) {
                        sb.append(" ");
                    }
                }
                sb.append("\n");
            }
            System.out.print(sb + "\n");
        }
    }
}
