package qltv;

public class CD extends TaiLieu{
    protected int soTT;
    protected String noiDung;
    
    public CD(String maTL, String tenTL, int viTri, int soTT, String noiDung) {
        super(maTL, tenTL, viTri);
        this.soTT = soTT;
        this.noiDung = noiDung;
    }
    
    public void hienThi() {
        super.hienThi();
        System.out.println("So thu tu: " + soTT);
        System.out.println("Noi dung: " + noiDung);
    }
}