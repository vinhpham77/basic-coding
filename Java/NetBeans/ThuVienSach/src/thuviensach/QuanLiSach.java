package thuviensach;

import java.util.Scanner;

public class QuanLiSach {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Nhap so sach giao khoa:");
        int n = sc.nextInt();
        System.out.println("Nhap so sach tham khao:");
        int m = sc.nextInt();
        Sach dss[] = new Sach[n + m];
        sc.nextLine();

        for (int i = 0; i < n; i++) {
            System.out.println("Sach giao khoa " + i);
            dss[i] = new SachGiaoKhoa();
            dss[i].nhapSach();
        }

        for (int i = n; i < m + n; i++) {
            System.out.println("Sach tham khao " + i);
            dss[i] = new SachThamKhao();
            dss[i].nhapSach();
        }
        
        DSSach d = new DSSach();
        int s = n + m;
        for (int i = 0; i < s; i++) {
            d.them(dss[i]);
        }
        
        System.out.println(d.tinh("Sach tham khao"));

    }
}
