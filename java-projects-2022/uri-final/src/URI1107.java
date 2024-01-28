import java.util.Scanner;

public class URI1107 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            int a = sc.nextInt();
            int c = sc.nextInt();
            if (a == 0 && c == 0) {
                break;
            }
            int[] arr = new int[c+1];
            for (int i = 1; i <= c; i++) {
                arr[i] = sc.nextInt();
            }
            int result = a - arr[1];
            for (int i = 2; i <= c; i++) {
                if (arr[i] < arr[i - 1]) {
                    result += arr[i - 1] - arr[i];
                }
            }
            System.out.println(result);
        }
    }
}
