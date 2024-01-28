import java.util.Scanner;

public class URI2062 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        for (int i = 0; i < n; ++i) {
            String word = input.next();
            if (word.contains("OB") && word.length() == 3) {
                word = "OBI";

            } else if (word.contains("UR") && word.length() == 3) {
                word = "URI";
            }
            System.out.printf(i != n - 1 ? "%s " : "%s\n", word);
        }
    }
}
