namespace QLSVTHvaSP
{
    internal class SVTH : SV
    {
        private string _tenDT;
        private float _diemDT;

        public SVTH() : base() { }

        public SVTH(string hoTen, int namSinh, float diemTB, string tenDT, float diemDT) : base(hoTen, namSinh, diemTB)
        {
            _tenDT = tenDT;
            _diemDT = diemDT;
        }

        public string TenDT { get => _tenDT; set => _tenDT = value; }
        public float DiemDT { get => _diemDT; set => _diemDT = value; }

        public override void HienThi()
        {
            base.HienThi();
            Console.Write($", {_tenDT}, {_diemDT}");
        }

        public override bool DuocTN()
        {
            return DiemTB >= 5 && _diemDT >= 5;
        }

        public override string LoaiSV()
        {
            return "TH";
        }
    }
}