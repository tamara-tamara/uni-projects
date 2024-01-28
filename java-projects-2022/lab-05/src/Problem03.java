import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionListener;

public class Problem03 extends JFrame {

    Problem03() {
        setSize(400, 400); //400 is a magical num
        setLocationRelativeTo(null);
        setVisible(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);


        var mainPanel = new JPanel();
        mainPanel.setBackground(Color.DARK_GRAY);

        mainPanel.addMouseMotionListener(new MouseMotionListener() {

            @Override
            public void mouseDragged(MouseEvent e) {
            }

            @Override
            public void mouseMoved(MouseEvent e) {
                String title = e.getX() + "," + e.getY();
                setTitle(title);
            }
        });


        this.add(mainPanel);
    }

    public static void main(String[] args) {
        Problem03 frame = new Problem03();
    }
}
