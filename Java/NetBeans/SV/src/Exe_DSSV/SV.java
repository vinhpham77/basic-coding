package Exe_DSSV;

public abstract class SV {

    protected String hoTen;
    protected int namSinh;
    protected double dtb;

    public SV(String hoTen, int namSinh, double dtb) {
        this.hoTen = hoTen;
        this.namSinh = namSinh;
        this.dtb = dtb;
    }

    public void hienThi() {
        System.out.println(this);
    }

    public boolean equals(Object sv) {
        if (sv != null && sv instanceof SV b) {
            return this.hoTen.equals(b.hoTen)
                    && this.namSinh == b.namSinh
                    && this.dtb == b.dtb;
        }
        return false;
    }

    public String toString() {
        return "Ho ten: " + hoTen + "\n"
                + "Nam sinh: " + namSinh + "\n"
                + "Diem trung binh: " + dtb;
    }

    public abstract String loaiSV();

    public abstract boolean duocTN();
}
