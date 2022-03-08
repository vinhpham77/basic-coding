package qltv;

public class Sach extends TaiLieu{
    protected String tacGia;
    protected String nhaXB;
    protected int namXB;
    
    public Sach(String maTL,
                String tenTL,
                int viTri,
                String tacGia,
                String nhaXB,
                int namXB) {
        super(maTL, tenTL, viTri);
        this.tacGia = tacGia;
        this.nhaXB = nhaXB;
        this.namXB = namXB;
    }
    
    public void hienThi() {
        super.hienThi();
        System.out.println("Tac gia: " + tacGia);
        System.out.println("Nha xuat ban: " + nhaXB);
        System.out.println("Nam xuat ban: " + namXB);
    }
}