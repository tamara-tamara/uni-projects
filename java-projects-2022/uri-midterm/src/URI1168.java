import java.util.Scanner;

public class URI1168 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();
        for (int i = 0; i < n; i++) {
            String number = scanner.nextLine();
            int led = 0;
            for (char digit : number.toCharArray()) {
                switch (digit) {
                    case '0', '9', '6':
                        led += 6;
                        break;
                    case '8':
                        led += 7;
                        break;
                    case '2', '3', '5':
                        led += 5;
                        break;
                    case '4':
                        led += 4;
                        break;
                    case '7':
                        led += 3;
                        break;
                    case '1':
                        led += 2;
                        break;
                }
            }
            System.out.println(led + " leds");
        }
    }
}
