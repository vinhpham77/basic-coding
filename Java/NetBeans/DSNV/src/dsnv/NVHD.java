package dsnv;

public class NVHD extends NV{
    protected double luong;
    protected String loaiHD;
    
    public NVHD(String hoTen, int phong, double luong, String loaiHD) {
        super(hoTen, phong);
        this.luong = luong;
        this.loaiHD = loaiHD;
    }
    
    public void hienThi() {
        super.hienThi();
        System.out.println("Luong(trieu VND): " + luong);
        System.out.println("Loai hop dong: " + loaiHD);
    }
    
    public String loaiNV() {
        return "HD";
    }
    
    public String layLoaiHD() {
        return loaiHD;
    }
    
    public double layLuong() {
        return luong;
    }
    
    public boolean laNVHDDH() {
        return loaiHD.equalsIgnoreCase("DH");
    }
}