package qlnv;

public class SuDung {

    public static void main(String[] args) {
        //Tạo danh sách nhân viên
        NV nv;
        DSNV dsnv = new DSNV();

        nv = new NVKD(100, "Nguyen Van A", 2002, 10, 3000000, 4500000);
        dsnv.them(nv);
        nv = new NVKD(101, "Nguyen Van B", 2001, 5, 2000000, 500000);
        dsnv.them(nv);
        nv = new NVKD(102, "Nguyen Van C", 1999, 12, 3500000, 7000000);
        dsnv.them(nv);
        nv = new NVVP(201, "Pham Van D", 1991, 10, 3000000, 2.2f);
        dsnv.them(nv);
        nv = new NVVP(202, "Pham Van E", 2001, 5, 2000000, 1.4f);
        dsnv.them(nv);
        nv = new NVVP(203, "Pham Van F", 2000, 5, 2300000, 1.5f);
        dsnv.them(nv);

        //Hiển thị danh sách nhân viên kinh doanh
        dsnv.hienThi("KD");
        System.out.println("");

        //Lưu danh sách nhân viên vào tệp đối tượng DSNV.dat
        dsnv.ghiTep();

        //Tính tiền lương trung bình của tất cả nhân viên và in lên màn hình
        System.out.println("Lương trung bình: " + dsnv.luongTB());
    }
}
