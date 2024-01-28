import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.ArrayList;


public class Problem05 extends JFrame {
    //    class GreenActionListener implements ActionListener{
//        @Override  //полиморфизм тэг, переписываем функционал суперкласса, добавляется для читабельности
//        public void actionPerformed(ActionEvent e){
//            backgroundColor = Color.green;
//            mainPanel.setBackground(backgroundColor);
//        }
//    }

    private static final int MinRect = 50;
    private static final int MinCross = 60;
    private static final int MaxCross = 100;
    private static final int MaxRect = 100;
    private static final int MinCircle = 25;
    private static final int MaxCircle = 50;

    private final ArrayList<Shape> shapes = new ArrayList<>();

    private Shape selectedShape = null;
    private boolean dragEnabled = false;
    private int prevMouseX;
    private int prevMouseY;

    abstract static class Shape {
        protected int x, y;
        protected boolean selected;

        public Shape(int x, int y) {
            this.x = x;
            this.y = y;
            selected = false;
        }

        public void setSelected(boolean selected) {
            this.selected = selected;
        }

        abstract boolean areCoordsInside(int x, int y);

        abstract void present(Graphics g); //method without implementation
        // if one method is abstract, then the whole class should be abstract

        protected void move(int x1, int y1, int x2, int y2) {
            int dx = x2 - x1;
            int dy = y2 - y1;
            x += dx;
            y += dy;
        }

        public String toString() {
            return String.format("Shape: %d, %d", x, y);
        }
    }

    static class Circle extends Shape {
        private final int radius;

        Circle(int x, int y, int radius) {
            super(x, y);
            if (radius <= 0) {
                throw new IllegalArgumentException("Radius should be a positive number");
            }
            this.radius = radius;
        }

        public String toString() {
            return String.format("Circle: %d, %d, %d", x, y, radius);
        }

        boolean areCoordsInside(int x, int y) {
            int dx = x - this.x;
            int dy = y - this.y;
            int distance = dx * dx + dy * dy;
            return distance <= radius * radius;
        }

        @Override
        void present(Graphics g) {
            Graphics2D g2 = (Graphics2D) g;
            g.setColor(Color.BLUE);
            g.fillOval(x - radius, y - radius, radius * 2, radius * 2);
            if (selected) {
                g.setColor(Color.RED);
                g2.setStroke(new BasicStroke(3));
                g.drawOval(x - radius, y - radius, radius * 2, radius * 2);
            }
        }
    }

    static class Cross extends Shape {
        Rectangle r1;
        Rectangle r2;
        private final int w;
        private final int h;

        public Cross(int x, int y, int aW1, int aW2) {
            super(x, y);
            this.w = aW1;
            this.h = aW2;
            r1 = new Rectangle(x - aW1 / 2, y - aW2 / 8, aW1, aW2 / 4);
            r2 = new Rectangle(x - aW1 / 8, y - aW2 / 2, aW1 / 4, aW2);
            if (w <= 0) {
                throw new IllegalArgumentException("Width should be a positive number.");
            }
            if (h <= 0) {
                throw new IllegalArgumentException("Height should be a positive number.");
            }
        }

        public boolean areCoordsInside(int x, int y) {
            return r1.areCoordsInside(x - w / 2, y - h / 8) || r2.areCoordsInside(x - w / 8, y - h / 2);
        }

        @Override
        protected void move(int x1, int y1, int x2, int y2) {
            super.move(x1, y1, x2, y2);
            r1 = new Rectangle(x - w / 2, y - h / 8, w, h / 4);
            r2 = new Rectangle(x - w / 8, y - h / 2, w / 4, h);
        }

        public String toString() {
            return String.format("Cross: (" + r2 + ")" + ",(" + r1 + ")");
        }

        void present(Graphics g) {
            Graphics2D g2 = (Graphics2D) g;
            g.setColor(Color.YELLOW);
            g.fillRect(x - w / 2, y - h / 8, w, h / 4);
            g.fillRect(x - w / 8, y - h / 2, w / 4, h);
            if (selected) {
                g2.setColor(Color.RED);
                g2.setStroke(new BasicStroke(3));
                g.drawRect(x - w / 2, y - h / 8, w, h / 4);
                g.drawRect(x - w / 8, y - h / 2, w / 4, h);
                g.setColor(Color.YELLOW);
                g.fillRect(x - w / 2, y - h / 8, w, h / 4);
                g.fillRect(x - w / 8, y - h / 2, w / 4, h);
            }
        }
    }

    static class Rectangle extends Shape {
        private final int width, height;

        Rectangle(int x, int y, int width, int height) {
            super(x, y);
            if (width <= 0) {
                throw new IllegalArgumentException("Width should be a positive number.");
            }
            if (height <= 0) {
                throw new IllegalArgumentException("Height should be a positive number.");
            }
            this.width = width;
            this.height = height;
        }

        boolean areCoordsInside(int x, int y) {
            int widHalf = width / 2;
            int heightHalf = height / 2;
            return x >= this.x - widHalf && x <= this.x + widHalf &&
                    y >= this.y - heightHalf && y <= this.y + heightHalf;
        }

        @Override
        void present(Graphics g) {
            Graphics2D g2 = (Graphics2D) g;
            g.setColor(Color.cyan);
            g.fillRect(x - width / 2, y - height / 2, width, height);
            if (selected) {
                g.setColor(Color.RED);
                g2.setStroke(new BasicStroke(3));
                g.drawRect(x - width / 2, y - height / 2, width, height);
            }
        }

        public String toString() {
            return String.format("Rect: %d, %d, %d, %d", x, y, width, height);
        }
    }

    class Canvas extends JPanel {

        protected void paintComponent(Graphics g) {
            super.paintComponent(g);
            for (var shape : shapes) {
                shape.present(g);

            }
        }
    }

    Problem05() {
        var canvas = new Canvas();

        setTitle("Graphics Editor");
        setSize(400, 400);
        setVisible(true); //видимость элементов ОБЯЗАТЕЛЬНО
        setLocationRelativeTo(null); // программа создается по центру, а по дефолту в (0;0)
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); //крестик в окне ОБЯЗАТЕЛЬНО

        setLayout(new BorderLayout());  // расставляет по границам окон в разным направлениях

        canvas.setBackground(Color.lightGray);
        JFrame thisFrame = this;
        canvas.addMouseListener(new MouseAdapter() {
            @Override
            public void mousePressed(MouseEvent e) {
                if (e.getButton() == MouseEvent.BUTTON1) {
                    if (selectedShape != null) {
                        selectedShape.setSelected(false);
                    }
                    selectedShape = null;
                    int mouseX = e.getX();
                    int mouseY = e.getY();
                    for (int i = shapes.size() - 1; i >= 0; --i) {
                        var shape = shapes.get(i);
                        if (shape.areCoordsInside(mouseX, mouseY)) {
                            selectedShape = shape;
                            selectedShape.setSelected(true);
                            break;
                        }
                    }
                    if (selectedShape != null) {
                        dragEnabled = true;
                        prevMouseX = mouseX;
                        prevMouseY = mouseY;
                    }
                    canvas.repaint();
                } else if (e.getButton() == MouseEvent.BUTTON3) {
                    int mouseX = e.getX();
                    int mouseY = e.getY();
                    for (int i = shapes.size() - 1; i >= 0; --i) {
                        var shape = shapes.get(i);
                        if (shape.areCoordsInside(mouseX, mouseY)) {
                            JOptionPane.showMessageDialog(thisFrame, shape);
                        }
                    }
                    canvas.repaint();
                }
            }

            public void mouseReleased(MouseEvent e) {
                dragEnabled = false;
                canvas.repaint();
            }

        });
        canvas.addMouseMotionListener(new MouseMotionAdapter() {
            @Override
            public void mouseDragged(MouseEvent e) {
                if (dragEnabled) {
                    selectedShape.move(prevMouseX, prevMouseY, e.getX(), e.getY());
                    prevMouseX = e.getX();
                    prevMouseY = e.getY();
                    canvas.repaint();

                }
            }
        });

        canvas.addKeyListener(new KeyAdapter() {
            @Override
            public void keyPressed(KeyEvent e) {
                if (e.getKeyCode() == KeyEvent.VK_DELETE) {
                    if (selectedShape != null) {
                        shapes.remove(selectedShape);
                        selectedShape = null;
                        canvas.repaint();
                    }
                }
            }
        });

        var toolbar = new JPanel();
        toolbar.setBackground(Color.white);
        toolbar.setLayout(new FlowLayout());


        this.add(canvas, BorderLayout.CENTER); //добавляет в текущее окно, расположение панели
        this.add(toolbar, BorderLayout.SOUTH); // this т.е относится к JFrame

        var rectButton = new JButton("Rectangle");

        // класс ActionListener абстрактный. нельзя создать
        //  ActionListener redListener = new RedActionListener();

        rectButton.addActionListener(e -> {

            int x = (int) (Math.random() * canvas.getWidth());
            int y = (int) (Math.random() * canvas.getHeight());
            int width = (int) (MinRect + Math.random() * (MaxRect - MinRect));
            int height = (int) (MinRect + Math.random() * (MaxRect - MinRect));
            shapes.add(new Rectangle(x, y, width, height));
            canvas.repaint();
            canvas.requestFocus();  // events lost focus
        });

        var circleButton = new JButton("Circle");

        circleButton.addActionListener(e -> {

            int x = (int) (Math.random() * canvas.getWidth());
            int y = (int) (Math.random() * canvas.getHeight());
            int radius = (int) (MinCircle + Math.random() * (MaxCircle - MinCircle));

            shapes.add(new Circle(x, y, radius));
            canvas.repaint();
            canvas.requestFocus();
        });
        var crossButton = new JButton("Cross");
        crossButton.addActionListener(e -> {
            int x = (int) (Math.random() * canvas.getWidth());
            int y = (int) (Math.random() * canvas.getHeight());
            int width = (int) (MinCross + Math.random() * (MaxCross - MinCross));
            int height = (int) (MinCross + Math.random() * (MaxCross - MinCross));
            shapes.add(new Cross(x, y, width, height));
            canvas.repaint();
            canvas.requestFocus();
        });


        toolbar.add(rectButton);
        toolbar.add(circleButton);
        toolbar.add(crossButton);
    }

    public static void main(String[] args) {
        Problem05 window = new Problem05();  //окно программы
        // JFrame main = new JFrame();
    }
}
