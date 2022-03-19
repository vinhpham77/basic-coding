namespace DSTL
{
    public class DSTL
    {
        List<TAILIEU> ds;

        public DSTL()
        {
            ds = new List<TAILIEU>();
        }

        public void them(TAILIEU tl)
        {
            if (!ds.Contains(tl))
            {
                ds.Add(tl);
            }
        }

        public void lietKe()
        {
            foreach (TAILIEU tl in ds)
            {
                tl.hienThi();
            }
        }

        public void lietKe(string loaiTL)
        {
            foreach (TAILIEU item in ds)
            {
                if (item.loaiTL().Equals(loaiTL))
                {
                    item.hienThi();
                }
            }
        }

        public void xem(string maTL)
        {
            foreach (TAILIEU item in ds)
            {
                if (item.MaTL.Equals(maTL))
                {
                    item.hienThi();
                }
            }
        }

        public void tim(string ten, string tacGia)
        {
            foreach (TAILIEU item in ds)
            {
                if (item is SACH sach)
                {
                    if (sach.TenTL.Equals(ten) && sach.TacGia.Equals(tacGia))
                    {
                        sach.hienThi();
                    }
                }
            }
        }

        public void tim(string ten, string chNganh, int so, int nam)
        {
            foreach (TAILIEU item in ds)
            {
                if (item is TAPCHI tapChi)
                {
                    if (tapChi.TenTL.Equals(ten) && tapChi.ChuyenNganh.Equals(chNganh) && tapChi.So == so && tapChi.Nam == nam)
                    {
                        tapChi.hienThi();
                    }
                }
            }
        }

        public void tim(string ten, int soTT, string noiDung)
        {
            foreach (TAILIEU item in ds)
            {
                if (item is CD cd)
                {
                    if (cd.TenTL.Equals(ten) && cd.SoTT == soTT && cd.NoiDung.Equals(noiDung))
                    {
                        cd.hienThi();
                    }
                }
            }
        }
    }
}
