package hoadon;

public class HangNhapKhau extends MatHang {
    private boolean uuTien;

    public HangNhapKhau(String tenHang, double donGia, boolean uuTien) {
        super(tenHang, donGia);
        this.uuTien = uuTien;
    }
    
    public double thue() {
        if (uuTien) {
            return donGia * 0.1;
        } else {
            return donGia * 0.2;
        }
    }
    
    public String toString() {
        return super.toString() + ";" + uuTien;
    }
}