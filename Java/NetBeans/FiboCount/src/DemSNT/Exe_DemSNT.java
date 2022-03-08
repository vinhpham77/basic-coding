package DemSNT;
import java.util.Scanner;

public class Exe_DemSNT {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Nhap so nguyen duong: ");
        int n = sc.nextInt();
        int kq = DemSNT.exec(n);
        System.out.println(kq);
    }
}