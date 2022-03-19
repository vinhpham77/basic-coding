namespace DSNV
{
    public class NVHD : NV
    {
        private float luong;
        private bool loaiHD;

        protected bool LoaiHD
        {
            get { return loaiHD; }
            set { loaiHD = value; }
        }

        protected float Luong
        {
            get { return luong; }
            set { luong = value; }
        }

        public NVHD(string hoTen, int phong, float luong, bool loaiHD) : base(hoTen, phong)
        {
            this.luong = luong;
            this.loaiHD = loaiHD;
        }

        public override void hienThi()
        {
            base.hienThi();
            Console.WriteLine($"Luong: {luong}");
            Console.WriteLine("Loai hop dong: {0}", loaiHD ? "Dai han" : "Ngan han");
        }

        public override bool laNVHDDH()
        {
            return loaiHD;
        }

        public override float layLuong()
        {
            return loaiHD ? luong + 2000000 : luong;
        }

        public override string loaiNV()
        {
            return "NVHD";
        }
    }
}
