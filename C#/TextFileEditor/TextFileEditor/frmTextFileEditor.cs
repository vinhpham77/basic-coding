using System;
using System.IO;
using System.Windows.Forms;

namespace TextFileEditor
{
    public partial class frmTextFileEditor : Form
    {
        public bool SaveEnabled { get => mnuItemSave.Enabled; set => mnuItemSave.Enabled = value; }
        public bool CloseEnabled { get => mnuItemClose.Enabled; set => mnuItemClose.Enabled = value; }

        public int SaveInstead()
        {
            var result = MessageBox.Show("Do you want to save this?", "Save", MessageBoxButtons.YesNoCancel, MessageBoxIcon.Warning);

            if (result == DialogResult.Yes)
            {
                mnuItemSave.PerformClick();
                return 1;
            }
            else if (result == DialogResult.No)
            {
                return 0;
            }
            else
            {
                return -1;
            }
        }
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
            if (mnuItemSave.Enabled && MdiChildren.Length > 0)
            {
                if (SaveInstead() == -1)
                {
                    return;
                }
                else
                {
                    ((frmTextFile)ActiveMdiChild).Close();
                }
            }

            mnuItemSave.Enabled = true;
            mnuItemClose.Enabled = true;
            frmTextFile frm = new frmTextFile();
            frm.MdiParent = this;
            frm.StartPosition = FormStartPosition.CenterScreen;
            frm.Show();
        }

        private void mnuItemSave_Click(object sender, EventArgs e)
        {
            SaveFileDialog dialog = new SaveFileDialog();
            dialog.Filter = "Text File|*.txt";
            if (dialog.ShowDialog().Equals(DialogResult.OK))
            {
                File.WriteAllText(dialog.FileName, ActiveMdiChild.ActiveControl.Text);
                mnuItemSave.Enabled = false;
            }
        }

        private void menuItemOpen_Click(object sender, EventArgs e)
        {
            OpenFileDialog dialog = new OpenFileDialog();
            dialog.Filter = "Text File|*.txt";
            if (dialog.ShowDialog().Equals(DialogResult.OK))
            {
                mnuItemNew.PerformClick();
                ((frmTextFile)ActiveMdiChild).rtxtText = File.ReadAllText(dialog.FileName);
            }
        }

        private void mnuItemClose_Click(object sender, EventArgs e)
        {
            if (mnuItemSave.Enabled && MdiChildren.Length > 0)
            {
                if (SaveInstead() == -1)
                {
                    return;
                }
            }

            mnuItemClose.Enabled = false;
            mnuItemSave.Enabled = false;
            ((frmTextFile)ActiveMdiChild).Close();
        }
    }
}
