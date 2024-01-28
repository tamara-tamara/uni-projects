
import java.util.Arrays;
import java.util.Comparator;


public class Problem02 {

    public static void main(String[] args) {
        Student[] students = {
                new Student("StudentD", 2.5, 1998),
                new Student("StudentA", 4.0, 2001),
                new Student("StudentB", 3.0, 2001),
                new Student("StudentC", 3.5, 2000)
        };
        System.out.println("Sorting students by name");
        System.out.println("Before:");
        System.out.println(Arrays.toString(students));
        Arrays.sort(students, (o1, o2) -> o1.getName().compareTo(o2.getName())
        );
        System.out.println("After:");
        System.out.println(Arrays.toString(students));
        System.out.println();

        System.out.println("Sorting students by GPA");
        System.out.println("Before:");
        System.out.println(Arrays.toString(students));
        Arrays.sort(students, (o1, o2) -> Double.compare(o1.getGPA(), o2.getGPA()));
        System.out.println("After:");
        System.out.println(Arrays.toString(students));
        System.out.println();

        System.out.println("Sorting students by birth year");
        System.out.println("Before:");
        System.out.println(Arrays.toString(students));
        Arrays.sort(students, (o1, o2) -> Integer.compare(o1.getBirthYear(), o2.getBirthYear()));
        System.out.println("After:");
        System.out.println(Arrays.toString(students));

    }
}


class Student {
    private String name;
    private double gpa;
    private int birthYear;

    public Student(String name, double gpa, int birthYear) {
        this.name = name;
        this.gpa = gpa;
        this.birthYear = birthYear;
    }

    @Override
    public String toString() {
        return "Student{" +
                "name='" + name + '\'' +
                ", gpa=" + gpa +
                ", birthYear=" + birthYear +
                '}';
    }

    public String getName() {
        return name;
    }

    public double getGPA() {
        return gpa;
    }

    public int getBirthYear() {
        return birthYear;
    }

}
