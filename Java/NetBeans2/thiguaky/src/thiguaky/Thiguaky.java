package thiguaky;

import java.util.Scanner;

public class Thiguaky {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Nhap so sinh vien toi da: ");
        int soSV = sc.nextInt();
        DSSV dssv = new DSSV(soSV);
        SinhVien sv;
        sv = new SinhVien("Nguyen A", "101", 3);
        dssv.them(sv);
        System.out.println(sv.hocPhi());
        sv = new SinhVien("Nguyen B", "102", 4);
        dssv.them(sv);
        System.out.println(sv.hocPhi());
        sv = new SinhVien("Nguyen C", "103", 4);
        dssv.them(sv);
        System.out.println(sv.hocPhi());
        
//        while (true) {            
//            System.out.println("\t1. Nhap sinh vien");
//            System.out.println("\t0. Thoat nhap");
//            System.out.print("Lua chon: ");
//            char choice = sc.next().charAt(0);
//            
//            if (choice == '1') {
//                System.out.print("\nNhap ho ten: ");
//                sc.nextLine();
//                String hoTen = sc.nextLine();
//                System.out.print("Nhap nganh hoc: ");
//                String nganhHoc = sc.nextLine();
//                System.out.print("Nhap so tin chi: ");
//                int soTinChi = sc.nextInt();          
//                System.out.println("");
//                
//                dssv.them(new SinhVien(hoTen, nganhHoc, soTinChi));
//            } else if (choice == '0') {
//                break;
//            }
//        }
        
//        System.out.println("\nDanh sach sinh vien");
//        dssv.hienThi();     
//        
//        System.out.println("\nSinh vien dong hoc phi cao nhat");
//        dssv.dongHPCaoNhat();
//        
//        System.out.println("\nTong hoc phi: " + dssv.tongHocPhi());
    }
}