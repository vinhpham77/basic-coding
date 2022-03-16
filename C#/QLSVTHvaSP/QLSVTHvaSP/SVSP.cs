namespace QLSVTHvaSP
{
    internal class SVSP : SV
    {
        private string _noiTT;
        private float _diemTT;

        public SVSP() : base() { }

        public SVSP(string hoTen, int namSinh, float diemTB, string noiTT, float diemTT) : base(hoTen, namSinh, diemTB)
        {
            _noiTT = noiTT;
            _diemTT = diemTT;
        }

        public string NoiTT { get => _noiTT; set => _noiTT = value; }
        public float DiemTT { get => _diemTT; set => _diemTT = value; }

        public override void HienThi()
        {
            base.HienThi();
            Console.Write($", {_noiTT}, {_diemTT}");
        }

        public override bool DuocTN()
        {
            return DiemTB >= 5 && _diemTT >= 7;
        }

        public override string LoaiSV()
        {
            return "SP";
        }
    }
}