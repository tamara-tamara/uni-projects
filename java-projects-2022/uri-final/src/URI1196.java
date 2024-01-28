import java.util.Scanner;

public class URI1196 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String keyboard1 = "`1234567890-=";
        String keyboard2 = "QWERTYUIOP[]\\";
        String keyboard3 = "ASDFGHJKL;'";
        String keyboard4 = "ZXCVBNM,./";
        while (input.hasNextLine()) {
            String message = input.nextLine();
            StringBuilder output = new StringBuilder();
            char res = ' ';
            for (int i = 0; i < message.length(); ++i) {
                if (message.charAt(i) == ' ') {
                    output.append(' ');
                }

                for (int j = 1; j < keyboard1.length(); ++j) {
                    if (message.charAt(i) == keyboard1.charAt(j)) {
                        res = keyboard1.charAt(j - 1);
                        output.append(res);
                    }
                }
                for (int j = 1; j < keyboard2.length(); ++j) {
                    if (message.charAt(i) == keyboard2.charAt(j)) {
                        res = keyboard2.charAt(j - 1);
                        output.append(res);
                    }
                }
                for (int j = 1; j < keyboard3.length(); ++j) {
                    if (message.charAt(i) == keyboard3.charAt(j)) {
                        res = keyboard3.charAt(j - 1);
                        output.append(res);
                    }
                }
                for (int j = 1; j < keyboard4.length(); ++j) {
                    if (message.charAt(i) == keyboard4.charAt(j)) {
                        res = keyboard4.charAt(j - 1);
                        output.append(res);
                    }
                }
            }
            System.out.println(output);
        }
    }
}
