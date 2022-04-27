using System;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;
using System.Windows.Forms;

namespace QLNVado
{
    internal static class Connection
    {
        public static SqlConnection Conn;
        public static SqlDataAdapter Da;
        public static SqlCommand Cmd;

        public static void Open()
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

        public static void Close()
        {
            Conn.Close();
        }

        public static DataTable GetData(string cmdText)
        {
            DataTable dt = new DataTable();
            Cmd = new SqlCommand(cmdText, Conn);
            Da = new SqlDataAdapter(Cmd);
            Da.Fill(dt);
            return dt;
        }
    }
}
