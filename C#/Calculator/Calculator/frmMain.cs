﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Calculator
{
    public partial class frmMain : Form
    {
        public frmMain()
        {
            InitializeComponent();
        }

        private void mnuItemStart_Click(object sender, EventArgs e)
        {
            frmMDI mdi = new frmMDI();
            mdi.MdiParent = this;
            mdi.Show();
        }

        private void frmMain_Load(object sender, EventArgs e)
        {

        }
    }
}
