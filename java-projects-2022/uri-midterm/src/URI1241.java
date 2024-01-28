import java.util.Scanner;

public class URI1241 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        for (int i = 0; i < n; ++i) {
            String a = input.next();
            String b = input.next();

            if (a.endsWith(b)) {
                System.out.println("encaixa");
            } else {
                System.out.println("nao encaixa");
            }

        }
    }
}
