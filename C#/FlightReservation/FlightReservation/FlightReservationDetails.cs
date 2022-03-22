using System;
using System.Windows.Forms;

namespace FlightReservation
{
    public partial class frmDetails : Form
    {
        public frmDetails()
        {
            InitializeComponent();
        }

        private void listBox2_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void btnVerify_Click(object sender, EventArgs e)
        {
            if (string.IsNullOrWhiteSpace(txtTicketNo.Text) || string.IsNullOrWhiteSpace(txtPassportNo.Text) || string.IsNullOrWhiteSpace(txtPassengerName.Text) || string.IsNullOrEmpty(lbxClass.Text) || string.IsNullOrEmpty(lbxSource.Text) || string.IsNullOrEmpty(lbxDestination.Text) || lbxSource.Text.Equals(lbxDestination.Text))
            {
                MessageBox.Show("Invalid!", "Verify", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            MessageBox.Show("Successfull!", "Verify", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            txtTicketNo.Clear();
            txtPassportNo.Clear();
            txtPassengerName.Clear();
            lbxSource.ClearSelected();
            lbxDestination.ClearSelected();
            pickerFlightDate.ResetText();
            lbxClass.ClearSelected();

            for (int i = 0; i < clbxServices.Items.Count; i++)
            {
                clbxServices.SetItemChecked(i, false);
            }

            clbxServices.ClearSelected();
        }
    }
}
