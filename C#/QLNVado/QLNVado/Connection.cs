using System.Configuration;
using System.Data;
using System.Data.SqlClient;
using System.Windows.Forms;

namespace QLNVado
{
    internal static class Connection
    {
        public static SqlConnection Conn;
        public static SqlCommand Cmd;

        public static void Open()
        {
            Conn = new SqlConnection();
            Conn.ConnectionString = ConfigurationManager.ConnectionStrings["VinCowboi"].ConnectionString.ToString();
            if (Conn.State == ConnectionState.Closed)
            {
                Conn.Open();
            }
        }

        public static void Close()
        {
            if (Conn.State == ConnectionState.Open)
            {
                Conn.Close();
            }
        }

        public static DataTable GetData(string cmdText)
        {
            DataTable dt = new DataTable();

            Cmd = new SqlCommand(cmdText, Conn);
            dt.Load(Cmd.ExecuteReader());

            return dt;
        }

        public static bool UpdateData(string cmdText, string[] name, string[] value)
        {
            bool isSucessful = true;
            try
            {
                Cmd = new SqlCommand(cmdText, Conn);
                Cmd.Parameters.Clear();
                Cmd.CommandText = cmdText;

                for (int i = 0; i < name.Length; i++)
                {
                    Cmd.Parameters.Add(new SqlParameter(name[i], value[i]));
                }

                Cmd.ExecuteNonQuery();
            }
            catch (System.Exception ex)
            {
                isSucessful = false;
                MessageBox.Show(ex.Message);
            }

            return isSucessful;
        }
    }
}
