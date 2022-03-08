package qltv;

public class DSTL {

    private TaiLieu[] ds;
    private int soTL;

    public DSTL(int soTL) {
        ds = new TaiLieu[soTL];
        this.soTL = 0;
    }

    public void them(TaiLieu tl) {
        ds[soTL++] = tl;
    }

    public void lietKe() {
        for (int i = 0; i < soTL; i++) {
            ds[i].hienThi();
            System.out.println("");
        }
    }

    public void lietKe(String taiLieu) {
        if (taiLieu.equalsIgnoreCase("Sach")) {
            for (int i = 0; i < soTL; i++) {
                TaiLieu d = ds[i];
                if (d instanceof Sach) {
                    d.hienThi();
                    System.out.println("");
                }
            }
        } else if (taiLieu.equalsIgnoreCase("CD")) {
            for (int i = 0; i < soTL; i++) {
                TaiLieu d = ds[i];
                if (d instanceof CD) {
                    d.hienThi();
                    System.out.println("");
                }
            }
        } else if (taiLieu.equalsIgnoreCase("TapChi")) {
            for (int i = 0; i < soTL; i++) {
                TaiLieu d = ds[i];
                if (d instanceof TapChi) {
                    d.hienThi();
                    System.out.println("qltv.DSTL.lietKe()");
                }
            }
        }
    }

    public void xem(String maTL) {
        int i;
        for (i = 0; i < soTL && !ds[i].maTL.equals(maTL); i++);
            ds[i].hienThi();
    }

    public void tim(String ten, String tacGia) {
        for (int i = 0; i < soTL; i++) {
            if (ds[i] instanceof Sach d) {
                if (d.tenTL.equals(ten) && d.tacGia.equals(tacGia)) {
                    d.hienThi();
                    break;
                }
            }
        }
    }

    public void tim(String ten, String chuyenNganh, int so, int nam) {
        for (int i = 0; i < soTL; i++) {
            if (ds[i] instanceof TapChi d) {
                if (d.tenTL.equals(ten) && d.chuyenNganh.equals(chuyenNganh)
                        && d.so == so && d.nam == nam) {
                    d.hienThi();
                    break;
                }
            }
        }
    }

    public void tim(String ten, int sTT, String noiDung) {
        for (int i = 0; i < soTL; i++) {
            if (ds[i] instanceof CD d) {
                if (d.tenTL.equals(ten) && d.soTT == sTT 
                        && d.noiDung.equals(noiDung)) {
                    d.hienThi();
                    break;
                }
            }
        }
    }
}
