
namespace TextFileEditor
{
    partial class frmTextFile
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(frmTextFile));
            this.rtxtTextFile = new System.Windows.Forms.RichTextBox();
            this.SuspendLayout();
            // 
            // rtxtTextFile
            // 
            resources.ApplyResources(this.rtxtTextFile, "rtxtTextFile");
            this.rtxtTextFile.Name = "rtxtTextFile";
            this.rtxtTextFile.TextChanged += new System.EventHandler(this.rtxtTextFile_TextChanged);
            // 
            // frmTextFile
            // 
            resources.ApplyResources(this, "$this");
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.rtxtTextFile);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "frmTextFile";
            this.ShowIcon = false;
            this.Load += new System.EventHandler(this.frmTextFile_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.RichTextBox rtxtTextFile;
    }
}