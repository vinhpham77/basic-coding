namespace DSTL
{
    public class Program
    {
        public static void Main(string[] args)
        {
            DSTL dstl = new DSTL();
            TAILIEU tl;

            tl = new SACH("S001", "The gioi", 1, "Khoa Pug", "Khoa hoc", 2020);
            dstl.them(tl);
            tl = new SACH("S002", "Triet hoc", 2, "Le Khoa", "Chinh tri", 2021);
            dstl.them(tl);
            tl = new CD("CD001", "Nhac song Ha Tay", 2, 14, "Nhac");
            dstl.them(tl);
            tl = new CD("CD002", "Nhac song Ha Tinh", 3, 15, "Nhac");
            dstl.them(tl);
            tl = new TAPCHI("TC001", "Thoi trang Cool", 33, "Thoi trang", 35, 2022);
            dstl.them(tl);
            tl = new TAPCHI("TC002", "Thien loi", 34, "Nhiep anh", 45, 2022);
            dstl.them(tl);

            // dstl.lietKe();

            // dstl.xem("TC001");

            // dstl.tim("The gioi", "Khoa Pug");

            // dstl.tim("Nhac song Ha Tinh", 15, "Nhac");

            // dstl.tim("Thien loi", "Nhiep anh", 45, 2022);

            Console.ReadKey();
        }
    }
}