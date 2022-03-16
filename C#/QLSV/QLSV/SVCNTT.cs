namespace QLSV
{
    internal class SVCNTT : SV
    {
        private float _pascal;
        private float _cSharp;
        private float _sql;

        public float Pascal { get => _pascal; set => _pascal = value; }
        public float CSharp { get => _cSharp; set => _cSharp = value; }
        public float Sql { get => _sql; set => _sql = value; }

        public SVCNTT() : base() { }

        public SVCNTT(string hoTen, int namSinh, float pascal, float cSharp, float sql) : base(hoTen, namSinh)
        {
            _pascal = pascal;
            _cSharp = cSharp;
            _sql = sql;
        }

        public override void Nhap()
        {
            base.Nhap();
            Console.Write("Nhap diem mon Pascal: ");
            _pascal = Convert.ToSingle(Console.ReadLine());
            Console.Write("Nhap diem mon C#: ");
            _cSharp = Convert.ToSingle(Console.ReadLine());
            Console.Write("Nhap diem mon SQL: ");
            _sql = Convert.ToSingle(Console.ReadLine());
        }

        public override string ThuocChNganh()
        {
            return "CNTT";
        }

        public override float TinhDiemTB()
        {
            return (_pascal + _cSharp + _sql) / 3;
        }

        public override void HienThi()
        {
            base.HienThi();
            Console.WriteLine($"Chuyen nganh: {ThuocChNganh()}");
            Console.WriteLine($"Diem trung binh: {TinhDiemTB()}");
        }
    }
}