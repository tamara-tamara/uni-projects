import java.util.Scanner;

public class URI1514 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        // StringBuilder in = new StringBuilder();
        int n = input.nextInt();
        int m = input.nextInt();
        while (n != 0 && m != 0) {
            int[][] points = new int[n][m];
            int characteristics = 0;
            boolean allCharec = false;
            int checker = 0;
            for (int i = 0; i < n; ++i) {
                int solved = 0;
                for (int j = 0; j < m; j++) {
                    points[i][j] = input.nextInt();
                    if (points[i][j] == 1) {
                        solved++;
                    }
                }
                if (solved == m) {
                    allCharec = true;
                }
                if (solved >= 1) {
                    checker++;
                }
            }
            boolean allChar2 = false;
            int checker2 = 0;
            for (int i = 0; i < m; ++i) {
                int solved2 = 0;
                for (int j = 0; j < n; ++j) {
                    if (points[j][i] == 1) {
                        solved2++;
                    }
                }
                if (solved2 == n) {
                    allChar2 = true;
                }
                if (solved2 >= 1) {
                    checker2++;
                }
            }
            if (checker2 == m) {
                characteristics++;
            }
            if (!allCharec) {
                characteristics++;
            }

            if (!allChar2) {
                characteristics++;
            }
            if (checker == n) {
                characteristics++;
            }

            // in.append(characteristics).append("\n");
            System.out.println(characteristics);
            n = input.nextInt();
            m = input.nextInt();

        }


    }
}
