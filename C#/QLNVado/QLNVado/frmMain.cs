using System;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.IO;
using System.Windows.Forms;

namespace QLNVado
{
    public partial class FrmMain : Form
    {
        string cmdText;
        string imgFolderPath;
        string imgPath;

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
            cbbDepartment_Load();
            dgvDSNV_Load();
            imgFolderPath = Directory.GetCurrentDirectory() + "\\Img\\";
            Directory.CreateDirectory(imgFolderPath);
            int columnsCount = dgvDSNV.Columns.Count;
            if (columnsCount > 0)
            {
                dgvDSNV.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.AllCells;
                dgvDSNV.Columns[dgvDSNV.Columns.Count - 1].AutoSizeMode = DataGridViewAutoSizeColumnMode.Fill;
            }
            Connection.Close();
        }

        private bool IsValid()
        {
            string loi = null;
            string phoneNumber = txtPhoneNumber.Text.Trim();
            int sdt;

            if (txtNo.Text.Trim().Length != 5)
            {
                loi = "Mã nhân viên phải đủ 5 ký tự";
            }
            else if (string.IsNullOrWhiteSpace(txtName.Text))
            {
                loi = "Tên không được để trống";
            }
            else if (phoneNumber.Length != 10 || !int.TryParse(phoneNumber, out sdt))
            {
                loi = "Số điện thoại không hợp lệ";
            }

            if (string.IsNullOrEmpty(loi))
            {
                return true;
            }

            MessageBox.Show(loi, "Lỗi", MessageBoxButtons.OK, MessageBoxIcon.Error);
            return false;
        }

        private void btnChooseImage_Click(object sender, EventArgs e)
        {
            OpenFileDialog oFile = new OpenFileDialog();
            oFile.Filter = "Image Files(*.jpg, *.png, *.svg)|*.jpg;*.png;*.svg|All files(*.)|*.*";

            if (oFile.ShowDialog() == DialogResult.OK)
            {
                imgPath = oFile.FileName;
                ptbImage.Image = Image.FromFile(oFile.FileName);
            }
        }

        private void dgvDSNV_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            int index = dgvDSNV.CurrentCell.RowIndex;

            if (index == -1)
            {
                return;
            }

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
            imgPath = imgFolderPath + dgvDSNV.Rows[index].Cells["Picture"].Value.ToString();

            if (File.Exists(imgPath))
            {
                ptbImage.Image = Image.FromFile(imgPath);
            }
            else
            {
                ptbImage.Image = null;
            }
        }

        private void btnInsert_Click(object sender, EventArgs e)
        {
            if (IsValid())
            {
                Connection.Open();

                if (!EmployeeExists())
                {
                    cmdText = "INSERT NhanVien VALUES (@MaNV, @TenNV, @NgaySinh, @GioiTinh, @SoDT, @MaPB, @Picture)";
                    string[] name = { "@MaNV", "@TenNV", "@NgaySinh", "@GioiTinh", "@SoDT", "@MaPB", "@Picture" };
                    string imgClonePath = "";

                    if (File.Exists(imgPath))
                    {
                        imgClonePath = txtNo.Text + Path.GetExtension(imgPath);
                        File.Copy(imgPath, imgFolderPath + imgClonePath, true);
                    }

                    string[] value = { txtNo.Text, txtName.Text, dtpBirthday.Text, rbnMale.Checked ? "True" : "False", txtPhoneNumber.Text, cbbDepartment.SelectedValue.ToString(), imgClonePath };
                    InformResult(sender, Connection.UpdateData(cmdText, name, value));
                    dgvDSNV_Load();
                }
                else
                {
                    InformExisting(sender, true);
                }

                Connection.Close();
            }
        }

        private bool EmployeeExists()
        {
            cmdText = "SELECT * FROM NhanVien WHERE MaNV='" + txtNo.Text.Trim() + "'";
            Connection.Cmd = new SqlCommand(cmdText, Connection.Conn);

            return Connection.Cmd.ExecuteScalar() != null;
        }

        private void InformExisting(object sender, bool existed)
        {
            if (existed)
            {
                MessageBox.Show("Đã tồn tại nhân viên có mã " + txtNo.Text, ((Button)sender).Text, MessageBoxButtons.OK, MessageBoxIcon.Stop);
            }
            else
            {
                MessageBox.Show("Không tồn tại nhân viên có mã " + txtNo.Text, ((Button)sender).Text, MessageBoxButtons.OK, MessageBoxIcon.Stop);
            }
        }

        private void InformResult(object sender, bool isSuccessful)
        {
            if (isSuccessful)
            {
                MessageBox.Show("Thành công!", ((Button)sender).Text, MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else
            {
                MessageBox.Show("Thất bại!", ((Button)sender).Text, MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void btnUpdate_Click(object sender, EventArgs e)
        {
            if (IsValid())
            {
                Connection.Open();

                if (EmployeeExists())
                {
                    cmdText = "UPDATE NhanVien " +
                        "SET TenNV = @TenNV, NgaySinh = @NgaySinh, GioiTinh = @GioiTinh, SoDT = @SoDT, MaPB = @MaPB, Picture = @Picture " +
                        "WHERE MaNV = @MaNV";
                    string[] name = { "@TenNV", "@NgaySinh", "@GioiTinh", "@SoDT", "@MaPB", "@Picture", "@MaNV" };
                    string imgClonePath = "";
                    
                    //if (File.Exists(imgPath))
                    //{
                        imgClonePath = txtNo.Text + Path.GetExtension(imgPath);
                       
                        
                        File.Copy(imgPath, imgFolderPath + imgClonePath, true);
                    //}

                    string[] value = { txtName.Text, dtpBirthday.Text, rbnMale.Checked ? "True" : "False", txtPhoneNumber.Text, cbbDepartment.SelectedValue.ToString(), imgClonePath, txtNo.Text };
                    InformResult(sender, Connection.UpdateData(cmdText, name, value));
                    dgvDSNV_Load();
                }
                else
                {
                    InformExisting(sender, false);
                }

                Connection.Close();
            }
        }

        private void btnDelete_Click(object sender, EventArgs e)
        {
            DialogResult dr = MessageBox.Show("Bạn có chắc chắn không?", "Xoá", MessageBoxButtons.YesNoCancel, MessageBoxIcon.Question);

            if (dr == DialogResult.Yes)
            {
                Connection.Open();

                if (EmployeeExists())
                {
                    int index = dgvDSNV.CurrentCell.RowIndex;
                    string currentNo = dgvDSNV.Rows[index].Cells["MaNV"].Value.ToString();
                    string currentImgPath = imgFolderPath + dgvDSNV.Rows[index].Cells["Picture"].Value.ToString();
                    cmdText = "DELETE FROM NhanVien WHERE MaNV = @MaNV";
                    string[] name = { "@MaNV" };
                    string[] value = { currentNo };
                    bool isSuccessful = Connection.UpdateData(cmdText, name, value);

                    if (isSuccessful && currentImgPath != null && File.Exists(currentImgPath) && currentImgPath.Equals(imgPath))
                    {
                        ptbImage.Image = null;
                        System.GC.Collect();
                        System.GC.WaitForPendingFinalizers();
                        File.Delete(currentImgPath);
                    }

                    InformResult(sender, isSuccessful);
                    dgvDSNV_Load();
                }
                else
                {
                    InformExisting(sender, false);
                }

                Connection.Close();
            }
        }
    }
}
