import java.util.Scanner;

public class URI1253 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        String[] result = new String[n];
        scanner.nextLine();
        for (int i = 0; i < n; ++i) {
            String input = scanner.next();
            char[] encode = input.toCharArray();
            int numOfShift = scanner.nextInt();
            for (int j = 0; j < encode.length; ++j) {
                char shift = encode[j];
                char shiftedPosition = (char) (shift - numOfShift);
                if (shiftedPosition < 'A') {
                    shiftedPosition = (char) (shiftedPosition + 26);
                }
                encode[j] = shiftedPosition;
            }
            result[i] = String.valueOf(encode);
        }
        for (int i = 0; i < n; i++) {
            System.out.println(result[i]);
        }
    }
}
