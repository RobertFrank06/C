using System;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Client
{
    public partial class Form1 : Form
    {
        private TcpClient _client;
        private NetworkStream _stream;
        private CancellationTokenSource _cts;

        public Form1()
        {
            InitializeComponent();
            tB_serverIP.Text = GetLocalIP();
            FormClosing += (sender, e) => Disconnect();
            melden("Bitte verbinden ...");
        }
        private async void bt_verbinden_Click(object sender, EventArgs e)
        {
            if (bt_verbinden.Text == "Trennen")
            {
                Disconnect();
                bt_verbinden.Text = "Verbinden";
                melden("Verbindung getrennt");
                return;
            }

            await TryConnectAsync();
        }
        private async Task TryConnectAsync()
        {
            bt_verbinden.Enabled = false;

            if (string.IsNullOrWhiteSpace(tB_serverIP.Text))
            {
                melden("Bitte eine gültige IP-Adresse eingeben.");
                bt_verbinden.Enabled = true;
                return;
            }

            try
            {
                _client = new TcpClient();
                await _client.ConnectAsync(tB_serverIP.Text, 42069);
                _stream = _client.GetStream();
                _cts = new CancellationTokenSource();
                _ = ReceiveMessagesAsync(_cts.Token);
                melden("Verbunden mit Server");
                bt_verbinden.Text = "Trennen";
            }
            catch (Exception ex)
            {
                melden($"Verbindung fehlgeschlagen: {ex.Message}");
            }
            finally
            {
                bt_verbinden.Enabled = true;
            }
        }
        private async void bt_senden_Click(object sender, EventArgs e)
        {
            if (_stream == null || !_client.Connected)
            {
                melden("Nicht verbunden.");
                return;
            }

            string message = $"Client {GetLocalIP()}: {tB_nachricht.Text}";
            if (string.IsNullOrWhiteSpace(message)) return;

            await SendMessageAsync(message);
        }
        private async Task SendMessageAsync(string message)
        {
            byte[] data = Encoding.UTF8.GetBytes(message);
            try
            {
                await _stream.WriteAsync(data, 0, data.Length);
                Invoke(new Action(() => listBox1.Items.Add(message)));
                melden("Nachricht gesendet");
                tB_nachricht.Clear();
            }
            catch (Exception ex)
            {
                melden($"Senden fehlgeschlagen: {ex.Message}");
            }
        }
        private async Task ReceiveMessagesAsync(CancellationToken token)
        {
            byte[] buffer = new byte[1024];
            while (!token.IsCancellationRequested)
            {
                int bytesRead;
                try
                {
                    bytesRead = await _stream.ReadAsync(buffer, 0, buffer.Length, token);
                    if (bytesRead == 0) throw new Exception("Verbindung geschlossen");
                }
                catch
                {
                    Disconnect();
                    melden("Verbindung zum Server verloren");
                    break;
                }
                Invoke(new Action(() => listBox1.Items.Add(Encoding.UTF8.GetString(buffer, 0, bytesRead))));
            }
        }
        private void Disconnect()
        {
            _cts?.Cancel();
            _stream?.Close();
            _client?.Close();
        }
        private string GetLocalIP() => Dns.GetHostEntry(Dns.GetHostName()).AddressList.FirstOrDefault(ip => ip.AddressFamily == AddressFamily.InterNetwork)?.ToString() ?? "";
        private void melden(string message) => toolStripStatusLabel1.Text = message;
    }
}
