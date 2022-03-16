namespace QLNV
{
    internal class NVHD : NV
    {
        private double luong;
        private string loaiHD;

        public NVHD(string hoTen, int phong, double luong, string loaiHD) : base(hoTen, phong)
        {
            this.luong = luong;
            this.loaiHD = loaiHD;
        }

        public override void hienThi()
        {
            base.hienThi();
            Console.WriteLine($"Luong: {luong}");
            Console.WriteLine($"Loai hop dong: {loaiHD}");
        }

        public override bool laNVHDDH()
        {
            return loaiHD.Equals("DH");
        }

        public override double layLuong()
        {
            return loaiHD.Equals("DH") ? luong * 2.0 : luong;
        }

        public override string loaiNV()
        {
            return "HD";
        }
    }
}
