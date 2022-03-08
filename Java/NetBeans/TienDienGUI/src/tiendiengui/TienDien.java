package tiendiengui;

public class TienDien {
    private int loaiDT;
    private double chiSoCu;
    private double chiSoMoi;
    private double dinhMuc;

    public TienDien(int loaiDT, double chSoCu, double chSoMoi, double dinhMuc) {
        this.loaiDT = loaiDT;
        this.chiSoCu = chSoCu;
        this.chiSoMoi = chSoMoi;
        this.dinhMuc = dinhMuc;
    }
    
    public double tinhTien() {
        final short GIA_DM_0 = 1500;
        final short GIA_DM_1 = 2000;
        final short GIA_DM_2 = 2500;
        final short GIA_VUOT_DM_0 = 2000;
        final short GIA_VUOT_DM_1 = 2500;
        final double GIA_VUOT_DM_2 = 3000;
        double tienTra = 0;
        double dienTieuThu = chiSoMoi - chiSoCu;
        boolean laVuotDM = dienTieuThu > dinhMuc;
        
        switch (loaiDT) {

            case 0 -> {
                if (laVuotDM) {
                    tienTra = dinhMuc * GIA_DM_0 
                            + (dienTieuThu - dinhMuc) * GIA_VUOT_DM_0; 
                } else {
                    tienTra = dienTieuThu * GIA_DM_0;
                }
            }
            case 1 -> {
                if (laVuotDM) {
                    tienTra = dinhMuc * GIA_DM_1 
                            + (dienTieuThu - dinhMuc) * GIA_VUOT_DM_1; 
                } else {
                    tienTra = dienTieuThu * GIA_DM_1;
                }
            }
            default -> {
                if (laVuotDM) {
                    tienTra = dinhMuc * GIA_DM_2 
                            + (dienTieuThu - dinhMuc) * GIA_VUOT_DM_2; 
                } else {
                    tienTra = dienTieuThu * GIA_DM_2;
                }
            }
        }
        
        return tienTra;
    }

    @Override
    public String toString() {
        return loaiDT + ";" + chiSoCu + ";" + chiSoMoi + ";" + dinhMuc;
    }
    
}