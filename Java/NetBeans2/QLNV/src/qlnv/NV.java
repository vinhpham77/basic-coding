package qlnv;

import java.io.Serializable;

public abstract class NV implements Serializable {

    protected int maNV;
    protected String hoTen;
    protected int namSinh;
    protected int soNamCT;
    protected float luongCB;

    public NV(int maNV, String hoTen, int namSinh, int soNamCT, float luongCB) {
        this.maNV = maNV;
        this.hoTen = hoTen;
        this.namSinh = namSinh;
        this.soNamCT = soNamCT;
        this.luongCB = luongCB;
    }

    public float layLuongCB() {
        return luongCB;
    }

    public void ganLuongCB(float luongCB) {
        this.luongCB = luongCB;
    }

    public abstract float tinhLuong();

    public abstract String loaiNV();

    public String toString() {
        return maNV + ";" + hoTen + ";" + namSinh + ";" + soNamCT + ";" + luongCB;
    }

    public boolean equals(Object obj) {
        if (obj instanceof NV) {
            NV nv = (NV) obj;
            if (maNV == nv.maNV && hoTen.equals(nv.hoTen) && namSinh == nv.namSinh && soNamCT == nv.soNamCT && luongCB == nv.luongCB) {
                return true;
            }
        }

        return false;
    }
}
