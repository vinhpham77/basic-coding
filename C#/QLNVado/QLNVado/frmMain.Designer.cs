
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
            this.lblName = new System.Windows.Forms.Label();
            this.lblBirthday = new System.Windows.Forms.Label();
            this.lblNo = new System.Windows.Forms.Label();
            this.txtName = new System.Windows.Forms.TextBox();
            this.txtNo = new System.Windows.Forms.TextBox();
            this.lblDepartment = new System.Windows.Forms.Label();
            this.dtpBirthday = new System.Windows.Forms.DateTimePicker();
            this.rbnMale = new System.Windows.Forms.RadioButton();
            this.rbnFemale = new System.Windows.Forms.RadioButton();
            this.cbbDepartment = new System.Windows.Forms.ComboBox();
            this.dgvDSNV = new System.Windows.Forms.DataGridView();
            this.ptbImage = new System.Windows.Forms.PictureBox();
            this.btnChooseImage = new System.Windows.Forms.Button();
            this.btnInsert = new System.Windows.Forms.Button();
            this.btnUpdate = new System.Windows.Forms.Button();
            this.btnDelete = new System.Windows.Forms.Button();
            this.lblPhoneNumber = new System.Windows.Forms.Label();
            this.txtPhoneNumber = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.dgvDSNV)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ptbImage)).BeginInit();
            this.SuspendLayout();
            // 
            // lblName
            // 
            this.lblName.AutoSize = true;
            this.lblName.Location = new System.Drawing.Point(22, 68);
            this.lblName.Margin = new System.Windows.Forms.Padding(5, 0, 5, 0);
            this.lblName.Name = "lblName";
            this.lblName.Size = new System.Drawing.Size(99, 20);
            this.lblName.TabIndex = 0;
            this.lblName.Text = "Tên nhân viên";
            // 
            // lblBirthday
            // 
            this.lblBirthday.AutoSize = true;
            this.lblBirthday.Location = new System.Drawing.Point(23, 114);
            this.lblBirthday.Margin = new System.Windows.Forms.Padding(5, 0, 5, 0);
            this.lblBirthday.Name = "lblBirthday";
            this.lblBirthday.Size = new System.Drawing.Size(74, 20);
            this.lblBirthday.TabIndex = 1;
            this.lblBirthday.Text = "Ngày sinh";
            // 
            // lblNo
            // 
            this.lblNo.AutoSize = true;
            this.lblNo.Location = new System.Drawing.Point(23, 22);
            this.lblNo.Margin = new System.Windows.Forms.Padding(5, 0, 5, 0);
            this.lblNo.Name = "lblNo";
            this.lblNo.Size = new System.Drawing.Size(97, 20);
            this.lblNo.TabIndex = 2;
            this.lblNo.Text = "Mã nhân viên";
            // 
            // txtName
            // 
            this.txtName.Location = new System.Drawing.Point(151, 65);
            this.txtName.Margin = new System.Windows.Forms.Padding(5, 7, 5, 7);
            this.txtName.Name = "txtName";
            this.txtName.Size = new System.Drawing.Size(224, 27);
            this.txtName.TabIndex = 4;
            // 
            // txtNo
            // 
            this.txtNo.Location = new System.Drawing.Point(151, 19);
            this.txtNo.Margin = new System.Windows.Forms.Padding(5, 7, 5, 7);
            this.txtNo.Name = "txtNo";
            this.txtNo.Size = new System.Drawing.Size(115, 27);
            this.txtNo.TabIndex = 5;
            // 
            // lblDepartment
            // 
            this.lblDepartment.AutoSize = true;
            this.lblDepartment.Location = new System.Drawing.Point(24, 247);
            this.lblDepartment.Margin = new System.Windows.Forms.Padding(5, 0, 5, 0);
            this.lblDepartment.Name = "lblDepartment";
            this.lblDepartment.Size = new System.Drawing.Size(80, 20);
            this.lblDepartment.TabIndex = 7;
            this.lblDepartment.Text = "Phòng ban";
            // 
            // dtpBirthday
            // 
            this.dtpBirthday.Format = System.Windows.Forms.DateTimePickerFormat.Short;
            this.dtpBirthday.Location = new System.Drawing.Point(151, 114);
            this.dtpBirthday.Margin = new System.Windows.Forms.Padding(5, 7, 5, 7);
            this.dtpBirthday.Name = "dtpBirthday";
            this.dtpBirthday.Size = new System.Drawing.Size(164, 27);
            this.dtpBirthday.TabIndex = 8;
            // 
            // rbnMale
            // 
            this.rbnMale.AutoSize = true;
            this.rbnMale.Location = new System.Drawing.Point(28, 159);
            this.rbnMale.Margin = new System.Windows.Forms.Padding(5, 7, 5, 7);
            this.rbnMale.Name = "rbnMale";
            this.rbnMale.Size = new System.Drawing.Size(59, 24);
            this.rbnMale.TabIndex = 9;
            this.rbnMale.TabStop = true;
            this.rbnMale.Text = "Nam";
            this.rbnMale.UseVisualStyleBackColor = true;
            // 
            // rbnFemale
            // 
            this.rbnFemale.AutoSize = true;
            this.rbnFemale.Location = new System.Drawing.Point(151, 159);
            this.rbnFemale.Margin = new System.Windows.Forms.Padding(5, 7, 5, 7);
            this.rbnFemale.Name = "rbnFemale";
            this.rbnFemale.Size = new System.Drawing.Size(47, 24);
            this.rbnFemale.TabIndex = 10;
            this.rbnFemale.TabStop = true;
            this.rbnFemale.Text = "Nữ";
            this.rbnFemale.UseVisualStyleBackColor = true;
            // 
            // cbbDepartment
            // 
            this.cbbDepartment.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbbDepartment.FormattingEnabled = true;
            this.cbbDepartment.Location = new System.Drawing.Point(151, 247);
            this.cbbDepartment.Margin = new System.Windows.Forms.Padding(5, 7, 5, 7);
            this.cbbDepartment.Name = "cbbDepartment";
            this.cbbDepartment.Size = new System.Drawing.Size(164, 27);
            this.cbbDepartment.TabIndex = 12;
            // 
            // dgvDSNV
            // 
            this.dgvDSNV.AllowUserToAddRows = false;
            this.dgvDSNV.AllowUserToDeleteRows = false;
            this.dgvDSNV.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dgvDSNV.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgvDSNV.Location = new System.Drawing.Point(26, 305);
            this.dgvDSNV.Margin = new System.Windows.Forms.Padding(5, 7, 5, 7);
            this.dgvDSNV.Name = "dgvDSNV";
            this.dgvDSNV.ReadOnly = true;
            this.dgvDSNV.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.dgvDSNV.RowHeadersWidth = 51;
            this.dgvDSNV.Size = new System.Drawing.Size(727, 264);
            this.dgvDSNV.TabIndex = 13;
            this.dgvDSNV.CellClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dgvDSNV_CellClick);
            // 
            // ptbImage
            // 
            this.ptbImage.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.ptbImage.Location = new System.Drawing.Point(610, 19);
            this.ptbImage.Margin = new System.Windows.Forms.Padding(5, 7, 5, 7);
            this.ptbImage.Name = "ptbImage";
            this.ptbImage.Size = new System.Drawing.Size(144, 172);
            this.ptbImage.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.ptbImage.TabIndex = 14;
            this.ptbImage.TabStop = false;
            // 
            // btnChooseImage
            // 
            this.btnChooseImage.Location = new System.Drawing.Point(609, 205);
            this.btnChooseImage.Margin = new System.Windows.Forms.Padding(5, 7, 5, 7);
            this.btnChooseImage.Name = "btnChooseImage";
            this.btnChooseImage.Size = new System.Drawing.Size(144, 43);
            this.btnChooseImage.TabIndex = 15;
            this.btnChooseImage.Text = "Chọn Ảnh";
            this.btnChooseImage.UseVisualStyleBackColor = true;
            this.btnChooseImage.Click += new System.EventHandler(this.btnChooseImage_Click);
            // 
            // btnInsert
            // 
            this.btnInsert.Location = new System.Drawing.Point(498, 19);
            this.btnInsert.Name = "btnInsert";
            this.btnInsert.Size = new System.Drawing.Size(75, 30);
            this.btnInsert.TabIndex = 16;
            this.btnInsert.Text = "Thêm";
            this.btnInsert.UseVisualStyleBackColor = true;
            // 
            // btnUpdate
            // 
            this.btnUpdate.Location = new System.Drawing.Point(498, 69);
            this.btnUpdate.Name = "btnUpdate";
            this.btnUpdate.Size = new System.Drawing.Size(75, 30);
            this.btnUpdate.TabIndex = 17;
            this.btnUpdate.Text = "Sửa";
            this.btnUpdate.UseVisualStyleBackColor = true;
            // 
            // btnDelete
            // 
            this.btnDelete.Location = new System.Drawing.Point(498, 119);
            this.btnDelete.Name = "btnDelete";
            this.btnDelete.Size = new System.Drawing.Size(75, 30);
            this.btnDelete.TabIndex = 18;
            this.btnDelete.Text = "Xoá";
            this.btnDelete.UseVisualStyleBackColor = true;
            // 
            // lblPhoneNumber
            // 
            this.lblPhoneNumber.AutoSize = true;
            this.lblPhoneNumber.Location = new System.Drawing.Point(24, 201);
            this.lblPhoneNumber.Name = "lblPhoneNumber";
            this.lblPhoneNumber.Size = new System.Drawing.Size(97, 20);
            this.lblPhoneNumber.TabIndex = 19;
            this.lblPhoneNumber.Text = "Số điện thoại";
            // 
            // txtPhoneNumber
            // 
            this.txtPhoneNumber.Location = new System.Drawing.Point(151, 198);
            this.txtPhoneNumber.Name = "txtPhoneNumber";
            this.txtPhoneNumber.Size = new System.Drawing.Size(100, 27);
            this.txtPhoneNumber.TabIndex = 20;
            // 
            // FrmMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 19F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(785, 596);
            this.Controls.Add(this.txtPhoneNumber);
            this.Controls.Add(this.lblPhoneNumber);
            this.Controls.Add(this.btnDelete);
            this.Controls.Add(this.btnUpdate);
            this.Controls.Add(this.btnInsert);
            this.Controls.Add(this.btnChooseImage);
            this.Controls.Add(this.ptbImage);
            this.Controls.Add(this.dgvDSNV);
            this.Controls.Add(this.cbbDepartment);
            this.Controls.Add(this.rbnFemale);
            this.Controls.Add(this.rbnMale);
            this.Controls.Add(this.dtpBirthday);
            this.Controls.Add(this.lblDepartment);
            this.Controls.Add(this.txtNo);
            this.Controls.Add(this.txtName);
            this.Controls.Add(this.lblNo);
            this.Controls.Add(this.lblBirthday);
            this.Controls.Add(this.lblName);
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

        private System.Windows.Forms.Label lblName;
        private System.Windows.Forms.Label lblBirthday;
        private System.Windows.Forms.Label lblNo;
        private System.Windows.Forms.TextBox txtName;
        private System.Windows.Forms.TextBox txtNo;
        private System.Windows.Forms.Label lblDepartment;
        private System.Windows.Forms.DateTimePicker dtpBirthday;
        private System.Windows.Forms.RadioButton rbnMale;
        private System.Windows.Forms.RadioButton rbnFemale;
        private System.Windows.Forms.ComboBox cbbDepartment;
        private System.Windows.Forms.DataGridView dgvDSNV;
        private System.Windows.Forms.PictureBox ptbImage;
        private System.Windows.Forms.Button btnChooseImage;
        private System.Windows.Forms.Button btnInsert;
        private System.Windows.Forms.Button btnUpdate;
        private System.Windows.Forms.Button btnDelete;
        private System.Windows.Forms.Label lblPhoneNumber;
        private System.Windows.Forms.TextBox txtPhoneNumber;
    }
}

