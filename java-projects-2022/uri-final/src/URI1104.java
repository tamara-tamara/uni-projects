import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class URI1104 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        while (true) {
            int numOfCardOfA = input.nextInt();
            int numOfCardsOfB = input.nextInt();
            if (numOfCardOfA == 0 && numOfCardsOfB == 0) {
                break;
            }
            Set<Integer> cardsOfA = new HashSet<>();
            Set<Integer> cardsOfB = new HashSet<>();
            for (int i = 0; i < numOfCardOfA; ++i) {
                cardsOfA.add(input.nextInt());
            }
            for (int i = 0; i < numOfCardsOfB; ++i) {
                cardsOfB.add(input.nextInt());
            }

            int uniqueCardsOfA = 0;
            int uniqueCardsOfB = 0;
            for (int value : cardsOfA) {
                if (!cardsOfB.contains(value)) {
                    uniqueCardsOfA++;
                }
            }
            for (int value : cardsOfB) {
                if (!cardsOfA.contains(value)) {
                    uniqueCardsOfB++;
                }
            }

            cardsOfA.removeAll(cardsOfB);   //remove identical cards
            System.out.println(Math.min(uniqueCardsOfA, uniqueCardsOfB));
        }
    }
}
