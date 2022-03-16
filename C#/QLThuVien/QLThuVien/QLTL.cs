namespace QLThuVien
{
    class DSTL
    {
        private List<TaiLieu> ds;

        public DSTL()
        {
            ds = new List<TaiLieu>();
        }

        public void them(TaiLieu tl)
        {
            if (!ds.Contains(tl))
            {
                ds.Add(tl);
            }
        }

        public void lietKe()
        {
            foreach (TaiLieu item in ds)
            {
                item.hienThi();
                Console.WriteLine();
            }
        }

        public void lietKe(string loaiTL)
        {
            foreach (TaiLieu item in ds)
            {
                if (item.loaiTL().Equals(loaiTL))
                {
                    item.hienThi();
                    Console.WriteLine();
                }
            }
        }

        public void xem(string maTL)
        {
            foreach (TaiLieu item in ds)
            {
                if (item.MaTL.Equals(maTL))
                {
                    item.hienThi();
                    break;
                }
            }
        }

        public void tim(string tenTL, string tenTG)
        {
            foreach (TaiLieu item in ds)
            {
                if (item is Sach && item.TenTL.Equals(tenTL))
                {
                    Sach sach = item as Sach;
                    if (sach.TacGia.Equals(tenTG))
                    {
                        sach.hienThi();
                    }
                }
            }
        }

        public void tim(string tenTL, string chNganh, int so, int nam)
        {
            foreach (TaiLieu item in ds)
            {
                if (item is TapChi && item.TenTL.Equals(tenTL))
                {
                    TapChi tapChi = item as TapChi;
                    if (tapChi.ChuyenNganh.Equals(chNganh) && tapChi.So == so && tapChi.Nam == nam)
                    {
                        tapChi.hienThi();
                    }
                }
            }
        }

        public void tim(string tenTL, int soTT, string noiDung)
        {
            foreach (TaiLieu item in ds)
            {
                if (item is CD && item.TenTL.Equals(tenTL))
                {
                    CD cd = item as CD;
                    if (cd.SoTT == soTT && cd.NoiDung.Equals(noiDung))
                    {
                        cd.hienThi();
                    }
                }
            }
        }
    }
}