package dsnv;

public class DSNV {

    NV[] ds;
    int soNV;

    public DSNV(int soNVMax) {
        ds = new NV[soNVMax];
        soNV = 0;
    }

    public void them(NV nv) {
        if (soNV < ds.length) {
            ds[soNV++] = nv;
        }
    }

    public void lietKe() {
        for (int i = 0; i < soNV; i++) {
            ds[i].hienThi();
        }
    }

    public void lietKe(String loaiNV) {
        for (int i = 0; i < soNV; i++) {
            if (ds[i].loaiNV().equalsIgnoreCase(loaiNV)) {
                ds[i].hienThi();
            }
        }
    }

    public double tongLuong() {
        double S = 0;
        for (int i = 0; i < soNV; i++) {
            S += ds[i].layLuong();
        }
        return S;
    }

    public void dsHDDH() {
        for (int i = 0; i < soNV; i++) {
            if (ds[i].laNVHDDH()) {
                ds[i].hienThi();
            }
        }
    }
}
