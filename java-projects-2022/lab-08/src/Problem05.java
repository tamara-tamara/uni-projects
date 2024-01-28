import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.file.Files;
import java.nio.file.StandardCopyOption;
import java.util.Scanner;

public class Problem05 {
    public static void main(String[] args) {
        if (args.length != 2) {
            System.err.println("Usage: java Problem05 <Text To Remove> <File to Process>");
            System.exit(-1);
        }
        File fileToProcess = new File(args[1]);
        if (!fileToProcess.exists()) {
            System.err.printf("File '%s' does not exist./n", args[1]);
            System.exit(-1);
        }
        File tempFile = null;
        try {
            tempFile = File.createTempFile("Problem05.temp", ".txt");
            tempFile.deleteOnExit();

        } catch (IOException ignored) {
            System.err.println("Failed to create a temporary file.");
            System.exit(-1);
        }
        try (Scanner input = new Scanner(fileToProcess);
             var output = new PrintWriter(tempFile)) {
            while (input.hasNext()) {
                output.println(input.nextLine().replaceAll(args[0], ""));
            }
        } catch (IOException ignored) {
            System.err.println("Failed to process the file.");
            System.exit(-1);
        }
        try {
            Files.copy(tempFile.toPath(), fileToProcess.toPath(), StandardCopyOption.REPLACE_EXISTING);
        } catch (IOException ignored) {
            System.err.println("Failed to save results.");
            System.exit(-1);
        }
    }
}
