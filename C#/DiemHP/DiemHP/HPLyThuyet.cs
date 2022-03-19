namespace DiemHP
{
    public class HPLyThuyet : DiemHP
    {
        private float chuyenCan;
        private float giuaKy;
        private float cuoiKy;

        public HPLyThuyet(string tenHP, int soTinChi, float cC, float gK, float cK) : base(tenHP, soTinChi)
        {
            chuyenCan = cC;
            giuaKy = gK;
            cuoiKy = cK;
        }

        public override void hienThi()
        {
            base.hienThi();
            Console.WriteLine($"Chuyen can: {chuyenCan}");
            Console.WriteLine($"Giua ky: {giuaKy}");
            Console.WriteLine($"Cuoi ky: {cuoiKy}");
        }

        public override float tinhDiem()
        {
            return chuyenCan * 0.1f + giuaKy * 0.3f + cuoiKy * 0.6f;
        }
    }
}
