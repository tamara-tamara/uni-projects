import java.util.Scanner;

public class URI2651 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String name = input.nextLine().toLowerCase();
        if (name.contains("zelda")) {
            System.out.println("Link Bolado");
        } else {
            System.out.println("Link Tranquilo");
        }
    }
}
