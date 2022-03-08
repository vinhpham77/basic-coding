package hcn;

public class HCN {

    private Diem d1;
    private Diem d2;

    public HCN() {

    }

    public HCN(Diem d1, Diem d2) {
        this.d1 = new Diem(d1);
        this.d2 = new Diem(d2);
    }

    public HCN(HCN old) {
        this.d1 = new Diem(old.d1);
        this.d2 = new Diem(old.d2);
    }

    public double chuVi() {
        Diem diemVG = new Diem(d1.layTung(), d2.layHoanh());
        double chieu1 = d1.khoangCach(diemVG);
        double chieu2 = d2.khoangCach(diemVG);
        return (chieu1 + chieu2) * 2;
    }

    public double dienTich() {
        Diem diemVG = new Diem(d1.layTung(), d2.layHoanh());
        double chieu1 = d1.khoangCach(diemVG);
        double chieu2 = d2.khoangCach(diemVG);
        return chieu1 * chieu2;
    }

    public String toString() {
        return "[(" + d1.layTung() + "," + d1.layHoanh() + "), ("
                + d2.layTung() + "," + d2.layHoanh() + ")]";
    }
}
