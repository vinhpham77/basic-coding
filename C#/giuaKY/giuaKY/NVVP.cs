namespace giuaKY
{
    public class NVVP : NV
    {
        private float heSoLuong;

        public NVVP(int maNV, string hoTen, int namSinh, int soNamCT, float luongCB, float heSoLuong) : base(maNV, hoTen, namSinh, soNamCT, luongCB)
        {
            this.heSoLuong = heSoLuong;
        }

        public override void nhap()
        {
            base.nhap();
            Console.Write("Nhap he so luong: ");
            heSoLuong = Convert.ToSingle(heSoLuong);
        }

        public override string loaiNV()
        {
            return "NVVP";
        }

        public override float tinhLuong()
        {
            float phuCap;

            if (soNamCT < 10)
            {
                phuCap = luongCB;
            }
            else
            {
                phuCap = 1.2f * luongCB;
            }

            return heSoLuong * luongCB + phuCap;
        }

        public override string ToString()
        {
            return base.ToString() + ";" + heSoLuong;
        }
    }
}
