namespace QLThuVien
{
    class Sach : TaiLieu
    {
        protected string tacGia;
        protected string nhaXB;
        protected int namXB;

        public string TacGia { get => tacGia; set => tacGia = value; }

        public Sach(string maTL, string tenTL, int viTri, string tacGia, string nhaXB, int namXB) : base(maTL, tenTL, viTri)
        {
            this.tacGia = tacGia;
            this.nhaXB = nhaXB;
            this.namXB = namXB;
        }

        public override void hienThi()
        {
            base.hienThi();
            Console.WriteLine($"Tac gia: {tacGia}");
            Console.WriteLine($"Nha xuat ban: {nhaXB}");
            Console.WriteLine($"Nam xuat ban: {namXB}");
        }

        public override string loaiTL()
        {
            return "Sach";
        }
    }
}