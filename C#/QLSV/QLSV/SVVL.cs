namespace QLSV
{
    internal class SVVL : SV
    {
        private float _coHoc;
        private float _dienHoc;
        private float _quangHoc;
        private float _vlHatNhan;

        public float CoHoc { get => _coHoc; set => _coHoc = value; }
        public float DienHoc { get => _dienHoc; set => _dienHoc = value; }
        public float VlHatNhan { get => _vlHatNhan; set => _vlHatNhan = value; }

        public SVVL() : base() { }

        public SVVL(string hoTen, int namSinh, float coHoc, float dienHoc, float quangHoc, float vlHatNhan) : base(hoTen, namSinh)
        {
            _coHoc = coHoc;
            _dienHoc = dienHoc;
            _quangHoc = quangHoc;
            _vlHatNhan = vlHatNhan;
        }

        public override void Nhap()
        {
            base.Nhap();
            Console.Write("Nhap diem mon Co hoc: ");
            _coHoc = Convert.ToSingle(Console.ReadLine());
            Console.Write("Nhap diem mon Dien hoc: ");
            _dienHoc = Convert.ToSingle(Console.ReadLine());
            Console.Write("Nhap diem mon Quang hoc: ");
            _quangHoc = Convert.ToSingle(Console.ReadLine());
            Console.Write("Nhap diem mon Vat ly hat nhan: ");
            _vlHatNhan = Convert.ToSingle(Console.ReadLine());
        }

        public override string ThuocChNganh()
        {
            return "Vat ly";
        }

        public override float TinhDiemTB()
        {
            return (_coHoc + _dienHoc + _quangHoc + _vlHatNhan) / 4;
        }

        public override void HienThi()
        {
            base.HienThi();
            Console.WriteLine($"Chuyenh nganh: {ThuocChNganh()}");
            Console.WriteLine($"Diem trung binh: {TinhDiemTB()}");
        }
    }
}