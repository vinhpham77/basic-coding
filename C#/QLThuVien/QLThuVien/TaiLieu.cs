namespace QLThuVien
{
    abstract class TaiLieu
    {
        protected string maTL;
        protected string tenTL;
        protected int viTri;

        public string MaTL { get => maTL; set => maTL = value; }
        public string TenTL { get => tenTL; set => tenTL = value; }

        public TaiLieu(string maTL, string tenTL, int viTri)
        {
            this.maTL = maTL;
            this.tenTL = tenTL;
            this.viTri = viTri;
        }

        public virtual void hienThi()
        {
            Console.WriteLine($"Ma tai lieu: {maTL}");
            Console.WriteLine($"Ten tai lieu: {tenTL}");
            Console.WriteLine($"Vi tri: {viTri}");
        }

        abstract public string loaiTL();
    }
}