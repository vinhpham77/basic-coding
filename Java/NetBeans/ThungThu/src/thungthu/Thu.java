package thungthu;

import java.util.Date;

public class Thu extends BuuPham{
    private String loaiThu;

    public Thu() {
    }

    public Thu(String loaiThu) {
        this.loaiThu = loaiThu;
    }

    public Thu(String ngGui, String ngNhan, Date ngayGui, String loaiThu) {
        super(ngGui, ngNhan, ngayGui);
        this.loaiThu = loaiThu;
    }

    @Override
    public short danTem() {
        if (loaiThu.equalsIgnoreCase("Thu dam bao")) {
            return 2000;
        } else {
            return 800;
        }
    }

    @Override
    public void hienThi() {
        super.hienThi();
        System.out.println("Loai thu: " + loaiThu);
    }

    @Override
    public String loaiBP() {
        return loaiThu;
    }
}