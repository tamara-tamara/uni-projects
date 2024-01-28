import java.util.Scanner;

public class URI1136 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            int n = sc.nextInt();
            int b = sc.nextInt();
            if (n == 0 && b == 0) {
                break;
            }
            int[] arr = new int[n+1];
            int[] arr2 = new int[b];
            for (int i = 0; i < b; i++) {
                arr2[i] = sc.nextInt();
            }
            for (int i = 0; i < b; i++) {
                for (int j = 0; j < b; j++) {
                    arr[Math.abs(arr2[i] - arr2[j])] = 1;
                }
            }
            boolean yOrN = true;
            for (int i = 0; i <= n; i++) {
                yOrN &= arr[i] == 1;
            }
            System.out.println(yOrN ? "Y" : "N");
        }
    }
}
