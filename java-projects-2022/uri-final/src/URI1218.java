import java.util.Scanner;

public class URI1218 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int caseNum = 0;
        while (input.hasNextInt()) {
            int neededSize = input.nextInt();
            input.nextLine();
            String[] shoes = input.nextLine().split(" ");
            char[] fOrM = new char[shoes.length / 2];
            int[] size = new int[shoes.length / 2];
            int index = 0;
            int indexSize = 0;
            for (int i = 0; i < shoes.length; ++i) {
                if (Character.isLetter(shoes[i].charAt(0))) {
                    fOrM[index] = shoes[i].charAt(0);
                    index++;
                } else {
                    size[indexSize] = Integer.parseInt(shoes[i]);
                    indexSize++;
                }
            }
            System.out.println("Caso " + (caseNum + 1) + ":");
            int pairs = 0;
            int f = 0;
            int m = 0;
            for (int i = 0; i < fOrM.length; ++i) {
                if (neededSize == size[i]) {
                    pairs++;
                    if (fOrM[i] == 'M') {
                        m++;
                    } else {
                        f++;
                    }
                }
            }
            System.out.println("Pares Iguais: " + pairs);
            System.out.println("F: " + f);
            System.out.println("M: " + m);
            if (input.hasNextInt()) {
                System.out.println();
            }
            caseNum++;
        }
    }
}
