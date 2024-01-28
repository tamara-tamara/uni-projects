import java.util.Scanner;

public class URI1383 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        for (int i = 0; i < n; i++) {
            int[][] sheet = new int[9][9];
            boolean isNotCorrect = false;
            for (int c = 0; c < 9; c++) {
                for (int d = 0; d < 9; d++) {
                    sheet[c][d] = input.nextInt();
                }
            }
            for (int row = 0; row < 9; row++) {
                boolean[] used = new boolean[10];
                for (int col = 0; col < 9; col++) {
                    int num = sheet[row][col];
                    if (used[num]) {
                        isNotCorrect = true;
                        break;
                    }
                    used[num] = true;
                }
                if (isNotCorrect) {
                    break;
                }
            }
            if (!isNotCorrect) {
                for (int col = 0; col < 9; col++) {
                    boolean[] used = new boolean[10];
                    for (int row = 0; row < 9; row++) {
                        int num = sheet[row][col];
                        if (used[num]) {
                            isNotCorrect = true;
                            break;
                        }
                        used[num] = true;
                    }
                    if (isNotCorrect) {
                        break;
                    }
                }
            }
            if (!isNotCorrect) {
                for (int row = 0; row < 9; row += 3) {
                    for (int col = 0; col < 9; col += 3) {
                        boolean[] used = new boolean[10];
                        for (int r = row; r < row + 3; r++) {
                            for (int c = col; c < col + 3; c++) {
                                int num = sheet[r][c];
                                if (used[num]) {
                                    isNotCorrect = true;
                                    break;
                                }
                                used[num] = true;
                            }
                            if (isNotCorrect) {
                                break;
                            }
                        }
                        if (isNotCorrect) {
                            break;
                        }
                    }
                    if (isNotCorrect) {
                        break;
                    }
                }
            }
            System.out.println("Instancia " + (i + 1));
            if (isNotCorrect) {
                System.out.println("NAO");
            } else {
                System.out.println("SIM");
            }
            System.out.println();
        }
    }
}
