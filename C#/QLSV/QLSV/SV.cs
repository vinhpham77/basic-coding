namespace QLSV
{
    internal abstract class SV
    {
        protected string? HoTen;
        protected int NamSinh;

        public SV() { }

        public SV(string hoTen, int namSinh)
        {
            HoTen = hoTen;
            NamSinh = namSinh;
        }

        public virtual void Nhap()
        {
            Console.Write("Nhap ho ten: ");
            HoTen = Console.ReadLine();
            Console.Write("Nhap nam sinh: ");
            NamSinh = Convert.ToInt32(Console.ReadLine());
        }

        public virtual void HienThi()
        {
            Console.WriteLine($"Ho ten: {HoTen}");
            Console.WriteLine($"Nam sinh: {NamSinh}");
        }

        abstract public string ThuocChNganh();
        abstract public float TinhDiemTB();
    }
}