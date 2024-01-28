import java.util.Scanner;

public class URI1437 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        while (true) {
            int n = input.nextInt();
            if (n == 0) {
                break;
            }
            String command = input.next();
            char res = 'N';
            for (int i = 0; i < n; ++i) {
                char direction = command.charAt(i);
                if (direction == 'E') {
                    if (res == 'N') {
                        res = 'O';
                    } else if (res == 'L') {
                        res = 'N';
                    } else if (res == 'S') {
                        res = 'L';
                    } else {
                        res = 'S';
                    }

                }
                if (direction == 'D') {
                    if (res == 'N') {
                        res = 'L';
                    } else if (res == 'L') {
                        res = 'S';
                    } else if (res == 'S') {
                        res = 'O';
                    } else {
                        res = 'N';
                    }
                }
            }
            System.out.println(res);

        }
    }
}
