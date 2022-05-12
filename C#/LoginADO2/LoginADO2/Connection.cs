using System.Configuration;
using System.Data;
using System.Data.SqlClient;
using System.Windows.Forms;

namespace LoginADO2
{
    class Connection
    {
        public static SqlCommand cmd;
        public static SqlDataReader dr;
        public static SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["VinCowboi"].ConnectionString);

        public static DataTable GetData(string cmdText)
        {
            DataTable dt = new DataTable();

            try
            {
                conn.Open();
                cmd = new SqlCommand(cmdText, conn);
                dr = cmd.ExecuteReader();
                dt.Load(dr);
            }
            catch
            {
                MessageBox.Show("Failed(database)!");
            }
            finally
            {
                conn.Close();
            }

            return dt;
        }

        public static int UpdateData(string cmdText)
        {
            int rowsAffected = 0;
            try
            {
                conn.Open();
                cmd = new SqlCommand(cmdText, conn);
                rowsAffected = cmd.ExecuteNonQuery();
            }
            catch
            {
                MessageBox.Show("Failed(database)!");
            }
            finally
            {
                conn.Close();
            }

            return rowsAffected;
        }
    }
}
