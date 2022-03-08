package tiendiengui;

import java.awt.*;
import java.awt.event.*;
import java.io.*;
import javax.swing.JOptionPane;

public class TienDienGUI implements ActionListener {
    
    Frame f = new Frame("Tiền điện");
    
    Label l1 = new Label("Đối tượng: ");
    Label l2 = new Label("Chỉ số cũ: ");
    Label l3 = new Label("Chỉ số mới: ");
    Label l4 = new Label("Định mức: ");
    Label l5 = new Label();
    
    TextField tf1 = new TextField(15);
    TextField tf2 = new TextField(15);
    TextField tf3 = new TextField(15);
    
    Choice c1 = new Choice();
    
    TextArea ta1 = new TextArea();
    
    Button b1 = new Button("Tính tiền");
    Button b2 = new Button("Sao lưu");
    Button b3 = new Button("Xem lịch sử");
    Button b4 = new Button("Xóa lịch sử");
    
    MouseAdapter ma;
    
    Panel p1 = new Panel(new GridLayout(4, 2));
    Panel p2 = new Panel(new GridLayout(1, 1));
    Panel p3 = new Panel(new GridLayout(5, 1));
    
    public TienDienGUI() {
        f.setLayout(new GridLayout(3, 3));
        p1.add(l1);
        c1.add("Cá nhân");
        c1.add("Đơn vị hành chính");
        c1.add("Đơn vị sản xuất");
        p1.add(c1);
        p1.add(l2);
        p1.add(tf1);
        p1.add(l3);
        p1.add(tf2);
        p1.add(l4);
        p1.add(tf3);
        f.add(p1);
        
        ta1.setEditable(false);
        p2.add(ta1);
        f.add(p2);
        
        p3.add(b1);
        p3.add(b2);
        p3.add(b3);
        p3.add(b4);
        p3.add(l5);
        f.add(p3);
        
        b1.addActionListener(this);
        b2.addActionListener(this);
        b3.addActionListener(this);
        b4.addActionListener(this);
        
        ma = new MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent mEvent) {
                Component c = mEvent.getComponent();
                c.setBackground(Color.LIGHT_GRAY);
            }
            public void mouseExited(java.awt.event.MouseEvent mEvent) {
                Component c = mEvent.getComponent();
                c.setBackground(Color.WHITE);
            }
        };
        
        b1.addMouseListener(ma);
        b2.addMouseListener(ma);
        b3.addMouseListener(ma);
        b4.addMouseListener(ma);
   
        f.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
        
        f.setSize(400, 350);
        f.setVisible(true);
        
    }
    
    @Override
    public void actionPerformed(ActionEvent e) {
        Object nutLenh = e.getSource();
        if (nutLenh == b1 || nutLenh == b2) {
            int loaiDT = 0;
            double chiSoCu = 0;
            double chiSoMoi = 0;
            double dinhMuc = 0;
            boolean loi = false;
            
            try {
                loaiDT = c1.getSelectedIndex();
                chiSoCu = Double.valueOf(tf1.getText());
                chiSoMoi = Double.valueOf(tf2.getText());
                dinhMuc = Double.valueOf(tf3.getText());
                
                if (chiSoCu > chiSoMoi) {
                    loi = true;
                    JOptionPane.showMessageDialog(null,
                        "Chỉ số cũ không thể lớn hơn chỉ số mới",
                        "Dữ liệu",
                        JOptionPane.WARNING_MESSAGE);
                }
            } catch (NumberFormatException ex) {
                loi = true;
                JOptionPane.showMessageDialog(null,
                        "Chưa nhập đủ dữ liệu hoặc dữ liệu của ô nào đó "
                        + "không phải là số thực.",
                        "Dữ liệu",
                        JOptionPane.WARNING_MESSAGE);
            } 
            
            if (!loi) {
                TienDien tienDien = new TienDien(loaiDT,
                        chiSoCu,
                        chiSoMoi,
                        dinhMuc);
                
                    String tienTra = String.valueOf(tienDien.tinhTien());
                    
                if (nutLenh == b1) {
                    ta1.setText(tienTra + " VNĐ");
                } else if (nutLenh == b2) {
                    String path = "C:\\TienDien\\data.txt";
                    
                    try {
                        File file = new File(path);
                        file.getParentFile().mkdirs();
                        file.createNewFile();
                        
                        try (FileWriter fw = new FileWriter(file, true);
                                BufferedWriter bw = new BufferedWriter(fw)) {
                            
                            bw.write(tienDien.toString() + ";" + tienTra);
                            bw.newLine();
                            bw.flush();
                        }
                    } catch (IOException ex) {
                        loi = true;
                        JOptionPane.showMessageDialog(null,
                                "Thất bại!",
                                "Sao lưu",
                                JOptionPane.ERROR_MESSAGE);
                    }
                    
                    if (!loi) {
                        JOptionPane.showMessageDialog(null,
                                "Thành công!",
                                "Sao lưu",
                                JOptionPane.INFORMATION_MESSAGE);
                        l5.setText("*Dữ liệu được sao lưu ở đường dẫn "
                                + path);
                    }
                }
            }
        }
        
        if (nutLenh == b3) {
            ta1.setText("");
            String path = "C:\\TienDien\\data.txt";
            
            try (FileReader fr = new FileReader(path);
                    BufferedReader br = new BufferedReader(fr)) {
                
                while (br.ready()) {
                    String line = br.readLine();
                    String[] part = line.split(";");
                    
                    if (part.length == 5) {
                        switch (part[0]) {
                            case "0" -> {
                                part[0] = "Cá nhân";
                            }
                            case "1" -> {
                                part[0] = "Đơn vị hành chính";
                            }
                            case "2" -> {
                                part[0] = "Đơn vị sản xuất";
                            }
                            default -> {
                                part[0] = "";
                            }
                        }

                        ta1.append("Đối tượng: " + part[0] + "\n");
                        ta1.append("Chỉ số cũ: " + part[1] + " kWh\n");
                        ta1.append("Chỉ số mới: " + part[2] + " kWh\n");
                        ta1.append("Định mức: " + part[3] + " kWh\n");
                        ta1.append("Số tiền thanh toán: " + part[4] + " VNĐ\n");
                    } else {
                        ta1.append("Truy xuất không thành công.\n");
                    }
                    
                    ta1.append("\n");
                }
            } catch (FileNotFoundException ex) {
                JOptionPane.showMessageDialog(null,
                        "Không tìm thấy file sao lưu!",
                        "Lịch sử",
                        JOptionPane.WARNING_MESSAGE);
            } catch (IOException ex) {
                JOptionPane.showMessageDialog(null,
                        "Lỗi truy xuất dữ liệu!",
                        "Lịch sử",
                        JOptionPane.ERROR_MESSAGE);
            }
        }
        
        if(nutLenh == b4) {
            String path = "C:\\TienDien\\data.txt";
            File file = new File(path);
            
            if (file.delete()) {
                JOptionPane.showMessageDialog(null,
                        "Xóa thành công!",
                        "Lịch sử",
                        JOptionPane.INFORMATION_MESSAGE);
            } else {
                JOptionPane.showMessageDialog(null,
                        "Xóa thất bại!",
                        "Lịch sử",
                        JOptionPane.ERROR_MESSAGE);
            }
        }
    }

}
