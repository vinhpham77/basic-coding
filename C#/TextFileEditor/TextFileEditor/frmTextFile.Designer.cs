
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
            this.rtxtTextFile = new System.Windows.Forms.RichTextBox();
            this.SuspendLayout();
            // 
            // rtxtTextFile
            // 
            this.rtxtTextFile.Location = new System.Drawing.Point(12, 12);
            this.rtxtTextFile.Name = "rtxtTextFile";
            this.rtxtTextFile.Size = new System.Drawing.Size(737, 381);
            this.rtxtTextFile.TabIndex = 0;
            this.rtxtTextFile.Text = "";
            // 
            // frmTextFile
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(761, 405);
            this.Controls.Add(this.rtxtTextFile);
            this.Name = "frmTextFile";
            this.Text = "TextFile";
            this.Load += new System.EventHandler(this.frmTextFile_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.RichTextBox rtxtTextFile;
    }
}