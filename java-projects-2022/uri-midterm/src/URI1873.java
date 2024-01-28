import java.util.Scanner;

public class URI1873 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        for (int i = 0; i < n; ++i) {
            String rajesh = input.next();
            String sheldon = input.next();
            rock_paper_scissors(rajesh, sheldon);

        }
    }

    static void rock_paper_scissors(String a, String b) {
        if (a.equals(b)) {
            System.out.println("empate");
        } else if (a.equals("pedra")) {
            if (b.equals("lagarto") || b.equals("tesoura")) {
                System.out.println("rajesh");
            } else {
                System.out.println("sheldon");
            }
        } else if (a.equals("papel")) {
            if (b.equals("pedra") || b.equals("Spock")) {
                System.out.println("rajesh");
            } else {
                System.out.println("sheldon");
            }
        } else if (a.equals("tesoura")) {
            if (b.equals("papel") || b.equals("lagarto")) {
                System.out.println("rajesh");
            } else {
                System.out.println("sheldon");
            }
        } else if (a.equals("lagarto")) {
            if (b.equals("spock") || b.equals("papel")) {
                System.out.println("rajesh");
            } else {
                System.out.println("sheldon");
            }
        } else if (a.equals("spock")) {
            if (b.equals("tesoura") || b.equals("pedra")) {
                System.out.println("rajesh");
            } else {
                System.out.println("sheldon");
            }
        }
    }
}
