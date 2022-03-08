package dsnv;

public class Exe_DSNV {

    public static void main(String[] args) {
        NV[] nv = new NV[5];
        nv[0] = new NVBC("Nguyen Van Mach", 2, 1.7f, (byte) 12);
        nv[1] = new NVBC("Nguyen Van Luong", 2, 2.0f, (byte) 17);
        nv[2] = new NVHD("Le Thi Mach", 1, 8, "NH");
        nv[3] = new NVHD("Nguyen Quang Mach", 1, 14, "DH");
        nv[4] = new NVHD("Nguyen Hoang Mach", 1, 14, "DH");

        DSNV ds = new DSNV(10);
        for (int i = 0; i < 5; i++) {
            ds.them(nv[i]);
        }

        ds.lietKe();
        ds.lietKe("HD");
        ds.lietKe("BC");
        System.out.println("Tong luong(trieu VND): " + ds.tongLuong());
        ds.dsHDDH();
    }
}
