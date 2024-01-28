import java.util.Scanner;

public class URI1574 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int numOfP = input.nextInt();
        for (int i = 0; i < numOfP; ++i) {
            int numOfCommand = input.nextInt();
            input.nextLine();
            int position = 0;
            String[] direction = new String[numOfCommand];
            for (int j = 0; j < numOfCommand; ++j) {
                String command = input.nextLine();
                if (command.length() > 5) {
                    String[] temp = command.split(" ");
                    int pos = Integer.parseInt(temp[2]);
                    if (direction[pos - 1].equals("l")) {
                        command = "LEFT";
                    } else {
                        command = "RIGHT";
                    }
                }
                if (command.equals("LEFT")) {
                    position--;
                    direction[j] = "l";
                } else if (command.equals("RIGHT")) {
                    position++;
                    direction[j] = "r";
                }

            }
            System.out.println(position);
        }

    }
}
