package tienthue;

public class TienThue {
    private String hoTen;
    private double thuNhap;
    private boolean laThuNhapTX;

    public TienThue() {
    }

    public TienThue(String hoTen, double thuNhap, boolean laThuNhapTX) {
        this.hoTen = hoTen;
        this.thuNhap = thuNhap;
        this.laThuNhapTX = laThuNhapTX;
    }

    public double tinhThue() {
        final int MUC_AP_THUE_TX = 5000000;
        final double THUE_TX = 10/100.0;
        final double THUE_KHONG_TX = 5/100.0;
        double tienThue;
        
        if (laThuNhapTX) {
            if (thuNhap > MUC_AP_THUE_TX) {
                tienThue = (thuNhap - MUC_AP_THUE_TX) * THUE_TX;
            } else {
                tienThue = 0;
            }
        } else {
            tienThue = thuNhap * THUE_KHONG_TX;
        }
        
        return tienThue;
    }
    
    public String toString() {
        return hoTen + ";" + thuNhap + ";" + laThuNhapTX; 
    }
}