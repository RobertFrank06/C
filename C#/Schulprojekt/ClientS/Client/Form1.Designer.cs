namespace Client
{
    partial class Form1
    {
        /// <summary>
        /// Erforderliche Designervariable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Verwendete Ressourcen bereinigen.
        /// </summary>
        /// <param name="disposing">True, wenn verwaltete Ressourcen gelöscht werden sollen; andernfalls False.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Vom Windows Form-Designer generierter Code

        /// <summary>
        /// Erforderliche Methode für die Designerunterstützung.
        /// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
        /// </summary>
        private void InitializeComponent()
        {
            this.statusStrip1 = new System.Windows.Forms.StatusStrip();
            this.toolStripStatusLabel1 = new System.Windows.Forms.ToolStripStatusLabel();
            this.bt_verbinden = new System.Windows.Forms.Button();
            this.bt_senden = new System.Windows.Forms.Button();
            this.tB_nachricht = new System.Windows.Forms.TextBox();
            this.listBox1 = new System.Windows.Forms.ListBox();
            this.tB_serverIP = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.statusStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // statusStrip1
            // 
            this.statusStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.statusStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripStatusLabel1});
            this.statusStrip1.Location = new System.Drawing.Point(0, 470);
            this.statusStrip1.Name = "statusStrip1";
            this.statusStrip1.Size = new System.Drawing.Size(998, 22);
            this.statusStrip1.TabIndex = 0;
            this.statusStrip1.Text = "statusStrip1";
            // 
            // toolStripStatusLabel1
            // 
            this.toolStripStatusLabel1.Name = "toolStripStatusLabel1";
            this.toolStripStatusLabel1.Size = new System.Drawing.Size(118, 17);
            this.toolStripStatusLabel1.Text = "toolStripStatusLabel1";
            // 
            // bt_verbinden
            // 
            this.bt_verbinden.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.bt_verbinden.Location = new System.Drawing.Point(319, 110);
            this.bt_verbinden.Name = "bt_verbinden";
            this.bt_verbinden.Size = new System.Drawing.Size(100, 28);
            this.bt_verbinden.TabIndex = 1;
            this.bt_verbinden.Text = "verbinden";
            this.bt_verbinden.UseVisualStyleBackColor = true;
            this.bt_verbinden.Click += new System.EventHandler(this.bt_verbinden_Click);
            // 
            // bt_senden
            // 
            this.bt_senden.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.bt_senden.Location = new System.Drawing.Point(319, 321);
            this.bt_senden.Name = "bt_senden";
            this.bt_senden.Size = new System.Drawing.Size(75, 26);
            this.bt_senden.TabIndex = 2;
            this.bt_senden.Text = "senden";
            this.bt_senden.UseVisualStyleBackColor = true;
            this.bt_senden.Click += new System.EventHandler(this.bt_senden_Click);
            // 
            // tB_nachricht
            // 
            this.tB_nachricht.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.tB_nachricht.Location = new System.Drawing.Point(319, 291);
            this.tB_nachricht.Name = "tB_nachricht";
            this.tB_nachricht.Size = new System.Drawing.Size(327, 20);
            this.tB_nachricht.TabIndex = 3;
            this.tB_nachricht.Text = "Hallo Server";
            // 
            // listBox1
            // 
            this.listBox1.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.listBox1.FormattingEnabled = true;
            this.listBox1.HorizontalScrollbar = true;
            this.listBox1.Location = new System.Drawing.Point(320, 151);
            this.listBox1.Name = "listBox1";
            this.listBox1.ScrollAlwaysVisible = true;
            this.listBox1.Size = new System.Drawing.Size(327, 134);
            this.listBox1.TabIndex = 4;
            // 
            // tB_serverIP
            // 
            this.tB_serverIP.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.tB_serverIP.Location = new System.Drawing.Point(531, 115);
            this.tB_serverIP.Name = "tB_serverIP";
            this.tB_serverIP.Size = new System.Drawing.Size(116, 20);
            this.tB_serverIP.TabIndex = 5;
            // 
            // label1
            // 
            this.label1.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(464, 118);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(67, 13);
            this.label1.TabIndex = 6;
            this.label1.Text = "SERVER IP:";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSize = true;
            this.ClientSize = new System.Drawing.Size(998, 492);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.tB_serverIP);
            this.Controls.Add(this.listBox1);
            this.Controls.Add(this.tB_nachricht);
            this.Controls.Add(this.bt_senden);
            this.Controls.Add(this.bt_verbinden);
            this.Controls.Add(this.statusStrip1);
            this.Name = "Form1";
            this.Text = "Client";
            this.statusStrip1.ResumeLayout(false);
            this.statusStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.StatusStrip statusStrip1;
        private System.Windows.Forms.ToolStripStatusLabel toolStripStatusLabel1;
        private System.Windows.Forms.Button bt_verbinden;
        private System.Windows.Forms.Button bt_senden;
        private System.Windows.Forms.TextBox tB_nachricht;
        private System.Windows.Forms.ListBox listBox1;
        private System.Windows.Forms.TextBox tB_serverIP;
        private System.Windows.Forms.Label label1;
    }
}

