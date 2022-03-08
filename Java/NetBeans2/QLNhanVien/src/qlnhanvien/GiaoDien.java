package qlnhanvien;

import java.awt.*;
import java.awt.event.*;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class GiaoDien implements ActionListener, WindowListener {

    Frame f = new Frame("QLNV");

    Label lbMaNV = new Label("Mã nhân viên:");
    Label lbHoTen = new Label("Họ tên:");
    Label lbNamSinh = new Label("Năm sinh:");
    Label lbSoNamCT = new Label("Số năm công tác:");
    Label lbLuongCB = new Label("Lương cơ bản:");
    Label lbLoaiNV = new Label("Loại nhân viên:");
    Label lbSoGioLT = new Label("Số giờ làm thêm:");
    Label lbSoLoi = new Label("Số lỗi:");

    TextField tfMaNV = new TextField();
    TextField tfHoTen = new TextField();
    TextField tfNamSinh = new TextField();
    TextField tfSoNamCT = new TextField();
    TextField tfLuongCB = new TextField();
    TextField tfSoGioLT = new TextField();
    TextField tfSoLoi = new TextField();

    Choice chLoaiNV = new Choice();

    TextArea taKetQua = new TextArea();

    Button btTinh = new Button("Tính");
    Button btDocTep = new Button("Đọc tệp");
    Button btGhiTep = new Button("Ghi tệp");

    Panel pNhap = new Panel(new GridLayout(9, 2));
    Panel pKetQua = new Panel(new GridLayout(1, 1));
    Panel pNutLenh = new Panel(new GridLayout(3, 1));

    public GiaoDien() {
        f.setLayout(new GridLayout(3, 1));

        chLoaiNV.add("Lập trình viên");
        chLoaiNV.add("Kiểm thử viên");

        taKetQua.setEditable(false);
        taKetQua.setSelectionStart(0);

        btTinh.addActionListener(this);
        btDocTep.addActionListener(this);
        btGhiTep.addActionListener(this);

        pNhap.add(lbMaNV);
        pNhap.add(tfMaNV);
        pNhap.add(lbHoTen);
        pNhap.add(tfHoTen);
        pNhap.add(lbNamSinh);
        pNhap.add(tfNamSinh);
        pNhap.add(lbSoNamCT);
        pNhap.add(tfSoNamCT);
        pNhap.add(lbLuongCB);
        pNhap.add(tfLuongCB);
        pNhap.add(lbLoaiNV);
        pNhap.add(chLoaiNV);
        pNhap.add(lbSoGioLT);
        pNhap.add(tfSoGioLT);
        pNhap.add(lbSoLoi);
        pNhap.add(tfSoLoi);

        pKetQua.add(taKetQua);

        pNutLenh.add(btTinh);
        pNutLenh.add(btDocTep);
        pNutLenh.add(btGhiTep);

        f.add(pNhap);
        f.add(pKetQua);
        f.add(pNutLenh);
        f.addWindowListener(this);
        f.setSize(700, 600);
        f.setVisible(true);
    }

    public void inNhapSai() {
        taKetQua.setText("Chưa nhập đủ thông tin hoặc chưa đúng định dạng!");
    }

    public void actionPerformed(ActionEvent e) {
        Button nutLenh = (Button) e.getSource();

        if (nutLenh == btTinh) {
            NhanVien nv;
            boolean nhapSai = false;
            int maNV = 0;
            String hoTen;
            int namSinh = 0;
            int soNamCT = 0;
            float luongCB = 0;
            boolean laLTV = true;
            int soGioLT = 0;
            int soLoi = 0;

            hoTen = tfHoTen.getText();
            if (hoTen.isBlank()) {
                nhapSai = true;
            }
            try {
                maNV = Integer.parseInt(tfMaNV.getText());
                namSinh = Integer.parseInt(tfNamSinh.getText());
                soNamCT = Integer.parseInt(tfSoNamCT.getText());
                luongCB = Float.parseFloat(tfLuongCB.getText());
            } catch (NumberFormatException ex) {
                inNhapSai();
            }
            if (chLoaiNV.getSelectedIndex() == 0) {
                laLTV = true;
                try {
                    soGioLT = Integer.parseInt(tfSoGioLT.getText());
                } catch (NumberFormatException ex) {
                    nhapSai = true;
                }
            } else {
                try {
                    soLoi = Integer.parseInt(tfSoLoi.getText());
                } catch (NumberFormatException ex) {
                    nhapSai = true;
                }
            }

            if (!nhapSai) {
                if (laLTV) {
                    nv = new LapTrinhVien(maNV, hoTen, namSinh, soNamCT, luongCB, soGioLT);
                } else {
                    nv = new KiemThuVien(maNV, hoTen, namSinh, soNamCT, luongCB, soLoi);
                }

                taKetQua.setText(nv.tinhLuong() + "đ");
            } else {
                inNhapSai();
            }
        } else if (nutLenh == btDocTep) {
            try (FileReader fr = new FileReader("LapTrinhVien.txt");
                    BufferedReader br = new BufferedReader(fr)) {

                String[] parts = br.readLine().split(",");

                if (parts.length == 5) {
                    tfMaNV.setText(parts[0]);
                    tfHoTen.setText(parts[1]);
                    tfNamSinh.setText(parts[2]);
                    tfSoNamCT.setText(parts[3]);
                    tfLuongCB.setText(parts[4]);
                    chLoaiNV.select(0);
                    tfSoGioLT.setText("0");
                }
            } catch (IOException ex) {
                taKetQua.setText("Lỗi đọc tệp!");
            }
        } else {
            try (FileWriter fw = new FileWriter("LuongLTV.txt", true);
                    BufferedWriter bw = new BufferedWriter(fw)) {

                NhanVien nv;
                boolean nhapSai = false;
                int maNV = 0;
                String hoTen;
                int namSinh = 0;
                int soNamCT = 0;
                float luongCB = 0;
                boolean laLTV = true;
                int soGioLT = 0;
                int soLoi = 0;
                float luong = 0;

                hoTen = tfHoTen.getText();
                if (hoTen.isBlank()) {
                    nhapSai = true;
                }
                try {
                    maNV = Integer.parseInt(tfMaNV.getText());
                    namSinh = Integer.parseInt(tfNamSinh.getText());
                    soNamCT = Integer.parseInt(tfSoNamCT.getText());
                    luongCB = Float.parseFloat(tfLuongCB.getText());
                } catch (NumberFormatException ex) {
                    inNhapSai();
                }
                if (chLoaiNV.getSelectedIndex() == 0) {
                    laLTV = true;
                    try {
                        soGioLT = Integer.parseInt(tfSoGioLT.getText());
                    } catch (NumberFormatException ex) {
                        nhapSai = true;
                    }
                } else {
                    try {
                        soLoi = Integer.parseInt(tfSoLoi.getText());
                    } catch (NumberFormatException ex) {
                        nhapSai = true;
                    }
                }

                if (!nhapSai) {
                    if (laLTV) {
                        nv = new LapTrinhVien(maNV, hoTen, namSinh, soNamCT, luongCB, soGioLT);
                    } else {
                        nv = new KiemThuVien(maNV, hoTen, namSinh, soNamCT, luongCB, soLoi);
                    }
                    luong = nv.tinhLuong();
                    bw.write(maNV + "," + hoTen + "," + luong);
                    bw.newLine();
                    bw.flush();
                    taKetQua.setText("Ghi tệp thành công!");
                } else {
                    inNhapSai();
                }
                
            } catch (IOException ex) {
                taKetQua.setText("Lỗi ghi tệp!");
            }
        }
    }

    public void windowOpened(WindowEvent e) {
    }

    public void windowClosing(WindowEvent e) {
        System.exit(0);
    }

    public void windowClosed(WindowEvent e) {
    }

    public void windowIconified(WindowEvent e) {
    }

    public void windowDeiconified(WindowEvent e) {
    }

    public void windowActivated(WindowEvent e) {
    }

    public void windowDeactivated(WindowEvent e) {
    }
}
