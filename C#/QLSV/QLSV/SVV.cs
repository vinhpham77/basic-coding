namespace QLSV
{
    internal class SVV : SV
    {
        private float _vhCoDien;
        private float _vhHienDai;

        public float VhCoDien { get => _vhCoDien; set => _vhCoDien = value; }
        public float VhHienDai { get => _vhHienDai; set => _vhHienDai = value; }

        public SVV() : base() { }

        public SVV(string hoTen, int namSinh, float vhCoDien, float vhHienDai) : base(hoTen, namSinh)
        {
            _vhCoDien = vhCoDien;
            _vhHienDai = vhHienDai;
        }

        public override void Nhap()
        {
            base.Nhap();
            Console.Write("Nhap diem mon Van hoc co dien: ");
            _vhCoDien = Convert.ToSingle(Console.ReadLine());
            Console.Write("Nhap diem mon Van hoc hien dai: ");
            _vhHienDai = Convert.ToSingle(Console.ReadLine());
        }

        public override string ThuocChNganh()
        {
            return "Van hoc";
        }

        public override float TinhDiemTB()
        {
            return (_vhCoDien + _vhHienDai) / 2;
        }

        public override void HienThi()
        {
            base.HienThi();
            Console.WriteLine($"Chuyen nganh: {ThuocChNganh()}");
            Console.WriteLine($"Diem trung binh: {TinhDiemTB()}");
        }
    }
}