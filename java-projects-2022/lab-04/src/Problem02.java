import java.util.ArrayList;
import java.util.Scanner;

public class Problem02 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        ArrayListInt num = new ArrayListInt();
        //  ArrayList<Integer> num = new ArrayList<>();
        while (input.hasNextInt()) {
            num.add(input.nextInt());
        }
        System.out.println("After insertions:");
        insertZeroBeforeEven(num);
        System.out.println(num);
        System.out.println("After deletions:");
        removeOdd(num);
        System.out.println(num);
    }

    private static void insertZeroBeforeEven(ArrayListInt num) {
        for (int i = 0; i < num.size(); ++i) {
            int temp = num.get(i);
            if (temp % 2 == 0) {
                num.add(i, 0);
                i++;
            }
        }
    }

    private static void removeOdd(ArrayListInt num) {

        for (int i = 0; i < num.size(); ++i) {
            int temp = num.get(i);
            if (temp % 2 != 0) {
                num.remove(i);
                i--;
            }
        }
    }
}
