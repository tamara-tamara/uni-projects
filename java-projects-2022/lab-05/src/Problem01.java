import javax.swing.*;
import java.awt.*;

public class Problem01 extends JFrame {
    Problem01() {
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
        controlPanel.add(new JButton("RED"));
        controlPanel.add(new JButton("GREEN"));
        controlPanel.add(new JButton("BLUE"));
        //  repaint();  // обновляет окно несколько раз

    }

    public static void main(String[] args) {
        Problem01 window = new Problem01();  //окно программы
        // JFrame main = new JFrame();
    }
}
