using System.Configuration;
using System.Data;
using System.Data.SqlClient;

namespace QLNS
{
    static class Connection
    {
        public static SqlConnection conn;
        public static SqlDataAdapter da;
        public static SqlCommand cmd;

        public static void Open()
        {
            conn = new SqlConnection
            {
                ConnectionString = ConfigurationManager.ConnectionStrings["VinCowboy"].ConnectionString
            };

            if (conn.State == ConnectionState.Closed)
            {
                conn.Open();
            }
        }

        public static void Close()
        {
            if (conn.State == ConnectionState.Open)
            {
                conn.Close();
            }
        }

        public static DataTable GetDaTa(string cmdText)
        {
            Open();
            DataTable dt = new DataTable();
            cmd = new SqlCommand(cmdText, conn);
            da = new SqlDataAdapter(cmd);
            da.Fill(dt);
            Close();
            return dt;
        }
    }
}
