using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Configuration;
using System.Data.SqlClient;
using System.Windows.Forms;
using System.Data;

namespace QLNVado
{
    static class Connect
    {
        static SqlConnection conn;
        static SqlDataAdapter da;
        static SqlCommand cmd;

        static public void ConnectToDB()
        {
            
        }

        static public void OpenConnection()
        {
            conn = new SqlConnection();
            conn.ConnectionString = ConfigurationManager.ConnectionStrings["VinCowboi"].ConnectionString;
            try
            {
                conn.Open();    
            }
            catch (Exception)
            {
                MessageBox.Show("Kết nối thất bại!", "Lỗi", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        static public void CloseConnection()
        {
            conn.Close();
        }

        static public DataTable GetData(string cmdText)
        {
            DataTable dt = new DataTable();
            cmd = new SqlCommand(cmdText);
            da = new SqlDataAdapter(cmd);
            da.Fill(dt);
            return dt;
        }
    }

    

}
