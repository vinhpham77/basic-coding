package hoadon;

import java.io.Serializable;

public class KhachHang implements Serializable {
    private String tenKhachHang;
    private String diaChi;

    public KhachHang(String tenKhachHang, String diaChi) {
        this.tenKhachHang = tenKhachHang;
        this.diaChi = diaChi;
    }
    
    public String layDiaChi() {
        return diaChi;
    }
    
    public String toString() {
        return tenKhachHang + ";" + diaChi;
    }
}