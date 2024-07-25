#include <esp_now.h>
#include <WiFi.h>

typedef struct struct_message {
  char text1[32];
  char text2[32];
  char text3[32];
} struct_message;

void onReceive(const esp_now_recv_info* info, const uint8_t *data, int len) {
  // Cast the incoming data to the struct_message type
  struct_message receivedData;
  memcpy(&receivedData, data, sizeof(receivedData));

  Serial.print("Bytes received: ");
  Serial.println(len);
  Serial.print("Text1: ");
  Serial.println(receivedData.text1);
  Serial.print("Text2: ");
  Serial.println(receivedData.text2);
  Serial.print("Text3: ");
  Serial.println(receivedData.text3);

  // Send acknowledgment back to sender
  uint8_t senderAddress[] ={0xE0, 0x5A, 0x1B, 0x75, 0xF4, 0x28};
  memcpy(senderAddress, info->src_addr, 6);

  char ackMessage[] = "ACK";
  esp_now_send(senderAddress, (uint8_t *)ackMessage, sizeof(ackMessage));
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // Register receive callback
  esp_now_register_recv_cb(onReceive);
}

void loop() {
  // Nothing to do here
}
