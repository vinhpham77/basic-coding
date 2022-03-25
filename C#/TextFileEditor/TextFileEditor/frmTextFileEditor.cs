using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

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
            if (mnuItemSave.Enabled)
            {
                var result = MessageBox.Show("Do you want to save this?", "Save", MessageBoxButtons.YesNoCancel, MessageBoxIcon.Warning);
                if (result == DialogResult.Yes)
                {
                    mnuItemSave.PerformClick();
                }
            }
            else
            {
                mnuItemSave.Enabled = true;
                mnuItemClose.Enabled = true;
                mnuItemSetColor.Enabled = true;
                frmTextFile frm = new frmTextFile();
                frm.MdiParent = this;
                frm.Show();
            }

        }

        private void mnuItemSave_Click(object sender, EventArgs e)
        {
            SaveFileDialog dialog = new SaveFileDialog();
            dialog.Filter = "Text File|*.txt";
            if (dialog.ShowDialog().Equals(DialogResult.OK))
            {
                File.WriteAllText(dialog.FileName, ActiveMdiChild.ActiveControl.Text);
            }
        }

        private void menuItemOpen_Click(object sender, EventArgs e)
        {

        }

        private void mnuItemClose_Click(object sender, EventArgs e)
        {
            ActiveMdiChild.Close();
        }
    }
}
