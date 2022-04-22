using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace QLNVado
{
    public partial class Form1 : Form
    {
        DataSet Ds;

        public Form1()
        {
            InitializeComponent();
        }

        public void Load_Department()
        {
            Connect.OpenConnection();
            string cmdText = String.Format("Select * from PhongBan");
            cmbDepartment.DataSource = Connect.GetData(cmdText);
            cmbDepartment.DisplayMember = "TenPB";
            cmbDepartment.ValueMember = "MaPB";
            Connect.CloseConnection();
        }

        public void Load_DSNV()
        {
            Connect.OpenConnection();
            string cmdText = string.Format("Select a.MaNV, a.TenNV, a.NgaySinh, a.GioiTinh, a.SoDT, b.TenPB from NhanVien as a, PhongBan as b where a.MaPB=b.MaPB");
            dgv.DataSource = Connect.GetData(cmdText);
            Connect.CloseConnection();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            Connect.ConnectToDB();
            Load_Department();
            Load_DSNV();
        }

        private void btnChooseImage_Click(object sender, EventArgs e)
        {
            OpenFileDialog open = new OpenFileDialog();
            open.Filter = "Images(*.IMG, *.JPG, *.PNG, *.SVG)|*.IMG;*.JPG;*.PNG;*.SVG|All files(*.*)|*.*";

            if (open.ShowDialog() == DialogResult.OK)
            {
                pictureBox1.ImageLocation = open.FileName;
            }
        }
    }
}
