using System;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;
using System.Windows.Forms;

namespace QLNVado
{
    internal static class Connect
    {
        public static SqlConnection Conn;
        public static SqlDataAdapter Da;
        public static SqlCommand Cmd;

        public static void OpenConnection()
        {
            Conn = new SqlConnection();
            Conn.ConnectionString = ConfigurationManager.ConnectionStrings["VinCowboi"].ConnectionString;
            try
            {
                Conn.Open();
            }
            catch (Exception)
            {
                MessageBox.Show("Kết nối thất bại!", "Lỗi", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        public static void CloseConnection()
        {
            Conn.Close();
        }

        public static DataTable GetData(string cmdText)
        {
            DataTable dt = new DataTable();
            Cmd = new SqlCommand(cmdText);
            Da = new SqlDataAdapter(Cmd);
            Da.Fill(dt);
            return dt;
        }
    }



}
