package qlluonggiaovien;

import java.awt.*;
import java.awt.event.*;

public class GiaoDien implements ActionListener {
    Frame f = new Frame("Quản lý lương giáo viên");
    
    Label l1 = new Label("Họ tên:");
    Label l2 = new Label("Giới tính:");
    Label l3 = new Label("Số năm công tác:");
    Label l4 = new Label("Số lớp dạy:");
    Label l5 = new Label("Số tiết trên tuần:");
    
    TextField tf1 = new TextField(25);
    TextField tf2 = new TextField(25);
    TextField tf3 = new TextField(10);
    TextField tf4 = new TextField(10);
    
    Choice c = new Choice();
    
    TextArea ta = new TextArea();
    
    Button b1 = new Button("Tính lương");
    Button b2 = new Button("Ghi file");
    
    MouseAdapter ma;
    WindowAdapter wa;
    
    Panel p1 = new Panel(new GridLayout(5, 2));
    Panel p2 = new Panel(new GridLayout(1, 1));
    Panel p3 = new Panel(new GridLayout(1, 2));
    public GiaoDien() {
        f.setLayout(new GridLayout(3, 2));
        
        p1.add(l1);
        p1.add(tf1);
        p1.add(l2);
        c.add("Nam");
        c.add("Nữ");
        c.add("Khác");
        p1.add(c);
        p1.add(l3);
        p1.add(tf2);
        p1.add(l4);
        p1.add(tf3);
        p1.add(l5);
        p1.add(tf4);
        
        ta.setEditable(false);
        p2.add(ta);
        
        ma = new MouseAdapter() {
            public void mouseEntered(MouseEvent mEvt) {
                Component c = mEvt.getComponent();
                c.setBackground(Color.LIGHT_GRAY);
            }

            public void mouseExited(MouseEvent mEvt) {
                Component c = mEvt.getComponent();
                c.setBackground(Color.WHITE);
            }
        };
        
        wa = new WindowAdapter() {
            public void windowClosing(WindowEvent wEvt) {
                System.exit(0);
            }
        };
        
        b1.addMouseListener(ma);
        b1.addActionListener(this);
        b2.addMouseListener(ma);
        b2.addActionListener(this);
        p3.add(b1);
        p3.add(b2);
        
        f.add(p1);
        f.add(p2);
        f.add(p3);
        f.addWindowListener(wa);
        
        f.setSize(400, 300);
        f.setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (true) {
            
        }
    }
    
    
}