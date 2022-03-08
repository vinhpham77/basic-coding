package hoadon;

public class HangNoiDia extends MatHang {

    public HangNoiDia(String tenHang, double donGia) {
        super(tenHang, donGia);
    }

    public double thue() {
        return donGia * 0.1;
    }
    
    public String toString() {
        return super.toString();
    }
}