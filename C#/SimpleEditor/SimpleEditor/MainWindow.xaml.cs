using System.Windows;
using System.Windows.Controls;
using System.Windows.Documents;
using System.Windows.Media;

namespace SimpleEditor
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    /// 
    public partial class MainWindow : Window
    {
        public bool init { get; set; } = false;
        public MainWindow()
        {
            InitializeComponent();

            foreach (FontFamily item in Fonts.SystemFontFamilies)
            {
                cbxFonts.Items.Add(item.Source);
            }

            for (int i = 4; i <= 30; i += 2)
            {
                cbxFontSize.Items.Add(i.ToString());
            }

            cbxFonts.Text = rtxtBox.FontFamily.ToString();
            cbxFontSize.Text = rtxtBox.FontSize.ToString();

            init = true;
        }

        private void rtxtBox_TextChanged(object sender, TextChangedEventArgs e)
        {
            string s = new TextRange(rtxtBox.Document.ContentStart, rtxtBox.Document.ContentEnd).Text;
            statusChar.Content = "Char " + (s.Replace("\n", string.Empty).Length - 1);
            statusLine.Content = "Line " + (s.Split('\n').Length - 1);

            int column = rtxtBox.CaretPosition.GetLineStartPosition(0).GetOffsetToPosition(rtxtBox.CaretPosition);
            statusCol.Content = "Col " + column;
        }

        private void mnuStatusBar_Click(object sender, RoutedEventArgs e)
        {
            if (mnuStatusBar.IsChecked)
            {
                statusBar.Visibility = Visibility.Collapsed;
                mnuStatusBar.IsChecked = false;
            }
            else
            {
                statusBar.Visibility = Visibility.Visible;
                mnuStatusBar.IsChecked = true;
            }
        }

        private void mnuNewFile_Click(object sender, RoutedEventArgs e)
        {
            rtxtBox.IsEnabled = true;
            rtxtBox.Document.Blocks.Clear();
        }

        private void ComboBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if (init)
            {
                rtxtBox.FontSize = 4 + cbxFontSize.SelectedIndex * 2;
                rtxtBox.Focus();
            }
        }

        private void cbxFonts_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if (init)
            {
                rtxtBox.FontFamily = new FontFamily(cbxFonts.SelectedItem.ToString());
                rtxtBox.Focus();
            }
        }
    }
}
