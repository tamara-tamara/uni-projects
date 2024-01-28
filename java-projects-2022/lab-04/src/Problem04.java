import java.util.ArrayList;
import java.util.Random;

public class Problem04 {
    public static void main(String[] args) {
        Random random = new Random();
        final int ELEMENTS = 100_000;
        {
            long startTime = System.nanoTime();
            ArrayList<Integer> numbers = new ArrayList<>();
            for (int i = 0; i < ELEMENTS; ++i) {
                numbers.add(random.nextInt(ELEMENTS));
            }
            for (int i = 0; i < ELEMENTS; ++i) {
                numbers.add(0, random.nextInt(ELEMENTS));
            }
            for (int i = 0; i < ELEMENTS*2; ++i) {
                numbers.remove(0);
            }
            long endTime = System.nanoTime();
            long totalTime = endTime - startTime;
            System.out.printf("%.5f%n", totalTime / 1000000000.0);
        }
        {
            long startTime = System.nanoTime();
            ArrayListInt numbers = new ArrayListInt();
            for (int i = 0; i < ELEMENTS; ++i) {
                numbers.add(random.nextInt(ELEMENTS));
            }
            for (int i = 0; i < ELEMENTS; ++i) {
                numbers.add(0, random.nextInt(ELEMENTS));
            }
            for (int i = 0; i < ELEMENTS*2; ++i) {
                numbers.remove(0);
            }
            long endTime = System.nanoTime();
            long totalTime = endTime - startTime;
            System.out.printf("%.5f%n", totalTime / 1_000_000_000.0);

        }
    }
}
