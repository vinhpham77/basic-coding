namespace DSNV
{
    abstract public class NV
    {
        private string hoTen;
        private int phong;

        protected string HoTen
        {
            get { return hoTen; }
            set { hoTen = value; }
        }

        protected int Phong
        {
            get { return phong; }
            set { phong = value; }
        }

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
        abstract public float layLuong();
        abstract public bool laNVHDDH();
    }
}
