namespace Calculator
{
    partial class frmMDI
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
            this.mnuArith = new System.Windows.Forms.MenuStrip();
            this.mnuItemArith = new System.Windows.Forms.ToolStripMenuItem();
            this.mnuItemAdd = new System.Windows.Forms.ToolStripMenuItem();
            this.mnuItemSubtract = new System.Windows.Forms.ToolStripMenuItem();
            this.mnuItemMultipy = new System.Windows.Forms.ToolStripMenuItem();
            this.mnuItemDivide = new System.Windows.Forms.ToolStripMenuItem();
            this.mnuItemExit = new System.Windows.Forms.ToolStripMenuItem();
            this.mnuItemQuit = new System.Windows.Forms.ToolStripMenuItem();
            this.pnlCal = new System.Windows.Forms.Panel();
            this.txtResult = new System.Windows.Forms.TextBox();
            this.txtSecondNo = new System.Windows.Forms.TextBox();
            this.txtFirstNo = new System.Windows.Forms.TextBox();
            this.lblResult = new System.Windows.Forms.Label();
            this.lblSecondNo = new System.Windows.Forms.Label();
            this.lblFirstNo = new System.Windows.Forms.Label();
            this.mnuArith.SuspendLayout();
            this.pnlCal.SuspendLayout();
            this.SuspendLayout();
            // 
            // mnuArith
            // 
            this.mnuArith.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.mnuArith.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.mnuItemArith,
            this.mnuItemExit});
            this.mnuArith.Location = new System.Drawing.Point(0, 0);
            this.mnuArith.Name = "mnuArith";
            this.mnuArith.Size = new System.Drawing.Size(393, 28);
            this.mnuArith.TabIndex = 0;
            this.mnuArith.Text = "menuStrip1";
            // 
            // mnuItemArith
            // 
            this.mnuItemArith.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.mnuItemAdd,
            this.mnuItemSubtract,
            this.mnuItemMultipy,
            this.mnuItemDivide});
            this.mnuItemArith.Name = "mnuItemArith";
            this.mnuItemArith.ShortcutKeyDisplayString = "";
            this.mnuItemArith.Size = new System.Drawing.Size(163, 24);
            this.mnuItemArith.Text = "&Arithmetic Calculator";
            this.mnuItemArith.Click += new System.EventHandler(this.aToolStripMenuItem_Click);
            // 
            // mnuItemAdd
            // 
            this.mnuItemAdd.Name = "mnuItemAdd";
            this.mnuItemAdd.Size = new System.Drawing.Size(224, 26);
            this.mnuItemAdd.Text = "Add";
            this.mnuItemAdd.Click += new System.EventHandler(this.mnuItemAdd_Click);
            // 
            // mnuItemSubtract
            // 
            this.mnuItemSubtract.Name = "mnuItemSubtract";
            this.mnuItemSubtract.Size = new System.Drawing.Size(224, 26);
            this.mnuItemSubtract.Text = "Subtract";
            this.mnuItemSubtract.Click += new System.EventHandler(this.mnuItemSubtract_Click);
            // 
            // mnuItemMultipy
            // 
            this.mnuItemMultipy.Name = "mnuItemMultipy";
            this.mnuItemMultipy.Size = new System.Drawing.Size(224, 26);
            this.mnuItemMultipy.Text = "Multipy";
            this.mnuItemMultipy.Click += new System.EventHandler(this.mnuItemMultipy_Click);
            // 
            // mnuItemDivide
            // 
            this.mnuItemDivide.Name = "mnuItemDivide";
            this.mnuItemDivide.Size = new System.Drawing.Size(224, 26);
            this.mnuItemDivide.Text = "Divide";
            this.mnuItemDivide.Click += new System.EventHandler(this.mnuItemDivide_Click);
            // 
            // mnuItemExit
            // 
            this.mnuItemExit.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.mnuItemQuit});
            this.mnuItemExit.Name = "mnuItemExit";
            this.mnuItemExit.Size = new System.Drawing.Size(47, 24);
            this.mnuItemExit.Text = "&Exit";
            // 
            // mnuItemQuit
            // 
            this.mnuItemQuit.Name = "mnuItemQuit";
            this.mnuItemQuit.Size = new System.Drawing.Size(120, 26);
            this.mnuItemQuit.Text = "&Quit";
            this.mnuItemQuit.Click += new System.EventHandler(this.mnuItemQuit_Click);
            // 
            // pnlCal
            // 
            this.pnlCal.BackColor = System.Drawing.SystemColors.Control;
            this.pnlCal.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pnlCal.Controls.Add(this.txtResult);
            this.pnlCal.Controls.Add(this.txtSecondNo);
            this.pnlCal.Controls.Add(this.txtFirstNo);
            this.pnlCal.Controls.Add(this.lblResult);
            this.pnlCal.Controls.Add(this.lblSecondNo);
            this.pnlCal.Controls.Add(this.lblFirstNo);
            this.pnlCal.Location = new System.Drawing.Point(35, 59);
            this.pnlCal.Name = "pnlCal";
            this.pnlCal.Size = new System.Drawing.Size(316, 171);
            this.pnlCal.TabIndex = 1;
            // 
            // txtResult
            // 
            this.txtResult.Location = new System.Drawing.Point(167, 123);
            this.txtResult.Name = "txtResult";
            this.txtResult.ReadOnly = true;
            this.txtResult.Size = new System.Drawing.Size(100, 22);
            this.txtResult.TabIndex = 5;
            this.txtResult.TextChanged += new System.EventHandler(this.textBox3_TextChanged);
            // 
            // txtSecondNo
            // 
            this.txtSecondNo.Location = new System.Drawing.Point(167, 73);
            this.txtSecondNo.Name = "txtSecondNo";
            this.txtSecondNo.Size = new System.Drawing.Size(100, 22);
            this.txtSecondNo.TabIndex = 4;
            // 
            // txtFirstNo
            // 
            this.txtFirstNo.Location = new System.Drawing.Point(167, 22);
            this.txtFirstNo.Name = "txtFirstNo";
            this.txtFirstNo.Size = new System.Drawing.Size(100, 22);
            this.txtFirstNo.TabIndex = 3;
            // 
            // lblResult
            // 
            this.lblResult.AutoSize = true;
            this.lblResult.Location = new System.Drawing.Point(38, 129);
            this.lblResult.Name = "lblResult";
            this.lblResult.Size = new System.Drawing.Size(45, 16);
            this.lblResult.TabIndex = 2;
            this.lblResult.Text = "Result";
            // 
            // lblSecondNo
            // 
            this.lblSecondNo.AutoSize = true;
            this.lblSecondNo.Location = new System.Drawing.Point(38, 79);
            this.lblSecondNo.Name = "lblSecondNo";
            this.lblSecondNo.Size = new System.Drawing.Size(105, 16);
            this.lblSecondNo.TabIndex = 1;
            this.lblSecondNo.Text = "Second Number";
            // 
            // lblFirstNo
            // 
            this.lblFirstNo.AutoSize = true;
            this.lblFirstNo.Location = new System.Drawing.Point(38, 28);
            this.lblFirstNo.Name = "lblFirstNo";
            this.lblFirstNo.Size = new System.Drawing.Size(83, 16);
            this.lblFirstNo.TabIndex = 0;
            this.lblFirstNo.Text = "First Number";
            // 
            // frmMDI
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.MenuBar;
            this.ClientSize = new System.Drawing.Size(393, 268);
            this.Controls.Add(this.pnlCal);
            this.Controls.Add(this.mnuArith);
            this.IsMdiContainer = true;
            this.MainMenuStrip = this.mnuArith;
            this.Name = "frmMDI";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.mnuArith.ResumeLayout(false);
            this.mnuArith.PerformLayout();
            this.pnlCal.ResumeLayout(false);
            this.pnlCal.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip mnuArith;
        private System.Windows.Forms.ToolStripMenuItem mnuItemArith;
        private System.Windows.Forms.Panel pnlCal;
        private System.Windows.Forms.Label lblFirstNo;
        private System.Windows.Forms.Label lblSecondNo;
        private System.Windows.Forms.Label lblResult;
        private System.Windows.Forms.TextBox txtFirstNo;
        private System.Windows.Forms.TextBox txtSecondNo;
        private System.Windows.Forms.TextBox txtResult;
        private System.Windows.Forms.ToolStripMenuItem mnuItemAdd;
        private System.Windows.Forms.ToolStripMenuItem mnuItemSubtract;
        private System.Windows.Forms.ToolStripMenuItem mnuItemMultipy;
        private System.Windows.Forms.ToolStripMenuItem mnuItemDivide;
        private System.Windows.Forms.ToolStripMenuItem mnuItemExit;
        private System.Windows.Forms.ToolStripMenuItem mnuItemQuit;
    }
}

