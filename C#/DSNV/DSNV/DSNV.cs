using System.Collections;

namespace DSNV
{
    public class DSNV
    {
        private ArrayList ds;

        public DSNV()
        {
            ds = new ArrayList();
        }

        public void them(NV nv)
        {
            if (!ds.Contains(nv))
            {
                ds.Add(nv);
            }
        }

        public void lietKe()
        {
            foreach (NV item in ds)
            {
                item.hienThi();
            }
        }

        public void lietKe(string loaiNV)
        {
            foreach (NV item in ds)
            {
                if (item.loaiNV().Equals(loaiNV))
                {
                    item.hienThi();
                }
            }
        }

        public double tongLuong()
        {
            double tong = 0;

            foreach (NV item in ds)
            {
                tong += item.layLuong();
            }

            return tong;
        }

        public void dsHDDH()
        {
            foreach (NV item in ds)
            {
                if (item.laNVHDDH())
                {
                    item.hienThi();
                }
            }
        }
    }
}
