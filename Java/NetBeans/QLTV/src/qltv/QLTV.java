package qltv;

public class QLTV {

    public static void main(String[] args) {
        TaiLieu[] taiLieu = new TaiLieu[6];
        taiLieu[0] = new Sach("S001", "Cuoc Song Ma", 10001,
                "Cambri Boiz", "NXB Thien Thu", 2002);
        taiLieu[1] = new Sach("S002", "Cuoc Doi Ma", 10002,
                "Domain Satan", "NXB Laibai", 2003);
        taiLieu[2] = new TapChi("TC001", "Con Nguoi Va Vat Chat", 2001,
                "Xa hoi", 156, 2021);
        taiLieu[3] = new TapChi("TC002", "Dong Tien So", 2011,
                "Tai chinh", 14, 2021);
        taiLieu[4] = new CD("CD001", "Tinh Say", 3001, 1, "Tinh yeu");
        taiLieu[5] = new CD("CD002", "Tran Anaconda", 3002, 2, "Dong vat");
        
        DSTL ds = new DSTL(50);
        for (TaiLieu taiLieuTT : taiLieu) {
            ds.them(taiLieuTT);
        }
        
        //ds.lietKe();
        //ds.lietKe("Sach");
        //ds.xem("S002");
        //ds.tim("Cuoc Song Ma", "Cambri Boiz");
        //ds.tim("Dong Tien So", "Tai chinh", 14, 2021);
        //ds.tim("Tinh Say", 1, "Tinh yeu");
    }
}
