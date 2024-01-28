import java.util.Arrays;
import java.util.Scanner;

public class URI1248 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        input.nextLine();
        for (int i = 0; i < n; ++i) {
            String dietPlan = input.nextLine();
            char[] diet = dietPlan.toCharArray();
            String breakfast = input.nextLine();
            String lunch = input.nextLine();
            if (dietPlan.isEmpty() && (!breakfast.isEmpty() || !lunch.isEmpty())) {
                System.out.println("CHEATER");
            } else {
                int counter = 0;
                for (int j = 0; j < breakfast.length(); ++j) {
                    for (int k = 0; k < dietPlan.length(); ++k) {
                        if (diet[k] == breakfast.charAt(j)) {
                            diet[k] = '0';
                            counter++;
                            break;
                        }
                    }
                }
                int counter2 = 0;
                for (int j = 0; j < lunch.length(); ++j) {
                    for (int k = 0; k < dietPlan.length(); ++k) {
                        if (diet[k] == lunch.charAt(j)) {
                            diet[k] = '0';
                            counter2++;
                            break;
                        }
                    }
                }
                if (counter2 != lunch.length() || counter != breakfast.length()) {
                    System.out.println("CHEATER");
                } else {
                    Arrays.sort(diet);
                    for (int j = 0; j < diet.length; ++j) {
                        if (diet[j] != '0') {
                            System.out.print(diet[j]);
                        }
                    }
                    System.out.println();

                }
            }
        }

    }
}
