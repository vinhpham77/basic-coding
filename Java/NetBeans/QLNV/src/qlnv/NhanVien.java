package qlnv;
import java.util.Date;

public class NhanVien {
    private String hoTen;
    private Date ngaySinh;
    private String chucVu;
    private float heSoLuong;
    private double luongCB;
    
    @SuppressWarnings("deprecation")
    public NhanVien() {
        this.hoTen = null;
        this.ngaySinh = new Date(100, 1, 1);
        this.chucVu = null;
        this.heSoLuong = 0;
        this.luongCB = 0;   
    }
    
    public NhanVien(String hoTen, Date ngSinh) {
        this.hoTen = hoTen;
        this.ngaySinh = (Date) ngSinh.clone();
        this.chucVu = null;
        this.heSoLuong = 0;
        this.luongCB = 0;   
    }
    
    public NhanVien(String hoTen, Date ngSinh, String chucVu, float hsLuong, double luongCB) {
        this.hoTen = hoTen;
        this.ngaySinh = (Date) ngSinh.clone();
        this.chucVu = chucVu;
        this.heSoLuong = hsLuong;
        this.luongCB = luongCB;   
    }
    
    public double tinhLuong() {
        float heSoPC = 0;
        switch (this.chucVu) {
            case "Giam doc" ->
                heSoPC = 1.0f;
            case "Pho giam doc" ->
                heSoPC = 0.8f;
            case "Truong phong" ->
                heSoPC = 0.5f;
            case "Pho phong" ->
                heSoPC = 0.4f;
            default -> heSoPC = 0;
        }
        return (this.heSoLuong + heSoPC) * this.luongCB;
    }
    
    public double tinhTienBHXH() {
        return this.tinhLuong() * 0.6f;
    }
    
    public double tinhTienBXTN() {
        return this.tinhLuong() * 0.1f;
    }
    
    public double tinhTienNhan() {
        return this.tinhLuong() - (this.tinhTienBHXH() + this.tinhTienBXTN());
    }
    
    public String toString() {
        return "Ho ten: " + this.hoTen + '\n'
                + "Ngay sinh: " + this.ngaySinh + '\n'
                + "Chuc vu: " + this.chucVu + '\n'
                + "Luong: " + this.tinhLuong() + '\n';
    }
    
    public void hienThi() {
        System.out.println(this.toString());
    }
}