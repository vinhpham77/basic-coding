package qlluonggiaovien;

public class GiaoVien {
    private String hoTen;
    private String gioiTinh;
    private int soNamCT;
    private int soLopDay;
    private int soTiet;

    public GiaoVien(String hoTen, String gioiTinh, int soNamCT, int soLopDay, int soTiet) {
        this.hoTen = hoTen;
        this.gioiTinh = gioiTinh;
        this.soNamCT = soNamCT;
        this.soLopDay = soLopDay;
        this.soTiet = soTiet;
    }
    
    public double tinhLuong() {
        double tienLuong = (soLopDay * soTiet * 4) * 50000;
        double heSoPhuCap;
        
        if (soNamCT < 1) {
            heSoPhuCap = 0;
        } else if (soNamCT >= 1 && soNamCT <= 5) {
            heSoPhuCap = tienLuong * 1.2 / 100;
        } else if (soNamCT <= 10) {
            heSoPhuCap = tienLuong * 1.5 / 100;
        } else {
            heSoPhuCap = tienLuong * 1.7 / 100;
        }
        
        return tienLuong + heSoPhuCap;
    }
    
    public String toString() {
        return hoTen + ";" + gioiTinh + ";" + soNamCT + ";" + soLopDay + ";" + soTiet;
    }
}