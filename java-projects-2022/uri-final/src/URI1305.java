import java.util.Scanner;

public class URI1305 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        while (input.hasNextLine()) {
            String num = input.nextLine();
            String cutoff = input.nextLine();
            double decimalPart = 0;
            if (num.contains(".") && (num.charAt((num.length() - 1)) != '.')) {
                String[] word = num.split("\\.");
                decimalPart = Double.parseDouble("0." + word[1]);
            } else if (num.charAt((num.length() - 1)) == '.') {
                decimalPart = Double.parseDouble("0.0");
            } else {
                decimalPart = Double.parseDouble("0.0");
            }
            double cutOff = Double.parseDouble(cutoff);
            int res = 0;
            if (decimalPart > cutOff) {
                res = (int) Math.ceil(Double.parseDouble(num));
            } else {
                res = (int) Math.floor(Double.parseDouble(num));
            }
            System.out.println(res);
        }
    }
}
