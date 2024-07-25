#include <esp_now.h>
#include <WiFi.h>

typedef struct struct_message {
  char a[32];
} struct_message;

void onReceive(const esp_now_recv_info* info, const uint8_t *data, int len) {
  // Cast the incoming data to the struct_message type
  struct_message receivedData;
  memcpy(&receivedData, data, sizeof(receivedData));

  Serial.print("Bytes received: ");
  Serial.println(len);
  Serial.print("Message: ");
  Serial.println(receivedData.a);
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
