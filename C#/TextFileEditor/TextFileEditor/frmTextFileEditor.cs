using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TextFileEditor
{
    public partial class frmTextFileEditor : Form
    {
        public frmTextFileEditor()
        {
            InitializeComponent();
        }

        private void frmEditor_Load(object sender, EventArgs e)
        {

        }

        private void mnuItemExit_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void mnuItemNew_Click(object sender, EventArgs e)
        {
            frmTextFile frm = new frmTextFile();
            frm.MdiParent = this;
            frm.Show();

            
        }
    }
}
