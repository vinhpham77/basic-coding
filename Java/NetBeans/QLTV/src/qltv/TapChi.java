package qltv;

public class TapChi extends TaiLieu{
    protected String chuyenNganh;
    protected int so;
    protected int nam;
    
    public TapChi(String maTL,
                String tenTL,
                int viTri,
                String chuyenNganh,
                int so,
                int nam) {
        super(maTL, tenTL, viTri);
        this.chuyenNganh = chuyenNganh;
        this.so = so;
        this.nam = nam;
    }
    
    public void hienThi() {
        super.hienThi();
        System.out.println("Chuyen nganh " + chuyenNganh);
        System.out.println("So: " + so);
        System.out.println("Nam: " + nam);
    }
}