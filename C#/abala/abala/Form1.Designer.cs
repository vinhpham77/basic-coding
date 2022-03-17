namespace abala
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
            this.lbFirstName = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.lbBirthday = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.lbLanguage = new System.Windows.Forms.Label();
            this.cbxEnglish = new System.Windows.Forms.CheckBox();
            this.cbxJapanese = new System.Windows.Forms.CheckBox();
            this.txtFirstName = new System.Windows.Forms.TextBox();
            this.txtLastName = new System.Windows.Forms.TextBox();
            this.lbSubjects = new System.Windows.Forms.Label();
            this.lbQQ = new System.Windows.Forms.Label();
            this.rbtnMale = new System.Windows.Forms.RadioButton();
            this.rbtnFemale = new System.Windows.Forms.RadioButton();
            this.lbLastName = new System.Windows.Forms.Label();
            this.pbxImage = new System.Windows.Forms.PictureBox();
            this.lbxSubjects = new System.Windows.Forms.ListBox();
            this.pnBtn = new System.Windows.Forms.Panel();
            this.btnRefresh = new System.Windows.Forms.Button();
            this.btnWatchInfo = new System.Windows.Forms.Button();
            this.btnChooseImage = new System.Windows.Forms.Button();
            this.dateTimePicker1 = new System.Windows.Forms.DateTimePicker();
            this.cbxQQ = new System.Windows.Forms.ComboBox();
            ((System.ComponentModel.ISupportInitialize)(this.pbxImage)).BeginInit();
            this.pnBtn.SuspendLayout();
            this.SuspendLayout();
            // 
            // lbFirstName
            // 
            this.lbFirstName.AutoSize = true;
            this.lbFirstName.Location = new System.Drawing.Point(22, 20);
            this.lbFirstName.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.lbFirstName.Name = "lbFirstName";
            this.lbFirstName.Size = new System.Drawing.Size(45, 13);
            this.lbFirstName.TabIndex = 0;
            this.lbFirstName.Text = "Họ đệm";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(22, 54);
            this.label2.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(0, 13);
            this.label2.TabIndex = 1;
            // 
            // lbBirthday
            // 
            this.lbBirthday.AutoSize = true;
            this.lbBirthday.Location = new System.Drawing.Point(21, 98);
            this.lbBirthday.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.lbBirthday.Name = "lbBirthday";
            this.lbBirthday.Size = new System.Drawing.Size(54, 13);
            this.lbBirthday.TabIndex = 2;
            this.lbBirthday.Text = "Ngày sinh";
            this.lbBirthday.Click += new System.EventHandler(this.label3_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(22, 136);
            this.label4.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(47, 13);
            this.label4.TabIndex = 3;
            this.label4.Text = "Giới tính";
            // 
            // lbLanguage
            // 
            this.lbLanguage.AutoSize = true;
            this.lbLanguage.Location = new System.Drawing.Point(21, 169);
            this.lbLanguage.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.lbLanguage.Name = "lbLanguage";
            this.lbLanguage.Size = new System.Drawing.Size(56, 13);
            this.lbLanguage.TabIndex = 4;
            this.lbLanguage.Text = "Ngoại ngữ";
            // 
            // cbxEnglish
            // 
            this.cbxEnglish.AutoSize = true;
            this.cbxEnglish.Location = new System.Drawing.Point(77, 169);
            this.cbxEnglish.Margin = new System.Windows.Forms.Padding(2);
            this.cbxEnglish.Name = "cbxEnglish";
            this.cbxEnglish.Size = new System.Drawing.Size(75, 17);
            this.cbxEnglish.TabIndex = 5;
            this.cbxEnglish.Tag = "";
            this.cbxEnglish.Text = "Tiếng Anh";
            this.cbxEnglish.UseVisualStyleBackColor = true;
            // 
            // cbxJapanese
            // 
            this.cbxJapanese.AutoSize = true;
            this.cbxJapanese.Location = new System.Drawing.Point(77, 190);
            this.cbxJapanese.Margin = new System.Windows.Forms.Padding(2);
            this.cbxJapanese.Name = "cbxJapanese";
            this.cbxJapanese.Size = new System.Drawing.Size(79, 17);
            this.cbxJapanese.TabIndex = 6;
            this.cbxJapanese.Text = "Tiếng Nhật";
            this.cbxJapanese.UseVisualStyleBackColor = true;
            // 
            // txtFirstName
            // 
            this.txtFirstName.Location = new System.Drawing.Point(79, 17);
            this.txtFirstName.Margin = new System.Windows.Forms.Padding(2);
            this.txtFirstName.Name = "txtFirstName";
            this.txtFirstName.Size = new System.Drawing.Size(76, 20);
            this.txtFirstName.TabIndex = 7;
            // 
            // txtLastName
            // 
            this.txtLastName.Location = new System.Drawing.Point(79, 54);
            this.txtLastName.Margin = new System.Windows.Forms.Padding(2);
            this.txtLastName.Name = "txtLastName";
            this.txtLastName.Size = new System.Drawing.Size(76, 20);
            this.txtLastName.TabIndex = 8;
            // 
            // lbSubjects
            // 
            this.lbSubjects.AutoSize = true;
            this.lbSubjects.Location = new System.Drawing.Point(22, 221);
            this.lbSubjects.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.lbSubjects.Name = "lbSubjects";
            this.lbSubjects.Size = new System.Drawing.Size(49, 13);
            this.lbSubjects.TabIndex = 11;
            this.lbSubjects.Text = "Môn học";
            // 
            // lbQQ
            // 
            this.lbQQ.AutoSize = true;
            this.lbQQ.Location = new System.Drawing.Point(22, 305);
            this.lbQQ.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.lbQQ.Name = "lbQQ";
            this.lbQQ.Size = new System.Drawing.Size(54, 13);
            this.lbQQ.TabIndex = 12;
            this.lbQQ.Text = "Quê quán";
            // 
            // rbtnMale
            // 
            this.rbtnMale.AutoSize = true;
            this.rbtnMale.Checked = true;
            this.rbtnMale.Location = new System.Drawing.Point(76, 132);
            this.rbtnMale.Margin = new System.Windows.Forms.Padding(2);
            this.rbtnMale.Name = "rbtnMale";
            this.rbtnMale.Size = new System.Drawing.Size(47, 17);
            this.rbtnMale.TabIndex = 13;
            this.rbtnMale.TabStop = true;
            this.rbtnMale.Text = "Nam";
            this.rbtnMale.UseVisualStyleBackColor = true;
            this.rbtnMale.CheckedChanged += new System.EventHandler(this.rbtnGender_CheckedChanged);
            // 
            // rbtnFemale
            // 
            this.rbtnFemale.AutoSize = true;
            this.rbtnFemale.Location = new System.Drawing.Point(120, 132);
            this.rbtnFemale.Margin = new System.Windows.Forms.Padding(2);
            this.rbtnFemale.Name = "rbtnFemale";
            this.rbtnFemale.Size = new System.Drawing.Size(39, 17);
            this.rbtnFemale.TabIndex = 14;
            this.rbtnFemale.Text = "Nữ";
            this.rbtnFemale.UseVisualStyleBackColor = true;
            // 
            // lbLastName
            // 
            this.lbLastName.AutoSize = true;
            this.lbLastName.Location = new System.Drawing.Point(22, 54);
            this.lbLastName.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.lbLastName.Name = "lbLastName";
            this.lbLastName.Size = new System.Drawing.Size(26, 13);
            this.lbLastName.TabIndex = 15;
            this.lbLastName.Text = "Tên";
            // 
            // pbxImage
            // 
            this.pbxImage.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pbxImage.Location = new System.Drawing.Point(235, 20);
            this.pbxImage.Margin = new System.Windows.Forms.Padding(2);
            this.pbxImage.Name = "pbxImage";
            this.pbxImage.Size = new System.Drawing.Size(75, 91);
            this.pbxImage.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pbxImage.TabIndex = 16;
            this.pbxImage.TabStop = false;
            // 
            // lbxSubjects
            // 
            this.lbxSubjects.FormattingEnabled = true;
            this.lbxSubjects.Items.AddRange(new object[] {
            "OOP",
            "Onh Ninh",
            "Niea"});
            this.lbxSubjects.Location = new System.Drawing.Point(76, 221);
            this.lbxSubjects.Margin = new System.Windows.Forms.Padding(2);
            this.lbxSubjects.Name = "lbxSubjects";
            this.lbxSubjects.SelectionMode = System.Windows.Forms.SelectionMode.MultiSimple;
            this.lbxSubjects.Size = new System.Drawing.Size(91, 69);
            this.lbxSubjects.TabIndex = 17;
            this.lbxSubjects.SelectedIndexChanged += new System.EventHandler(this.listBox1_SelectedIndexChanged);
            // 
            // pnBtn
            // 
            this.pnBtn.Controls.Add(this.btnRefresh);
            this.pnBtn.Controls.Add(this.btnWatchInfo);
            this.pnBtn.Controls.Add(this.btnChooseImage);
            this.pnBtn.Location = new System.Drawing.Point(219, 177);
            this.pnBtn.Margin = new System.Windows.Forms.Padding(2);
            this.pnBtn.Name = "pnBtn";
            this.pnBtn.Size = new System.Drawing.Size(121, 103);
            this.pnBtn.TabIndex = 19;
            // 
            // btnRefresh
            // 
            this.btnRefresh.Location = new System.Drawing.Point(27, 75);
            this.btnRefresh.Margin = new System.Windows.Forms.Padding(2);
            this.btnRefresh.Name = "btnRefresh";
            this.btnRefresh.Size = new System.Drawing.Size(56, 19);
            this.btnRefresh.TabIndex = 2;
            this.btnRefresh.Text = "Làm mới";
            this.btnRefresh.UseVisualStyleBackColor = true;
            this.btnRefresh.Click += new System.EventHandler(this.button3_Click);
            // 
            // btnWatchInfo
            // 
            this.btnWatchInfo.Location = new System.Drawing.Point(16, 41);
            this.btnWatchInfo.Margin = new System.Windows.Forms.Padding(2);
            this.btnWatchInfo.Name = "btnWatchInfo";
            this.btnWatchInfo.Size = new System.Drawing.Size(85, 19);
            this.btnWatchInfo.TabIndex = 1;
            this.btnWatchInfo.Text = "Xem thông tin";
            this.btnWatchInfo.UseVisualStyleBackColor = true;
            // 
            // btnChooseImage
            // 
            this.btnChooseImage.Location = new System.Drawing.Point(27, 2);
            this.btnChooseImage.Margin = new System.Windows.Forms.Padding(2);
            this.btnChooseImage.Name = "btnChooseImage";
            this.btnChooseImage.Size = new System.Drawing.Size(56, 19);
            this.btnChooseImage.TabIndex = 0;
            this.btnChooseImage.Text = "Chọn ảnh";
            this.btnChooseImage.UseVisualStyleBackColor = true;
            this.btnChooseImage.Click += new System.EventHandler(this.button1_Click);
            // 
            // dateTimePicker1
            // 
            this.dateTimePicker1.Format = System.Windows.Forms.DateTimePickerFormat.Short;
            this.dateTimePicker1.Location = new System.Drawing.Point(79, 98);
            this.dateTimePicker1.Margin = new System.Windows.Forms.Padding(2);
            this.dateTimePicker1.Name = "dateTimePicker1";
            this.dateTimePicker1.Size = new System.Drawing.Size(88, 20);
            this.dateTimePicker1.TabIndex = 20;
            // 
            // cbxQQ
            // 
            this.cbxQQ.FormattingEnabled = true;
            this.cbxQQ.Items.AddRange(new object[] {
            "Bình Định",
            "Kanh Ba",
            "Nghĩa Nang"});
            this.cbxQQ.Location = new System.Drawing.Point(76, 302);
            this.cbxQQ.Margin = new System.Windows.Forms.Padding(2);
            this.cbxQQ.Name = "cbxQQ";
            this.cbxQQ.Size = new System.Drawing.Size(92, 21);
            this.cbxQQ.TabIndex = 18;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(361, 366);
            this.Controls.Add(this.dateTimePicker1);
            this.Controls.Add(this.pnBtn);
            this.Controls.Add(this.cbxQQ);
            this.Controls.Add(this.lbxSubjects);
            this.Controls.Add(this.pbxImage);
            this.Controls.Add(this.lbLastName);
            this.Controls.Add(this.rbtnFemale);
            this.Controls.Add(this.rbtnMale);
            this.Controls.Add(this.lbQQ);
            this.Controls.Add(this.lbSubjects);
            this.Controls.Add(this.txtLastName);
            this.Controls.Add(this.txtFirstName);
            this.Controls.Add(this.cbxJapanese);
            this.Controls.Add(this.cbxEnglish);
            this.Controls.Add(this.lbLanguage);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.lbBirthday);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.lbFirstName);
            this.Margin = new System.Windows.Forms.Padding(2);
            this.Name = "Form1";
            this.Text = "5";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.pbxImage)).EndInit();
            this.pnBtn.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lbFirstName;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label lbBirthday;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label lbLanguage;
        private System.Windows.Forms.CheckBox cbxEnglish;
        private System.Windows.Forms.CheckBox cbxJapanese;
        private System.Windows.Forms.TextBox txtFirstName;
        private System.Windows.Forms.TextBox txtLastName;
        private System.Windows.Forms.Label lbSubjects;
        private System.Windows.Forms.Label lbQQ;
        private System.Windows.Forms.RadioButton rbtnMale;
        private System.Windows.Forms.RadioButton rbtnFemale;
        private System.Windows.Forms.Label lbLastName;
        private System.Windows.Forms.PictureBox pbxImage;
        private System.Windows.Forms.ListBox lbxSubjects;
        private System.Windows.Forms.Panel pnBtn;
        private System.Windows.Forms.DateTimePicker dateTimePicker1;
        private System.Windows.Forms.Button btnChooseImage;
        private System.Windows.Forms.Button btnWatchInfo;
        private System.Windows.Forms.Button btnRefresh;
        private System.Windows.Forms.ComboBox cbxQQ;
    }
}

