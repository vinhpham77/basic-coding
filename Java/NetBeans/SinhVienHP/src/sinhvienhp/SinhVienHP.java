package sinhvienhp;

public class SinhVienHP {
    private String hoTen;
    private int nganh;
    private int doiTuong;
    private int soTCHL;

    public SinhVienHP(String hoTen, int nganh, int doiTuong, int soTCHL) {
        this.hoTen = hoTen;
        this.nganh = nganh;
        this.doiTuong = doiTuong;
        this.soTCHL = soTCHL;
    }
    
    public double hocPhiHK() {
        double hocPhiGoc;
        double tiLeGiamHP;
        
        switch (nganh) {
            case 102: {
                hocPhiGoc = 3000000;
                break;
            }
            case 101: {
                hocPhiGoc = 2750000;
                break;
            }
            default: {
                hocPhiGoc = 0;
            }
        }
        switch (doiTuong) {
            case 1: {
                tiLeGiamHP = 1;
                break;
            }
            case 2: {
                tiLeGiamHP = 0.7;
                break;
            }
            case 3: {
                tiLeGiamHP = 0.5;
                break;
            }
            default: {
                tiLeGiamHP = 0;
            }
        }
        
        return hocPhiGoc - hocPhiGoc * tiLeGiamHP;
    }
    
    public double hocPhiHL() {
        double hocPhiHL = 0;
        
        if (nganh == 101 || nganh == 103) {
            hocPhiHL = 200000 * soTCHL;
        } else if (nganh == 102) {
            hocPhiHL = 225000 * soTCHL;
        }
        
        return hocPhiHL;
    }
    
    public double hocPhiTong() {
        return hocPhiHK() + hocPhiHL();
    }
}