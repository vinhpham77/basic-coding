package Exe_DSSV;

public class Exe_DSSV {

    public static void main(String[] args) {
        DSSV ds = new DSSV();
        SV s;
        s = new SVSP("Nguyen Van A", 1987, 7.0, "Truong X", 7.0);
        ds.them(s);
        s = new SVTH("Le Thi B", 1987, 7.5, "Java", 7.0);
        ds.them(s);
        s = new SVTH("Tran Van Tam", 1991, 4.5, "PHP", 7.5);
        ds.them(s);
        s = new SVSP("Le Hoang", 2000, 6.0, "QNU", 6.0);
        ds.them(s);
        s = new SVSP("Nguyen Van A", 1987, 7.0, "Truong X", 7.0);
        ds.them(s);
        
        ds.lietKe();

    }
}
