namespace DSNV
{
    public class NVBC : NV
    {
        private float hsLuong;
        private int soNamCT;

        protected int SoNamCT
        {
            get { return soNamCT; }
            set { soNamCT = value; }
        }

        protected float HSLuong
        {
            get { return hsLuong; }
            set { hsLuong = value; }
        }

        public NVBC(string hoTen, int phong, float hsLuong, int soNamCT) : base(hoTen, phong)
        {
            this.hsLuong = hsLuong;
            this.soNamCT = soNamCT;
        }

        public override void hienThi()
        {
            base.hienThi();
            Console.WriteLine($"He so luong: {hsLuong}");
            Console.WriteLine($"So nam cong tac: {soNamCT}");
        }

        public override bool laNVHDDH()
        {
            return false;
        }

        public override float layLuong()
        {
            return soNamCT < 10 ? hsLuong * 2000000 : hsLuong * 4000000;
        }

        public override string loaiNV()
        {
            return "NVBC";
        }
    }
}
