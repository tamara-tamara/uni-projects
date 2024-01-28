import java.util.Comparator;

interface MyComparable {

    int compareTo(BigRational o);

    int compareTo(Object other);
}

interface MyComparator {
    int compare(Object object1, Object object2);
}

public class MyArrays {
    public static void sort(int[] integers) {
        for (int i = 0; i < integers.length - 1; ++i) {
            int minI = i;
            for (int j = i + 1; j < integers.length; ++j) {
                if (integers[j] < integers[minI]) {
                    minI = j;
                }
            }
            if (minI != i) {
                int temp = integers[i];
                integers[i] = integers[minI];
                integers[minI] = temp;
            }
        }
    }

    public static void sort(Object[] elements) {
        for (int i = 0; i < elements.length - 1; ++i) {
            int minI = i;
            for (int j = i + 1; j < elements.length; ++j) {
                if (((MyComparable) elements[j]).compareTo(elements[minI]) < 0) {
                    minI = j;
                }
            }
            if (minI != i) {
                Object temp = elements[i];
                elements[i] = elements[minI];
                elements[minI] = temp;
            }
        }
    }

    public static void sort(Object[] elements, MyComparator comparator) {
        for (int i = 0; i < elements.length - 1; ++i) {
            int minI = i;
            for (int j = i + 1; j < elements.length; ++j) {
                if (comparator.compare(elements[j], elements[minI]) < 0) {
                    minI = j;
                }
            }
            if (minI != i) {
                Object temp = elements[i];
                elements[i] = elements[minI];
                elements[minI] = temp;
            }
        }
    }
}
