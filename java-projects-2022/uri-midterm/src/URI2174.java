import java.util.Scanner;

public class URI2174 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        String[] pokemon = new String[n];
        input.nextLine();
        for (int i = 0; i < n; ++i) {
            pokemon[i] = input.nextLine();
        }
        int counter = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (pokemon[i].equals(pokemon[j])) {
                    pokemon[j] = "  ";

                }
            }
        }
        for (int i = 0; i < n; ++i) {
            String word = pokemon[i];
            if (Character.isLetter(word.charAt(0))) {
                counter++;
            }
        }
        int result = 151 - counter;
        System.out.println("Falta(m) " + result + " pomekon(s).");
    }
}
