package thungthu;

public class ThungThu {
    private BuuPham[] dsBuuPham;
    private byte soLuong;

    public ThungThu() {
    }

    public ThungThu(byte soLuong) {
        this.dsBuuPham = new BuuPham[soLuong];
        this.soLuong = 0;
    }
    
    public void them(BuuPham bp) {
        if (soLuong < dsBuuPham.length) {
            dsBuuPham[soLuong++] = bp;
        }
    }

    public void lietKe() {
        for (int i = 0; i < soLuong; i++) {
            dsBuuPham[i].hienThi();
            System.out.println("");
        }
    }
    
    public void lietKe(String loaiBP) {
        for (int i = 0; i < soLuong; i++) {
            if (dsBuuPham[i].loaiBP().equalsIgnoreCase(loaiBP)) {
                dsBuuPham[i].hienThi();
                System.out.println("");
            }
        }
    }
    
    public int tongTien() {
        int s = 0;
        for (int i = 0; i < soLuong; i++) {
            s += dsBuuPham[i].danTem();
        }
        return s;
    }
    
    public int tongTien(String loaiBP) {
        int s = 0;
        for (int i = 0; i < soLuong; i++) {
            if (dsBuuPham[i].loaiBP().equalsIgnoreCase(loaiBP)) {
                s += dsBuuPham[i].danTem();      
            }
        }
        return s;
    }
}