
namespace TextFileEditor
{
    partial class frmTextFileEditor
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.mnuItemFile = new System.Windows.Forms.ToolStripMenuItem();
            this.mnuItemNew = new System.Windows.Forms.ToolStripMenuItem();
            this.menuItemOpen = new System.Windows.Forms.ToolStripMenuItem();
            this.mnuItemClose = new System.Windows.Forms.ToolStripMenuItem();
            this.mnuItemSave = new System.Windows.Forms.ToolStripMenuItem();
            this.mnuItemSetColor = new System.Windows.Forms.ToolStripMenuItem();
            this.mnuItemExit = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.mnuItemFile,
            this.mnuItemExit});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(1067, 28);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // mnuItemFile
            // 
            this.mnuItemFile.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.mnuItemNew,
            this.menuItemOpen,
            this.mnuItemClose,
            this.mnuItemSave,
            this.mnuItemSetColor});
            this.mnuItemFile.Name = "mnuItemFile";
            this.mnuItemFile.Size = new System.Drawing.Size(46, 24);
            this.mnuItemFile.Text = "File";
            // 
            // mnuItemNew
            // 
            this.mnuItemNew.Image = global::TextFileEditor.Properties.Resources.file_solid;
            this.mnuItemNew.Name = "mnuItemNew";
            this.mnuItemNew.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.N)));
            this.mnuItemNew.Size = new System.Drawing.Size(224, 26);
            this.mnuItemNew.Text = "New";
            this.mnuItemNew.Click += new System.EventHandler(this.mnuItemNew_Click);
            // 
            // menuItemOpen
            // 
            this.menuItemOpen.Name = "menuItemOpen";
            this.menuItemOpen.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.O)));
            this.menuItemOpen.Size = new System.Drawing.Size(224, 26);
            this.menuItemOpen.Text = "Open";
            this.menuItemOpen.Click += new System.EventHandler(this.menuItemOpen_Click);
            // 
            // mnuItemClose
            // 
            this.mnuItemClose.Enabled = false;
            this.mnuItemClose.Name = "mnuItemClose";
            this.mnuItemClose.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.W)));
            this.mnuItemClose.Size = new System.Drawing.Size(224, 26);
            this.mnuItemClose.Text = "Close";
            this.mnuItemClose.Click += new System.EventHandler(this.mnuItemClose_Click);
            // 
            // mnuItemSave
            // 
            this.mnuItemSave.AutoSize = false;
            this.mnuItemSave.Enabled = false;
            this.mnuItemSave.Name = "mnuItemSave";
            this.mnuItemSave.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.S)));
            this.mnuItemSave.Size = new System.Drawing.Size(224, 26);
            this.mnuItemSave.Text = "Save";
            this.mnuItemSave.Click += new System.EventHandler(this.mnuItemSave_Click);
            // 
            // mnuItemSetColor
            // 
            this.mnuItemSetColor.Enabled = false;
            this.mnuItemSetColor.Name = "mnuItemSetColor";
            this.mnuItemSetColor.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.F1)));
            this.mnuItemSetColor.Size = new System.Drawing.Size(224, 26);
            this.mnuItemSetColor.Text = "Set Color";
            // 
            // mnuItemExit
            // 
            this.mnuItemExit.Name = "mnuItemExit";
            this.mnuItemExit.Size = new System.Drawing.Size(47, 24);
            this.mnuItemExit.Text = "Exit";
            this.mnuItemExit.Click += new System.EventHandler(this.mnuItemExit_Click);
            // 
            // frmTextFileEditor
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSize = true;
            this.ClientSize = new System.Drawing.Size(1067, 554);
            this.Controls.Add(this.menuStrip1);
            this.IsMdiContainer = true;
            this.MainMenuStrip = this.menuStrip1;
            this.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "frmTextFileEditor";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.frmEditor_Load);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem mnuItemFile;
        private System.Windows.Forms.ToolStripMenuItem mnuItemNew;
        private System.Windows.Forms.ToolStripMenuItem menuItemOpen;
        private System.Windows.Forms.ToolStripMenuItem mnuItemClose;
        private System.Windows.Forms.ToolStripMenuItem mnuItemSave;
        private System.Windows.Forms.ToolStripMenuItem mnuItemSetColor;
        private System.Windows.Forms.ToolStripMenuItem mnuItemExit;
    }
}

