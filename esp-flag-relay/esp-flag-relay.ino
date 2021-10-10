#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <AutoConnect.h>
#include "PageBuilder.h"

ESP8266WebServer Server;
AutoConnect Portal(Server);
AutoConnectConfig Config;

String SendHTML(){
  String ptr = "<!DOCTYPE html> <html>\n";
 ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
 ptr +="<title>Ergo Display Control</title>\n";
 ptr +="<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
 ptr +="body{margin-top: 0px;} h1 {color: #444444;margin-top: 30px; margin-bottom: 30px} h3 {color: #444444;}\n";
 ptr +=".button {display:inline-block; background-color: darkgreen;color: white;padding: 32px 32px; \n";
 ptr +="text-decoration: none;font-size: 32px; font-weight: bold; margin: 6px ;cursor: pointer;border-radius: 12px;}\n";
 ptr +=".button.white {background-color: white;}\n";
 ptr +=".button:hover{background-color: limegreen}\n";
 ptr +="</style></head>\n";
 ptr +="<body>\n";
 ptr +="<h1>Ergo Flag Display</h1>\n";
 ptr +="<a class=\"button\" href=\"/flag1\">&#x2615;</a><a class=\"button\" href=\"/flag2\">&#x1F377;</a><a class=\"button\" href=\"/flag3\">3</a><p>\n";
 ptr +="<a class=\"button\" href=\"/flag4\">4</a><a class=\"button\" href=\"/flag5\">5</a><a class=\"button\" href=\"/flag6\">6</a><p>\n";
 ptr +="<a class=\"button\" href=\"/flag7\">7</a><a class=\"button\" href=\"/flag8\">8</a><a class=\"button white\">-</a>\n";
 ptr +="</body>\n";
 ptr +="</html>\n";
  return ptr;
}

void rootPage() {
  Server.send(200, "text/html", SendHTML());
}

void handle_flag1() {
  digitalWrite(LED_BUILTIN, HIGH);
  Server.send(200, "text/html", SendHTML());
}

void handle_flag2() {
  digitalWrite(LED_BUILTIN, LOW);
  Server.send(200, "text/html", SendHTML());
}

void handle_flag3() {
  digitalWrite(LED_BUILTIN, HIGH);
  Server.send(200, "text/html", SendHTML());
}

void handle_flag4() {
  digitalWrite(LED_BUILTIN, LOW);
  Server.send(200, "text/html", SendHTML());
}

void handle_flag5() {
  digitalWrite(LED_BUILTIN, HIGH);
  Server.send(200, "text/html", SendHTML());
}

void handle_flag6() {
  digitalWrite(LED_BUILTIN, LOW);
  Server.send(200, "text/html", SendHTML());
}

void handle_flag7() {
  digitalWrite(LED_BUILTIN, HIGH);
  Server.send(200, "text/html", SendHTML());
}

void handle_flag8() {
  digitalWrite(LED_BUILTIN, LOW);
  Server.send(200, "text/html", SendHTML());
}

void handle_NotFound() {
  ESP8266WebServer& IntServer = Portal.host();
  IntServer.send(404, "text/html", "Unknown.");
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

  Server.on("/", rootPage);
  Server.on("/flag1", handle_flag1);
  Server.on("/flag2", handle_flag2);
  Server.on("/flag3", handle_flag3);
  Server.on("/flag4", handle_flag4);
  Server.on("/flag5", handle_flag5);
  Server.on("/flag6", handle_flag6);
  Server.on("/flag7", handle_flag7);
  Server.on("/flag8", handle_flag8);
  Server.onNotFound(handle_NotFound);

  Config.channel = 3;
  Portal.config(Config);
  Portal.begin();

  Serial.begin(115200);
  Serial.println("Web Server started:" + WiFi.localIP().toString());
}

void loop() {
  Portal.handleClient();
}
