import java.util.ArrayList;
import java.util.Scanner;

public class Problem01 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        ArrayListInt num = new ArrayListInt();
       // ArrayList<Integer> num = new ArrayList<>();

        while (input.hasNextInt()){
            num.add(input.nextInt());
        }
        System.out.println("Before reversing:");
        System.out.println(num);
        System.out.println("After reversing:");
        reverseNumbers(num);
        System.out.println(num);

    }
    private static void reverseNumbers(ArrayListInt num){
        for (int i=0, j = num.size()-1;i<j;i++,j--){
            int temp = num.get(i);
            num.set(i,num.get(j)) ;
            num.set(j,temp);
        }
    }
}
