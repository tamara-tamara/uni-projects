import java.util.Scanner;

public class URI1262 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        while (input.hasNext()) {
            String trace = input.next();
            int processes = input.nextInt();
            int clockCycle = 0;
            int numOfR = 0;
            for (int i = 0; i < trace.length(); ++i) {
                if (trace.charAt(i) == 'W') {
                    clockCycle++;
                    if (numOfR <= processes && numOfR != 0) {
                        clockCycle++;
                    } else {
                        int div = numOfR / processes;
                        clockCycle += div;
                        if (numOfR % processes != 0) {
                            clockCycle++;
                        }
                    }
                    numOfR = 0;
                } else if (trace.charAt(i) == 'R') {
                    numOfR++;

                    if (i + 1 == trace.length() && numOfR <= processes && numOfR != 0) {
                        clockCycle++;
                    } else if (i + 1 == trace.length() && numOfR != 0) {
                        int div = numOfR / processes;
                        clockCycle += div;
                        if (numOfR % processes != 0) {
                            clockCycle++;
                        }
                    }
                }
            }
            System.out.println(clockCycle);
        }
    }
}
