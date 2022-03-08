package dsnv;

public class NVBC extends NV {
    protected float hsLuong;
    protected byte soNamCT;
    
    public NVBC(String hoTen, int phong, float hsLuong, byte soNamCT) {
        super(hoTen, phong);
        this.hsLuong = hsLuong;
        this.soNamCT = soNamCT;
    }
    
    public void hienThi() {
        super.hienThi();
        System.out.println("He so luong(trieu VND): " + hsLuong);
        System.out.println("So nam cong tac: " + soNamCT);
    }
    
    public String loaiNV() {
        return "BC";
    }
    
    public double layLuong() {
        return hsLuong * soNamCT;
    }
}