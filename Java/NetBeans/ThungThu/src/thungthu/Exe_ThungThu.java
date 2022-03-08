package thungthu;

import java.util.Date;

public class Exe_ThungThu {
    
    public static void main(String[] args) {
        Date[] dsDate = new Date[5];
        dsDate[0] = new Date(121, 11, 12);
        dsDate[1] = new Date(121, 11, 13);
        dsDate[2] = new Date(121, 11, 14);
        dsDate[3] = new Date(121, 11, 15);
        dsDate[4] = new Date(121, 11, 16);
        
        BuuPham[] dsBuuPham = new BuuPham[5];
        dsBuuPham[0] = new Thu("Pham Trung Toan", "Pham Trung Kien", dsDate[0],
                        "Thu thuong");
        dsBuuPham[1] = new Thu("Pham Trung Truc", "Pham Trung Thu", dsDate[1],
                        "Thu thuong");
        dsBuuPham[2] = new Thu("Pham Trung Tin", "Pham Trung Diep", dsDate[2],
                        "Thu dam bao");
        dsBuuPham[3] = new BuuKien("Pham Trung Trung", "Pham Trung Anh",
                        dsDate[3]);
        dsBuuPham[4] = new BuuKien("Pham Trung Minh", "Pham Trung Sinh",
                        dsDate[4]);
        
        ThungThu thungThu = new ThungThu((byte) 100);
        for (int i = 0; i < 5; i++) {
            thungThu.them(dsBuuPham[i]);
        }
        
        //thungThu.lietKe();
        //thungThu.lietKe("Buu kien");
        //System.out.println("Tong tien: " + thungThu.tongTien());
        //System.out.println("Tong tien: " + thungThu.tongTien("Thu thuong"));
    }
}