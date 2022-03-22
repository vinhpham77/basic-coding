namespace giuaKY
{
    public class NVKD : NV
    {
        private float doanhThu;

        public NVKD(int maNV, string hoTen, int namSinh, int soNamCT, float luongCB, float doanhThu) : base(maNV, hoTen, namSinh, soNamCT, luongCB)
        {
            this.doanhThu = doanhThu;
        }

        public override void nhap()
        {
            base.nhap();
            Console.Write("Nhap doanh thu: ");
            doanhThu = Convert.ToSingle(doanhThu);
        }

        public override string loaiNV()
        {
            return "NVKD";
        }

        public override float tinhLuong()
        {
            float phanTramHH;

            if (doanhThu < 2000000)
            {
                phanTramHH = 0.02f;
            }
            else if (doanhThu < 5000000)
            {
                phanTramHH = 0.05f;
            }
            else
            {
                phanTramHH = 0.07f;
            }

            return luongCB + doanhThu * phanTramHH;
        }

        public override string ToString()
        {
            return base.ToString() + ";" + doanhThu;
        }
    }
}
