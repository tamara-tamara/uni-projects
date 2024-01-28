import java.util.Scanner;

public class URI1609 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        for (int i = 0; i < n; ++i) {
            int numOfNum = input.nextInt();
            int[] numOfSheep = new int[numOfNum];
            int numOfDistinct = 0;
            boolean isUnique = true;
            for (int j = 0; j < numOfNum; ++j) {
                numOfSheep[j] = input.nextInt();
            }
            for (int j = 0; j < numOfSheep.length; ++j) {
                for (int k = j + 1; k < numOfSheep.length; ++k) {
                    if (numOfSheep[j] == numOfSheep[k]) {
                        isUnique = false;
                        break;
                    }
                }
                if (isUnique) {
                    numOfDistinct++;
                }
                isUnique = true;
            }
            System.out.println(numOfDistinct);
        }
    }
}
