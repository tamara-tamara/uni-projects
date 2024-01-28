import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;


public class Problem02 extends JFrame {
//    class GreenActionListener implements ActionListener{
//        @Override  //тэг, переписываем функционал суперкласса, добавляется для читабельности
//        public void actionPerformed(ActionEvent e){
//            backgroundColor = Color.green;
//            mainPanel.setBackground(backgroundColor);
//        }
//    }

    Problem02() {
        setTitle("First GUI App");
        setSize(400, 400);
        setVisible(true); //видимость элементов ОБЯЗАТЕЛЬНО
        setLocationRelativeTo(null); // программа создается по центру, а по дефолту в (0;0)
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); //крестик в окне ОБЯЗАТЕЛЬНО

        setLayout(new BorderLayout());  // расставляет по границам окон в разным направлениях

        var mainPanel = new JPanel();  // блоки
        mainPanel.setBackground(Color.red);
        var controlPanel = new JPanel();
        controlPanel.setBackground(Color.darkGray);

        this.add(mainPanel, BorderLayout.CENTER); //добавляет в текущее окно, расположение панели
        this.add(controlPanel, BorderLayout.SOUTH); // this т.е относится к JFrame

        var redButton = new JButton("RED");

        // класс ActionListener абстрактный. нельзя создать
        //  ActionListener redListener = new RedActionListener();

        redButton.addActionListener(e -> mainPanel.setBackground(Color.red));

        var greenButton = new JButton("GREEN");

        // класс ActionListener абстрактный. нельзя создать
        //ActionListener greenListener = new GreenActionListener();

        greenButton.addActionListener(e -> {
            mainPanel.setBackground(Color.green);
            System.out.println("Color changed to green");
        }); // классы, состоящие из одного метода могут быть лямбда-выражение

        var blueButton = new JButton("BLUE");

        // класс ActionListener абстрактный. нельзя создать

        //implicit class declaration, класс в одну строчку, который больше нигде не используется
        blueButton.addActionListener(e -> mainPanel.setBackground(Color.blue));


        controlPanel.add(redButton);
        controlPanel.add(greenButton);
        controlPanel.add(blueButton);
        //  repaint();  // обновляет окно несколько раз

    }

    public static void main(String[] args) {
        Problem02 window = new Problem02();  //окно программы
        // JFrame main = new JFrame();
    }
}
