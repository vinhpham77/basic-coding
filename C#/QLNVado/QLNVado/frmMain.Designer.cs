
namespace QLNVado
{
    partial class FrmMain
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
            this.lblEmplyeeName = new System.Windows.Forms.Label();
            this.lblEmployeeBirthday = new System.Windows.Forms.Label();
            this.lblEmployeeNo = new System.Windows.Forms.Label();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.txtEmployeeNo = new System.Windows.Forms.TextBox();
            this.lblDepartment = new System.Windows.Forms.Label();
            this.dtpEmployeeBirthday = new System.Windows.Forms.DateTimePicker();
            this.rbnMale = new System.Windows.Forms.RadioButton();
            this.rbnFemale = new System.Windows.Forms.RadioButton();
            this.cbbDepartment = new System.Windows.Forms.ComboBox();
            this.dgvDSNV = new System.Windows.Forms.DataGridView();
            this.ptbImage = new System.Windows.Forms.PictureBox();
            this.btnChooseImage = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.dgvDSNV)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ptbImage)).BeginInit();
            this.SuspendLayout();
            // 
            // lblEmplyeeName
            // 
            this.lblEmplyeeName.AutoSize = true;
            this.lblEmplyeeName.Location = new System.Drawing.Point(27, 84);
            this.lblEmplyeeName.Margin = new System.Windows.Forms.Padding(5, 0, 5, 0);
            this.lblEmplyeeName.Name = "lblEmplyeeName";
            this.lblEmplyeeName.Size = new System.Drawing.Size(119, 25);
            this.lblEmplyeeName.TabIndex = 0;
            this.lblEmplyeeName.Text = "Tên nhân viên";
            // 
            // lblEmployeeBirthday
            // 
            this.lblEmployeeBirthday.AutoSize = true;
            this.lblEmployeeBirthday.Location = new System.Drawing.Point(28, 140);
            this.lblEmployeeBirthday.Margin = new System.Windows.Forms.Padding(5, 0, 5, 0);
            this.lblEmployeeBirthday.Name = "lblEmployeeBirthday";
            this.lblEmployeeBirthday.Size = new System.Drawing.Size(91, 25);
            this.lblEmployeeBirthday.TabIndex = 1;
            this.lblEmployeeBirthday.Text = "Ngày sinh";
            // 
            // lblEmployeeNo
            // 
            this.lblEmployeeNo.AutoSize = true;
            this.lblEmployeeNo.Location = new System.Drawing.Point(28, 29);
            this.lblEmployeeNo.Margin = new System.Windows.Forms.Padding(5, 0, 5, 0);
            this.lblEmployeeNo.Name = "lblEmployeeNo";
            this.lblEmployeeNo.Size = new System.Drawing.Size(118, 25);
            this.lblEmployeeNo.TabIndex = 2;
            this.lblEmployeeNo.Text = "Mã nhân viên";
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(178, 84);
            this.textBox1.Margin = new System.Windows.Forms.Padding(5, 7, 5, 7);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(240, 31);
            this.textBox1.TabIndex = 4;
            // 
            // txtEmployeeNo
            // 
            this.txtEmployeeNo.Location = new System.Drawing.Point(178, 29);
            this.txtEmployeeNo.Margin = new System.Windows.Forms.Padding(5, 7, 5, 7);
            this.txtEmployeeNo.Name = "txtEmployeeNo";
            this.txtEmployeeNo.Size = new System.Drawing.Size(115, 31);
            this.txtEmployeeNo.TabIndex = 5;
            // 
            // lblDepartment
            // 
            this.lblDepartment.AutoSize = true;
            this.lblDepartment.Location = new System.Drawing.Point(28, 240);
            this.lblDepartment.Margin = new System.Windows.Forms.Padding(5, 0, 5, 0);
            this.lblDepartment.Name = "lblDepartment";
            this.lblDepartment.Size = new System.Drawing.Size(99, 25);
            this.lblDepartment.TabIndex = 7;
            this.lblDepartment.Text = "Phòng ban";
            // 
            // dtpEmployeeBirthday
            // 
            this.dtpEmployeeBirthday.Format = System.Windows.Forms.DateTimePickerFormat.Short;
            this.dtpEmployeeBirthday.Location = new System.Drawing.Point(178, 139);
            this.dtpEmployeeBirthday.Margin = new System.Windows.Forms.Padding(5, 7, 5, 7);
            this.dtpEmployeeBirthday.Name = "dtpEmployeeBirthday";
            this.dtpEmployeeBirthday.Size = new System.Drawing.Size(164, 31);
            this.dtpEmployeeBirthday.TabIndex = 8;
            // 
            // rbnMale
            // 
            this.rbnMale.AutoSize = true;
            this.rbnMale.Location = new System.Drawing.Point(33, 189);
            this.rbnMale.Margin = new System.Windows.Forms.Padding(5, 7, 5, 7);
            this.rbnMale.Name = "rbnMale";
            this.rbnMale.Size = new System.Drawing.Size(71, 29);
            this.rbnMale.TabIndex = 9;
            this.rbnMale.TabStop = true;
            this.rbnMale.Text = "Nam";
            this.rbnMale.UseVisualStyleBackColor = true;
            // 
            // rbnFemale
            // 
            this.rbnFemale.AutoSize = true;
            this.rbnFemale.Location = new System.Drawing.Point(178, 189);
            this.rbnFemale.Margin = new System.Windows.Forms.Padding(5, 7, 5, 7);
            this.rbnFemale.Name = "rbnFemale";
            this.rbnFemale.Size = new System.Drawing.Size(57, 29);
            this.rbnFemale.TabIndex = 10;
            this.rbnFemale.TabStop = true;
            this.rbnFemale.Text = "Nữ";
            this.rbnFemale.UseVisualStyleBackColor = true;
            // 
            // cbbDepartment
            // 
            this.cbbDepartment.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbbDepartment.FormattingEnabled = true;
            this.cbbDepartment.Location = new System.Drawing.Point(178, 237);
            this.cbbDepartment.Margin = new System.Windows.Forms.Padding(5, 7, 5, 7);
            this.cbbDepartment.Name = "cbbDepartment";
            this.cbbDepartment.Size = new System.Drawing.Size(164, 33);
            this.cbbDepartment.TabIndex = 12;
            // 
            // dgvDSNV
            // 
            this.dgvDSNV.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgvDSNV.Location = new System.Drawing.Point(32, 310);
            this.dgvDSNV.Margin = new System.Windows.Forms.Padding(5, 7, 5, 7);
            this.dgvDSNV.Name = "dgvDSNV";
            this.dgvDSNV.ReadOnly = true;
            this.dgvDSNV.RowHeadersWidth = 51;
            this.dgvDSNV.Size = new System.Drawing.Size(707, 322);
            this.dgvDSNV.TabIndex = 13;
            // 
            // ptbImage
            // 
            this.ptbImage.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.ptbImage.Location = new System.Drawing.Point(595, 29);
            this.ptbImage.Margin = new System.Windows.Forms.Padding(5, 7, 5, 7);
            this.ptbImage.Name = "ptbImage";
            this.ptbImage.Size = new System.Drawing.Size(144, 172);
            this.ptbImage.TabIndex = 14;
            this.ptbImage.TabStop = false;
            // 
            // btnChooseImage
            // 
            this.btnChooseImage.Location = new System.Drawing.Point(595, 227);
            this.btnChooseImage.Margin = new System.Windows.Forms.Padding(5, 7, 5, 7);
            this.btnChooseImage.Name = "btnChooseImage";
            this.btnChooseImage.Size = new System.Drawing.Size(144, 43);
            this.btnChooseImage.TabIndex = 15;
            this.btnChooseImage.Text = "Chọn Ảnh";
            this.btnChooseImage.UseVisualStyleBackColor = true;
            // 
            // FrmMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(10F, 25F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(773, 660);
            this.Controls.Add(this.btnChooseImage);
            this.Controls.Add(this.ptbImage);
            this.Controls.Add(this.dgvDSNV);
            this.Controls.Add(this.cbbDepartment);
            this.Controls.Add(this.rbnFemale);
            this.Controls.Add(this.rbnMale);
            this.Controls.Add(this.dtpEmployeeBirthday);
            this.Controls.Add(this.lblDepartment);
            this.Controls.Add(this.txtEmployeeNo);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.lblEmployeeNo);
            this.Controls.Add(this.lblEmployeeBirthday);
            this.Controls.Add(this.lblEmplyeeName);
            this.Font = new System.Drawing.Font("Segoe UI", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Margin = new System.Windows.Forms.Padding(5, 7, 5, 7);
            this.Name = "FrmMain";
            this.Text = "QLNV";
            this.Load += new System.EventHandler(this.FrmMain_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dgvDSNV)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ptbImage)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lblEmplyeeName;
        private System.Windows.Forms.Label lblEmployeeBirthday;
        private System.Windows.Forms.Label lblEmployeeNo;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.TextBox txtEmployeeNo;
        private System.Windows.Forms.Label lblDepartment;
        private System.Windows.Forms.DateTimePicker dtpEmployeeBirthday;
        private System.Windows.Forms.RadioButton rbnMale;
        private System.Windows.Forms.RadioButton rbnFemale;
        private System.Windows.Forms.ComboBox cbbDepartment;
        private System.Windows.Forms.DataGridView dgvDSNV;
        private System.Windows.Forms.PictureBox ptbImage;
        private System.Windows.Forms.Button btnChooseImage;
    }
}

