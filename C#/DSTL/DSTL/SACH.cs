namespace DSTL
{
    public class SACH : TAILIEU
    {
        private string tacGia;
        protected string nhaXB;
        protected int namXB;

        public SACH(string maTL, string tenTL, int viTri, string tacGia, string nhaXB, int namXB) : base(maTL, tenTL, viTri)
        {
            this.tacGia = tacGia;
            this.namXB = namXB;
            this.nhaXB = nhaXB;
        }

        public string TacGia { get => tacGia; protected set => tacGia = value; }

        public override void hienThi()
        {
            base.hienThi();
            Console.WriteLine($"Tac gia: {tacGia}");
            Console.WriteLine($"Nha xuat ban: {nhaXB}");
            Console.WriteLine($"Nam xuat ban: {namXB}");
        }

        public override string loaiTL()
        {
            return "Sach";
        }
    }
}
