import java.util.Scanner;

public class URI1786 {
        public static void main(String[] args) {
            Scanner input = new Scanner(System.in);
            while (input.hasNextInt()) {
                String sequence = input.nextLine();
                char[] seqToChar = sequence.toCharArray();
                int result = 0;
                int result2 = 0;
                int index = seqToChar.length;
                for (int i = 0; i < seqToChar.length; ++i) {
                    char b = seqToChar[i];
                    int a = Integer.parseInt(String.valueOf(b));
                    result += a * (i + 1);
                    result2 += a * (index);
                    index--;
                }

                int b1 = result % 11;
                int b2 = result2 % 11;
                if (b1 == 10) {
                    b1 = 0;
                }
                if (b2 == 10) {
                    b2 = 0;
                }
                System.out.println(seqToChar[0] + "" + seqToChar[1] + "" + seqToChar[2] + "." + seqToChar[3] + seqToChar[4] + seqToChar[5] + "." + seqToChar[6] + seqToChar[7] + seqToChar[8]
                        + "-" + b1 + b2);


            }
        }
    }
