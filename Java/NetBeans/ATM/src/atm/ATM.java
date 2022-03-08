package atm;

public class ATM {

    private final String soTK;
    private double soDu;

    public ATM(String soTK, double soDu) {
        this.soTK = soTK;
        this.soDu = soDu;
    }

    public String laySTK() {
        return this.soTK;
    }

    public double laySoDu() {
        return this.soDu;
    }

    public String toString() {
        return "STK: " + this.soTK + " co so du la: " + this.soDu;
    }
    
    public void napTien(double soTien) {
        if (soTien > 0) {
            this.soDu += soTien;
        }
    }
    
    public boolean rutTien(double soTien) {
        if (soTien > 0 && this.soDu >= soTien) {
            this.soDu -= soTien;
            return true;
        }
        return false;
    }
    
    public boolean chuyenTien(ATM ngNhan, double soTien) {
        if (this.rutTien(soTien)) {
            ngNhan.napTien(soTien);
            return true;
        }
        return false;
    }
}
