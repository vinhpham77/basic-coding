package atm;

public class Exe_ATM {

    public static void main(String[] args) {
        ATM[] KH = new ATM[5];
        KH[0] = new ATM("1111111", 100);
        KH[1] = new ATM("2222222", 500);
        KH[2] = new ATM("3333333", 750);
        KH[3] = new ATM("4444444", 235);
        KH[4] = new ATM("5555555", 12500);

        KH[0].napTien(1000);
        KH[0].chuyenTien(KH[1], 500);
        KH[1].rutTien(200);
        for (ATM khHang : KH) {
            System.out.println(khHang.toString());
        }
        double tongTien = 0;
        for (ATM khHang : KH) {
            tongTien += khHang.laySoDu();
        }
        System.out.println("Tong so tien cua cac khach hang: " + tongTien);
    }
}
