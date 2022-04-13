using System.Windows.Forms;

namespace QLNS
{
    partial class frmQLNS
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(frmQLNS));
            this.pnlInfo = new System.Windows.Forms.Panel();
            this.cbbDepartment = new System.Windows.Forms.ComboBox();
            this.txtCoefficientsSal = new System.Windows.Forms.TextBox();
            this.txtEmployeeName = new System.Windows.Forms.TextBox();
            this.txtEmployeeNo = new System.Windows.Forms.TextBox();
            this.lblCoefficientsSal = new System.Windows.Forms.Label();
            this.lblDepartment = new System.Windows.Forms.Label();
            this.lblEmployeeName = new System.Windows.Forms.Label();
            this.lblEmployeeNo = new System.Windows.Forms.Label();
            this.pnlButtons = new System.Windows.Forms.Panel();
            this.btnRefresh = new System.Windows.Forms.Button();
            this.btnGroupBy = new System.Windows.Forms.Button();
            this.btnDelete = new System.Windows.Forms.Button();
            this.btnUpdate = new System.Windows.Forms.Button();
            this.btnInsert = new System.Windows.Forms.Button();
            this.txtSearch = new System.Windows.Forms.TextBox();
            this.btnSearch = new System.Windows.Forms.Button();
            this.dgvQLNS = new System.Windows.Forms.DataGridView();
            this.pnlInfo.SuspendLayout();
            this.pnlButtons.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgvQLNS)).BeginInit();
            this.SuspendLayout();
            // 
            // pnlInfo
            // 
            this.pnlInfo.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pnlInfo.Controls.Add(this.cbbDepartment);
            this.pnlInfo.Controls.Add(this.txtCoefficientsSal);
            this.pnlInfo.Controls.Add(this.txtEmployeeName);
            this.pnlInfo.Controls.Add(this.txtEmployeeNo);
            this.pnlInfo.Controls.Add(this.lblCoefficientsSal);
            this.pnlInfo.Controls.Add(this.lblDepartment);
            this.pnlInfo.Controls.Add(this.lblEmployeeName);
            this.pnlInfo.Controls.Add(this.lblEmployeeNo);
            resources.ApplyResources(this.pnlInfo, "pnlInfo");
            this.pnlInfo.Name = "pnlInfo";
            // 
            // cbbDepartment
            // 
            this.cbbDepartment.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbbDepartment.FormattingEnabled = true;
            resources.ApplyResources(this.cbbDepartment, "cbbDepartment");
            this.cbbDepartment.Name = "cbbDepartment";
            // 
            // txtCoefficientsSal
            // 
            resources.ApplyResources(this.txtCoefficientsSal, "txtCoefficientsSal");
            this.txtCoefficientsSal.Name = "txtCoefficientsSal";
            // 
            // txtEmployeeName
            // 
            resources.ApplyResources(this.txtEmployeeName, "txtEmployeeName");
            this.txtEmployeeName.Name = "txtEmployeeName";
            // 
            // txtEmployeeNo
            // 
            resources.ApplyResources(this.txtEmployeeNo, "txtEmployeeNo");
            this.txtEmployeeNo.Name = "txtEmployeeNo";
            // 
            // lblCoefficientsSal
            // 
            resources.ApplyResources(this.lblCoefficientsSal, "lblCoefficientsSal");
            this.lblCoefficientsSal.Name = "lblCoefficientsSal";
            // 
            // lblDepartment
            // 
            resources.ApplyResources(this.lblDepartment, "lblDepartment");
            this.lblDepartment.Name = "lblDepartment";
            // 
            // lblEmployeeName
            // 
            resources.ApplyResources(this.lblEmployeeName, "lblEmployeeName");
            this.lblEmployeeName.Name = "lblEmployeeName";
            // 
            // lblEmployeeNo
            // 
            resources.ApplyResources(this.lblEmployeeNo, "lblEmployeeNo");
            this.lblEmployeeNo.Name = "lblEmployeeNo";
            // 
            // pnlButtons
            // 
            this.pnlButtons.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pnlButtons.Controls.Add(this.btnRefresh);
            this.pnlButtons.Controls.Add(this.btnGroupBy);
            this.pnlButtons.Controls.Add(this.btnDelete);
            this.pnlButtons.Controls.Add(this.btnUpdate);
            this.pnlButtons.Controls.Add(this.btnInsert);
            resources.ApplyResources(this.pnlButtons, "pnlButtons");
            this.pnlButtons.Name = "pnlButtons";
            // 
            // btnRefresh
            // 
            resources.ApplyResources(this.btnRefresh, "btnRefresh");
            this.btnRefresh.Name = "btnRefresh";
            this.btnRefresh.UseVisualStyleBackColor = true;
            // 
            // btnGroupBy
            // 
            resources.ApplyResources(this.btnGroupBy, "btnGroupBy");
            this.btnGroupBy.Name = "btnGroupBy";
            this.btnGroupBy.UseVisualStyleBackColor = true;
            // 
            // btnDelete
            // 
            resources.ApplyResources(this.btnDelete, "btnDelete");
            this.btnDelete.Name = "btnDelete";
            this.btnDelete.UseVisualStyleBackColor = true;
            // 
            // btnUpdate
            // 
            resources.ApplyResources(this.btnUpdate, "btnUpdate");
            this.btnUpdate.Name = "btnUpdate";
            this.btnUpdate.UseVisualStyleBackColor = true;
            // 
            // btnInsert
            // 
            resources.ApplyResources(this.btnInsert, "btnInsert");
            this.btnInsert.Name = "btnInsert";
            this.btnInsert.UseVisualStyleBackColor = true;
            this.btnInsert.Click += new System.EventHandler(this.btnInsert_Click);
            // 
            // txtSearch
            // 
            resources.ApplyResources(this.txtSearch, "txtSearch");
            this.txtSearch.Name = "txtSearch";
            // 
            // btnSearch
            // 
            resources.ApplyResources(this.btnSearch, "btnSearch");
            this.btnSearch.Name = "btnSearch";
            this.btnSearch.UseVisualStyleBackColor = true;
            // 
            // dgvQLNS
            // 
            this.dgvQLNS.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dgvQLNS.BackgroundColor = System.Drawing.SystemColors.Control;
            this.dgvQLNS.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            resources.ApplyResources(this.dgvQLNS, "dgvQLNS");
            this.dgvQLNS.Name = "dgvQLNS";
            this.dgvQLNS.RowTemplate.Height = 24;
            // 
            // frmQLNS
            // 
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.None;
            resources.ApplyResources(this, "$this");
            this.Controls.Add(this.dgvQLNS);
            this.Controls.Add(this.btnSearch);
            this.Controls.Add(this.txtSearch);
            this.Controls.Add(this.pnlButtons);
            this.Controls.Add(this.pnlInfo);
            this.MaximizeBox = false;
            this.Name = "frmQLNS";
            this.ShowIcon = false;
            this.Load += new System.EventHandler(this.frmQLNS_Load);
            this.pnlInfo.ResumeLayout(false);
            this.pnlInfo.PerformLayout();
            this.pnlButtons.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dgvQLNS)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Panel pnlInfo;
        private System.Windows.Forms.Panel pnlButtons;
        private System.Windows.Forms.Button btnInsert;
        private System.Windows.Forms.Button btnUpdate;
        private System.Windows.Forms.Button btnDelete;
        private System.Windows.Forms.Button btnGroupBy;
        private System.Windows.Forms.Button btnRefresh;
        private System.Windows.Forms.Label lblEmployeeNo;
        private System.Windows.Forms.Label lblEmployeeName;
        private System.Windows.Forms.Label lblDepartment;
        private System.Windows.Forms.Label lblCoefficientsSal;
        private System.Windows.Forms.TextBox txtEmployeeNo;
        private System.Windows.Forms.TextBox txtEmployeeName;
        private System.Windows.Forms.TextBox txtCoefficientsSal;
        private System.Windows.Forms.ComboBox cbbDepartment;
        private System.Windows.Forms.TextBox txtSearch;
        private System.Windows.Forms.Button btnSearch;
        private System.Windows.Forms.DataGridView dgvQLNS;
    }
}

