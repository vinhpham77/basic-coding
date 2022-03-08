package tudien;

public class Exe_TuDien {
    
    public static void main(String[] args) {
        Nghia[] dsNghia = new Nghia[7];
        dsNghia[0] = new Nghia("Mới", "Tính từ", "I will buy a new house.");
        dsNghia[1] = new Nghia("Cũ", "Tính từ", "The old house has been destroyed.");
        dsNghia[2] = new Nghia("Ngôi nhà", "Danh từ", "A home is nicer than a house.");
        dsNghia[3] = new Nghia("Luôn", "Trạng từ", "She is always complaining about everything.");
        dsNghia[4] = new Nghia("Mua", "Động từ", "I will buy a new house.");
        dsNghia[5] = new Nghia("Phần ngực(của cơ thể)", "Danh từ", "Her heart was pounding in her chest.");
        dsNghia[6] = new Nghia("Rương, hộp to(đựng đồ vật)", "Danh từ", "In our family, we should have a medicine chest.");
        
        Nghia[] nghiaNew = {dsNghia[0]};
        Nghia[] nghiaOld = {dsNghia[1]};
        Nghia[] nghiaHouse = {dsNghia[2]};
        Nghia[] nghiaAlways = {dsNghia[3]};
        Nghia[] nghiaBuy = {dsNghia[4]};
        Nghia[] nghiaChest = {dsNghia[5], dsNghia[6]};
        
        TuDien tuDien = new TuDien();
        tuDien.them("New", nghiaNew);
        tuDien.them("Old", nghiaOld);
        tuDien.them("House", nghiaHouse);
        tuDien.them("Always", nghiaAlways);
        tuDien.them("Buy", nghiaBuy);
        tuDien.them("Chest", nghiaChest);
        
        tuDien.hienThi();
        tuDien.saoLuu("Data.txt");
        tuDien.docFile("Data.txt");
        tuDien.tra("Always");
    }
}
