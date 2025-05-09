namespace Server
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
            this.bt_starten = new System.Windows.Forms.Button();
            this.statusStrip1 = new System.Windows.Forms.StatusStrip();
            this.toolStripStatusLabel1 = new System.Windows.Forms.ToolStripStatusLabel();
            this.tB_nachricht = new System.Windows.Forms.TextBox();
            this.bt_senden = new System.Windows.Forms.Button();
            this.listBox1 = new System.Windows.Forms.ListBox();
            this.label1 = new System.Windows.Forms.Label();
            this.tB_serverIP = new System.Windows.Forms.TextBox();
            this.statusStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // bt_starten
            // 
            this.bt_starten.AutoSize = true;
            this.bt_starten.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.bt_starten.Location = new System.Drawing.Point(12, 22);
            this.bt_starten.Name = "bt_starten";
            this.bt_starten.Size = new System.Drawing.Size(49, 23);
            this.bt_starten.TabIndex = 0;
            this.bt_starten.Text = "starten";
            this.bt_starten.UseVisualStyleBackColor = true;
            this.bt_starten.Click += new System.EventHandler(this.bt_starten_Click);
            // 
            // statusStrip1
            // 
            this.statusStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.statusStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripStatusLabel1});
            this.statusStrip1.Location = new System.Drawing.Point(0, 252);
            this.statusStrip1.Name = "statusStrip1";
            this.statusStrip1.Size = new System.Drawing.Size(324, 22);
            this.statusStrip1.TabIndex = 1;
            this.statusStrip1.Text = "statusStrip1";
            // 
            // toolStripStatusLabel1
            // 
            this.toolStripStatusLabel1.Name = "toolStripStatusLabel1";
            this.toolStripStatusLabel1.Size = new System.Drawing.Size(118, 17);
            this.toolStripStatusLabel1.Text = "toolStripStatusLabel1";
            // 
            // tB_nachricht
            // 
            this.tB_nachricht.Location = new System.Drawing.Point(12, 187);
            this.tB_nachricht.Name = "tB_nachricht";
            this.tB_nachricht.Size = new System.Drawing.Size(282, 20);
            this.tB_nachricht.TabIndex = 2;
            this.tB_nachricht.Text = "Hallo Client";
            // 
            // bt_senden
            // 
            this.bt_senden.Location = new System.Drawing.Point(12, 213);
            this.bt_senden.Name = "bt_senden";
            this.bt_senden.Size = new System.Drawing.Size(75, 25);
            this.bt_senden.TabIndex = 3;
            this.bt_senden.Text = "senden";
            this.bt_senden.UseVisualStyleBackColor = true;
            this.bt_senden.Click += new System.EventHandler(this.bt_senden_Click);
            // 
            // listBox1
            // 
            this.listBox1.FormattingEnabled = true;
            this.listBox1.HorizontalScrollbar = true;
            this.listBox1.Location = new System.Drawing.Point(12, 60);
            this.listBox1.Name = "listBox1";
            this.listBox1.ScrollAlwaysVisible = true;
            this.listBox1.SelectionMode = System.Windows.Forms.SelectionMode.MultiSimple;
            this.listBox1.Size = new System.Drawing.Size(282, 95);
            this.listBox1.TabIndex = 4;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(132, 33);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(67, 13);
            this.label1.TabIndex = 8;
            this.label1.Text = "SERVER IP:";
            // 
            // tB_serverIP
            // 
            this.tB_serverIP.Location = new System.Drawing.Point(199, 28);
            this.tB_serverIP.Name = "tB_serverIP";
            this.tB_serverIP.Size = new System.Drawing.Size(96, 20);
            this.tB_serverIP.TabIndex = 7;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoScroll = true;
            this.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.AutoValidate = System.Windows.Forms.AutoValidate.EnableAllowFocusChange;
            this.ClientSize = new System.Drawing.Size(324, 274);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.tB_serverIP);
            this.Controls.Add(this.listBox1);
            this.Controls.Add(this.bt_senden);
            this.Controls.Add(this.tB_nachricht);
            this.Controls.Add(this.statusStrip1);
            this.Controls.Add(this.bt_starten);
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.Text = "Server";
            this.statusStrip1.ResumeLayout(false);
            this.statusStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button bt_starten;
        private System.Windows.Forms.StatusStrip statusStrip1;
        private System.Windows.Forms.ToolStripStatusLabel toolStripStatusLabel1;
        private System.Windows.Forms.TextBox tB_nachricht;
        private System.Windows.Forms.Button bt_senden;
        private System.Windows.Forms.ListBox listBox1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox tB_serverIP;
    }
}

