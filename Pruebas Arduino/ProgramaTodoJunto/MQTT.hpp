WiFiClient espClient;
PubSubClient mqttClient(espClient);  
void SuscribeMqtt(char* topic) {
  mqttClient.subscribe(topic);
}
String payload;
void PublishMqtt(char* topic,unsigned long data) {  
  payload = "";
  payload = String(data);  
  mqttClient.publish(topic, (char*)payload.c_str());
}
String content = "";
void OnMqttReceived(char* topic, byte* payload, unsigned int length) {
  Serial.print("Received on ");  Serial.print(topic);  Serial.print(": ");
  content = "";
  for (size_t i = 0; i < length; i++) {  
      content.concat((char)payload[i]);
  }
  Serial.print(content);  Serial.println();
}

String getContent(){
  return content;
}
