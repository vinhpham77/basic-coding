using System;
using System.Drawing;
using System.Windows.Forms;

namespace abala
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            OpenFileDialog oFile = new OpenFileDialog();
            oFile.Filter = "Tập tin ảnh|*.jpg;*.png;*.bmp|File tuỳ ý(*.*)|*.*";
            if (oFile.ShowDialog() == DialogResult.OK)
            {
                pbxImage.Image = Image.FromFile(oFile.FileName);
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            txtFirstName.Clear();
            txtLastName.Clear();
            if (rbtnFemale.Checked)
            {
                rbtnMale.Select();
            }
            cbxEnglish.Checked = false;
            cbxEnglish.Checked = false;
            cbxJapanese.Checked = false;
            lbxSubjects.ClearSelected();
            cbxQQ.SelectedIndex = 0;
        }

        private void rbtnGender_CheckedChanged(object sender, EventArgs e)
        {

        }
    }
}
