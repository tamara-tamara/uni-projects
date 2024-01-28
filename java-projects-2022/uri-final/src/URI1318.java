import java.util.Scanner;

public class URI1318 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        while (true) {
            int numOfRealTickets = input.nextInt();
            int numOfGuests = input.nextInt();
            if (numOfGuests == 0 && numOfRealTickets == 0) {
                break;
            }
            int[] tickets = new int[numOfGuests];
            int[] realTickets = new int[numOfRealTickets];
            int checker = 1;
            for (int i = 0; i < numOfGuests; ++i) {
                tickets[i] = input.nextInt();
                int index = tickets[i];
                realTickets[index - 1] += checker;
            }
            int numOfFakeTickets = 0;
            for (int i = 0; i < realTickets.length; ++i) {
                if (realTickets[i] > 1) {
                    numOfFakeTickets++;
                }
            }
            System.out.println(numOfFakeTickets);
        }
    }
}
