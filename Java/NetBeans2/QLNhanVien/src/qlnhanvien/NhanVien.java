package qlnhanvien;

public abstract class NhanVien {
    protected int maNV;
    protected String hoTen;
    protected int namSinh;
    protected int soNamCT;
    protected float luongCB;

    public NhanVien(int MaNV, String hoTen, int namSinh, int soNamCT, float luongCB) {
        this.maNV = MaNV;
        this.hoTen = hoTen;
        this.namSinh = namSinh;
        this.soNamCT = soNamCT;
        this.luongCB = luongCB;
    }
    
    public float layLuongCB() {
        return luongCB;
    }
    
    public void ganLuongCB(float luongCB) {
        this.luongCB = luongCB;
    }
    
    public abstract float tinhLuong();
    
    public String toString() {
        return maNV + ";" + hoTen + ";" + namSinh + ";" + soNamCT + ";" + luongCB;
    }
}