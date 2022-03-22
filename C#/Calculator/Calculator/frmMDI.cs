using System;
using System.Windows.Forms;

namespace Calculator
{
    public partial class frmMDI : Form
    {
        public frmMDI()
        {
            InitializeComponent();
        }

        public bool GetData(out double firstNo, out double secondNo)
        {
            firstNo = 0;
            secondNo = 0;

            return double.TryParse(txtFirstNo.Text, out firstNo) && double.TryParse(txtSecondNo.Text, out secondNo);
        }

        public void WarnInvalidData()
        {
            MessageBox.Show("Invalid data!", "Calculator", MessageBoxButtons.OK, MessageBoxIcon.Error);
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void aToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }

        private void mnuItemQuit_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void mnuItemAdd_Click(object sender, EventArgs e)
        {
            double firstNo;
            double secondNo;

            if (GetData(out firstNo, out secondNo))
            {
                txtResult.Text = (firstNo + secondNo).ToString();
            }
            else
            {
                txtResult.Text = null;
                WarnInvalidData();
            }
        }

        private void mnuItemSubtract_Click(object sender, EventArgs e)
        {
            double firstNo;
            double secondNo;

            if (GetData(out firstNo, out secondNo))
            {
                txtResult.Text = (firstNo - secondNo).ToString();
            }
            else
            {
                txtResult.Text = null;
                WarnInvalidData();
            }
        }

        private void mnuItemMultipy_Click(object sender, EventArgs e)
        {
            double firstNo;
            double secondNo;

            if (GetData(out firstNo, out secondNo))
            {
                txtResult.Text = (firstNo * secondNo).ToString();
            }
            else
            {
                txtResult.Text = null;
                WarnInvalidData();
            }
        }

        private void mnuItemDivide_Click(object sender, EventArgs e)
        {
            double firstNo;
            double secondNo;

            if (GetData(out firstNo, out secondNo))
            {
                if (secondNo != 0)
                {
                    txtResult.Text = (firstNo / secondNo).ToString();
                }
                else
                {
                    txtResult.Text = null;
                    MessageBox.Show("Math Error!", "Calculator", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
            else
            {
                txtResult.Text = null;
                WarnInvalidData();
            }
        }
    }
}
