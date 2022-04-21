using System.Configuration;
using System.Data;
using System.Data.SqlClient;
using System.Windows.Forms;

namespace QLNS
{
    public partial class frmQLNS : Form 
    {
        DataSet ds;
        SqlCommand cmd;
        SqlConnection conn;
        SqlDataAdapter adapter;

        public frmQLNS()
        {
            InitializeComponent();
        }
        
        private void InformFailedConnectionToDB()
        {
            MessageBox.Show("Lỗi truy xuất dữ liệu!", "Cơ sở dữ liệu", MessageBoxButtons.OK, MessageBoxIcon.Stop);
        }

        private void dgvQLNS_Load()
        {
            try
            {
                conn.Open();
                cmd = new SqlCommand("select * from DSNV", conn);
                adapter.SelectCommand = cmd;
                adapter.Fill(ds, "DSNV");
                dgvQLNS.DataSource = ds.Tables["DSNV"];
            }
            catch (System.Exception)
            {
                InformFailedConnectionToDB();
            }
            finally
            {
                conn.Close();
            }
        }

        private void cbbDepartment_Load()
        {
            try
            {
                conn.Open();
                cmd = new SqlCommand("select * from DMPHONG", conn);
                adapter.SelectCommand = cmd;
                adapter.Fill(ds, "PHONGBAN");
                cbbDepartment.DataSource = ds.Tables["PHONGBAN"];
                cbbDepartment.DisplayMember = "TenPhong";
                cbbDepartment.ValueMember = "MaPhong";
            }
            catch (System.Exception)
            {
                InformFailedConnectionToDB();
            }
            finally
            {
                conn.Close();
            }
        }

        private void frmQLNS_Load(object sender, System.EventArgs e)
        {
            conn = new SqlConnection();
            adapter = new SqlDataAdapter();
            ds = new DataSet("DSNV");

            conn.ConnectionString = ConfigurationManager.ConnectionStrings["VinCowboi"].ConnectionString;
            dgvQLNS_Load();
            cbbDepartment_Load();
        }

        private void btnInsert_Click(object sender, System.EventArgs e)
        {
            string sql = string.Format("insert DSNV values ('{0}', '{1}', '{2}', '{3}')", txtEmployeeNo.Text, txtEmployeeName.Text, cbbDepartment.SelectedText, txtCoefficientsSal.Text);
            bool isSuccessfull = true;

            try
            {
                conn.Open();
                cmd = new SqlCommand(sql, conn);
                adapter.InsertCommand = cmd;
                adapter.Update(ds, "DSNV");

            }
            catch (System.Exception)
            {
                isSuccessfull = false;
            }
            finally
            {
                InformSucessfulAction(sender, isSuccessfull);
                conn.Close();
            }
        }

        private void dgvQLNS_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }
    }
}
