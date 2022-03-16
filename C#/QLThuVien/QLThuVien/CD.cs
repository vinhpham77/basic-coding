namespace QLThuVien
{
    class CD : TaiLieu
    {
        protected int soTT;
        protected string noiDung;

        public int SoTT { get => soTT; set => soTT = value; }
        public string NoiDung { get => noiDung; set => noiDung = value; }

        public CD(string maTL, string tenTL, int viTri, int soTT, string noiDung) : base(maTL, tenTL, viTri)
        {
            this.soTT = soTT;
            this.noiDung = noiDung;
        }

        public override void hienThi()
        {
            base.hienThi();
            Console.WriteLine($"So thu tu: {soTT}");
            Console.WriteLine($"Noi dung: {noiDung}");
        }

        public override string loaiTL()
        {
            return "CD";
        }
    }
}