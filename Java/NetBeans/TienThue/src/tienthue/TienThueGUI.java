package tienthue;

import java.awt.*;
import java.awt.event.*;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Vector;
import javax.swing.JOptionPane;

public class TienThueGUI implements ActionListener {

    Frame f1 = new Frame("Tiền thuế");

    Label l1 = new Label("Họ tên:");
    Label l2 = new Label("Thu nhập:");

    TextField tf1 = new TextField(15);
    TextField tf2 = new TextField(15);

    TextArea ta = new TextArea();

    CheckboxGroup cbg = new CheckboxGroup();
    Checkbox cb1 = new Checkbox("Thu nhập thường xuyên", cbg, true);
    Checkbox cb2 = new Checkbox("Thu nhập không thường xuyên", cbg, false);

    Button b1 = new Button("Tính thuế");
    Button b2 = new Button("Lưu");
    Button b3 = new Button("Hiển thị danh sách");

    Vector<String> vct = new Vector<>();

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

    WindowAdapter wa = new WindowAdapter() {
        public void windowClosing(WindowEvent wEvt) {
            try (FileWriter fw = new FileWriter("data.txt");
                    BufferedWriter bw = new BufferedWriter(fw)) {

                int n = vct.size();

                for (int i = 0; i < n; i++) {
                    String line = vct.elementAt(i);

                    bw.write(line);
                    bw.newLine();
                }

                bw.flush();
            } catch (Exception e) {
                JOptionPane.showMessageDialog(null,
                        "Không như mong đợi!",
                        "Sao lưu",
                        JOptionPane.ERROR_MESSAGE);
            }
            System.exit(0);
        }
    };

    Panel p1 = new Panel(new GridLayout(3, 2));
    Panel p2 = new Panel(new GridLayout(1, 1));
    Panel p3 = new Panel(new GridLayout(3, 1));

    public TienThueGUI() {
        f1.setLayout(new GridLayout(3, 1));
        f1.setBackground(Color.LIGHT_GRAY);

        p1.add(l1);
        p1.add(tf1);
        p1.add(l2);
        p1.add(tf2);
        p1.add(cb1);
        p1.add(cb2);
        f1.add(p1);

        ta.setEditable(false);
        p2.add(ta);
        f1.add(p2);

        b1.addMouseListener(ma);
        b1.addActionListener(this);
        b2.addMouseListener(ma);
        b2.addActionListener(this);
        b3.addMouseListener(ma);
        b3.addActionListener(this);
        p3.add(b1);
        p3.add(b2);
        p3.add(b3);
        f1.add(p3);

        f1.addWindowListener(wa);
        f1.setSize(400, 300);
        f1.setVisible(true);

        truyXuatDulieu();
//        f0.setLayout(new GridLayout(2, 1));
//
//        f0.add(tf0);
//        b0.addMouseListener(ma);
//        b0.addActionListener(this);
//        f0.add(b0);
//
//        f0.addWindowListener(wa);
//        f0.setSize(400, 300);
//        f0.setVisible(true);
    }

    public void truyXuatDulieu() {
        try (FileReader fr = new FileReader("data.txt");
                BufferedReader br = new BufferedReader(fr)) {

            while (br.ready()) {
                String line = br.readLine();
                vct.add(line);
            }
        } catch (Exception e) {
            JOptionPane.showMessageDialog(null,
                    "Không như mong đợi!",
                    "Truy xuất",
                    JOptionPane.ERROR_MESSAGE);
        }
    }

//    public boolean coTheLayDL(TienThue tt) {
//        boolean thanhCong = true;
//        String hoTen = "";
//        double thuNhap = 0;
//        boolean laThuNhapTX = true;
//
//        try {
//            hoTen = tf1.getText();
//            thuNhap = Double.valueOf(tf2.getText());
//            laThuNhapTX = cbg.getSelectedCheckbox() == cb1;
//
//        } catch (NumberFormatException ex) {
//            thanhCong = false;
//            JOptionPane.showMessageDialog(null,
//                    "Thông tin không đầy đủ hoặc không phù hợp",
//                    "Tính tiền",
//                    JOptionPane.WARNING_MESSAGE);
//        }
//
//        if (thanhCong) {
//            tt = new TienThue(hoTen, thuNhap, laThuNhapTX);
//        }
//        return thanhCong;
//    }
    @Override
    public void actionPerformed(ActionEvent e) {
        Object nutLenh = e.getSource();
        if (nutLenh == b1 || nutLenh == b2) {
            boolean thanhCong = true;
            String hoTen = "";
            double thuNhap = 0;
            boolean laThuNhapTX = true;
            TienThue tt;
            try {
                hoTen = tf1.getText();
                thuNhap = Double.valueOf(tf2.getText());
                laThuNhapTX = cbg.getSelectedCheckbox() == cb1;

            } catch (NumberFormatException ex) {
                thanhCong = false;
                JOptionPane.showMessageDialog(null,
                        "Thông tin không đầy đủ hoặc không phù hợp",
                        "Tính tiền",
                        JOptionPane.WARNING_MESSAGE);
            }

            if (thanhCong) {
                tt = new TienThue(hoTen, thuNhap, laThuNhapTX);
                String tienTra = String.valueOf(tt.tinhThue());

                if (nutLenh == b1) {
                    ta.setText(tienTra + " VNĐ");
                } else {
                    String line = tt.toString() + ";" + tienTra;
                    vct.add(line);

                    JOptionPane.showMessageDialog(null,
                            "Thành công!",
                            "Lưu",
                            JOptionPane.INFORMATION_MESSAGE);
                }
            }
        }

        if (nutLenh == b3) {
            int n = vct.size();
            ta.setText("");

            for (int i = 0; i < n; i++) {
                String line = vct.elementAt(i);
                String[] parts = line.split(";");

                if (parts[2].equals("true")) {
                    parts[2] = "thường xuyên";
                } else {
                    parts[2] = "không thường xuyên";
                }

                ta.append("Họ tên: " + parts[0] + "\n");
                ta.append("Thu nhập: " + parts[1] + "\n");
                ta.append("Loại thu nhập: " + parts[2] + "\n");
                ta.append("Thuế: " + parts[3] + " VNĐ\n\n");
            }
            ta.setCaretPosition(0);
        }
    }
}
