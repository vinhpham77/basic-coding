using System.Collections;

namespace QLSVTHvaSP
{
    internal class DSSV
    {
        private ArrayList _ds;

        public ArrayList Ds { get => _ds; set => _ds = value; }

        public DSSV()
        {
            _ds = new ArrayList();
        }

        public void Them(SV sv)
        {
            if (!_ds.Contains(sv))
            {
                _ds.Add(sv);
            }
        }

        public void LietKe()
        {
            foreach (SV item in _ds)
            {
                item.HienThi();
                Console.WriteLine();
            }
        }

        public void LietKe(string loaiSV)
        {
            foreach (SV item in _ds)
            {
                if (item.LoaiSV().Equals(loaiSV))
                {
                    item.HienThi();
                    Console.WriteLine();
                }
            }
        }

        public void DSTN()
        {
            foreach (SV item in _ds)
            {
                if (item.DuocTN())
                {
                    item.HienThi();
                    Console.WriteLine();
                }
            }
        }
    }
}