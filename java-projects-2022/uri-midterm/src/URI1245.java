import java.util.Scanner;
import java.util.ArrayList;

public class URI1245 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        while (input.hasNextInt()) {
            int n = input.nextInt();
            ArrayList<String> inputD = new ArrayList<>();
            ArrayList<String> inputE = new ArrayList<>();
            int totalPairs = 0;
            input.nextLine();
            for (int i = 0; i < n; ++i) {
                String leftOrRight = input.nextLine();
                String size = leftOrRight.substring(0, 2);
                if (leftOrRight.contains("D")) {
                    inputD.add(size);
                }
                if (leftOrRight.contains("E")) {
                    inputE.add(size);
                }
            }
            for (String a : inputD) {
                if (inputE.contains(a)) {
                    totalPairs++;
                    inputE.remove(a);
                }
            }
            System.out.println(totalPairs);
        }

    }
}
