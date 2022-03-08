package tudien;

import java.io.*;
import java.util.Hashtable;

public class TuDien {

    Hashtable<String, Nghia[]> tuDien;

    public TuDien() {
        tuDien = new Hashtable<>();
    }

    public void them(String tu, Nghia[] nghia) {
        tuDien.put(tu, nghia);
    }

    public void tra(String tu) {
        Nghia[] nghia = tuDien.get(tu);
        for (Nghia item : nghia) {
            item.hienThi();
        }
    }

    public void hienThi() {
        tuDien.entrySet().forEach(entry -> {
            String tu = entry.getKey();
            Nghia[] nghia = entry.getValue();
            System.out.println("Tu: " + tu);
            for (Nghia item : nghia) {
                item.hienThi();
                System.out.println("");
            }
        });
    }

    public void saoLuu(String filePath) {
        try (FileWriter fw = new FileWriter(filePath);
                BufferedWriter bw = new BufferedWriter(fw)) {
            
            tuDien.entrySet().forEach(entry -> {
                String tu = entry.getKey();
                Nghia[] nghia = entry.getValue();
                
                try {
                    bw.write(tu);
                    for (Nghia item : nghia) {
                        bw.write("-");
                        bw.write(item.toString());
                    }
                    bw.newLine();
                } catch (IOException ex) {
                    System.out.println("Loi ghi");
                }
            });
            bw.flush();
        } catch (IOException e) {          
        }
    }

    public void docFile(String filePath) {
        try {
            try (FileReader fr = new FileReader(filePath);
                    BufferedReader br = new BufferedReader(fr)) {

                for (String line = br.readLine(); line != null; line = br.readLine()) {
                    String[] list = line.split("-");
                    System.out.println("Từ: " + list[0]);
                    for (int i = 1; i < list.length; i += 3) {
                        System.out.println("Nghĩa: " + list[i]);
                        System.out.println("Loại: " + list[i + 1]);
                        System.out.println("Ví dụ: " + list[i + 2]);
                    }
                    System.out.println("");
                }
            }
        } catch (IOException e) {
        }
    }

}
