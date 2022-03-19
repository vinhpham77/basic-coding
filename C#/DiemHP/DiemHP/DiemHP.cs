namespace DiemHP
{
    abstract public class DiemHP
    {
        private string tenHP;
        private int soTinChi;

        protected DiemHP(string tenHP, int soTinChi)
        {
            this.tenHP = tenHP;
            this.soTinChi = soTinChi;
        }

        public string TenHP
        {
            get { return tenHP; }
            protected set { if (value is not null) { tenHP = value; } }
        }

        public int SoTinChi
        {
            get { return soTinChi; }
            protected set { if (value > 0) { soTinChi = value; } }
        }

        public virtual void hienThi()
        {
            Console.WriteLine($"Ten hoc phan: {tenHP}");
            Console.WriteLine($"So tin chi: {soTinChi}");
        }

        abstract public float tinhDiem();
    }
}