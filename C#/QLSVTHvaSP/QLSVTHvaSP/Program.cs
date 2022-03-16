namespace QLSVTHvaSP
{
    class Program
    {
        static void Main(string[] args)
        {
            DSSV dssv = new DSSV();
            SV sv;
            int soSV;
            int choice;
            bool isComfirmed = false;
            string hoTen;
            string loaiSV;

            Console.Write("Nhap so luong sinh vien: ");
            soSV = Convert.ToInt32(Console.ReadLine());

            for (int i = 0; i < soSV; i++)
            {
                Console.Write("Nhap loai sinh vien(1 - TH, khac 1 - SP): ");
                choice = Convert.ToInt32(Console.ReadLine());

                if (choice == 1)
                {
                    sv = new SVTH();
                }
                else
                {
                    sv = new SVSP();
                }

                dssv.Them(sv);
            }

            sv = new SVTH("Pham Van Mach", 2002, 6.7f, "Binh Dinh", 4.1f);
            dssv.Them(sv);
            sv = new SVSP("Pham Van Vinh", 2002, 6.7f, "Binh Duong", 7.1f);
            dssv.Them(sv);

            Console.Write("Nhap ho ten sinh vien can tim: ");
            hoTen = Console.ReadLine();

            Console.WriteLine(dssv.Ds.Count);
            for (int i = 0; i < soSV; i++)
            {
                SV svien = dssv.Ds[i] as SV;
                if (svien.HoTenGS.Equals(hoTen))
                {
                    svien.HienThi();
                    Console.WriteLine();
                    isComfirmed = true;
                }
            }
            if (!isComfirmed)
            {
                Console.WriteLine("Khong co");
            }

            Console.Write("Nhap ho ten sinh vien can xoa: ");
            hoTen = Console.ReadLine();

            for (int i = 0; i < soSV; i++)
            {
                SV svien = dssv.Ds[i] as SV;
                svien.HienThi();
                if (svien.HoTenGS.Equals(hoTen))
                {
                    dssv.Ds.RemoveAt(i);
                    soSV--;
                    isComfirmed = true;
                    break;
                }
            }
            if (isComfirmed)
            {
                Console.WriteLine("Xoa thanh cong!");
            }
            else
            {
                Console.WriteLine("Xoa that bai!");
            }

            dssv.LietKe();

            Console.Write("\nNhap loai sinh vien can liet ke: ");
            loaiSV = Console.ReadLine();
            dssv.LietKe(loaiSV);

            Console.ReadKey();
        }
    }
}