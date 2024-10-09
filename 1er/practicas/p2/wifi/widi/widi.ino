  #include <WiFi.h>

const char* ssid = "TuSSID";
const char* password = "TuContraseña";

WiFiServer server(80); // Puerto 80 para servidor HTTP

void setup() {
  Serial.begin(115200);

  // Conexión a la red WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando a WiFi...");
  }
  Serial.println("Conectado a la red WiFi!");

  // Iniciar servidor
  server.begin();
}

void loop() {
  WiFiClient client = server.available(); // Escuchar por clientes
  if (client) {
    Serial.println("Nuevo cliente conectado.");
    String request = client.readStringUntil('\r');
    Serial.println("Petición recibida: " + request);

    // Aquí puedes procesar la petición y controlar las salidas
    if (request.indexOf("/encender") != -1) {
      // Encender un LED o activar una salida
      digitalWrite(LED_BUILTIN, HIGH);
    } else if (request.indexOf("/apagar") != -1) {
      // Apagar un LED o desactivar una salida
      digitalWrite(LED_BUILTIN, LOW);
    }

    // Enviar respuesta HTTP
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println();
    client.println("<html><body>Salida controlada</body></html>");
    client.stop(); // Cerrar la conexión
    Serial.println("Cliente desconectado.");
  }
}
