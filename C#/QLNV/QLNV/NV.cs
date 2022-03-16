namespace QLNV
{
    internal abstract class NV
    {
        protected string hoTen;
        protected int phong;

        public NV(string hoTen, int phong)
        {
            this.hoTen = hoTen;
            this.phong = phong;
        }

        public virtual void hienThi()
        {
            Console.WriteLine($"Ho ten: {hoTen}");
            Console.WriteLine($"Phong: {phong}");
        }

        abstract public string loaiNV();
        abstract public double layLuong();
        abstract public bool laNVHDDH();
    }
}
