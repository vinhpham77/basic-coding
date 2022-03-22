using System.Collections;

namespace giuaKY
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
            ds.Add(nv);
        }

        public void hienThi(string loaiNV)
        {
            foreach (NV item in ds)
            {
                if (item.loaiNV().Equals(loaiNV))
                {
                    Console.WriteLine(item);
                }
            }
        }

        public float luongTB()
        {
            float tongLuong = 0;

            foreach (NV item in ds)
            {
                tongLuong += item.tinhLuong();
            }

            return tongLuong / ds.Count;
        }
    }
}
