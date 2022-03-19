namespace DSTL
{
    abstract public class TAILIEU
    {
        protected string maTL;
        private string tenTL;
        protected int viTri;

        public string MaTL { get => maTL; protected set => maTL = value; }
        public string TenTL { get => tenTL; protected set => tenTL = value; }

        public TAILIEU(string maTL, string tenTL, int viTri)
        {
            this.maTL = maTL ?? throw new ArgumentNullException(nameof(maTL));
            this.tenTL = tenTL;
            this.viTri = viTri;
        }

        public virtual void hienThi()
        {
            Console.WriteLine($"Ma tai lieu: {maTL}");
            Console.WriteLine($"Ten tai lieu: {tenTL}");
            Console.WriteLine($"Vi tri: {viTri}");
        }

        abstract public string loaiTL();
    }
}
