using System;
using System.Windows.Forms;

namespace Login
{
    public partial class frmLogin : Form
    {
        public frmLogin()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void btnOK_Click(object sender, EventArgs e)
        {
            if (txtUsername.Text.Equals("Admin") && txtPassword.Text.Equals("Admin"))
            {
                frmEmployee obj = new frmEmployee();
                obj.Show();
                Hide();
            }
            else
            {
                MessageBox.Show("Login failed!");
            }
        }

        private void btnExit_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void frmLogin_Load(object sender, EventArgs e)
        {

        }
    }
}
