import java.util.Scanner;

public class URI1329 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        while (true) {
            int n = input.nextInt();
            if (n == 0) {
                break;
            }
            int scoreForMary = 0;
            int scoreForJohn = 0;
            for (int i = 0; i < n; ++i) {
                int score = input.nextInt();
                if (score == 0) {
                    scoreForMary++;
                } else {
                    scoreForJohn++;
                }
            }
            System.out.println("Mary won " + scoreForMary + " times and John won " + scoreForJohn + " times");
        }
    }
}

