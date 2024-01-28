package game.models.view;
import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

public class Buttons extends JButton implements MouseListener {
    public Buttons(String text){
         setText(text);
        setFont(new Font("Georgia", Font.PLAIN, 21));
        setFocusable(false);
        setBackground(new Color(170, 215, 81));
        setForeground(Color.black);
        addMouseListener(this);
    }

    @Override
    public void mouseClicked(MouseEvent e) {

    }

    @Override
    public void mousePressed(MouseEvent e) {

    }

    @Override
    public void mouseReleased(MouseEvent e) {

    }

    @Override
    public void mouseEntered(MouseEvent e) {

    }

    @Override
    public void mouseExited(MouseEvent e) {

    }
}
