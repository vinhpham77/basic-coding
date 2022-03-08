package thuviensach;

import java.util.Scanner;

public class SachThamKhao extends Sach {

    private double thue;

    public SachThamKhao() {
    }

    public SachThamKhao(String maSach, String ngayNhap, double donGia, int soLuong, String nhaSanXuat, double thue) {
        super(maSach, ngayNhap, donGia, soLuong, nhaSanXuat);
        this.thue = thue;
    }

    public double getThue() {
        return thue;
    }

    public void setThue(double thue) {
        this.thue = thue;
    }

    public double thanhTien() {
        return soLuong * donGia + thue;
    }

    public void nhapSach() {
        super.nhapSach();
        Scanner scanner = new Scanner(System.in);
        System.out.print("Nhap thue: ");
        thue = scanner.nextDouble();
    }

    public String toString() {
        return super.toString() + 
               "Thue: " + thue + "\n";
    }

    public boolean equals(Object hp) {
        if (hp instanceof SachThamKhao b) {
            return super.equals(hp) && (thue == b.thue);
        }
        return false;
    }

    public String loai() {
        return "Sach tham khao";
    }
}