import java.util.Scanner;

public class URI1743 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int[] firstRow = new int[5];
        int[] secondRow = new int[5];
        for (int i = 0; i < 5; ++i) {
            firstRow[i] = input.nextInt();
        }
        for (int i = 0; i < 5; ++i) {
            secondRow[i] = input.nextInt();
        }
        boolean isCompatible = true;
        for (int i = 0; i < secondRow.length; ++i) {
            if (firstRow[i] == secondRow[i]) {
                isCompatible = false;
                break;
            }
        }
        if (isCompatible) {
            System.out.println("Y");
        } else {
            System.out.println("N");
        }

    }
}
