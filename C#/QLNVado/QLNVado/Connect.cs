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

        public static void ConnectToDB()
        {
            conn = new SqlConnection();
            conn.ConnectionString = ConfigurationManager.ConnectionStrings["VinCowboi"].ConnectionString;
        }

        public static void OpenConnection()
        {
            try
            {
                conn.Open();    
            }
            catch (Exception)
            {
                MessageBox.Show("Kết nối thất bại!", "Lỗi", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        public static void CloseConnection()
        {
            conn.Close();
        }

        public static DataTable GetData(string cmdText)
        {
            DataTable dt = new DataTable();
            da = new SqlDataAdapter(cmdText, conn);
            da.Fill(dt);
            return dt;
        }
    }

    

}
