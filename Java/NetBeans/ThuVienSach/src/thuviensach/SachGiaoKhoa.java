package thuviensach;

import java.util.Scanner;

public class SachGiaoKhoa extends Sach {

    protected String tinhTrang;

    public SachGiaoKhoa() {
    }

    public SachGiaoKhoa(String maSach, String ngayNhap, double donGia, int soLuong, String nhaSanXuat, String tinhTrang) {
        super(maSach, ngayNhap, donGia, soLuong, nhaSanXuat);
        this.tinhTrang = tinhTrang;
    }

    public String getTinhTrang() {
        return tinhTrang;
    }

    public void setTinhTrang(String tinhTrang) {
        this.tinhTrang = tinhTrang;
    }

    public String tinhTrangSach() {
        return tinhTrang;
    }

    public double thanhTien() {
        if (tinhTrang.equals("moi")) {
            return soLuong * donGia;
        }
        return soLuong * donGia * 0.5;
    }

    public void nhapSach() {
        super.nhapSach();
        System.out.print("Nhap tinh trang sach : ");
        Scanner sc = new Scanner(System.in);
        tinhTrang = sc.nextLine();
    }

    public String toString() {
        return super.toString() +
               "Tinh trang: " + tinhTrangSach() + "\n";
    }

    public boolean equals(Object hp) {
        if (hp instanceof SachGiaoKhoa b) {
            return super.equals(hp) && (tinhTrang.equals(b.tinhTrang));
        }
        return false;
    }

    public String loai() {
        return "Sach giao khoa";
    }
}
