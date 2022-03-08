package QLPhongHoc;

import java.io.*;
import java.util.Vector;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Exe_QLPhongHoc {

    public static void main(String[] args) {
        Vector<PhongHoc> dsPhongHoc = new Vector<>(5);
        PhongHoc phong;

        phong = new PhongLT("01", "A1", 140, 13, true);
        dsPhongHoc.add(phong);
        phong = new PhongLT("02", "A1", 113, 11, true);
        dsPhongHoc.add(phong);
        phong = new PhongTH("01", "A3", 140, 14, "Sinh vật", 93);
        dsPhongHoc.add(phong);
        phong = new PhongTH("02", "A3", 210, 14, "Vật lý", 150);
        dsPhongHoc.add(phong);
        phong = new PhongTH("03", "A3", 175, 17, "Hoá chất", 116);
        dsPhongHoc.add(phong);

        System.out.println("Hiển thị tất cả phòng học: ");
        dsPhongHoc.forEach(phongHoc -> {
            phongHoc.hienThi();
        });
        System.out.println("");

        System.out.println("Hiển thị phòng học không đạt chuẩn: ");
        dsPhongHoc.forEach(phongHoc -> {
            if (!phongHoc.datChuan()) {
                phongHoc.hienThi();
            }
        });
        System.out.println("");

        System.out.println("Hiển thị phòng học lý thuyết: ");
        dsPhongHoc.forEach(phongHoc -> {
            if (phongHoc.loaiPhong().equals("LT")) {
                phongHoc.hienThi();
            }
        });
        System.out.println("");

        try (FileOutputStream fos = new FileOutputStream("PhongHoc.dat");
                ObjectOutputStream oos = new ObjectOutputStream(fos)) {

            for (PhongHoc phongHoc : dsPhongHoc) {
                oos.writeObject(phongHoc);
            }
        } catch (FileNotFoundException ex) {
            Logger.getLogger(Exe_QLPhongHoc.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(Exe_QLPhongHoc.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        System.out.println("Đọc file: ");
        try (FileInputStream fis = new FileInputStream("PhongHoc.dat");
                ObjectInputStream ois = new ObjectInputStream(fis)) {

            for (int i = 0; i < 5; i++) {
                PhongHoc phongHoc = (PhongHoc) ois.readObject();
                phongHoc.hienThi();
            }
        } catch (FileNotFoundException ex) {
            Logger.getLogger(Exe_QLPhongHoc.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException | ClassNotFoundException ex) {
            Logger.getLogger(Exe_QLPhongHoc.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
