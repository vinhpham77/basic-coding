namespace QLSV
{
    class Program
    {
        static void Main(string[] args)
        {
            SV[] dssv;
            int soLuongSV;
            string? chNganh;

            Console.Write("Nhap so luong sinh vien: ");
            soLuongSV = Convert.ToInt32(Console.ReadLine());
            dssv = new SV[soLuongSV];

            for (int i = 0; i < soLuongSV; i++)
            {
                Console.Write("Nhap chuyen nganh cua sinh vien: ");
                chNganh = Console.ReadLine();
                switch (chNganh)
                {
                    case "CNTT":
                        {
                            dssv[i] = new SVCNTT();
                            dssv[i].Nhap();
                            break;
                        }
                    case "Van hoc":
                        {
                            dssv[i] = new SVV();
                            dssv[i].Nhap();
                            break;
                        }
                    case "Vat ly":
                        {
                            dssv[i] = new SVVL();
                            dssv[i].Nhap();
                            break;
                        }
                    default:
                        Environment.Exit(1);
                        break;
                }
            }

            Console.WriteLine();
            for (int i = 0; i < soLuongSV; i++)
            {
                dssv[i].HienThi();
            }

            Console.WriteLine();
            for (int i = 0; i < soLuongSV; i++)
            {
                if (dssv[i].TinhDiemTB() >= 5)
                {
                    dssv[i].HienThi();
                }
            }

            Console.ReadKey();
        }
    }
}