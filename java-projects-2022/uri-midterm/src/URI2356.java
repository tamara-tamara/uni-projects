import java.util.Scanner;

public class URI2356 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        while (input.hasNextLine()) {
            String dna = input.nextLine();
            String geneticCode = input.nextLine();
            int counter = 0;
            if (dna.contains(geneticCode)) {
                counter++;
            }
            System.out.println(counter == 1 ? "Resistente" : "Nao resistente");
        }
    }
}
