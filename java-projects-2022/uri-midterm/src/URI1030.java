import java.util.Scanner;

public class URI1030 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int[] people = new int[n];
        int[] steps = new int[n];
        for (int i = 0; i < n; i++) {
            people[i] = input.nextInt();
            steps[i] = input.nextInt();
            int result = 0;
            for (int j = 2; j <= people[i]; j++) {
                result += steps[i];
                result %= j;
            }
            System.out.printf("Case %d: %d\n", i + 1, result + 1);
        }

    }
}
