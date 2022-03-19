namespace DSTL
{
    public class TAPCHI : TAILIEU
    {
        private string chuyenNganh;
        private int so;
        private int nam;

        public string ChuyenNganh { get => chuyenNganh; protected set => chuyenNganh = value; }
        public int So { get => so; protected set => so = value; }
        public int Nam { get => nam; protected set => nam = value; }

        public TAPCHI(string maTL, string tenTL, int viTri, string cNganh, int so, int nam) : base(maTL, tenTL, viTri)
        {
            chuyenNganh = cNganh;
            this.so = so;
            this.nam = nam;
        }

        public override void hienThi()
        {
            base.hienThi();
            Console.WriteLine($"Chuyen nganh: {chuyenNganh}");
            Console.WriteLine($"So: {so}");
            Console.WriteLine($"Nam: {nam}");
        }

        public override string loaiTL()
        {
            return "TapChi";
        }
    }
}
