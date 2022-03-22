using System;
using System.IO;
using System.Windows.Forms;

namespace Login
{
    public partial class frmEmployee : Form
    {
        public frmEmployee()
        {
            InitializeComponent();
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            if (string.IsNullOrWhiteSpace(txtName.Text) || string.IsNullOrWhiteSpace(txtAddress.Text) || string.IsNullOrEmpty(cbxDepartment.Text))
            {
                MessageBox.Show("Invalid entered data!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            SaveFileDialog saveFileDialog = new SaveFileDialog();
            saveFileDialog.Filter = "Text Document|*.txt";
            saveFileDialog.FileName = txtName.Text;

            if (saveFileDialog.ShowDialog() == DialogResult.OK)
            {
                string data;
                data = txtName.Text + ";" + txtAddress.Text + ";" + pickerJoining.Text + ";" + lbxEducation.Text + cbxDepartment.Text;
                Stream stream = saveFileDialog.OpenFile();
                StreamWriter streamWriter = new StreamWriter(stream);

                streamWriter.WriteLine(data);
                streamWriter.Close();
                stream.Close();

                btnClear.Enabled = true;
            }
        }

        private void btnExit_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            txtName.Clear();
            txtAddress.Clear();
            pickerJoining.ResetText();
            lbxEducation.SelectedIndex = 0;
            cbxDepartment.ResetText();
        }

        private void frmEmployee_Load(object sender, EventArgs e)
        {

        }
    }
}
