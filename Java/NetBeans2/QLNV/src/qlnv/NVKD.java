package qlnv;

public class NVKD extends NV {

    private float doanhThu;

    public NVKD(int maNV, String hoTen, int namSinh, int soNamCT, float luongCB, float doanhThu) {
        super(maNV, hoTen, namSinh, soNamCT, luongCB);
        this.doanhThu = doanhThu;
    }

    public float tinhLuong() {
        float phanTramHH;

        if (doanhThu < 2000000) {
            phanTramHH = 0.02f;
        } else if (doanhThu < 5000000) {
            phanTramHH = 0.05f;
        } else {
            phanTramHH = 0.07f;
        }

        return luongCB + doanhThu * phanTramHH;
    }

    public String loaiNV() {
        return "KD";
    }

    public String toString() {
        return super.toString() + ";" + doanhThu;
    }

    public boolean equals(Object obj) {
        if (obj instanceof NVKD) {
            NVKD nvkd = (NVKD) obj;

            if (super.equals(nvkd) && doanhThu == nvkd.doanhThu) {
                return true;
            }
        }

        return false;
    }
}
