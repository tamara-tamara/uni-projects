import java.util.ArrayList;
import java.util.Scanner;

public class URI1367 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        while (true) {
            int n = input.nextInt();
            if (n == 0) {
                break;
            }
            int totalResult = 0;
            int numOfCorrect = 0;
            ArrayList<String> tests = new ArrayList<>();
            for (int i = 0; i < n; ++i) {
                String letter = input.next();
                int time = input.nextInt();
                String status = input.next();
                tests.add(letter);

                if (status.equals("correct")) {
                    totalResult += time;
                    numOfCorrect++;
                    tests.removeIf(tests::equals);
                } else {
                    totalResult += 20;
                }
            }
            System.out.println(numOfCorrect + " " + (totalResult - tests.size()*20));
        }
    }
}
