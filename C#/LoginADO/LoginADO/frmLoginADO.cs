using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;
using System.Configuration;

namespace LoginADO
{
    public partial class frmLoginADO : Form
    {
        DataTable dt;
        SqlConnection conn;
        SqlCommand cmd;
        string cmdText;

        public frmLoginADO()
        {
            InitializeComponent();
        }

        private void btnOK_Click(object sender, EventArgs e)
        {
            bool match = false;
            try
            {
                conn.Open();
                cmdText = string.Format("SELECT * FROM Account WHERE Username='{0}' AND Password='{1}'", txtUsername.Text.Trim(), txtPassword.Text.Trim());
                cmd = new SqlCommand(cmdText, conn);
                match = cmd.ExecuteScalar() != null;
            }
            catch (Exception)
            {
                match = false;
                MessageBox.Show("Lỗi liên quan CSDL!");
            }
            finally
            {
                conn.Close();
                if (match)
                {
                    MessageBox.Show("Đăng nhập thành công!");
                }
                else
                {
                    MessageBox.Show("Sai tên đăng nhập hoặc mật khẩu!");
                }
            }

        }

        private void btnCancel_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void frmLoginADO_Load(object sender, EventArgs e)
        {
            conn = new SqlConnection();
            conn.ConnectionString = ConfigurationManager.ConnectionStrings["VinCowboi"].ConnectionString;
        }
    }
}
