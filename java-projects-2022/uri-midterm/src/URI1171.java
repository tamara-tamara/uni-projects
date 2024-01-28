import java.util.Arrays;
import java.util.Scanner;

public class URI1171 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = input.nextInt();
        }

        Arrays.sort(arr);
        int count = 1;

        for (int i = 1; i < n; i++) {
            if (arr[i] == arr[i - 1]) {
                count++;
            } else {
                System.out.println(arr[i - 1] + " aparece " + count + " vez(es)");
                count = 1;
            }
        }

        System.out.println(arr[n - 1] + " aparece " + count + " vez(es)");
    }
}



