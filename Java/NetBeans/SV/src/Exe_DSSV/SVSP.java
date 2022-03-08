package Exe_DSSV;

public class SVSP extends SV {

    protected String noiTT;
    protected double diemTT;

    public SVSP(String hoTen, int namSinh, double dtb, String noiTT, double diemTT) {
        super(hoTen, namSinh, dtb);
        this.noiTT = noiTT;
        this.diemTT = diemTT;
    }

    public void hienThi() {
        super.hienThi();
        System.out.println("Noi thuc tap: " + noiTT);
        System.out.println("Diem thuc tap: " + diemTT);
    }

    public String loaiSV() {
        return "SP";
    }

    public boolean equals(Object sv) {
        if (sv != null && sv instanceof SVSP b) {
            return super.equals(b)
                    && this.noiTT.equals(b.noiTT)
                    && this.diemTT == b.diemTT;
        }
        return false;
    }

    public String toString() {
        return super.toString() + "\n"
                + "Noi thuc tap: " + noiTT + "\n"
                + "Diem thuc tap: " + diemTT;
    }

    public boolean duocTN() {
        return dtb >= 5.0f && diemTT >= 7.0f;
    }
}
