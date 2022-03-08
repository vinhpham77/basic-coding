package thungthu;

import java.util.Date;

public abstract class BuuPham{
    protected String ngGui;
    protected String ngNhan;
    protected Date ngayGui;

    public BuuPham() {
    }

    public BuuPham(String ngGui, String ngNhan, Date ngayGui) {
        this.ngGui = ngGui;
        this.ngNhan = ngNhan;
        this.ngayGui = ngayGui;
    }
    
    public void hienThi() {
        System.out.println("Nguoi gui: " + ngGui);
        System.out.println("Nguoi nhan: " + ngNhan);
        System.out.println("Ngay gui: " + ngayGui);
    }
    
    public abstract String loaiBP();
    public abstract short danTem();
}