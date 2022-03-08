package qlnv;

import java.util.Date;

public class Exe_QLNV {

    public static void main(String[] args) {
        @SuppressWarnings("deprecation")
        Date nhanVien1 = new Date(102, 12, 10);
        @SuppressWarnings("deprecation")
        Date nhanVien2 = new Date(105, 12, 4);
        NhanVien a = new NhanVien("Pham Van Mach", nhanVien1, "Giam doc", 3.5f, 1000000);
        NhanVien b = new NhanVien("Pham Van Vinh", nhanVien2);
        a.hienThi();
        b.hienThi();
    }
}
