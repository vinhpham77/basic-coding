package Exe_DSSV;

import java.util.*;

public class DSSV {

    private Vector ds;
    
    public DSSV(){
        ds = new Vector();
    }

    public void them(SV sv) {
        if (!ds.contains(sv)) {
            ds.addElement(sv);
        }
    }

//    public void timSV()
    
    public void lietKe() {
        for (Enumeration e = ds.elements(); e.hasMoreElements();) {
            System.out.println(e.nextElement() + "\n");
        }
    }
//        ds.forEach((t) -> {
//            System.out.println(t + "\n");
//        });
    
}