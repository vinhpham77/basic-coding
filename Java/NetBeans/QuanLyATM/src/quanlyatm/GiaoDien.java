package quanlyatm;

import java.awt.*;
import java.awt.event.*;
import java.io.*;

public class GiaoDien implements ActionListener {

    Frame f = new Frame("Banking");

    Label l1 = new Label("Số tài khoản:");
    Label l2 = new Label("Số dư:");

    TextField tf1 = new TextField(45);
    TextField tf2 = new TextField(15);

    TextArea ta = new TextArea();

    Button b1 = new Button("Nạp tiền vào tài khoản");
    Button b2 = new Button("Rút tiền");
    Button b3 = new Button("Chuyển khoản");
    Button b4 = new Button("Lưu tài khoản");
    Button b5 = new Button("Hiển thị danh sách tài khoản");

    Panel p1 = new Panel(new GridLayout(2, 2));
    Panel p2 = new Panel(new GridLayout(1, 1));
    Panel p3 = new Panel(new GridLayout(5, 1));

    public GiaoDien() {
        f.setLayout(new GridLayout(3, 2));

        p1.add(l1);
        p1.add(tf1);
        p1.add(l2);
        p1.add(tf2);

        p2.add(ta);

        MouseAdapter ma = new MouseAdapter() {
            public void mouseEntered(MouseEvent mEvt) {
                Component c = mEvt.getComponent();
                c.setBackground(Color.LIGHT_GRAY);
            }

            public void mouseExited(MouseEvent mEvt) {
                Component c = mEvt.getComponent();
                c.setBackground(Color.WHITE);
            }
        };

        b1.addMouseListener(ma);
        b1.addActionListener(this);
        b2.addMouseListener(ma);
        b2.addActionListener(this);
        b3.addMouseListener(ma);
        b3.addActionListener(this);
        b4.addMouseListener(ma);
        b4.addActionListener(this);
        b5.addMouseListener(ma);
        b5.addActionListener(this);
        
        p3.add(b1);
        p3.add(b2);
        p3.add(b3);
        p3.add(b4);
        p3.add(b5);

        f.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent wEvt) {
                System.exit(0);
            }
        });

        f.add(p1);
        f.add(p2);
        f.add(p3);

        f.setSize(500, 400);
        f.setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        
        if (e.getSource() == b4) {
            String sTK = tf1.getText();
            String soDu = tf2.getText();
            
            try (FileWriter fw = new FileWriter("NV.txt", true);
                    BufferedWriter bw = new BufferedWriter(fw)) {

                bw.write(sTK);
                bw.write(";");
                bw.write(soDu);
                bw.newLine();

                bw.flush();
            } catch (IOException ex) {
                ta.setText("Lỗi ghi tệp");
            }
        }
        
        if (e.getSource() == b5) {
            try (FileReader fr = new FileReader("ATM.txt");
                    BufferedReader bw = new BufferedReader(fr)) {

                ta.setText("");
                while (bw.ready()) {                    
                    String line = bw.readLine();
                    String[] parts = line.split(";");
                    
                    ta.append("Số tài khoản: " + parts[0] + "\n");
                    ta.append("Số dư: " + parts[1] + "\n\n");
                }
            } catch (IOException ex) {
                ta.setText("Lỗi đọc tệp");
            }
        }
    }
}
