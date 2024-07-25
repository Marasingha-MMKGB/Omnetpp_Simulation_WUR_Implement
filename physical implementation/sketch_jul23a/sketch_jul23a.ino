#include <esp_now.h>
#include <WiFi.h>

// Replace with the MAC Address of your receiver
uint8_t receiverAddress[] = {0xD4, 0x8A, 0xFC, 0xCF, 0xD8, 0x24};

typedef struct struct_message {
  char text1[32];
  char text2[32];
  char text3[32];
} struct_message;

struct_message myData;

void onSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("\r\nLast Packet Send Status: ");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}

void onReceive(const esp_now_recv_info* info, const uint8_t *data, int len) {
  // Print received data (ACK message)
  Serial.print("Received: ");
  Serial.println((char *)data);
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // Register send callback
  esp_now_register_send_cb(onSent);

  // Register receive callback
  esp_now_register_recv_cb(onReceive);

  // Register peer
  esp_now_peer_info_t peerInfo;
  memcpy(peerInfo.peer_addr, receiverAddress, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  // Add peer
  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer");
    return;
  }
}

void loop() {
  strcpy(myData.text1, "Text1");
  strcpy(myData.text2, "Text2");
  strcpy(myData.text3, "Text3");

  // Send message via ESP-NOW
  esp_err_t result = esp_now_send(receiverAddress, (uint8_t *)&myData, sizeof(myData));

  if (result == ESP_OK) {
    Serial.println("Sent with success");
  } else {
    Serial.println("Error sending the data");
  }

  delay(5000);  // Wait for 2 seconds before sending the next message
}
