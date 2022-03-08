package tudien;

public class Nghia {

    private String nghia;
    private String phanLoai;
    private String viDu;

    public Nghia(String nghia, String phanLoai, String viDu) {
        this.nghia = nghia;
        this.phanLoai = phanLoai;
        this.viDu = viDu;
    }
    
    public void hienThi() {
        System.out.println("Nghĩa: " + nghia);
        System.out.println("Loại: " + phanLoai);
        System.out.println("Ví dụ: " + viDu);
    }
    
    public String toString() {
        return nghia + "-" + phanLoai + "-" + viDu;
    }
}