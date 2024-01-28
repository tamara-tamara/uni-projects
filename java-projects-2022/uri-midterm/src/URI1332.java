import java.util.Scanner;

public class URI1332 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        for (int i = 0; i < n; ++i) {
            String num = input.next();
            if (num.length() == 5) {
                System.out.println(3);
            } else if ((num.charAt(0) == 'o' && num.charAt(1) == 'n') || (num.charAt(0) == 'o' && num.charAt(2) == 'e') || (num.charAt(1) == 'n') && num.charAt(2) == 'e') {
                System.out.println(1);
            } else {
                System.out.println(2);
            }
        }
    }
}
