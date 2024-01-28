package game.models.view;

import game.models.controllers.GameController;

import javax.swing.*;

public class GameFrame extends JFrame {
    public GameFrame() {
        add(new GameController());
        setTitle("Crazy Snake ~:");
        setSize(750, 700);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        //setResizable(false);
        pack();
        setLocationRelativeTo(null);
        setVisible(true);
    }
}
