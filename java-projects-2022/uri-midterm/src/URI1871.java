import java.util.Scanner;

public class URI1871 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        while (true) {
            int firstNum = input.nextInt();
            int secondNum = input.nextInt();
            if (firstNum == 0 && firstNum == secondNum) {
                break;
            }
            int sum = firstNum + secondNum;
            String zeroFinder = Integer.toString(sum);
            String result = "";
            for (int i = 0; i < zeroFinder.length(); ++i) {
                if (zeroFinder.charAt(i) != '0') {
                    result += zeroFinder.charAt(i);
                }
            }
            System.out.println(result);

        }
    }
}
