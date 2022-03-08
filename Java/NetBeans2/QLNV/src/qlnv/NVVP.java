package qlnv;

public class NVVP extends NV {

    private float heSoLuong;

    public NVVP(int maNV, String hoTen, int namSinh, int soNamCT, float luongCB, float heSoLuong) {
        super(maNV, hoTen, namSinh, soNamCT, luongCB);
        this.heSoLuong = heSoLuong;
    }

    public float tinhLuong() {
        float phuCap;

        if (soNamCT < 10) {
            phuCap = luongCB;
        } else {
            phuCap = 1.2f * luongCB;
        }

        return heSoLuong * luongCB + phuCap;
    }

    public String loaiNV() {
        return "VP";
    }

    public String toString() {
        return super.toString() + ";" + heSoLuong;
    }

    public boolean equals(Object obj) {
        if (obj instanceof NVVP) {
            NVVP nvvp = (NVVP) obj;

            if (super.equals(nvvp) && heSoLuong == nvvp.heSoLuong) {
                return true;
            }
        }

        return false;
    }
}
