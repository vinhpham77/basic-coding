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
                pictureBox1.Image = Image.FromFile(oFile.FileName);
            }
        }
    }
}
