namespace giuaKY
{
    public class Program
    {
        public static void Main(string[] args)
        {
            DSNV ds = new DSNV();
            NV nv;

            nv = new NVVP(100, "Nguyen Van A", 2000, 5, 3200000, 3.5f);
            ds.them(nv);
            nv = new NVVP(101, "Nguyen Van B", 2001, 11, 4000000, 3.9f);
            ds.them(nv);
            nv = new NVVP(102, "Nguyen Van C", 2002, 2, 3000000, 3.3f);
            ds.them(nv);
            nv = new NVKD(200, "Le Thi A", 2000, 5, 3000000, 1000000);
            ds.them(nv);
            nv = new NVKD(201, "Le Thi B", 2001, 6, 3000000, 3000000);
            ds.them(nv);
            nv = new NVKD(202, "Le Thi C", 2002, 9, 3500000, 10000000);
            ds.them(nv);

            ds.hienThi("NVKD");

            Console.WriteLine("\nTien luong trung binh cua tat ca nhan vien: {0} VND", ds.luongTB());

            Console.ReadKey();

        }
    }
}