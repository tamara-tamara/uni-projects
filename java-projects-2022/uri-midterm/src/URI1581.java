import java.util.Scanner;

public class URI1581 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        for (int i = 0; i < n; ++i) {
            int numOfPeople = input.nextInt();
            String[] language = new String[numOfPeople];
            boolean areSame = true;
            for (int j = 0; j < numOfPeople; ++j) {
                language[j] = input.next();
                if (!language[0].equals(language[j])) {
                    areSame = false;
                }
            }
            if (areSame) {
                System.out.println(language[0]);
            } else {
                System.out.println("ingles");
            }
        }
    }
}
