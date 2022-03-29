using System;
using System.Windows.Forms;

namespace TextFileEditor
{
    public partial class frmTextFile : Form
    {
        public string rtxtText { get => rtxtTextFile.Text; set => rtxtTextFile.Text = value; }

        public frmTextFile()
        {
            InitializeComponent();
        }

        private void frmTextFile_Load(object sender, EventArgs e)
        {

        }

        private void rtxtTextFile_TextChanged(object sender, EventArgs e)
        {
            ((frmTextFileEditor)MdiParent).SaveEnabled = true;
        }

        protected override void OnFormClosing(FormClosingEventArgs e)
        {
            base.OnFormClosing(e);

            if (e.CloseReason == CloseReason.WindowsShutDown) return;

            frmTextFileEditor frm = ((frmTextFileEditor)MdiParent);
            if (frm.SaveEnabled)
            {
                if (frm.SaveInstead() == -1)
                {
                    e.Cancel = true;
                }
                else
                {
                    frm.SaveEnabled = false;
                    frm.CloseEnabled = false;
                }
            }
        }
    }
}
