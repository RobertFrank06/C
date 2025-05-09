using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Server
{
    public partial class Form1 : Form
    {
        private TcpListener _server;
        private readonly List<TcpClient> _clients = new List<TcpClient>();
        private CancellationTokenSource _cts;
        private bool _isServerRunning = false; // Track if the server is running

        public Form1()
        {
            InitializeComponent();
            tB_serverIP.Text = GetLocalIP()?.ToString() ?? "127.0.0.1";
            FormClosing += (s, e) => StopServer();
            toolStripStatusLabel1.Text = "Server ist bereit, bitte starten.";
        }
        private async void bt_starten_Click(object sender, EventArgs e)
        {
            if (_isServerRunning)
            {
                melden("Server wird neugestartet.");
                StopServer(); // Stop any previously running server
            }
            await StartServer(); // Start a new server instance
        }
        private async Task HandleClient(TcpClient client, CancellationToken token)
        {
            var stream = client.GetStream();
            var buffer = new byte[1024];

            try
            {
                while (!token.IsCancellationRequested)
                {
                    int bytesRead = await stream.ReadAsync(buffer, 0, buffer.Length, token);
                    if (bytesRead == 0) break;
                    string message = Encoding.UTF8.GetString(buffer, 0, bytesRead);
                    Invoke(new Action(() => listBox1.Items.Add(message)));
                    await SendToAllClients(message, client); // Nachricht an alle senden
                }
            }
            catch { }
            finally
            {
                lock (_clients) _clients.Remove(client);
                client.Close();
                melden($"Client {client.Client.RemoteEndPoint} getrennt.");
            }
        }
        private async Task SendToAllClients(string message, TcpClient sender = null)
        {
            List<TcpClient> clientsCopy;
            lock (_clients) clientsCopy = new List<TcpClient>(_clients);
            byte[] data = Encoding.UTF8.GetBytes(message);
            foreach (var client in clientsCopy)
            {
                if (client != sender && client.Connected)
                    try { await client.GetStream().WriteAsync(data, 0, data.Length); } catch { }
            }
        }
        private async void bt_senden_Click(object sender, EventArgs e)
        {
            if (string.IsNullOrWhiteSpace(tB_nachricht.Text)) return;
            await SendToAllClients("Server: " + tB_nachricht.Text); // Nachricht an alle Clients senden
            Invoke(new Action(() => listBox1.Items.Add("Server: " + tB_nachricht.Text)));
            melden("Nachricht gesendet.");
            tB_nachricht.Clear();
        }
        private async Task StartServer()
        {
            try
            {
                _server = new TcpListener(GetLocalIP(), 42069);
                _server.Start();
                _cts = new CancellationTokenSource();
                _isServerRunning = true; // Mark the server as running
                bt_starten.Text = "neustarten";
                melden("Server gestartet. Warte auf Clients ...");

                while (!_cts.Token.IsCancellationRequested)
                {
                    var client = await _server.AcceptTcpClientAsync();
                    if (_cts.Token.IsCancellationRequested) break;
                    lock (_clients) _clients.Add(client);
                    melden($"Client {client.Client.RemoteEndPoint} verbunden.");
                    _ = HandleClient(client, _cts.Token);
                }
            }
            catch (Exception ex)
            {
                melden("Fehler beim Start: " + ex.Message);
            }
        }
        private void StopServer()
        {
            if (!_isServerRunning) return; // Prevent stopping the server if it is not running

            _cts?.Cancel();
            _server?.Stop();
            lock (_clients)
            {
                foreach (var c in _clients) c.Close();
                _clients.Clear();
            }
            _isServerRunning = false; // Mark the server as stopped
            melden("Server gestoppt.");
        }
        private void melden(string message) => toolStripStatusLabel1.Text = message;
        private IPAddress GetLocalIP() => Dns.GetHostEntry(Dns.GetHostName()).AddressList.FirstOrDefault(ip => ip.AddressFamily == AddressFamily.InterNetwork);
    }
}
