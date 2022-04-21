using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SqlClient;
using System.Configuration;
using System.Windows.Forms;

namespace QLNS
{
    static class connect
    {
        static SqlConnection conn;
        static SqlDataAdapter da;
        static SqlCommand cmd;

        static public void openConnect()
        {
            conn = new SqlConnection();
            conn.ConnectionString = ConfigurationManager.ConnectionStrings["VinCowboi"].ConnectionString;
            try
            {
                conn.Open();
            }
            catch (Exception)
            {

                throw;
            }
        }

        static public void InformSucessfulAction(object sender, bool isSuccessful)
        {
            if (isSuccessful)
            {
                MessageBox.Show("Thành công!", (sender as Button).Text, MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else
            {
                MessageBox.Show("Thất bại!", (sender as Button).Text, MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
    }
}
