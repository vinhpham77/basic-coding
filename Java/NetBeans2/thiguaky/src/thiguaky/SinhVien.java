package thiguaky;

public class SinhVien {
    
    private String hoTen;
    private String nganhHoc;
    private int soTinChi;

    public SinhVien() {
    }

    public SinhVien(String hoTen, String nganhHoc, int soTinChi) {
        this.hoTen = hoTen;
        this.nganhHoc = nganhHoc;
        this.soTinChi = soTinChi;
    }

    public double hocPhi() {
        switch (nganhHoc) {
            case "102" -> {
                return 200000 * soTinChi;
            }
            case "103" -> {
                return 220000 * soTinChi;
            }
            default -> {
                return 0;
            }
        }
    }
    
    public void hienThi() {
        System.out.println("Ho ten: " + hoTen);
        System.out.println("Nganh hoc: " + nganhHoc);
        System.out.println("So tin chi: " + soTinChi);
        System.out.println("Hoc phi: " + hocPhi());
    }
}