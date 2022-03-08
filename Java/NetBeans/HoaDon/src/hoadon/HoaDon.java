package hoadon;

import java.io.Serializable;

public class HoaDon implements Serializable {
    private KhachHang khachHang;
    private MatHang matHang;
    private int soLuong;

    public HoaDon(KhachHang khachHang, MatHang matHang, int soLuong) {
        this.khachHang = khachHang;
        this.matHang = matHang;
        this.soLuong = soLuong;
    }
    
    public double thanhTien() {
        return soLuong * matHang.donGia + matHang.thue();
    }

    public KhachHang layKhachHang() {
        return khachHang;
    }
    
    public MatHang layMatHang() {
        return matHang;
    }
    
    public String toString() {
        return khachHang.toString() + ";" + matHang.toString() + ";" + soLuong;
    }
}