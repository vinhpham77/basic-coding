package qlnhanvien;

public class NhanVien {

    private String hoTen;
    private String ngaySinh;
    private String chucVu;
    private double hsLuong;
    private long luongCB;

    public NhanVien(String hoTen, String ngaySinh, String chucVu, double hsLuong, long luongCB) {
        this.hoTen = hoTen;
        this.ngaySinh = ngaySinh;
        this.chucVu = chucVu;
        this.hsLuong = hsLuong;
        this.luongCB = luongCB;
    }

    public double tinhLuong() {
        double heSoPC = 0;
        
        if (chucVu.equals("Giám đốc")) {
            heSoPC = 1.0;
        }
        if (chucVu.equals("Phó giám đốc")) {
            heSoPC = 0.8;
        }
        if (chucVu.equals("Trưởng phòng")) {
            heSoPC = 0.5;
        }
        if (chucVu.equals("Phó phòng")) {
            heSoPC = 0.4;
        }
        
        return (hsLuong + heSoPC) * luongCB;
    }
    
    public double tinhTienBHXH() {
        return tinhLuong() * 0.6;
    }
}
