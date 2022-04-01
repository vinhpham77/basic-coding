using System.Windows;

namespace Calculator2
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        public bool GetData(out int a, out int b)
        {
            a = 0;
            b = 0;

            return int.TryParse(txt1.Text, out a) && int.TryParse(txt2.Text, out b);
        }

        private void CheckBox_Checked(object sender, RoutedEventArgs e)
        {

        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            int a;
            int b;

            if (GetData(out a, out b))
            {
                txtAnsw.Text = (a + b).ToString();
            }
            else
            {
                txtAnsw.Text = "Invalid!";
            }
        }

        private void btnSub_Click(object sender, RoutedEventArgs e)
        {
            int a;
            int b;

            if (GetData(out a, out b))
            {
                txtAnsw.Text = (a - b).ToString();
            }
            else
            {
                txtAnsw.Text = "Invalid!";
            }
        }

        private void cbxCenter_Click(object sender, RoutedEventArgs e)
        {
            if ((bool)cbxCenter.IsChecked)
            {
                txt1.TextAlignment = TextAlignment.Center;
                txt2.TextAlignment = TextAlignment.Center;
                txtAnsw.TextAlignment = TextAlignment.Center;
            }
            else
            {
                txt1.TextAlignment = TextAlignment.Left;
                txt2.TextAlignment = TextAlignment.Left;
                txtAnsw.TextAlignment = TextAlignment.Left;
            }
        }
    }
}
