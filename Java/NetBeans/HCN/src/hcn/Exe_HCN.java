package hcn;

public class Exe_HCN {

    public static void main(String[] args) {
        Diem[] diem = new Diem[10];
        diem[0] = new Diem(4, -3);
        diem[1] = new Diem(1, -5);
        diem[2] = new Diem(0, 3);
        diem[3] = new Diem(9, 2);
        diem[4] = new Diem(-5, 7);
        diem[5] = new Diem(1, -1);
        diem[6] = new Diem(6, 0);
        diem[7] = new Diem(4, 2);
        diem[8] = new Diem(-6, 8);
        diem[9] = new Diem(-2, -1);

        HCN[] hcn = new HCN[5];
        hcn[0] = new HCN(diem[0], diem[1]);
        hcn[1] = new HCN(diem[2], diem[3]);
        hcn[2] = new HCN(diem[4], diem[5]);
        hcn[3] = new HCN(diem[6], diem[7]);
        hcn[4] = new HCN(diem[8], diem[9]);

        System.out.format("%-20s %-7s %-5s\n",
                "HCN",
                "CHU VI",
                "DIEN TICH");
        for (HCN hcnTT : hcn) {
            System.out.format("%-20s %-7s %-5s\n",
                    hcnTT,
                    hcnTT.chuVi(),
                    hcnTT.dienTich());  
        }
//        for (byte i = 0; i < hcn.length; i++) {
//            System.out.println(hcn[i]);
//            System.out.println("Chu vi: " + hcn[i].chuVi());
//            System.out.println("Dien tich: " + hcn[i].dienTich() + "\n");
//        }
        for (byte i = 0; i < hcn.length - 1; i++) {
            for (byte j = (byte) (i + 1); j < hcn.length; j++) {
                if (hcn[i].dienTich() > hcn[j].dienTich()) {
                    HCN temp;
                    temp = new HCN(hcn[i]);
                    hcn[i] = new HCN(hcn[j]);
                    hcn[j] = new HCN(temp);
                }
            }
        }
        System.out.format("\n%-20s %-5s\n",
                "HCN",
                "DIEN TICH");
        for (HCN hcnTT2 : hcn) {
            System.out.format("%-20s %-5s\n",
                    hcnTT2,
                    hcnTT2.dienTich());
        }
    }
}
