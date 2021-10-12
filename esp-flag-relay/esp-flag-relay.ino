#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <AutoConnect.h>
#include "PageBuilder.h"

#define D0  16
#define D1  5
#define D2  4
#define D3  0
#define D4  2
#define D5  14
#define D6  12
#define D7  13
#define D8  15

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
 ptr +="<a class=\"button\" href=\"/flag1\">1</a><a class=\"button\" href=\"/flag2\">2</a><a class=\"button\" href=\"/flag3\">3</a><p>\n";
 ptr +="<a class=\"button\" href=\"/flag4\">4</a><a class=\"button\" href=\"/flag5\">5</a><a class=\"button\" href=\"/flag6\">6</a><p>\n";
 ptr +="<a class=\"button\" href=\"/flag7\">7</a><a class=\"button\" href=\"/flag8\">8</a><a class=\"button\" href=\"/flag9\">9</a><p>\n";
 ptr +="</body>\n";
 ptr +="</html>\n";
  return ptr;
}

void rootPage() {
  Server.send(200, "text/html", SendHTML());
}

void handle_flag1() {
  digitalWrite(D0, HIGH);
  delay(1000);
  digitalWrite(D0, LOW);
  Server.send(200, "text/html", SendHTML());
}

void handle_flag2() {

  digitalWrite(D1, HIGH);
  delay(1000);
  digitalWrite(D1, LOW);
  Server.send(200, "text/html", SendHTML());
}

void handle_flag3() {
  
  digitalWrite(D2, HIGH);
  delay(1000);
  digitalWrite(D2, LOW);
  Server.send(200, "text/html", SendHTML());
}

void handle_flag4() {
  
  digitalWrite(D3, HIGH);
  delay(1000);
  digitalWrite(D3, LOW);
  Server.send(200, "text/html", SendHTML());
}

void handle_flag5() {
  
  digitalWrite(D4, HIGH);
  delay(1000);
  digitalWrite(D4, LOW);
  Server.send(200, "text/html", SendHTML());
}

void handle_flag6() {
  
  digitalWrite(D5, HIGH);
  delay(1000);
  digitalWrite(D5, LOW);
  Server.send(200, "text/html", SendHTML());
}

void handle_flag7() {
  
  digitalWrite(D6, HIGH);
  delay(1000);
  digitalWrite(D6, LOW);
  Server.send(200, "text/html", SendHTML());
}

void handle_flag8() {
  
  digitalWrite(D7, HIGH);
  delay(1000);
  digitalWrite(D7, LOW);
  Server.send(200, "text/html", SendHTML());
}

void handle_flag9() {
  
  digitalWrite(D8, HIGH);
  delay(1000);
  digitalWrite(D8, LOW);
  Server.send(200, "text/html", SendHTML());
}

void handle_NotFound() {
  ESP8266WebServer& IntServer = Portal.host();
  IntServer.send(404, "text/html", "Unknown.");
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
  pinMode(D8, OUTPUT);
  
  Server.on("/", rootPage);
  Server.on("/flag1", handle_flag1);
  Server.on("/flag2", handle_flag2);
  Server.on("/flag3", handle_flag3);
  Server.on("/flag4", handle_flag4);
  Server.on("/flag5", handle_flag5);
  Server.on("/flag6", handle_flag6);
  Server.on("/flag7", handle_flag7);
  Server.on("/flag8", handle_flag8);
  Server.on("/flag9", handle_flag9);
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
