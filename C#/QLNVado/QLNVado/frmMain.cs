using System;
using System.Data;
using System.Windows.Forms;
using System.Drawing;
using System.IO;
using System.Configuration;

namespace QLNVado
{
    public partial class FrmMain : Form
    {
        DataSet ds;
        string cmdText;
        public FrmMain()
        {
            InitializeComponent();
        }

        private void cbbDepartment_Load()
        {
            cmdText = "SELECT * FROM PhongBan";
            DataTable dt = Connection.GetData(cmdText);
            cbbDepartment.DataSource = dt;
            cbbDepartment.DisplayMember = "TenPB";
            cbbDepartment.ValueMember = "MaPB";
        }

        private void dgvDSNV_Load()
        {
            cmdText = "SELECT * FROM NhanVien";
            DataTable dt = Connection.GetData(cmdText);
            dgvDSNV.DataSource = dt;
        }
        private void FrmMain_Load(object sender, EventArgs e)
        {
            Connection.Open();
            ds = new DataSet("QLNV");
            cbbDepartment_Load();
            dgvDSNV_Load();
            Connection.Close();
        }

        private void btnChooseImage_Click(object sender, EventArgs e)
        {
            OpenFileDialog oFile = new OpenFileDialog();
            oFile.Filter = "Image Files(*.jpg, *.png, *.svg)|*.jpg;*.png;*.svg|All files(*.)|*.*";
            
            if (oFile.ShowDialog() == DialogResult.OK)
            {
                ptbImage.Image = Image.FromFile(oFile.FileName);
            }
        }

        private void dgvDSNV_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            int index = dgvDSNV.CurrentCell.RowIndex;
            
            txtNo.Text = dgvDSNV.Rows[index].Cells["MaNV"].Value.ToString();
            txtName.Text = dgvDSNV.Rows[index].Cells["TenNV"].Value.ToString();
            dtpBirthday.Text = dgvDSNV.Rows[index].Cells["NgaySinh"].Value.ToString();
            if (dgvDSNV.Rows[index].Cells["GioiTinh"].Value.ToString() == "True")
            {
                rbnMale.Checked = true;
            }
            else
            {
                rbnFemale.Checked = true;
            }
            txtPhoneNumber.Text = dgvDSNV.Rows[index].Cells["SoDT"].Value.ToString();
            cbbDepartment.SelectedValue = dgvDSNV.Rows[index].Cells["MaPB"].Value.ToString();
            string imgPath = ConfigurationManager.AppSettings["imgPath"] + dgvDSNV.Rows[index].Cells["Picture"].Value.ToString();
            if (!string.IsNullOrWhiteSpace(imgPath) || !Directory.Exists(imgPath))
            {
                ptbImage.Image = Image.FromFile(imgPath);
            }
        }
    }
}
