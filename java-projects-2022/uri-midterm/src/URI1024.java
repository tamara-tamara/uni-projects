import java.util.Scanner;

public class URI1024 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        String message = "";
        String[] result = new String[n];
        scanner.nextLine();
        for (int i = 0; i < n; ++i) {
            message = scanner.nextLine();
            char[] charMess = message.toCharArray();
            for (int j = 0; j < charMess.length; ++j) {
                char let = charMess[j];
                if (Character.isLetter(let)) {
                    char shiftTo3 = (char) (let + 3);
                    charMess[j] = shiftTo3;
                }

            }
            int reverse = charMess.length - 1;
            for (int k = 0; k < reverse; ++k) {
                char shift = charMess[k];
                charMess[k] = charMess[reverse];
                charMess[reverse] = shift;
                reverse--;
            }
            int half = charMess.length / 2;
            for (int t = half; t < charMess.length; t++) {
                char halfLet = charMess[t];
                char shiftTo1 = (char) (halfLet - 1);
                charMess[t] = shiftTo1;
            }
            result[i] = String.valueOf(charMess);

        }
        for (int i = 0; i < n; i++) {
            System.out.println(result[i]);
        }

    }
}
