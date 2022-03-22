namespace FlightReservation
{
    partial class frmDetails
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
            this.lbHeading = new System.Windows.Forms.Label();
            this.lbTicketNo = new System.Windows.Forms.Label();
            this.lbPassengerName = new System.Windows.Forms.Label();
            this.lbPassportNo = new System.Windows.Forms.Label();
            this.lbSource = new System.Windows.Forms.Label();
            this.lbFlightDate = new System.Windows.Forms.Label();
            this.lbClass = new System.Windows.Forms.Label();
            this.lbServices = new System.Windows.Forms.Label();
            this.txtTicketNo = new System.Windows.Forms.TextBox();
            this.txtPassengerName = new System.Windows.Forms.TextBox();
            this.txtPassportNo = new System.Windows.Forms.TextBox();
            this.lbxSource = new System.Windows.Forms.ListBox();
            this.lbxClass = new System.Windows.Forms.ListBox();
            this.lbDestination = new System.Windows.Forms.Label();
            this.lbxDestination = new System.Windows.Forms.ListBox();
            this.pickerFlightDate = new System.Windows.Forms.DateTimePicker();
            this.btnVerify = new System.Windows.Forms.Button();
            this.btnClear = new System.Windows.Forms.Button();
            this.clbxServices = new System.Windows.Forms.CheckedListBox();
            this.SuspendLayout();
            // 
            // lbHeading
            // 
            this.lbHeading.AutoSize = true;
            this.lbHeading.BackColor = System.Drawing.Color.LightSalmon;
            this.lbHeading.Location = new System.Drawing.Point(127, 31);
            this.lbHeading.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.lbHeading.Name = "lbHeading";
            this.lbHeading.Size = new System.Drawing.Size(201, 23);
            this.lbHeading.TabIndex = 0;
            this.lbHeading.Text = "Flight Reservation Details";
            // 
            // lbTicketNo
            // 
            this.lbTicketNo.AutoSize = true;
            this.lbTicketNo.BackColor = System.Drawing.SystemColors.GradientActiveCaption;
            this.lbTicketNo.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.lbTicketNo.Location = new System.Drawing.Point(41, 85);
            this.lbTicketNo.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.lbTicketNo.Name = "lbTicketNo";
            this.lbTicketNo.Size = new System.Drawing.Size(82, 23);
            this.lbTicketNo.TabIndex = 1;
            this.lbTicketNo.Text = "Ticket No";
            // 
            // lbPassengerName
            // 
            this.lbPassengerName.AutoSize = true;
            this.lbPassengerName.BackColor = System.Drawing.SystemColors.GradientActiveCaption;
            this.lbPassengerName.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.lbPassengerName.Location = new System.Drawing.Point(41, 131);
            this.lbPassengerName.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.lbPassengerName.Name = "lbPassengerName";
            this.lbPassengerName.Size = new System.Drawing.Size(148, 23);
            this.lbPassengerName.TabIndex = 2;
            this.lbPassengerName.Text = "Passenger\'s Name";
            // 
            // lbPassportNo
            // 
            this.lbPassportNo.AutoSize = true;
            this.lbPassportNo.BackColor = System.Drawing.SystemColors.GradientActiveCaption;
            this.lbPassportNo.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.lbPassportNo.Location = new System.Drawing.Point(41, 173);
            this.lbPassportNo.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.lbPassportNo.Name = "lbPassportNo";
            this.lbPassportNo.Size = new System.Drawing.Size(102, 23);
            this.lbPassportNo.TabIndex = 3;
            this.lbPassportNo.Text = "Passport No";
            // 
            // lbSource
            // 
            this.lbSource.AutoSize = true;
            this.lbSource.BackColor = System.Drawing.SystemColors.GradientActiveCaption;
            this.lbSource.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.lbSource.Location = new System.Drawing.Point(41, 226);
            this.lbSource.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.lbSource.Name = "lbSource";
            this.lbSource.Size = new System.Drawing.Size(62, 23);
            this.lbSource.TabIndex = 4;
            this.lbSource.Text = "Source";
            // 
            // lbFlightDate
            // 
            this.lbFlightDate.AutoSize = true;
            this.lbFlightDate.BackColor = System.Drawing.SystemColors.GradientActiveCaption;
            this.lbFlightDate.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.lbFlightDate.Location = new System.Drawing.Point(41, 368);
            this.lbFlightDate.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.lbFlightDate.Name = "lbFlightDate";
            this.lbFlightDate.Size = new System.Drawing.Size(93, 23);
            this.lbFlightDate.TabIndex = 5;
            this.lbFlightDate.Text = "Flight Date";
            // 
            // lbClass
            // 
            this.lbClass.AutoSize = true;
            this.lbClass.BackColor = System.Drawing.SystemColors.GradientActiveCaption;
            this.lbClass.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.lbClass.Location = new System.Drawing.Point(41, 423);
            this.lbClass.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.lbClass.Name = "lbClass";
            this.lbClass.Size = new System.Drawing.Size(48, 23);
            this.lbClass.TabIndex = 6;
            this.lbClass.Text = "Class";
            // 
            // lbServices
            // 
            this.lbServices.AutoSize = true;
            this.lbServices.BackColor = System.Drawing.SystemColors.GradientActiveCaption;
            this.lbServices.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.lbServices.Location = new System.Drawing.Point(41, 495);
            this.lbServices.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.lbServices.Name = "lbServices";
            this.lbServices.Size = new System.Drawing.Size(70, 23);
            this.lbServices.TabIndex = 7;
            this.lbServices.Text = "Services";
            // 
            // txtTicketNo
            // 
            this.txtTicketNo.Location = new System.Drawing.Point(231, 85);
            this.txtTicketNo.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.txtTicketNo.Name = "txtTicketNo";
            this.txtTicketNo.Size = new System.Drawing.Size(188, 30);
            this.txtTicketNo.TabIndex = 8;
            // 
            // txtPassengerName
            // 
            this.txtPassengerName.Location = new System.Drawing.Point(231, 131);
            this.txtPassengerName.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.txtPassengerName.Name = "txtPassengerName";
            this.txtPassengerName.Size = new System.Drawing.Size(188, 30);
            this.txtPassengerName.TabIndex = 9;
            // 
            // txtPassportNo
            // 
            this.txtPassportNo.Location = new System.Drawing.Point(231, 173);
            this.txtPassportNo.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.txtPassportNo.Name = "txtPassportNo";
            this.txtPassportNo.Size = new System.Drawing.Size(188, 30);
            this.txtPassportNo.TabIndex = 10;
            // 
            // lbxSource
            // 
            this.lbxSource.FormattingEnabled = true;
            this.lbxSource.ItemHeight = 23;
            this.lbxSource.Items.AddRange(new object[] {
            "Brazil",
            "Vietnam",
            "Japan",
            "USA",
            "Russia"});
            this.lbxSource.Location = new System.Drawing.Point(231, 226);
            this.lbxSource.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.lbxSource.Name = "lbxSource";
            this.lbxSource.Size = new System.Drawing.Size(188, 50);
            this.lbxSource.TabIndex = 12;
            // 
            // lbxClass
            // 
            this.lbxClass.FormattingEnabled = true;
            this.lbxClass.ItemHeight = 23;
            this.lbxClass.Items.AddRange(new object[] {
            "First",
            "Bussiness",
            "Casual"});
            this.lbxClass.Location = new System.Drawing.Point(231, 423);
            this.lbxClass.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.lbxClass.Name = "lbxClass";
            this.lbxClass.Size = new System.Drawing.Size(188, 50);
            this.lbxClass.TabIndex = 13;
            this.lbxClass.SelectedIndexChanged += new System.EventHandler(this.listBox2_SelectedIndexChanged);
            // 
            // lbDestination
            // 
            this.lbDestination.AutoSize = true;
            this.lbDestination.BackColor = System.Drawing.SystemColors.GradientActiveCaption;
            this.lbDestination.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.lbDestination.Location = new System.Drawing.Point(41, 296);
            this.lbDestination.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.lbDestination.Name = "lbDestination";
            this.lbDestination.Size = new System.Drawing.Size(97, 23);
            this.lbDestination.TabIndex = 14;
            this.lbDestination.Text = "Destination";
            // 
            // lbxDestination
            // 
            this.lbxDestination.FormattingEnabled = true;
            this.lbxDestination.ItemHeight = 23;
            this.lbxDestination.Items.AddRange(new object[] {
            "Brazil",
            "Vietnam",
            "Japan",
            "USA",
            "Russia"});
            this.lbxDestination.Location = new System.Drawing.Point(231, 296);
            this.lbxDestination.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.lbxDestination.Name = "lbxDestination";
            this.lbxDestination.Size = new System.Drawing.Size(188, 50);
            this.lbxDestination.TabIndex = 16;
            // 
            // pickerFlightDate
            // 
            this.pickerFlightDate.Format = System.Windows.Forms.DateTimePickerFormat.Short;
            this.pickerFlightDate.Location = new System.Drawing.Point(231, 368);
            this.pickerFlightDate.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.pickerFlightDate.Name = "pickerFlightDate";
            this.pickerFlightDate.Size = new System.Drawing.Size(188, 30);
            this.pickerFlightDate.TabIndex = 17;
            // 
            // btnVerify
            // 
            this.btnVerify.BackColor = System.Drawing.Color.LightSalmon;
            this.btnVerify.Location = new System.Drawing.Point(131, 591);
            this.btnVerify.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.btnVerify.Name = "btnVerify";
            this.btnVerify.Size = new System.Drawing.Size(85, 34);
            this.btnVerify.TabIndex = 18;
            this.btnVerify.Text = "Verify";
            this.btnVerify.UseVisualStyleBackColor = false;
            this.btnVerify.Click += new System.EventHandler(this.btnVerify_Click);
            // 
            // btnClear
            // 
            this.btnClear.BackColor = System.Drawing.Color.LightSalmon;
            this.btnClear.Location = new System.Drawing.Point(243, 591);
            this.btnClear.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.btnClear.Name = "btnClear";
            this.btnClear.Size = new System.Drawing.Size(85, 34);
            this.btnClear.TabIndex = 19;
            this.btnClear.Text = "Clear";
            this.btnClear.UseVisualStyleBackColor = false;
            this.btnClear.Click += new System.EventHandler(this.btnClear_Click);
            // 
            // clbxServices
            // 
            this.clbxServices.CheckOnClick = true;
            this.clbxServices.FormattingEnabled = true;
            this.clbxServices.Items.AddRange(new object[] {
            "Child Care",
            "Nurse",
            "Chef"});
            this.clbxServices.Location = new System.Drawing.Point(231, 495);
            this.clbxServices.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.clbxServices.Name = "clbxServices";
            this.clbxServices.Size = new System.Drawing.Size(188, 54);
            this.clbxServices.TabIndex = 20;
            // 
            // frmDetails
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 23F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(477, 643);
            this.Controls.Add(this.clbxServices);
            this.Controls.Add(this.btnClear);
            this.Controls.Add(this.btnVerify);
            this.Controls.Add(this.pickerFlightDate);
            this.Controls.Add(this.lbxDestination);
            this.Controls.Add(this.lbDestination);
            this.Controls.Add(this.lbxClass);
            this.Controls.Add(this.lbxSource);
            this.Controls.Add(this.txtPassportNo);
            this.Controls.Add(this.txtPassengerName);
            this.Controls.Add(this.txtTicketNo);
            this.Controls.Add(this.lbServices);
            this.Controls.Add(this.lbClass);
            this.Controls.Add(this.lbFlightDate);
            this.Controls.Add(this.lbSource);
            this.Controls.Add(this.lbPassportNo);
            this.Controls.Add(this.lbPassengerName);
            this.Controls.Add(this.lbTicketNo);
            this.Controls.Add(this.lbHeading);
            this.Font = new System.Drawing.Font("Segoe UI", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.Name = "frmDetails";
            this.Text = "Flight Reservation Details";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lbHeading;
        private System.Windows.Forms.Label lbTicketNo;
        private System.Windows.Forms.Label lbPassengerName;
        private System.Windows.Forms.Label lbPassportNo;
        private System.Windows.Forms.Label lbSource;
        private System.Windows.Forms.Label lbFlightDate;
        private System.Windows.Forms.Label lbClass;
        private System.Windows.Forms.Label lbServices;
        private System.Windows.Forms.TextBox txtTicketNo;
        private System.Windows.Forms.TextBox txtPassengerName;
        private System.Windows.Forms.TextBox txtPassportNo;
        private System.Windows.Forms.ListBox lbxSource;
        private System.Windows.Forms.ListBox lbxClass;
        private System.Windows.Forms.Label lbDestination;
        private System.Windows.Forms.ListBox lbxDestination;
        private System.Windows.Forms.DateTimePicker pickerFlightDate;
        private System.Windows.Forms.Button btnVerify;
        private System.Windows.Forms.Button btnClear;
        private System.Windows.Forms.CheckedListBox clbxServices;
    }
}

