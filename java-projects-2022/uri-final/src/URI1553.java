import java.util.Scanner;

public class URI1553 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        while (true) {
            int numOfQ = input.nextInt();
            int freq = input.nextInt();
            if (numOfQ == 0 && freq == 0) {
                break;
            }
            int[] questions = new int[numOfQ];
            int[] pos = new int[101];
            for (int i = 0; i < numOfQ; ++i) {
                questions[i] = input.nextInt();
                pos[questions[i]]++;
            }
            int counter = 0;
            for (int i = 1; i <= 100; ++i) {
                if (pos[i] >= freq) {
                    counter++;
                }
            }
            System.out.println(counter);

        }
    }
}
