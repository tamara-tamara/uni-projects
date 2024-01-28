package game.models.controllers;

import game.models.Apple;
import game.models.Field;
import game.models.Snake;
import game.models.view.Buttons;
import game.models.view.Rules;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.awt.geom.Rectangle2D;

public class GameController extends JPanel implements ActionListener {

    public final Buttons startBtn = new Buttons("Start");
    public final Buttons rulesBtn = new Buttons("Rules");
    public Buttons restartBtn = new Buttons("Restart");
    public Buttons playBtn = new Buttons("Continue");
    public Buttons pauseBtn = new Buttons("Pause");
    public Snake snake;
    Apple apple;
    public Field field;
    public Timer timer;

    public boolean isRunning = false;
    private boolean isPaused = false;


    public GameController() {
        field = new Field(20, 20);
        snake = new Snake(field, 0, 0, 1, 0, 3);
        apple = new Apple(field, snake);
        field.setApple(apple);
        setPreferredSize(new Dimension(1050, 700));
        setBackground(Color.BLACK);
        setFocusable(true);

        addKeyListener(new MyKeyListener());
        setLayout(null);


        startBtn.addActionListener(this);
        rulesBtn.addActionListener(this);
        restartBtn.addActionListener(this);
        pauseBtn.addActionListener(this);
        playBtn.addActionListener(this);

        startBtn.setBounds(getWidth() / 4 + 900, getHeight() / 4 + 200, 120, 70);
        rulesBtn.setBounds(getWidth() / 4 + 900, getHeight() / 4 + 400, 120, 70);
        pauseBtn.setBounds(getWidth() / 4 + 900, getHeight() / 4 + 200, 120, 70);
        playBtn.setBounds(getWidth() / 4 + 900, getHeight() / 4 + 200, 120, 70);
        restartBtn.setBounds(getWidth() / 4 + 900, getHeight() / 4 + 300, 120, 70);

        restartBtn.setVisible(false);
        pauseBtn.setVisible(false);
        playBtn.setVisible(false);
        rulesBtn.setVisible(true);

        add(startBtn);
        add(rulesBtn);
        add(restartBtn);
        add(pauseBtn);
        add(playBtn);

    }

    public void startTheGame() {
        isRunning = true;
        isPaused = false;
        timer = new Timer(200, this);
        timer.start();
        startBtn.setVisible(false);
        rulesBtn.setVisible(true);
        restartBtn.setVisible(true);
        pauseBtn.setVisible(true);
    }

    public void restartTheGame() {
        isPaused = false;
        timer.stop();
        isRunning = false;
        snake.score = 0;

        snake.makeNewSnake();
        startTheGame();
    }


    protected void paintComponent(Graphics g) {  //painComponent is called when window is changed
        super.paintComponent(g);
        Graphics2D g2 = (Graphics2D) g;
        g2.setColor(new Color(225, 225, 0));
        g2.setFont(new Font("", Font.PLAIN, 24));
        if (!isRunning) {   //Title logo
            drawInCenter(g2, "SNAKE", new Font("", Font.PLAIN, 150), getHeight() / 3);
            drawInCenter(g2, "GAME", new Font("", Font.PLAIN, 150), getHeight() / 3 + 150);
            drawInCenter(g2, "have fun!", new Font("", Font.ITALIC, 24), getHeight() / 3 + 250);
            // menu.paintComponents(g);
            return;
        }
        if (snake.isDead()) {   //Losing message
            pauseBtn.setVisible(false);
            playBtn.setVisible(false);
            rulesBtn.setVisible(false);
            g2.setColor(new Color(225, 225, 0));
            g2.setFont(new Font("", Font.PLAIN, 24));

            drawInCenter(g2, "YOU", new Font("", Font.PLAIN, 150), 200);
            drawInCenter(g2, "LOST!", new Font("", Font.PLAIN, 150), 350);
            return;
        }

        float cellW = getWidth() / (float) field.getWidth();
        float cellH = getHeight() / (float) field.getHeight();
        float cellSize = Math.min(cellH, cellW);
        float fieldWidth = field.getWidth() * cellSize;
        float fieldHeight = field.getHeight() * cellSize;
        float horShift = (getWidth() - fieldWidth) * 0.5f;
        float verShift = (getHeight() - fieldHeight) * 0.5f;
        float scrX;
        float scrY;
        //Field
        for (int y = 0; y < field.getHeight(); ++y) {
            for (int x = 0; x < field.getWidth(); ++x) {
                scrX = horShift + x * cellSize;
                scrY = verShift + y * cellSize;
                g2.setColor(field.getColor());
                g2.fill(new Rectangle2D.Float(scrX, scrY, cellSize - 1, cellSize - 1));
            }
        }

        //Apple
        Apple apple = field.getApple();
        scrX = horShift + apple.getX() * cellSize;
        scrY = verShift + apple.getY() * cellSize;
        g2.setColor(apple.getColor());
        g2.fill(new Rectangle2D.Float(scrX, scrY, cellSize - 1, cellSize - 1));

        for (Point point : snake.getBody()) {
            scrX = horShift + point.x * cellSize;
            scrY = verShift + point.y * cellSize;
            g2.setColor(snake.isDead() ? snake.getDeadSnake() : snake.getAliveSnake());
            g2.fill(new Rectangle2D.Float(scrX, scrY, cellSize - 1, cellSize - 1));
        }
        g2.setColor(new Color(93, 150, 150));
        Font font = g2.getFont().deriveFont(Font.BOLD, 24f);
        g2.setFont(font);
        g2.drawString("Score: " + snake.getScore(), 900, 70);
        setFocusable(true);
        requestFocus();
        if (isPaused) {
            // Display "PAUSED" message
            g2.setColor(new Color(225, 225, 225));
            g2.setFont(new Font("", Font.PLAIN, 150));
            drawInCenter(g2, "PAUSED", new Font("", Font.PLAIN, 150), getHeight() / 2);
        }


    }

    public void drawInCenter(Graphics g, String mes, Font font, int y) {
        FontMetrics metrics = g.getFontMetrics(font);
        int x = (getWidth() - metrics.stringWidth(mes)) / 2;
        g.setFont(font);
        g.drawString(mes, x, y);
    }

    public void play() {
        isPaused = false;
        playBtn.setVisible(false);
        pauseBtn.setVisible(true);
        timer.start();
    }

    public void pause() {
        isPaused = true;
        playBtn.setVisible(true);
        pauseBtn.setVisible(false);
        timer.stop();

    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (isRunning) {
            snake.move();
            if (apple.collidedWithSnake(snake)) {
                apple.makeNewApple(field, snake);
            }
        }
        repaint();
        if (e.getSource() == startBtn) {
            startTheGame();
            repaint();
        }
        if (e.getSource() == restartBtn) {
            restartTheGame();
            // repaint();
        }
        if (e.getSource() == rulesBtn) {
            new Rules();
            repaint();
        }
        if (e.getSource() == pauseBtn) {
            pause();
        }
        if (e.getSource() == playBtn) {
            play();
        }

    }

    public class MyKeyListener extends KeyAdapter {
        @Override
        public void keyPressed(KeyEvent e) {

            switch (e.getKeyCode()) {
                case KeyEvent.VK_UP:
                    snake.turnUp();
                    break;
                case KeyEvent.VK_DOWN:
                    snake.turnDown();
                    break;
                case KeyEvent.VK_LEFT:
                    snake.turnLeft();
                    break;
                case KeyEvent.VK_RIGHT:
                    snake.turnRight();
                    break;
                case KeyEvent.VK_ESCAPE:
                    if (isPaused) {
                        play();
                    } else {
                        pause();
                    }
                    break;
            }
        }
    }
}
