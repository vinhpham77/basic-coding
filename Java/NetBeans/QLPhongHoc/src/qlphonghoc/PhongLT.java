package QLPhongHoc;

public class PhongLT extends PhongHoc {

    private static final long serialVersionUID = 1L;

    private boolean coMayChieu;

    public PhongLT(String maPhong,
            String dayNha,
            double dienTich,
            int soBongDen,
            boolean coMayChieu) {
        
        super(maPhong, dayNha, dienTich, soBongDen);
        this.coMayChieu = coMayChieu;
    }

    public boolean datChuan() {
        return coMayChieu && (int) (dienTich / 10) == soBongDen;
    }

    public String loaiPhong() {
        return "LT";
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
