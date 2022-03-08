package qlluonggiaovien;

public class SuDung {
    public static void main(String[] args) {
        GiaoVien[] gv = new GiaoVien[5];
        gv[0] = new GiaoVien("V", "Nam", 3, 5, 3);
        gv[1] = new GiaoVien("V", "Nam", 3, 10, 3);
        gv[2] = new GiaoVien("V", "Nam", 1, 5, 5);
        gv[3] = new GiaoVien("V", "Nam", 8, 2, 5);
        gv[4] = new GiaoVien("V", "Nam", 3, 11, 11);
        
        for (int i = 0; i < gv.length; i++) {
            System.out.println(gv[i].tinhLuong());
        }
    }
}