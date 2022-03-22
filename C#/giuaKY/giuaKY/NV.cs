namespace giuaKY
{
    abstract public class NV
    {
        protected int maNV;
        protected string hoTen;
        protected int namSinh;
        protected int soNamCT;
        protected float luongCB;

        public NV(int maNV, string hoTen, int namSinh, int soNamCT, float luongCB)
        {
            this.maNV = maNV;
            this.hoTen = hoTen;
            this.namSinh = namSinh;
            this.soNamCT = soNamCT;
            this.luongCB = luongCB;
        }

        public virtual void nhap()
        {
            Console.Write("Nhap ma nhan vien: ");
            maNV = Convert.ToInt32(Console.ReadLine());
            Console.Write("Nhap ho ten: ");
            hoTen = Console.ReadLine();
            Console.Write("Nhap nam sinh: ");
            namSinh = Convert.ToInt32(Console.ReadLine());
            Console.Write("Nhap so nam cong tac: ");
            soNamCT = Convert.ToInt32(Console.ReadLine());
            Console.Write("Nhap luong co ban: ");
            luongCB = Convert.ToSingle(Console.ReadLine());
        }

        abstract public float tinhLuong();
        abstract public string loaiNV();
        public override string ToString()
        {
            return maNV + ";" + hoTen + ";" + namSinh + ";" + soNamCT + ";" + luongCB;
        }
    }
}
