
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
            this.mnuItemChangeColor = new System.Windows.Forms.ToolStripMenuItem();
            this.mnuItemExit = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.mnuItemFile,
            this.mnuItemExit});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(800, 24);
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
            this.mnuItemChangeColor});
            this.mnuItemFile.Name = "mnuItemFile";
            this.mnuItemFile.Size = new System.Drawing.Size(37, 20);
            this.mnuItemFile.Text = "File";
            // 
            // mnuItemNew
            // 
            this.mnuItemNew.Name = "mnuItemNew";
            this.mnuItemNew.Size = new System.Drawing.Size(180, 22);
            this.mnuItemNew.Text = "New";
            this.mnuItemNew.Click += new System.EventHandler(this.mnuItemNew_Click);
            // 
            // menuItemOpen
            // 
            this.menuItemOpen.Name = "menuItemOpen";
            this.menuItemOpen.Size = new System.Drawing.Size(180, 22);
            this.menuItemOpen.Text = "Open";
            // 
            // mnuItemClose
            // 
            this.mnuItemClose.Name = "mnuItemClose";
            this.mnuItemClose.Size = new System.Drawing.Size(180, 22);
            this.mnuItemClose.Text = "Close";
            // 
            // mnuItemSave
            // 
            this.mnuItemSave.Name = "mnuItemSave";
            this.mnuItemSave.Size = new System.Drawing.Size(180, 22);
            this.mnuItemSave.Text = "Save";
            // 
            // mnuItemChangeColor
            // 
            this.mnuItemChangeColor.Name = "mnuItemChangeColor";
            this.mnuItemChangeColor.Size = new System.Drawing.Size(180, 22);
            this.mnuItemChangeColor.Text = "Change Color";
            // 
            // mnuItemExit
            // 
            this.mnuItemExit.Name = "mnuItemExit";
            this.mnuItemExit.Size = new System.Drawing.Size(38, 20);
            this.mnuItemExit.Text = "Exit";
            this.mnuItemExit.Click += new System.EventHandler(this.mnuItemExit_Click);
            // 
            // frmTextFileEditor
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.menuStrip1);
            this.IsMdiContainer = true;
            this.MainMenuStrip = this.menuStrip1;
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
        private System.Windows.Forms.ToolStripMenuItem mnuItemChangeColor;
        private System.Windows.Forms.ToolStripMenuItem mnuItemExit;
    }
}

