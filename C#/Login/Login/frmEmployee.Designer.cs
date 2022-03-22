namespace Login
{
    partial class frmEmployee
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
            this.lbEmployeeDetail = new System.Windows.Forms.Label();
            this.lbName = new System.Windows.Forms.Label();
            this.lbAddress = new System.Windows.Forms.Label();
            this.lbDateJoining = new System.Windows.Forms.Label();
            this.lbEducation = new System.Windows.Forms.Label();
            this.lbDepartment = new System.Windows.Forms.Label();
            this.txtName = new System.Windows.Forms.TextBox();
            this.txtAddress = new System.Windows.Forms.TextBox();
            this.pickerJoining = new System.Windows.Forms.DateTimePicker();
            this.lbxEducation = new System.Windows.Forms.ListBox();
            this.cbxDepartment = new System.Windows.Forms.ComboBox();
            this.btnSave = new System.Windows.Forms.Button();
            this.btnClear = new System.Windows.Forms.Button();
            this.btnExit = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // lbEmployeeDetail
            // 
            this.lbEmployeeDetail.AutoSize = true;
            this.lbEmployeeDetail.Location = new System.Drawing.Point(133, 16);
            this.lbEmployeeDetail.Name = "lbEmployeeDetail";
            this.lbEmployeeDetail.Size = new System.Drawing.Size(148, 16);
            this.lbEmployeeDetail.TabIndex = 0;
            this.lbEmployeeDetail.Text = "Employee Details Form";
            // 
            // lbName
            // 
            this.lbName.AutoSize = true;
            this.lbName.Location = new System.Drawing.Point(49, 55);
            this.lbName.Name = "lbName";
            this.lbName.Size = new System.Drawing.Size(109, 16);
            this.lbName.TabIndex = 1;
            this.lbName.Text = "Employee Name";
            // 
            // lbAddress
            // 
            this.lbAddress.AutoSize = true;
            this.lbAddress.Location = new System.Drawing.Point(49, 91);
            this.lbAddress.Name = "lbAddress";
            this.lbAddress.Size = new System.Drawing.Size(123, 16);
            this.lbAddress.TabIndex = 2;
            this.lbAddress.Text = "Employee Address";
            // 
            // lbDateJoining
            // 
            this.lbDateJoining.AutoSize = true;
            this.lbDateJoining.Location = new System.Drawing.Point(49, 152);
            this.lbDateJoining.Name = "lbDateJoining";
            this.lbDateJoining.Size = new System.Drawing.Size(96, 16);
            this.lbDateJoining.TabIndex = 3;
            this.lbDateJoining.Text = "Date of Joining";
            // 
            // lbEducation
            // 
            this.lbEducation.AutoSize = true;
            this.lbEducation.Location = new System.Drawing.Point(49, 191);
            this.lbEducation.Name = "lbEducation";
            this.lbEducation.Size = new System.Drawing.Size(67, 16);
            this.lbEducation.TabIndex = 4;
            this.lbEducation.Text = "Education";
            // 
            // lbDepartment
            // 
            this.lbDepartment.AutoSize = true;
            this.lbDepartment.Location = new System.Drawing.Point(49, 236);
            this.lbDepartment.Name = "lbDepartment";
            this.lbDepartment.Size = new System.Drawing.Size(77, 16);
            this.lbDepartment.TabIndex = 5;
            this.lbDepartment.Text = "Department";
            // 
            // txtName
            // 
            this.txtName.Location = new System.Drawing.Point(203, 52);
            this.txtName.Name = "txtName";
            this.txtName.Size = new System.Drawing.Size(200, 22);
            this.txtName.TabIndex = 6;
            // 
            // txtAddress
            // 
            this.txtAddress.Location = new System.Drawing.Point(203, 91);
            this.txtAddress.Multiline = true;
            this.txtAddress.Name = "txtAddress";
            this.txtAddress.Size = new System.Drawing.Size(200, 43);
            this.txtAddress.TabIndex = 7;
            // 
            // pickerJoining
            // 
            this.pickerJoining.Format = System.Windows.Forms.DateTimePickerFormat.Short;
            this.pickerJoining.Location = new System.Drawing.Point(203, 152);
            this.pickerJoining.Name = "pickerJoining";
            this.pickerJoining.Size = new System.Drawing.Size(120, 22);
            this.pickerJoining.TabIndex = 8;
            // 
            // lbxEducation
            // 
            this.lbxEducation.FormattingEnabled = true;
            this.lbxEducation.ItemHeight = 16;
            this.lbxEducation.Items.AddRange(new object[] {
            "UnderGraduate",
            "PostGraduate"});
            this.lbxEducation.Location = new System.Drawing.Point(203, 191);
            this.lbxEducation.Name = "lbxEducation";
            this.lbxEducation.Size = new System.Drawing.Size(120, 20);
            this.lbxEducation.TabIndex = 9;
            this.lbxEducation.SelectedIndexChanged += new System.EventHandler(this.listBox1_SelectedIndexChanged);
            // 
            // cbxDepartment
            // 
            this.cbxDepartment.FormattingEnabled = true;
            this.cbxDepartment.Items.AddRange(new object[] {
            "A1",
            "A2",
            "B6",
            "B7"});
            this.cbxDepartment.Location = new System.Drawing.Point(203, 228);
            this.cbxDepartment.Name = "cbxDepartment";
            this.cbxDepartment.Size = new System.Drawing.Size(121, 24);
            this.cbxDepartment.TabIndex = 10;
            // 
            // btnSave
            // 
            this.btnSave.BackColor = System.Drawing.Color.PeachPuff;
            this.btnSave.Location = new System.Drawing.Point(70, 280);
            this.btnSave.Name = "btnSave";
            this.btnSave.Size = new System.Drawing.Size(75, 23);
            this.btnSave.TabIndex = 11;
            this.btnSave.Text = "Save";
            this.btnSave.UseVisualStyleBackColor = false;
            this.btnSave.Click += new System.EventHandler(this.btnSave_Click);
            // 
            // btnClear
            // 
            this.btnClear.BackColor = System.Drawing.Color.PeachPuff;
            this.btnClear.Enabled = false;
            this.btnClear.Location = new System.Drawing.Point(171, 280);
            this.btnClear.Name = "btnClear";
            this.btnClear.Size = new System.Drawing.Size(75, 23);
            this.btnClear.TabIndex = 12;
            this.btnClear.Text = "Clear";
            this.btnClear.UseVisualStyleBackColor = false;
            this.btnClear.Click += new System.EventHandler(this.btnClear_Click);
            // 
            // btnExit
            // 
            this.btnExit.BackColor = System.Drawing.Color.PeachPuff;
            this.btnExit.Location = new System.Drawing.Point(269, 280);
            this.btnExit.Name = "btnExit";
            this.btnExit.Size = new System.Drawing.Size(75, 23);
            this.btnExit.TabIndex = 13;
            this.btnExit.Text = "Exit";
            this.btnExit.UseVisualStyleBackColor = false;
            this.btnExit.Click += new System.EventHandler(this.btnExit_Click);
            // 
            // frmEmployee
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.PaleGoldenrod;
            this.ClientSize = new System.Drawing.Size(439, 322);
            this.Controls.Add(this.btnExit);
            this.Controls.Add(this.btnClear);
            this.Controls.Add(this.btnSave);
            this.Controls.Add(this.cbxDepartment);
            this.Controls.Add(this.lbxEducation);
            this.Controls.Add(this.pickerJoining);
            this.Controls.Add(this.txtAddress);
            this.Controls.Add(this.txtName);
            this.Controls.Add(this.lbDepartment);
            this.Controls.Add(this.lbEducation);
            this.Controls.Add(this.lbDateJoining);
            this.Controls.Add(this.lbAddress);
            this.Controls.Add(this.lbName);
            this.Controls.Add(this.lbEmployeeDetail);
            this.Name = "frmEmployee";
            this.Text = "Form2";
            this.Load += new System.EventHandler(this.frmEmployee_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lbEmployeeDetail;
        private System.Windows.Forms.Label lbName;
        private System.Windows.Forms.Label lbAddress;
        private System.Windows.Forms.Label lbDateJoining;
        private System.Windows.Forms.Label lbEducation;
        private System.Windows.Forms.Label lbDepartment;
        private System.Windows.Forms.TextBox txtName;
        private System.Windows.Forms.TextBox txtAddress;
        private System.Windows.Forms.DateTimePicker pickerJoining;
        private System.Windows.Forms.ListBox lbxEducation;
        private System.Windows.Forms.ComboBox cbxDepartment;
        private System.Windows.Forms.Button btnSave;
        private System.Windows.Forms.Button btnClear;
        private System.Windows.Forms.Button btnExit;
    }
}