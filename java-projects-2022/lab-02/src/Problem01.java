import java.util.Scanner;

public class Problem01 {
    public static void main(String[] args) {
        Field field = new Field();
        Turtle turtle1 = new Turtle(field);
        Turtle turtle2 = new Turtle(field, field.FIELD_WIDTH - 1, field.FIELD_HEIGHT - 1, -1, 0);
        Turtle[] turtles = new Turtle[]{turtle1, turtle2};
        //Turtle turtle = turtle1;
        Turtle selectedTurtle = turtles[0];
        Scanner scan = new Scanner(System.in);
        while (scan.hasNextLine()) {
            try {
                String command = scan.nextLine();
                //command = command.toUpperCase();
                String[] parts = command.split(" ");
                if (!(parts.length > 0 && parts[0].trim().length() > 0)) {
                    throw new IllegalArgumentException("No command to execute were provided.");
                }
                String command1 = parts[0].trim();
                switch (command1) {
                    case "select":
                        if (parts.length > 2) {
                            throw new IllegalArgumentException("More arguments than necessary were provided for the 'select' command.");
                        } else if (parts.length < 2) {
                            throw new IllegalArgumentException("The turtle number was not provided.");
                        }
                        int turtNum;
                        try {
                            turtNum = Integer.parseInt(parts[1]) - 1;
                        } catch (NumberFormatException e) {
                            throw new NumberFormatException("The turtle number is not valid.");
                        }
                        if (turtNum >= 0 && turtNum < turtles.length) {
                            selectedTurtle = turtles[turtNum];
                        } else {
                            throw new NumberFormatException(String.format("There is no turtle with the number " + (turtNum + 1) + "."));
                        }
                        break;
                    case "move":
                        if (parts.length > 2) {
                            throw new IllegalArgumentException("More arguments than necessary were provided for the 'move' command.");
                        } else if (parts.length < 2) {
                            throw new IllegalArgumentException("The number of steps was not provided.");
                        }
                        int steps;
                        try {
                            steps = Integer.parseInt(parts[1]);
                        } catch (NumberFormatException e) {
                            throw new NumberFormatException("The number of steps is not valid.");
                        }
                        if (steps < 0) {
                            throw new IllegalArgumentException("The number of steps can't be negative.");
                        }
                        selectedTurtle.move(steps);
                        break;
                    case "turn-right":
                        selectedTurtle.turnRight();
                        break;
                    case "turn-left":
                        selectedTurtle.turnLeft();
                        break;
                    case "pen-up":
                        selectedTurtle.putPenUp();
                        break;
                    case "pen-down":
                        selectedTurtle.putPenDown();
                        break;
                    case "exit":
                        System.exit(0);
                    case "display":
                        field.displayField(turtles);
                        break;
                    default:
                        throw new IllegalArgumentException("Unknown command.");
                }
            } catch (IllegalArgumentException e) {
                System.err.println(e.getMessage() + " Please, try again.");
            }
        }
    }
}


