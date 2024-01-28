import java.util.Scanner;

public class URI1273 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        while (n != 0) {
            input.nextLine();
            int size = 0;
            String[] line = new String[n];
            for (int i = 0; i < n; ++i) {
                line[i] = input.nextLine();
                if (line[i].length() > size) {
                    size = line[i].length();
                }
            }
            for (int i = 0; i < n; ++i) {
                int difference = size - line[i].length();
                for (int j = 0; j < difference; ++j) {
                    System.out.print(" ");
                }
                System.out.println(line[i]);
            }
            if ((n = input.nextInt()) != 0) {
                System.out.println();
            }
        }
    }
}
