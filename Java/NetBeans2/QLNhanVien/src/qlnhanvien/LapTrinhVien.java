package qlnhanvien;

public class LapTrinhVien extends NhanVien {
    private int soGioLT;

    public LapTrinhVien(int MaNV, String hoTen, int namSinh, int soNamCT, float luongCB, int soGioLT) {
        super(MaNV, hoTen, namSinh, soNamCT, luongCB);
        this.soGioLT = soGioLT;
    }
    
    public int laySoGioLT() {
        return soGioLT;
    }
    
    public float tinhLuong() {
        int tienTangGio;
        
        if (soNamCT < 2) {
            tienTangGio = 100000;
        } else {
            tienTangGio = 200000;
        }
        
        return luongCB + soGioLT * tienTangGio;
    }
    
    public String toString() {
        return super.toString() + ";" + soGioLT;
    }
}