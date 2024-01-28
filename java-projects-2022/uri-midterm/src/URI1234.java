import java.util.Scanner;

public class URI1234 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        while (input.hasNextLine()) {
            String sentence = input.nextLine();
            if (sentence.equals("0")) {
                break;
            }
            char[] lines = sentence.toCharArray();
            int index = 0;
            for (int i = 0; i < lines.length; ++i) {
                if (index % 2 == 0 && Character.isLetterOrDigit(lines[i])) {
                    lines[i] = Character.toUpperCase(lines[i]);
                    index++;
                } else if (index % 2 != 0 && Character.isLetterOrDigit(lines[i])) {
                    lines[i] = Character.toLowerCase(lines[i]);
                    index++;
                } else {
                    index += 2;
                }
            }
            String result = new String(lines);
            System.out.println(result);
        }
    }
}
