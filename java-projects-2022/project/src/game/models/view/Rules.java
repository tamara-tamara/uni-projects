package game.models.view;

import javax.swing.*;
import java.awt.*;

public class Rules extends JFrame {
    public Rules() {
        setSize(600, 600);
        setResizable(false);
        setLayout(null);
        setLocationRelativeTo(null);
        setVisible(true);
    }

    public void paint(Graphics g) {
        super.paint(g);
        g.setColor(Color.magenta);
        Font font = g.getFont().deriveFont(Font.BOLD, 20f);
        g.setFont(font);
        g.drawString("This is Crazy Snake game by Toma:)", 50, 50);
        g.drawString("How to play?", 50, 100);
        g.drawString("The goal of the game is to control a snake ", 50, 150);
        g.drawString("  and help it grow by eating food while avoiding", 50, 200);
        g.drawString("  collisions with the walls or its own tail.", 50, 250);
        g.drawString("Controls: Use the arrow keys (up, down, left, right) ", 50, 300);
        g.drawString("  to control the direction of the snake's movement.", 50, 350);
        g.drawString("Use ESC button to pause the game.", 50, 400);
        g.drawString("Have fun! :)", 50, 450);

    }
}
