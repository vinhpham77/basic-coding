package hcn;

public class Diem {

    private int x;
    private int y;

    public Diem() {

    }

    public Diem(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public Diem(Diem old) {
        this.x = old.x;
        this.y = old.y;
    }

    public int layTung() {
        return this.x;
    }

    public int layHoanh() {
        return this.y;
    }

    public double khoangCach(Diem p) {
        return Math.sqrt((p.x - this.x) * (p.x - this.x) + (p.y - this.y) * (p.y - this.y));
    }

    public String toString() {
        return "(" + this.x + "," + this.y + ")";
    }
}
