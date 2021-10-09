#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <AutoConnect.h>


ESP8266WebServer Server;
AutoConnect Portal(Server);
AutoConnectConfig Config;


void rootPage() {
  char content[] = "Hello, world";
  Server.send(200, "text/plain", content);
}

void handleNotFound() {
  ESP8266WebServer& IntServer = Portal.host();
  IntServer.send(404, "text/html", "Unknown.");
}

void setup() {
  delay(1000);
  Serial.begin(115200);
  Serial.println();

  Server.on("/", rootPage);
  Server.onNotFound(handleNotFound);

  Config.channel = 3;
  Portal.config(Config);
  Portal.begin();
  Serial.println("Web Server started:" + WiFi.localIP().toString());
}

void loop() {
  Portal.handleClient();
}
