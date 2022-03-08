package qltv;

public class TaiLieu {
    protected String maTL;
    protected String tenTL;
    protected int viTri;
    
    public TaiLieu(String maTL, String tenTL, int viTri) {
        this.maTL = maTL;
        this.tenTL = tenTL;
        this.viTri = viTri;
    }
    
    public void hienThi() {
        System.out.println("Ma TL: " + maTL);
        System.out.println("Ten TL: " + tenTL);
        System.out.println("Vi tri: " + viTri);
    }  
}