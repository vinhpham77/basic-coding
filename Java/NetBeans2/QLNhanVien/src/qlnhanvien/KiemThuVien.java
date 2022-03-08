package qlnhanvien;

public class KiemThuVien extends NhanVien {
    private int soLoi;

    public KiemThuVien(int MaNV, String hoTen, int namSinh, int soNamCT, float luongCB, int soLoi) {
        super(MaNV, hoTen, namSinh, soNamCT, luongCB);
        this.soLoi = soLoi;
    }

    public int laySoLoi() {
        return soLoi;
    }
    
    public float tinhLuong() {
        if (soLoi > 10) {
            return luongCB + 50000 * 10 + 100000 * (soLoi - 10);
        } else {
            return luongCB + 50000 * soLoi;
        }
    }
    
    public String toString() {
        return super.toString() + ";" + soLoi;
    }
}