package hoadon;

import java.io.*;
import java.util.Vector;

public class SuDung {
    
    public static void main(String[] args) {        
        KhachHang[] khachHangs = new KhachHang[3];
        khachHangs[0] = new KhachHang("Nguyen Van A", "Vung Tau");
        khachHangs[1] = new KhachHang("Nguyen Thi B", "Quy Nhon");
        khachHangs[2] = new KhachHang("Pham Van Mach", "Ha Noi");
        
        MatHang[] matHangs = new MatHang[5];
        matHangs[0] = new HangNoiDia("Nuoc mam", 20000);
        matHangs[1] = new HangNoiDia("Nuoc tuong", 13000);
        matHangs[2] = new HangNoiDia("Bot nem", 19500);
        matHangs[3] = new HangNhapKhau("Mi chinh", 17500, false);
        matHangs[4] = new HangNhapKhau("Sot Mayonnaise", 27000, true);
        
        Vector<HoaDon> hoaDons = new Vector<>();
        hoaDons.add(new HoaDon(khachHangs[0], matHangs[0], 100));
        hoaDons.add(new HoaDon(khachHangs[0], matHangs[1], 110));
        hoaDons.add(new HoaDon(khachHangs[0], matHangs[2], 120));
        hoaDons.add(new HoaDon(khachHangs[1], matHangs[3], 200));
        hoaDons.add(new HoaDon(khachHangs[2], matHangs[4], 300));
        
        //Hien thi 5 hoa don
        for (HoaDon hoaDon : hoaDons) {
            System.out.println(hoaDon);
        }
        System.out.println("");
        
        //Tong thanh tien 5 hoa don
        double tong = 0;
        for (HoaDon hoaDon : hoaDons) {
            tong += hoaDon.thanhTien();
        }
        System.out.println("Tong thanh tien cua nam hoa don: " + tong + "\n");
        
        //Liet ke cac khach hang mua hang nhap khau
        for (HoaDon hoaDon : hoaDons) {
            if (hoaDon.layMatHang() instanceof HangNhapKhau) {
                System.out.println(hoaDon.layKhachHang());
            }
        }
        System.out.println("");
        
        //Luu 5 hoa don vao tep HoaDon.dat kieu tep doi tuong
        try {
            FileOutputStream fos = new FileOutputStream("HoaDon.dat");
            ObjectOutputStream ois = new ObjectOutputStream(fos);
            
            for (HoaDon hoaDon : hoaDons) {
                ois.writeObject(hoaDon);
            }
            
            fos.close();
            ois.close();
        } catch (IOException e) {
            System.out.println("Loi ghi tep");
        }
        
        //Doc tep HoaDon.dat ra mot mang cac hoa don va hien thi mang do
        HoaDon[] hoaDonss = new HoaDon[5];
        try {
            FileInputStream fis = new FileInputStream("HoaDon.dat");
            ObjectInputStream ois = new ObjectInputStream(fis);
            
            int i = 0;
            while (fis.available() != 0) {                
                hoaDonss[i] = (HoaDon)ois.readObject();
                i++;
            }
            
            fis.close();
            ois.close();
        } catch (Exception e) {
            System.out.println("Loi doc tep");
        }
        
        for (HoaDon hoaDon : hoaDonss) {
            System.out.println(hoaDon);
        }
    }
}