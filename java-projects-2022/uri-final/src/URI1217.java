import java.util.Scanner;

public class URI1217 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int numOfDays = input.nextInt();
        float totalNumOfFruit = 0;
        float totalNumOfMoney = 0;
        for (int i = 0; i < numOfDays; ++i) {
            int fruitCounter = 0;
            float amountOfMoney = input.nextFloat();
            totalNumOfMoney += amountOfMoney;
            input.nextLine();
            String[] nameOfFruit = input.nextLine().split(" ");
            fruitCounter += nameOfFruit.length;
            totalNumOfFruit += fruitCounter;
            System.out.println("day " + (i + 1) + ": " + fruitCounter + " kg");
        }
        System.out.printf("%.2f kg by day\n", totalNumOfFruit / numOfDays);
        System.out.printf("R$ %.2f by day\n", totalNumOfMoney / numOfDays);
    }
}
