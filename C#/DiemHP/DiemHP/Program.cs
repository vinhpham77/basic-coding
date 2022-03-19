namespace DiemHP
{
    class Program
    {
        public static void Main(string[] args)
        {
            List<SinhVien> dssv = new();
            SinhVien sv;

            DiemHP[] hp = new DiemHP[6];
            hp[0] = new HPLyThuyet("Triet", 3, 5.6f, 6, 8.0f);
            hp[1] = new HPLyThuyet("Phap luat", 3, 6.7f, 4.1f, 7.7f);
            hp[2] = new HPLyThuyet("Ky nang giao tiep", 2, 10, 6, 8);
            hp[3] = new HPThucHanh("Lap trinh co ban", 3, 10, 9, 8);
            hp[4] = new HPThucHanh("CSDL", 3, 9, 7, 7.9f);
            hp[5] = new HPThucHanh("Web", 3, 9, 5, 9.3f);

            sv = new SinhVien("A", hp[0], hp[3]);
            dssv.Add(sv);
            sv = new SinhVien("B", hp[1], hp[4]);
            dssv.Add(sv);
            sv = new SinhVien("C", hp[2], hp[5]);
            dssv.Add(sv);

            foreach (SinhVien item in dssv)
            {
                item.hienThi();
                Console.WriteLine($"Diem trung binh: {item.tinhDTB()}\n");
            }

            Console.ReadKey();
        }
    }
}