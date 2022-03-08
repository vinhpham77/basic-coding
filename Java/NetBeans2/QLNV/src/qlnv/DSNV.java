package qlnv;

import java.io.*;
import java.util.Vector;

public class DSNV {
    private Vector<NV> ds;

    public DSNV() {
        ds = new Vector<>();
    }
    
    public void them(NV a) {
        if (!ds.contains(a)) {
            ds.add(a);
        }
    }
    
    public void hienThi(String loaiNV) {
        int soLuongNV = ds.size();
        
        for (int i = 0; i < soLuongNV; i++) {
            NV nv = ds.elementAt(i);
            
            if (nv.loaiNV().equals(loaiNV)) {
                System.out.println(nv);
            }
        }
    }
    
    public float luongTB() {
        int soLuongNV = ds.size();
        double tongLuong = 0;
        
        for (int i = 0; i < soLuongNV; i++) {
            tongLuong = ds.elementAt(i).tinhLuong();
        }
        
        return (float) tongLuong / soLuongNV;
    }
    
    public void ghiTep() {
        try {
            FileOutputStream fos = new FileOutputStream("DSNV.dat");
            ObjectOutputStream ous = new ObjectOutputStream(fos);
            int soLuongNV = ds.size();
            
            for (int i = 0; i < soLuongNV; i++) {
                ous.writeObject(ds.elementAt(i));
            }
            
            fos.close();
            ous.close();
        } catch (IOException e) {
            System.out.println("Lỗi ghi tệp!");
        }
    }

    
}