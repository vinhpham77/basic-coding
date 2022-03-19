namespace DiemHP
{
    public class HPThucHanh : DiemHP
    {
        private float db1;
        private float db2;
        private float db3;
        public HPThucHanh(string tenHP, int soTinChi, float db1, float db2, float db3) : base(tenHP, soTinChi)
        {
            this.db1 = db1;
            this.db2 = db2;
            this.db3 = db3;
        }

        public override void hienThi()
        {
            base.hienThi();
            Console.WriteLine($"Diem bai 1: {db1}");
            Console.WriteLine($"Diem bai 2: {db2}");
            Console.WriteLine($"Diem bai 3: {db3}");
        }

        public override float tinhDiem()
        {
            return (db1 + db2 + db3) / 3;
        }
    }
}
