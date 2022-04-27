using System;
using System.Data;
using System.Windows.Forms;
namespace QLNVado
{
    public partial class FrmMain : Form
    {
        DataSet ds;
        string cmdText;
        public FrmMain()
        {
            InitializeComponent();
        }

        private void cbbDepartment_Load()
        {
            cmdText = "SELECT * FROM PhongBan";
            DataTable dt = Connection.GetData(cmdText);
            cbbDepartment.DataSource = dt;
            cbbDepartment.DisplayMember = "TenPB";
            cbbDepartment.ValueMember = "MaPB";
        }

        private void FrmMain_Load(object sender, EventArgs e)
        {
            Connection.Open();
            ds = new DataSet("QLNV");
            cbbDepartment_Load();
            Connection.Close();
        }
    }
}
