namespace DSTL
{
    public class CD : TAILIEU
    {
        private int soTT;
        private string noiDung;

        public int SoTT { get => soTT; protected set => soTT = value; }
        public string NoiDung { get => noiDung; protected set => noiDung = value; }

        public CD(string maTL, string tenTL, int viTri, int soTT, string noiDung) : base(maTL, tenTL, viTri)
        {
            this.noiDung = noiDung;
            this.soTT = soTT;
        }

        public override void hienThi()
        {
            base.hienThi();
            Console.WriteLine($"So thu tu: {soTT}");
            Console.WriteLine($"Noi dung: {noiDung}");
        }

        public override string loaiTL()
        {
            return "CD";
        }
    }
}
