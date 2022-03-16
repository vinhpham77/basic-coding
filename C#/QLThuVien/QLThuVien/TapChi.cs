namespace QLThuVien
{
    class TapChi : TaiLieu
    {
        protected string chuyenNganh;
        protected int so;
        protected int nam;

        public string ChuyenNganh { get => chuyenNganh; set => chuyenNganh = value; }
        public int So { get => so; set => so = value; }
        public int Nam { get => nam; set => nam = value; }

        public TapChi(string maTL, string tenTL, int viTri, string chuyenNganh, int so, int nam) : base(maTL, tenTL, viTri)
        {
            this.chuyenNganh = chuyenNganh;
            this.so = so;
            this.nam = nam;
        }

        public override void hienThi()
        {
            base.hienThi();
            Console.WriteLine($"Chuyen nganh: {chuyenNganh}");
            Console.WriteLine($"So: {so}");
            Console.WriteLine($"Nam: {nam}");
        }

        public override string loaiTL()
        {
            return "TapChi";
        }
    }
}