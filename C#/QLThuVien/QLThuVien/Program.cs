namespace QLThuVien
{
    class Program
    {
        static void Main(string[] args)
        {
            TaiLieu tl;
            DSTL ds = new DSTL();

            tl = new Sach("S001", "ABC", 1, "Nguyen Gia Hoan", "Kim Dong", 2002);
            ds.them(tl);
            tl = new Sach("S002", "ABD", 1, "Pham Gia", "Tien Phong", 2010);
            ds.them(tl);
            tl = new TapChi("TC001", "ADE", 1, "Khoa hoc may tinh", 15, 2010);
            ds.them(tl);
            tl = new TapChi("TC002", "BDE", 1, "Thoi trang", 24, 2019);
            ds.them(tl);
            tl = new CD("CD001", "DEA", 1, 1, "Gala hai Viet 2020");
            ds.them(tl);
            tl = new CD("CD002", "DEB", 1, 2, "Lien khuc nhac xuan 2020");
            ds.them(tl);

            // ds.lietKe();
            // ds.lietKe("Sach");
            // ds.xem("S002");
            //ds.tim("ABD", "Pham Gia");
            //ds.tim("ADE", "Khoa hoc may tinh", 15, 2010);
            //ds.tim("DEA", 1, "Gala hai Viet 2020");

            Console.ReadKey();
        }
    }
}