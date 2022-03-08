package qlnhanvien;

import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.util.Date;

public class GiaoDien implements ActionListener {

    Frame f = new Frame("Quản lý nhân viên");

    Label l1 = new Label("Họ tên:");
    Label l2 = new Label("Ngày sinh:");
    Label l3 = new Label("Chức vụ:");
    Label l4 = new Label("Hệ số lương:");
    Label l5 = new Label("Lương cơ bản:");

    TextField tf1 = new TextField(45);
    TextField tf2 = new TextField(45);
    TextField tf3 = new TextField(10);
    TextField tf4 = new TextField(10);

    TextArea ta = new TextArea();

    Choice c1 = new Choice();

    Button b1 = new Button("Tính lương, tiền BHXH");
    Button b2 = new Button("Lưu nhân viên");
    Button b3 = new Button("Hiển thị danh sách nhân viên");

    Panel p1 = new Panel(new GridLayout(5, 2));
    Panel p2 = new Panel(new GridLayout(1, 1));
    Panel p3 = new Panel(new GridLayout(3, 1));

    public GiaoDien() {
        f.setLayout(new GridLayout(3, 2));

        p1.add(l1);
        p1.add(tf1);
        p1.add(l2);
        tf2.setText("VD: 10/10/2002 -> 102/10/10; 1/1/1999 -> 99/1/1");
        p1.add(tf2);
        p1.add(l3);
        c1.add("Giám đốc");
        c1.add("Phó giám đốc");
        c1.add("Trưởng phòng");
        c1.add("Phó phòng");
        p1.add(c1);
        p1.add(l4);
        p1.add(tf3);
        p1.add(l5);
        p1.add(tf4);

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
        b3.addMouseListener(ma);
        b3.addActionListener(this);
        p3.add(b1);
        p3.add(b2);
        p3.add(b3);

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

        if (e.getSource() == b1) {
            String hoTen = tf1.getText();
            Date ngaySinh = new Date(tf2.getText());
            String chucVu = c1.getSelectedItem();
            double hsLuong = Double.valueOf(tf3.getText());
            long luongCB = Long.valueOf(tf4.getText());
            NhanVien nv = new NhanVien(hoTen, hoTen, chucVu, hsLuong, luongCB);
            
            String tienLuong = String.valueOf(nv.tinhLuong());
            String tienBHXH = String.valueOf(nv.tinhTienBHXH());
            ta.setText("Lương: " + tienLuong + "\n Tiền BHXH: " + tienBHXH);
        }
        
        if (e.getSource() == b2) {
            String hoTen = tf1.getText();
            Date ngaySinh = new Date(tf2.getText());
            String chucVu = c1.getSelectedItem();
            double hsLuong = Double.valueOf(tf3.getText());
            long luongCB = Long.valueOf(tf4.getText());
            NhanVien nv = new NhanVien(hoTen, hoTen, chucVu, hsLuong, luongCB);
            
            try (FileWriter fw = new FileWriter("NV.txt", true);
                    BufferedWriter bw = new BufferedWriter(fw)) {

                bw.write(hoTen);
                bw.write(";");
                bw.write(String.valueOf(ngaySinh));
                bw.write(";");
                bw.write(chucVu);
                bw.write(";");
                bw.write(String.valueOf(hsLuong));
                bw.write(";");
                bw.write(String.valueOf(luongCB));
                bw.newLine();

                bw.flush();
            } catch (IOException ex) {
                ta.setText("Lỗi ghi tệp");
            }
        }
        
        if (e.getSource() == b3) {
            try (FileReader fr = new FileReader("NV.txt");
                    BufferedReader bw = new BufferedReader(fr)) {

                ta.setText("");
                while (bw.ready()) {                    
                    String line = bw.readLine();
                    String[] parts = line.split(";");
                    
                    ta.append("Họ tên: " + parts[0] + "\n");
                    ta.append("Ngày sinh: " + parts[1] + "\n");
                    ta.append("Chức vụ: " + parts[2] + "\n");
                    ta.append("Hệ số lương: " + parts[3] + "\n");
                    ta.append("Lương cơ bản: " + parts[4] + "\n\n");
                }

            } catch (IOException ex) {
                ta.setText("Lỗi đọc tệp");
            }
        }
    }
}
