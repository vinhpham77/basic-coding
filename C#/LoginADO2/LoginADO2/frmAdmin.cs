using System;
using System.Windows.Forms;

namespace LoginADO2
{
    public partial class frmAdmin : Form
    {
        string cmdText;

        public frmAdmin()
        {
            InitializeComponent();
        }

        private void dgvAccount_Load()
        {
            cmdText = "SELECT * FROM Account";
            dgvAccount.DataSource = Connection.GetData(cmdText);
        }

        private void Admin_Load(object sender, EventArgs e)
        {
            dgvAccount_Load();
        }

        private void dgvAccount_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            txtUsername.Text = txtUsername.Text.Trim();
            if (UsernameExists())
            {
                MessageBox.Show("Failed! Username '" + txtUsername.Text + "' has existed.");
            }
            else
            {
                cmdText = String.Format("INSERT Account VALUES ('{0}', '{1}')", txtUsername.Text, txtPassword.Text);
                if (Connection.UpdateData(cmdText) > 0)
                {
                    MessageBox.Show("Successful!");
                }
                else
                {
                    MessageBox.Show("Failed!");
                }
            }
        }

        private bool UsernameExists()
        {
            cmdText = string.Format("SELECT * FROM Account WHERE Username='{0}'", txtUsername.Text);
            return Connection.GetData(cmdText).Rows.Count > 0;
        }

        private void btnReload_Click(object sender, EventArgs e)
        {
            dgvAccount_Load();
            txtUsername.Text = "";
            txtPassword.Text = "";
        }

        private void btnDelete_Click(object sender, EventArgs e)
        {
            txtUsername.Text = txtUsername.Text.Trim();
            DialogResult result = MessageBox.Show("Bạn có chắc muốn xoá không!", "Xoá", MessageBoxButtons.YesNoCancel, MessageBoxIcon.Warning);

            if (result == DialogResult.Yes)
            {
                if (!UsernameExists())
                {
                    MessageBox.Show("Failed! Username '" + txtUsername.Text + "' has not existed.");
                }
                else
                {
                    cmdText = String.Format("DELETE FROM Account WHERE Username='{0}' AND Password='{1}'", txtUsername.Text, txtPassword.Text);
                    if (Connection.UpdateData(cmdText) > 0)
                    {
                        MessageBox.Show("Successful!");
                    }
                    else
                    {
                        MessageBox.Show("Failed!");
                    }
                }
            }

        }

        private void btnUpdate_Click(object sender, EventArgs e)
        {
            txtUsername.Text = txtUsername.Text.Trim();
            if (!UsernameExists())
            {
                MessageBox.Show("Failed! Username '" + txtUsername.Text + "' has not existed.");
            }
            else
            {
                cmdText = String.Format("UPDATE Account SET Password='{0}' WHERE Username='{1}'", txtPassword.Text, txtUsername.Text);
                if (Connection.UpdateData(cmdText) > 0)
                {
                    MessageBox.Show("Successful!");
                }
                else
                {
                    MessageBox.Show("Failed!");
                }
            }
        }
    }
}
