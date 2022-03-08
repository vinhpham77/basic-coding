package thiguaky;

public class DSSV {
    
    private SinhVien[] dssv;
    private int soSV;

    public DSSV(int soSV) {
        dssv = new SinhVien[soSV];
        this.soSV = 0;
    }
    
    public void them(SinhVien sv) {
        if (soSV < dssv.length) {
            dssv[soSV++] = sv;
        }
    } 
    
    public void hienThi() {
        for (int i = 0; i < soSV; i++) {
            dssv[i].hienThi();
            System.out.println("");
        }
    }
    
    public double tongHocPhi() {
        double s = 0;
        
        for (int i = 0; i < soSV; i++) {
            s += dssv[i].hocPhi();
        }
        
        return s;
    }
    
    public void dongHPCaoNhat() {
        double max = dssv[0].hocPhi();
        
        for (int i = 1; i < soSV; i++) { 
            double value = dssv[i].hocPhi();
            
            if (max <= value) {
                max = value;
            }
        }
        
        for (int i = 0; i < soSV; i++) {
            if (dssv[i].hocPhi() == max) {
                dssv[i].hienThi();
                System.out.println("");
            }
        }
    }  
}