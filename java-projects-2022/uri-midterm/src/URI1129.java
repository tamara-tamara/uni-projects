import java.util.Scanner;

public class URI1129 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int[] ansSheet = new int[5];
        String[] grade = {"A", "B", "C", "D", "E"};

        while (true) {
            int n = input.nextInt();
            if (n == 0) {
                break;
            }
            for (int i = 0; i < n; ++i) {
                int index = -1;
                boolean answer = false;
                for (int j = 0; j < 5; ++j) {
                    ansSheet[j] = input.nextInt();
                    if (ansSheet[j] <= 127) {
                        if (index == -1) {
                            index = j;
                            answer = true;
                        } else {
                            answer = false;
                        }
                    }
                }
                if (answer) {
                    System.out.println(grade[index]);
                } else {
                    System.out.println("*");
                }


            }
        }
    }
}
