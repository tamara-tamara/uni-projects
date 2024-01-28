import javax.swing.*;
import java.awt.*;

public class Problem04 extends JFrame {
    Problem04() {
        setSize(400, 400); //400 is a magical num
        setLocationRelativeTo(null);
        setVisible(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setTitle("Chessboard");

        var mainPanel = new CanvasPanel();

        this.add(mainPanel);
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
        }
    }

    public static void main(String[] args) {
        Problem04 frame = new Problem04();
    }
}
