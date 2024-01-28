import java.util.Scanner;

public class URI2137 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        while (input.hasNextInt()) {
            int n = input.nextInt();
            int[] codes = new int[n];
            for (int i = 0; i < n; ++i) {
                codes[i] = input.nextInt();
            }
            for (int i = 0; i < codes.length - 1; i++) {
                for (int j = 0; j < codes.length - i - 1; j++) {
                    if (codes[j] > codes[j + 1]) {
                        int temp = codes[j];
                        codes[j] = codes[j + 1];
                        codes[j + 1] = temp;
                    }
                }
            }
            for (int i = 0; i < codes.length; ++i) {
                String codeString = String.format("%04d", codes[i]);
                System.out.println(codeString);
            }
        }
    }
}
