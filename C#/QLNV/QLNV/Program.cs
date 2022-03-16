namespace QLNV
{
    class Program
    {
        static void Main()
        {
            NV nv;
            DSNV dsnv = new DSNV();

            nv = new NVBC("Pham Van A", 1, 3.4f, 5);
            dsnv.them(nv);
            nv = new NVBC("Pham Van B", 2, 3.5f, 4);
            dsnv.them(nv);
            nv = new NVHD("Nguyen Thi C", 3, 3000000, "DH");
            dsnv.them(nv);
            nv = new NVHD("Nguyen Van Loa", 4, 3500000, "NH");
            dsnv.them(nv);
            nv = new NVHD("Nguyen Hoang Cam", 3, 3700000, "DH");
            dsnv.them(nv);

            dsnv.lietKe();
            Console.WriteLine();

            dsnv.lietKe("HD");
            Console.WriteLine();

            dsnv.lietKe("BC");

            Console.WriteLine($"\nTong luong: {dsnv.tongLuong()}\n");

            dsnv.dsHDDH();

            Console.ReadKey();
        }
    }

}
