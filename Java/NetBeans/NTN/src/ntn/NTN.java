package ntn;

public class NTN {

    private int ngay;
    private int thang;
    private int nam;

    public NTN() {
        this.ngay = 1;
        this.thang = 1;
        this.nam = 2000;
    }

    public NTN(int nam) {
        this.nam = nam;
    }

    public NTN(int ngay, int thang, int nam) {
        this.ngay = ngay;
        this.thang = thang;
        this.nam = nam;
    }

    public NTN(NTN ntn) {
        this.ngay = ntn.ngay;
        this.thang = ntn.thang;
        this.nam = ntn.nam;
    }

    public void datNgay(int ngay) {
        if (ngay > 0 && ngay <= soNgay(thang, nam)) {
            this.ngay = ngay;
        }
    }

    public int layNgay() {
        return this.ngay;
    }

    public void datThang(int thang) {
        this.thang = thang;
    }

    public int layThang() {
        return this.thang;
    }

    public void datNam(int nam) {
        this.nam = nam;
    }

    public int layNam() {
        return this.nam;
    }

    private int soNgay(int thang, int nam) {
        int soNgay = 0;
        switch (thang) {
            case 1, 3, 5, 7, 8, 10, 12 -> soNgay = 31;
            case 4, 6, 9, 11 -> soNgay = 30;
            case 2 -> {
                if (nam % 4 == 0 && nam % 100 != 0) {
                    soNgay = 29;
                } else {
                    soNgay = 28;
                }
            }
        }
        return soNgay;
    }
    
    private NTN cong1Ngay() {
        this.ngay += 1;
        return this;
    }
    
    private NTN tru1Ngay() {
        this.ngay -= 1;
        return this;
    }
    
    public NTN cong(int n) {
        this.ngay += n;   
        return this;
    }
    
    public NTN tru(int n) {
        this.ngay
        return this;
    }
}
