package hoadon;

import java.io.Serializable;

public abstract class MatHang implements Serializable {
    protected String tenHang;
    protected double donGia;

    public MatHang(String tenHang, double donGia) {
        this.tenHang = tenHang;
        this.donGia = donGia;
    }
    
    public abstract double thue();
    
    public String toString() {
        return tenHang + ";" + donGia;
    }
}