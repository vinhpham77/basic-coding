package sinhvienhp;

import java.awt.*;
import java.awt.event.*;
import java.io.*;

public class GiaoDien implements ActionListener {
    Frame f = new Frame("Học phí sinh viên");
    
    Label l1 = new Label("Họ tên:");
    Label l2 = new Label("Ngành:");
    Label l3 = new Label("Đối tượng:");
    Label l4 = new Label("Số tín chỉ học lại:");
    
    TextField tf1 = new TextField(15);
    TextField tf2 = new TextField(15);
    
    TextArea ta = new TextArea();
    
    Choice c1 = new Choice();
    Choice c2 = new Choice();
    
    Button b1 = new Button("Tính học phí");
    Button b2 = new Button("Lưu kết quả");
    
    Panel p1 = new Panel(new GridLayout(4, 2));
    Panel p2 = new Panel(new GridLayout(1, 1));
    Panel p3 = new Panel(new GridLayout(2, 1));

    public GiaoDien() {
        f.setLayout(new GridLayout(3, 2));
        
        p1.add(l1);
        p1.add(tf1);
        p1.add(l2);
        c1.add("101");
        c1.add("102");
        c1.add("103");
        p1.add(c1);
        p1.add(l3);
        c2.add("01");
        c2.add("02");
        c2.add("03");
        c2.add("04");
        p1.add(c2);
        p1.add(l4);
        p1.add(tf2);
        
        ta.setEditable(false);
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
        p3.add(b1);
        p3.add(b2);
        
        f.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent wEvt) {
                System.exit(0);
            }
        });
        
        f.add(p1);
        f.add(p2);
        f.add(p3);
        
        f.setSize(300, 250);
        f.setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        String hoTen = tf1.getText();
        int nganh = c1.getSelectedIndex() + 101;
        int doiTuong = c2.getSelectedIndex() + 1;
        int soTCHL = Integer.valueOf(tf2.getText());
        SinhVienHP sv = new SinhVienHP(hoTen, nganh, doiTuong, soTCHL);
        String hocPhiHK = String.valueOf(sv.hocPhiHK());
        String hocPhiHL = String.valueOf(sv.hocPhiHL());
        String tongHocPhi = String.valueOf(sv.hocPhiTong());
        
        if (e.getActionCommand() == "Tính học phí") {
            ta.setText("Học phí học kì: " + hocPhiHK);
            ta.append("\nHọc phí học lại: " + hocPhiHL);
            ta.append("\nTổng học phí: " + tongHocPhi);
        }
        if (e.getActionCommand() == "Lưu kết quả") {
            try (FileWriter fw = new FileWriter("DSSVHP.txt", true);
                BufferedWriter bw = new BufferedWriter(fw)) {
                
                bw.write(hoTen);
                bw.write("-");
                bw.write(String.valueOf(nganh));
                bw.write("-");
                bw.write(String.valueOf(doiTuong));
                bw.write("-");
                bw.write(String.valueOf(soTCHL));
                bw.write("-");
                bw.write(hocPhiHK);
                bw.write("-");
                bw.write(hocPhiHL);
                bw.write("-");
                bw.write(tongHocPhi);
                bw.newLine();
                
                bw.flush();
            } catch (IOException ex) {
                ta.setText("Lỗi ghi tệp");
            }
        }
    }
}