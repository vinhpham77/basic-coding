package thuviensach;

import java.util.Scanner;

public abstract class Sach {

    protected String maSach;
    protected String ngayNhap;
    protected double donGia;
    protected int soLuong;
    protected String nhaSanXuat;

    public Sach() {
    }

    public Sach(String maSach, String ngayNhap, double donGia, int soLuong, String nhaSanXuat) {
        this.maSach = maSach;
        this.ngayNhap = ngayNhap;
        this.donGia = donGia;
        this.soLuong = soLuong;
        this.nhaSanXuat = nhaSanXuat;
    }

    public String getMaSach() {
        return maSach;
    }

    public void setMaSach(String maSach) {
        this.maSach = maSach;
    }

    public String getngayNhap() {
        return ngayNhap;
    }

    public void setngayNhap(String ngayNhap) {
        ngayNhap = ngayNhap;
    }

    public double getDonGia() {
        return donGia;
    }

    public void setDonGia(double donGia) {
        this.donGia = donGia;
    }

    public int getSoLuong() {
        return soLuong;
    }

    public void setSoLuong(int soLuong) {
        this.soLuong = soLuong;
    }

    public String getNhaSanXuat() {
        return nhaSanXuat;
    }

    public void setNhaSanXuat(String nhaSanXuat) {
        this.nhaSanXuat = nhaSanXuat;
    }

    public void nhapSach() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Nhap ma sach: ");
        maSach = scanner.nextLine();
        System.out.print("Ngay nhap: ");
        ngayNhap = scanner.nextLine();
        System.out.print("Nhap nha san xuat: ");
        nhaSanXuat = scanner.nextLine();
        System.out.print("Nhap don gia: ");
        donGia = scanner.nextDouble();
        System.out.print("Nhap so luong: ");
        soLuong = scanner.nextInt();
    }

    public String toString() {
        return "Ma sach: " + maSach + "\n" +
               "Nha san xuat: " + nhaSanXuat + "\n" +
               "Don gia: " + donGia + "\n" +
               "So luong: " + soLuong + "\n" +
               "Ngay nhap:" + ngayNhap + "\n";

    }

    public boolean equals(Object hp) {
        Sach b = (Sach) hp;
        return (this.maSach.equals(b.maSach)) && (this.ngayNhap.equals(b.ngayNhap)) && (this.donGia == b.donGia) && (this.nhaSanXuat.equals(b.nhaSanXuat) && (this.soLuong == b.soLuong));
    }

    public abstract String loai();
    
    public abstract double thanhTien();
}