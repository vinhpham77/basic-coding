namespace DSNV
{
    class Program
    {
        public static void Main(string[] args)
        {
            NV nv;
            DSNV dsnv = new DSNV();

            nv = new NVBC("ABC", 1, 3.4f, 8);
            dsnv.them(nv);
            nv = new NVBC("XYZ", 2, 3.4f, 11);
            dsnv.them(nv);
            nv = new NVHD("qwe", 2, 3000000, false);
            dsnv.them(nv);
            nv = new NVHD("ewer", 3, 3000000, true);
            dsnv.them(nv);

            //dsnv.lietKe();

            //dsnv.lietKe("NVBC");
            //dsnv.lietKe("NVHD");

            //Console.WriteLine($"Tong luong: {dsnv.tongLuong()}");
            //dsnv.dsHDDH();

            Console.ReadKey();
        }

    }
}