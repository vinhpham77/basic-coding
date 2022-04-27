using System.Data;
using System.Data.SqlClient;
using System.Windows.Forms;

namespace QLNS
{
    public partial class frmQLNS : Form
    {
        DataSet ds;
        DataTable dt;
        SqlCommandBuilder builder;
        string cmdText;
        string placeholderSearch;

        public frmQLNS()
        {
            InitializeComponent();
        }

        private void dgvQLNS_Load()
        {
            cmdText = "SELECT MaNV, HoTen, TenPhong, HeSoLuong, TenChucVu " +
                "FROM DSNV AS a, CHUCVU AS b, DMPHONG AS c " +
                "WHERE a.MaPhong=c.MaPhong and a.MaChucVu=b.MaChucVu";
            dt = Connection.GetDaTa(cmdText);
            dt.TableName = "DSNVFake";
            ds.Tables.Add(dt);
            dgvQLNS.DataSource = ds.Tables["DSNVfake"];

            cmdText = "SELECT * FROM DSNV";
            dt = Connection.GetDaTa(cmdText);
            dt.TableName = "DSNV";
            ds.Tables.Add(dt);
        }

        private void cbbDepartment_Load()
        {
            cmdText = "select * from DMPHONG";
            dt = Connection.GetDaTa(cmdText);
            cbbDepartment.DataSource = dt;
            cbbDepartment.DisplayMember = "TenPhong";
            cbbDepartment.ValueMember = "MaPhong";
        }

        private void cbbPosition_Load()
        {
            cmdText = "select * from CHUCVU";
            dt = Connection.GetDaTa(cmdText);
            cbbPosition.DataSource = dt;
            cbbPosition.DisplayMember = "TenChucVu";
            cbbPosition.ValueMember = "MaChucVu";
        }

        private void frmQLNS_Load(object sender, System.EventArgs e)
        {
            ds = new DataSet();
            builder = new SqlCommandBuilder();
            placeholderSearch = "Nhập tên nhân viên cần tìm";

            txtSearch.Text = placeholderSearch;
            dgvQLNS_Load();
            cbbDepartment_Load();
            cbbPosition_Load();
            //SetUpdatingDatabase();
        }

        //private void SetUpdatingDatabase()
        //{
        //    SqlParameter MaNV = new SqlParameter("@MaNV", SqlDbType.Char, 5, "MaNV");
        //    SqlParameter HoTen = new SqlParameter("@HoTen", SqlDbType.NVarChar, 30, "HoTen");
        //    SqlParameter MaPhong = new SqlParameter("@MaPhong", SqlDbType.Char, 5, "MaPhong");
        //    SqlParameter HeSoLuong = new SqlParameter("@HeSoLuong", SqlDbType.Float, 5, "HeSoLuong");
        //    SqlParameter MaChucVu = new SqlParameter("@MaChucVu", SqlDbType.Char, 5, "MaChucVu");

        //    MaNV.SourceVersion = DataRowVersion.Original;

        //    Connection.da.InsertCommand = new SqlCommand("INSERT DSNV VALUES (@MaNV, @HoTen, @MaPhong, @HeSoLuong, @MaChucVu)");
        //    Connection.da.InsertCommand.Parameters.Add(MaNV);
        //    Connection.da.InsertCommand.Parameters.Add(HoTen);
        //    Connection.da.InsertCommand.Parameters.Add(MaPhong);
        //    Connection.da.InsertCommand.Parameters.Add(HeSoLuong);
        //    Connection.da.InsertCommand.Parameters.Add(MaChucVu);

        //    Connection.da.DeleteCommand = new SqlCommand("DELETE FROM DSNV WHERE MaNV=@MaNV");
        //    Connection.da.UpdateCommand = new SqlCommand("UPDATE DSNV SET HoTen=@HoTen, MaPhong=@MaPhong, HeSoLuong=@HeSoLuong, MaChucVu=@MaChucVu WHERE MaNV=@MaNV");

        //    Connection.da.InsertCommand.Connection = Connection.conn;
        //    Connection.da.DeleteCommand.Connection = Connection.conn;
        //    Connection.da.UpdateCommand.Connection = Connection.conn;
        //}

        public void InformSuccessfulAction(object sender, bool isSuccessful)
        {
            if (isSuccessful)
            {
                MessageBox.Show("Thành công!", (sender as Button).Text, MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else
            {
                MessageBox.Show("Thất bại!", (sender as Button).Text, MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void btnInsert_Click(object sender, System.EventArgs e)
        {
            bool isSuccessful = false;
            cmdText = "SELECT * FROM DSNV";

            try
            {
                int employeeNo = GetEmployeeNoRowIndex();

                if (employeeNo == -1)
                {
                    DataRow drReal = ds.Tables["DSNV"].NewRow();
                    DataRow drFake = ds.Tables["DSNVFake"].NewRow();

                    drReal["MaNV"] = drFake["MaNV"] = txtEmployeeNo.Text.Trim();
                    drReal["HoTen"] = drFake["HoTen"] = txtEmployeeName.Text.Trim();
                    drReal["MaPhong"] = cbbDepartment.SelectedValue;
                    drFake["TenPhong"] = cbbDepartment.Text;
                    drReal["HeSoLuong"] = drFake["HeSoLuong"] = float.Parse(txtCoefficientsSal.Text);
                    drReal["MaChucVu"] = cbbPosition.SelectedValue;
                    drFake["TenChucVu"] = cbbPosition.Text;

                    ds.Tables["DSNV"].Rows.Add(drReal);
                    ds.Tables["DSNVFake"].Rows.Add(drFake);

                    Connection.da.SelectCommand = new SqlCommand(cmdText, Connection.conn);
                    builder.DataAdapter = Connection.da;
                    Connection.da.Update(ds, "DSNV");
                    isSuccessful = true;
                }
            }
            catch (System.Exception)
            {
                isSuccessful = false;
            }
            finally
            {
                InformSuccessfulAction(sender, isSuccessful);
            }
        }

        private void btnSearch_Click(object sender, System.EventArgs e)
        {
            cmdText = "SELECT MaNV, HoTen, TenPhong, HeSoLuong, TenChucVu " +
                "FROM DSNV AS a, CHUCVU AS b, DMPHONG AS c " +
                "WHERE a.MaPhong=c.MaPhong and a.MaChucVu=b.MaChucVu and HoTen LIKE N'%" + txtSearch.Text.Trim() + "%'";
            dgvQLNS.DataSource = Connection.GetDaTa(cmdText);
        }

        private void btnRefresh_Click(object sender, System.EventArgs e)
        {
            txtEmployeeName.Clear();
            txtEmployeeNo.Clear();
            txtCoefficientsSal.Clear();
            cbbDepartment.SelectedIndex = 0;
            cbbPosition.SelectedIndex = 0;
            txtSearch.Text = placeholderSearch;
            dgvQLNS.DataSource = ds.Tables["DSNVfake"];
            dgvQLNS.ClearSelection();
        }

        private void btnGroupBy_Click(object sender, System.EventArgs e)
        {
            cmdText = "SELECT TenPhong, COUNT(DSNV.MaPhong) AS SoLuong FROM DMPHONG, DSNV WHERE DMPHONG.MaPhong=DSNV.MaPhong GROUP BY TenPhong";
            dgvQLNS.DataSource = Connection.GetDaTa(cmdText);
        }

        private void btnDelete_Click(object sender, System.EventArgs e)
        {
            DialogResult dr = MessageBox.Show("Bạn có chắc chắn muốn xoá không?", "Xoá", MessageBoxButtons.YesNoCancel, MessageBoxIcon.Warning);
            if (dr != DialogResult.Yes)
            {
                return;
            }

            bool isSuccessful = false;
            cmdText = "SELECT * FROM DSNV";

            try
            {
                int employeeNoRowIndex = GetEmployeeNoRowIndex();

                if (employeeNoRowIndex > -1)
                {
                    ds.Tables["DSNV"].Rows[employeeNoRowIndex].Delete();
                    ds.Tables["DSNVfake"].Rows[employeeNoRowIndex].Delete();

                    Connection.da.SelectCommand = new SqlCommand(cmdText, Connection.conn);
                    builder.DataAdapter = Connection.da;
                    Connection.da.Update(ds, "DSNV");
                    isSuccessful = true;
                }
            }
            catch (System.Exception)
            {
                isSuccessful = false;
            }
            finally
            {
                InformSuccessfulAction(sender, isSuccessful);
            }
        }

        private void btnUpdate_Click(object sender, System.EventArgs e)
        {
            bool isSuccessful = false;
            cmdText = "SELECT * FROM DSNV";
            DataTable dtReal = ds.Tables["DSNV"];
            DataTable dtFake = ds.Tables["DSNVFake"];
            int index = GetEmployeeNoRowIndex();

            try
            {
                if (index > -1)
                {
                    dtReal.Rows[index].BeginEdit();
                    dtFake.Rows[index].BeginEdit();

                    dtReal.Rows[index]["HoTen"] = dtFake.Rows[index]["HoTen"] = txtEmployeeName.Text.Trim();
                    dtReal.Rows[index]["MaPhong"] = cbbDepartment.SelectedValue;
                    dtFake.Rows[index]["TenPhong"] = cbbDepartment.Text;
                    dtReal.Rows[index]["HeSoLuong"] = dtFake.Rows[index]["HeSoLuong"] = float.Parse(txtCoefficientsSal.Text);
                    dtReal.Rows[index]["MaChucVu"] = cbbPosition.SelectedValue;
                    dtFake.Rows[index]["TenChucVu"] = cbbPosition.Text;

                    dtReal.Rows[index].EndEdit();
                    dtFake.Rows[index].EndEdit();

                    Connection.da.SelectCommand = new SqlCommand(cmdText, Connection.conn);
                    builder.DataAdapter = Connection.da;
                    Connection.da.Update(ds, "DSNV");
                    isSuccessful = true;
                }
            }
            catch (System.Exception)
            {
                isSuccessful = false;
                dtReal.Rows[index].CancelEdit();
                dtFake.Rows[index].CancelEdit();
            }
            finally
            {
                InformSuccessfulAction(sender, isSuccessful);
            }
        }

        public int GetEmployeeNoRowIndex()
        {
            for (int i = 0; i < ds.Tables["DSNV"].Rows.Count; i++)
            {
                string maNV = ds.Tables["DSNV"].Rows[i].ItemArray[0].ToString().Trim();

                if (maNV.Equals(txtEmployeeNo.Text))
                {
                    return i;
                }
            }

            return -1;
        }

        private void txtSearch_Enter(object sender, System.EventArgs e)
        {
            if (txtSearch.Text.Equals(placeholderSearch))
            {
                txtSearch.Clear();
            }
        }

        private void txtSearch_Leave(object sender, System.EventArgs e)
        {
            if (string.IsNullOrWhiteSpace(txtSearch.Text))
            {
                txtSearch.Text = placeholderSearch;
            }
        }

        private void dgvQLNS_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            int index = dgvQLNS.CurrentCell.RowIndex;

            txtEmployeeNo.Text = dgvQLNS.Rows[index].Cells[0].Value.ToString().Trim();
            txtEmployeeName.Text = dgvQLNS.Rows[index].Cells[1].Value.ToString();
            cbbDepartment.Text = dgvQLNS.Rows[index].Cells[2].Value.ToString();
            txtCoefficientsSal.Text = dgvQLNS.Rows[index].Cells[3].Value.ToString();
            cbbPosition.Text = dgvQLNS.Rows[index].Cells[4].Value.ToString();
        }
    }
}
