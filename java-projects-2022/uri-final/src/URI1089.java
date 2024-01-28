import java.util.Scanner;

public class URI1089 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        while (true) {
            int num = input.nextInt();
            if (num == 0) {
                break;
            }
            int[] sample = new int[num];
            int numOfPeaks = 0;
            for (int i = 0; i < num; ++i) {
                sample[i] = input.nextInt();
            }
            for (int i = 0; i < num; ++i) {
                if (sample[(i + num - 1) % num] < sample[i] && sample[i] > sample[(i + 1) % num] || sample[i] < sample[(i + 1) % num] && sample[i] < sample[(i + num - 1) % num]) {
                    numOfPeaks++;
                }
            }
            System.out.println(numOfPeaks);
        }
    }
}
