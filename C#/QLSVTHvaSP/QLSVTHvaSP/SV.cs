namespace QLSVTHvaSP
{
    internal abstract class SV
    {
        protected string HoTen;
        protected int NamSinh;
        protected float DiemTB;

        public string HoTenGS { get => HoTen; set => HoTen = value; }
        public int NamSinhGS { get => NamSinh; set => NamSinh = value; }
        public float DiemTBGS { get => DiemTB; set => DiemTB = value; }

        public SV() { }

        public SV(string hoTen, int namSinh, float diemTB)
        {
            HoTen = hoTen;
            NamSinh = namSinh;
            DiemTB = diemTB;
        }

        public virtual void NhapSV()
        {
            Console.Write("Nhap ho ten: ");
            HoTen = Console.ReadLine();

        }

        public virtual void HienThi()
        {
            Console.Write($"{HoTen}, {NamSinh}, {DiemTB}");
        }

        public override bool Equals(object obj)
        {
            if (obj is null || !(obj is SV))
            {
                SV sv = obj as SV;
                return HoTen.Equals(sv.HoTen) && NamSinh == sv.NamSinh && DiemTB == sv.DiemTB;
            }

            return false;
        }
        abstract public string LoaiSV();
        abstract public bool DuocTN();

        public override int GetHashCode()
        {
            throw new NotImplementedException();
        }
    }
}