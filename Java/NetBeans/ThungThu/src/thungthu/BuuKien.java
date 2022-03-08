package thungthu;

import java.util.Date;

public class BuuKien extends BuuPham{

    public BuuKien(String ngGui, String ngNhan, Date ngayGui) {
        super(ngGui, ngNhan, ngayGui);
    }
    
    @Override
    public short danTem() {
        return 5000;
    }

    @Override
    public String loaiBP() {
        return "Buu kien";
    }
}