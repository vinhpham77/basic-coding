package Exe_DSSV;

public class SVTH extends SV{

    protected String tenDT;
    protected double diemDT;

    public SVTH(String hoTen, int namSinh, double dtb, String tenDT, double diemDT) {
        super(hoTen, namSinh, dtb);
        this.tenDT = tenDT;
        this.diemDT = diemDT;
    }
    
    public void hienThi() {
        super.hienThi();
        System.out.println("Ten dao tao: " + tenDT);
        System.out.println("Diem dao tao: " + diemDT);
    }
    
    public String loaiSV() {
        return "TH";
    }
    
    public boolean equals(Object sv) {
        if (sv != null && sv instanceof SVTH b) {
            return super.equals(b)
                    && this.tenDT.equals(b.tenDT)
                    && diemDT == b.diemDT;
        }
        return false;
    }
    
    public String toString() {
        return super.toString() + "\n" +
               "Ten dao tao: " + tenDT + "\n" +
               "Diem dao tao: " + diemDT;
    }
    
    public boolean duocTN() {
        return dtb >= 5.0f && diemDT >= 7.0f;
    }
    
    
}
