namespace DiemHP
{
    public class SinhVien
    {
        private string hoTen;
        private DiemHP hp1;
        private DiemHP hp2;

        public SinhVien(string hoTen, DiemHP hp1, DiemHP hp2)
        {
            this.hoTen = hoTen;
            this.hp1 = hp1;
            this.hp2 = hp2;
        }

        public void hienThi()
        {
            Console.WriteLine($"Ho ten: {hoTen}");
            hp1.hienThi();
            hp2.hienThi();
        }

        public float tinhDTB()
        {
            return (hp1.tinhDiem() * hp1.SoTinChi + hp2.tinhDiem() * hp2.SoTinChi) / (hp1.SoTinChi + hp2.SoTinChi);
        }
    }
}
