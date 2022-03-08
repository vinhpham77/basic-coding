package QLPhongHoc;

import java.io.Serializable;

public abstract class PhongHoc implements Serializable {

    private static final long serialVersionUID = 1L;

    protected String maPhong;
    protected String dayNha;
    protected double dienTich;
    protected int soBongDen;

    public PhongHoc(String maPhong,
            String dayNha,
            double dienTich,
            int soBongDen) {

        this.maPhong = maPhong;
        this.dayNha = dayNha;
        this.dienTich = dienTich;
        this.soBongDen = soBongDen;
    }

    public double layDienTich() {
        return dienTich;
    }

    public int laySoBongDen() {
        return soBongDen;
    }

    public abstract boolean datChuan();

    public abstract String loaiPhong();

    public void hienThi() {
        System.out.println("Mã phòng: " + maPhong);
        System.out.println("Dãy nhà: " + dayNha);
        System.out.println("Diện tích: " + dienTich);
        System.out.println("Số bóng đèn: " + soBongDen);
    }
}
