package QLPhongHoc;

public class PhongTH extends PhongHoc {

    private static final long serialVersionUID = 1L;

    private String chuyenNganh;
    private int sucChua;

    public PhongTH(String maPhong,
            String dayNha,
            double dienTich,
            int soBongDen,
            String chuyenNganh,
            int sucChua) {

        super(maPhong, dayNha, dienTich, soBongDen);
        this.chuyenNganh = chuyenNganh;
        this.sucChua = sucChua;
    }

    public boolean datChuan() {
        return (int) (dienTich / 10) == soBongDen
                && (int) (dienTich / 1.5) == sucChua;
    }

    public String loaiPhong() {
        return "TH";
    }

    public void hienThi() {
        super.hienThi();
        if (datChuan()) {
            System.out.println("Đạt chuẩn: Có");
        } else {
            System.out.println("Đạt chuẩn: Không");
        }
    }
}
