namespace QLNV
{
    internal class NVBC : NV
    {
        private float hsLuong;
        private int soNamCT;

        public NVBC(string hoTen, int phong, float hsLuong, int soNamCT) : base(hoTen, phong)
        {
            this.hsLuong = hsLuong;
            this.soNamCT = soNamCT;
        }

        public override void hienThi()
        {
            base.hienThi();
            Console.WriteLine($"He so lương: {hsLuong}");
            Console.WriteLine($"So nam cong tac: {soNamCT}");
        }

        public override bool laNVHDDH()
        {
            return false;
        }

        public override double layLuong()
        {
            return soNamCT >= 5 ? 5000000 * hsLuong : 3000000 * hsLuong;
        }

        public override string loaiNV()
        {
            return "NVBC";
        }
    }
}
