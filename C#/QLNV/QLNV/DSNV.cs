namespace QLNV
{
    internal class DSNV
    {
        private List<NV> ds;

        public DSNV()
        {
            ds = new List<NV>();
        }

        public bool them(NV nv)
        {
            if (!ds.Contains(nv))
            {
                ds.Add(nv);
                return true;
            }

            return false;
        }

        public void lietKe()
        {
            foreach (NV nv in ds)
            {
                nv.hienThi();
            }
        }

        public void lietKe(string loaiNV)
        {
            foreach (NV nv in ds)
            {
                if (nv.loaiNV().Equals(loaiNV))
                {
                    nv.hienThi();
                }
            }
        }

        public double tongLuong()
        {
            double tong = 0;

            foreach (NV nv in ds)
            {
                tong += nv.layLuong();
            }

            return tong;
        }

        public void dsHDDH()
        {
            foreach (NV nv in ds)
            {
                if (nv.laNVHDDH())
                {
                    nv.hienThi();
                }
            }
        }
    }
}
