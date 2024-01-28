import java.util.Scanner;
//
//class Shape{
//   protected final int x,y;
//
//    public Shape(int x, int y){
//        this.x =x;
//        this.y =y;
//    }
//    boolean areCoordsInside(int x, int y){
//        return false;
//    }
//    void present(){
//        System.out.println(this);
//    }
//    public String toString(){
//        return String.format("Shape: %d, %d",x ,y);
//    }
//}
//
//class Rectangle extends Shape{
//    private final int width, height;
//
//    Rectangle(int x, int y, int width, int height) {
//        super(x, y);
//        this.width = width;
//        this.height = height;
//    }
//    boolean areCoordsInside(int x, int y) {
//        return x >= this.x && x <= this.x + width &&
//                y >= this.y && y <= this.y + height;
//    }
//
//    public String toString() {
//        return String.format("Rect: %d, %d, %d, %d", x, y, width, height);
//    }
//}
//class Circle extends Shape{
//    private final int radius;
//    Circle(int x, int y, int radius){
//        super(x,y);
//        this.radius = radius;
//    }
//    public String toString(){
//        return String.format("Circle: %d, %d, %d", x, y, radius);
//    }
//    boolean areCoordsInside(int x, int y){
//        int dx= x -this.x;
//        int dy= y -this.y;
//        int distance = dx*dx+dy*dy;
//        return distance<=radius*radius;
//    }
//}
//
public class Problem03 {
    public static void main(String[] args) {
        Shape[] shapes = {
                new Rectangle(10, 10, 100, 100),
                new Rectangle(400, 400, 100, 100),

                new Circle(500, 10, 100),
                new Circle(800, 800, 100)
        };
        Scanner scanner = new Scanner(System.in);
        int mouseX, mouseY;
        do {
            System.out.print("x: ");
            mouseX = scanner.nextInt();
            System.out.print("y: ");
            mouseY = scanner.nextInt();
            if (mouseX == 1 && mouseY == 1) {
                break;
            }
            for (var shape : shapes) {
                if (shape.areCoordsInside(mouseX, mouseY)) {
                    shape.present();
                }
            }
        } while (true);
    }

}



