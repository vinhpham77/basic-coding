package dsnv;

public abstract class NV {
    protected String hoTen;
    protected int phong;
    
    public NV(String hoTen, int phong) {
        this.hoTen = hoTen;
        this.phong = phong;
    }
    
    public void hienThi() {
        System.out.println("Ho ten: " + hoTen);
        System.out.println("Phong: " + phong);
    }

    public abstract String loaiNV();
    
    public abstract double layLuong();
    
    public boolean laNVHDDH() {
        return false;
    }
}