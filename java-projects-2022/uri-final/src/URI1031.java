import java.util.Scanner;

public class URI1031 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        while (true) {
            int numOfDistricts = input.nextInt();
            if (numOfDistricts == 0) {
                break;
            }
            boolean isCorrectN = false;
            int correctOrder = 1;
            while (true) {
                int firstDistrict = 0;
                for (int i = 2; i <= numOfDistricts - 1; i++) {
                    int nextDistrict = firstDistrict + correctOrder;
                    firstDistrict = nextDistrict % i;
                }
                if (firstDistrict == 11) {
                    isCorrectN = true;
                }
                if (isCorrectN) {
                    break;
                }
                correctOrder++;
            }
            System.out.println(correctOrder);
        }
    }
}
