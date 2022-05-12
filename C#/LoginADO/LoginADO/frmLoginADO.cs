using System;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;
using System.Windows.Forms;

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
                MessageBox.Show("Error(database)!");
            }
            finally
            {
                conn.Close();
                if (match)
                {
                    MessageBox.Show("Login successfully!");
                }
                else
                {
                    MessageBox.Show("Invalid username or password!");
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
