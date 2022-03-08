package thuviensach;

import java.util.*;

public class DSSach {

    private Vector ds;

    public DSSach() {
        ds = new Vector();
    }

    public void them(Object a) {
        if (!ds.contains(a)) {
            ds.addElement(a);
        }
    }

    public void hienThi() {
        Enumeration e = ds.elements();
        while (e.hasMoreElements()) {
            System.out.println(e.nextElement());
        }
    }

    public int tinh(String loaiSach) {
        int tong = 0;

        for (int i = 0; i < ds.size(); i++) {
            Sach elementAt = (Sach) ds.elementAt(i);
            if (elementAt.loai().equalsIgnoreCase(loaiSach)) {
                tong += elementAt.thanhTien();
            }
        }
        return tong;
    }

    public void inX(String x) {
        for (int i = 0; i < ds.size(); i++) {
            if (((Sach) ds.elementAt(i)).getNhaSanXuat().equals(x)) {
                System.out.println(ds.elementAt(i).toString());
            }
        }
    }
}
