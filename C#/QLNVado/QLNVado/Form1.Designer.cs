
namespace QLNVado
{
    partial class Form1
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
            this.cmbDepartment = new System.Windows.Forms.ComboBox();
            this.dgv = new System.Windows.Forms.DataGridView();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.btnChooseImage = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.dgv)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // lblEmplyeeName
            // 
            this.lblEmplyeeName.AutoSize = true;
            this.lblEmplyeeName.Location = new System.Drawing.Point(24, 72);
            this.lblEmplyeeName.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.lblEmplyeeName.Name = "lblEmplyeeName";
            this.lblEmplyeeName.Size = new System.Drawing.Size(92, 16);
            this.lblEmplyeeName.TabIndex = 0;
            this.lblEmplyeeName.Text = "Tên nhân viên";
            // 
            // lblEmployeeBirthday
            // 
            this.lblEmployeeBirthday.AutoSize = true;
            this.lblEmployeeBirthday.Location = new System.Drawing.Point(24, 118);
            this.lblEmployeeBirthday.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.lblEmployeeBirthday.Name = "lblEmployeeBirthday";
            this.lblEmployeeBirthday.Size = new System.Drawing.Size(68, 16);
            this.lblEmployeeBirthday.TabIndex = 1;
            this.lblEmployeeBirthday.Text = "Ngày sinh";
            // 
            // lblEmployeeNo
            // 
            this.lblEmployeeNo.AutoSize = true;
            this.lblEmployeeNo.Location = new System.Drawing.Point(24, 24);
            this.lblEmployeeNo.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.lblEmployeeNo.Name = "lblEmployeeNo";
            this.lblEmployeeNo.Size = new System.Drawing.Size(87, 16);
            this.lblEmployeeNo.TabIndex = 2;
            this.lblEmployeeNo.Text = "Mã nhân viên";
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(144, 72);
            this.textBox1.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(193, 22);
            this.textBox1.TabIndex = 4;
            // 
            // txtEmployeeNo
            // 
            this.txtEmployeeNo.Location = new System.Drawing.Point(144, 21);
            this.txtEmployeeNo.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.txtEmployeeNo.Name = "txtEmployeeNo";
            this.txtEmployeeNo.Size = new System.Drawing.Size(93, 22);
            this.txtEmployeeNo.TabIndex = 5;
            // 
            // lblDepartment
            // 
            this.lblDepartment.AutoSize = true;
            this.lblDepartment.Location = new System.Drawing.Point(24, 208);
            this.lblDepartment.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.lblDepartment.Name = "lblDepartment";
            this.lblDepartment.Size = new System.Drawing.Size(73, 16);
            this.lblDepartment.TabIndex = 7;
            this.lblDepartment.Text = "Phòng ban";
            // 
            // dtpEmployeeBirthday
            // 
            this.dtpEmployeeBirthday.Format = System.Windows.Forms.DateTimePickerFormat.Short;
            this.dtpEmployeeBirthday.Location = new System.Drawing.Point(144, 118);
            this.dtpEmployeeBirthday.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.dtpEmployeeBirthday.Name = "dtpEmployeeBirthday";
            this.dtpEmployeeBirthday.Size = new System.Drawing.Size(132, 22);
            this.dtpEmployeeBirthday.TabIndex = 8;
            // 
            // rbnMale
            // 
            this.rbnMale.AutoSize = true;
            this.rbnMale.Checked = true;
            this.rbnMale.Location = new System.Drawing.Point(29, 164);
            this.rbnMale.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.rbnMale.Name = "rbnMale";
            this.rbnMale.Size = new System.Drawing.Size(55, 20);
            this.rbnMale.TabIndex = 9;
            this.rbnMale.TabStop = true;
            this.rbnMale.Text = "Nam";
            this.rbnMale.UseVisualStyleBackColor = true;
            // 
            // rbnFemale
            // 
            this.rbnFemale.AutoSize = true;
            this.rbnFemale.Location = new System.Drawing.Point(144, 164);
            this.rbnFemale.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.rbnFemale.Name = "rbnFemale";
            this.rbnFemale.Size = new System.Drawing.Size(43, 20);
            this.rbnFemale.TabIndex = 10;
            this.rbnFemale.Text = "Nữ";
            this.rbnFemale.UseVisualStyleBackColor = true;
            // 
            // cmbDepartment
            // 
            this.cmbDepartment.FormattingEnabled = true;
            this.cmbDepartment.Location = new System.Drawing.Point(144, 204);
            this.cmbDepartment.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.cmbDepartment.Name = "cmbDepartment";
            this.cmbDepartment.Size = new System.Drawing.Size(193, 24);
            this.cmbDepartment.TabIndex = 12;
            // 
            // dgv
            // 
            this.dgv.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dgv.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgv.EnableHeadersVisualStyles = false;
            this.dgv.GridColor = System.Drawing.SystemColors.Control;
            this.dgv.Location = new System.Drawing.Point(29, 260);
            this.dgv.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.dgv.Name = "dgv";
            this.dgv.RowTemplate.ReadOnly = true;
            this.dgv.Size = new System.Drawing.Size(609, 292);
            this.dgv.TabIndex = 13;
            // 
            // pictureBox1
            // 
            this.pictureBox1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pictureBox1.Location = new System.Drawing.Point(505, 21);
            this.pictureBox1.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(133, 151);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.pictureBox1.TabIndex = 14;
            this.pictureBox1.TabStop = false;
            // 
            // btnChooseImage
            // 
            this.btnChooseImage.Location = new System.Drawing.Point(505, 203);
            this.btnChooseImage.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.btnChooseImage.Name = "btnChooseImage";
            this.btnChooseImage.Size = new System.Drawing.Size(133, 28);
            this.btnChooseImage.TabIndex = 15;
            this.btnChooseImage.Text = "Chọn Ảnh";
            this.btnChooseImage.UseVisualStyleBackColor = true;
            this.btnChooseImage.Click += new System.EventHandler(this.btnChooseImage_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(668, 576);
            this.Controls.Add(this.btnChooseImage);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.dgv);
            this.Controls.Add(this.cmbDepartment);
            this.Controls.Add(this.rbnFemale);
            this.Controls.Add(this.rbnMale);
            this.Controls.Add(this.dtpEmployeeBirthday);
            this.Controls.Add(this.lblDepartment);
            this.Controls.Add(this.txtEmployeeNo);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.lblEmployeeNo);
            this.Controls.Add(this.lblEmployeeBirthday);
            this.Controls.Add(this.lblEmplyeeName);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dgv)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
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
        private System.Windows.Forms.ComboBox cmbDepartment;
        private System.Windows.Forms.DataGridView dgv;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Button btnChooseImage;
    }
}

