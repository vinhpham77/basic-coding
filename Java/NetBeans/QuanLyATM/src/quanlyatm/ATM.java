package quanlyatm;

public class ATM {

    private String soTK;
    private double soDu;

    public ATM(String stk, double sd) {
        this.soTK = stk;
        this.soDu = sd;
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

    public void hienThi() {
        System.out.println(this.toString());
    }

    public void napTien(double st) {
        if (st > 0) {
            this.soDu += st;
        }
    }

    public boolean rutTien(double st) {
        if (st > 0 && this.soDu - st >= 50) {
            this.soDu -= st;
            return true;
        }
        return false;
    }

    public boolean chuyenTien(ATM ngNhan, double st) {
        if (this.rutTien(st)) {
            ngNhan.napTien(st);
            return true;
        }
        return false;
    }

}
