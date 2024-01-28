import java.util.*;

public class URI1120 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();
        while (!input.equals("0 0")) {
            String[] split = input.split(" ");
            String number = split[0];
            String contract = split[1];

            String res = contract.replace(number, "");
            char[] num = res.toCharArray();
            if (res.equals("")) {
                System.out.println(0);
            } else {
                int zeroCounter = 0;
                for (int i = 0; i < num.length; ++i) {
                    if (num[i] == '0') {
                        zeroCounter++;
                    }
                }
                if (zeroCounter == num.length) {
                    System.out.println(0);
                } else {
                    boolean isZero = true;
                    for (int k = 0; k < res.length(); ++k) {
                        if (num[k] != '0') {
                            isZero = false;
                        }
                        if (!isZero)
                            System.out.print(num[k]);
                    }
                    System.out.println();
                }
            }
            input = sc.nextLine();
        }
    }
}