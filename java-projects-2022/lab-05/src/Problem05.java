import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

public class Problem05 extends JFrame {
    private int column;
    private int row;

    Problem05() {
        setSize(400, 400); //400 is a magical num
        setLocationRelativeTo(null);
        setVisible(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setTitle("Move Robot");


        var mainPanel = new CanvasPanel();
        mainPanel.setFocusable(true);  // focus на этом панеле как бы на переднем фоне

        this.add(mainPanel);

        column = 0;
        row = 0;
        mainPanel.addKeyListener(new KeyAdapter() {
            @Override
            public void keyPressed(KeyEvent e) {
                super.keyPressed(e);
                if (e.getKeyCode() == KeyEvent.VK_LEFT && column > 0) {
                    column--;


                } else if (e.getKeyCode() == KeyEvent.VK_RIGHT && column < 7) {
                    column++;
                } else if (e.getKeyCode() == KeyEvent.VK_UP && row > 0) {
                    row--;
                } else if (e.getKeyCode() == KeyEvent.VK_DOWN && row < 7) {
                    row++;
                }
                repaint();

            }
        });

    }

    class CanvasPanel extends JPanel {
        @Override
        protected void paintComponent(Graphics g) {
            super.paintComponent(g);

            int rectWidth = getWidth() / 8;
            int rectHeight = getHeight() / 8;
            for (int i = 0; i < 8; ++i) {
                for (int j = 0; j < 8; ++j) {
                    int rectX = rectWidth * i;
                    int rectY = rectHeight * j;
                    Color c = (i + j) % 2 == 0 ? Color.BLACK : Color.WHITE;
                    g.setColor(c);
                    g.fillRect(rectX, rectY, rectWidth, rectHeight);
                }
            }
            g.setColor(Color.RED);
            g.fillOval(column * rectWidth, row * rectHeight, rectWidth, rectHeight);  //0;0 координата правого верхнего угла
        }
    }

    public static void main(String[] args) {
        Problem05 frame = new Problem05();
    }
}
