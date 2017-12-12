// echo '{ "port": D5 }' | json2msgpack >data.mp
// coapclient.py -o POST -p coap://192.168.2.103/digital -f data.mp
#include <Arduino.h>
#include <tfwifi.h>
#include <WiFiUdp.h>
#include "microcoap/coap.h"
#include "udp_microcoap_wrapper.h"
#include "digital.h"
#include "main.h"

WiFiUDP Udp;

void setup() {
  Serial.begin(9600);
  setup_wifi();
  Udp.begin(5683);

  coap_setup();
  udp_microcoap_wrapper_init(&Udp);
}

extern void app_loop();

void loop() {
    udp_microcoap_wrapper *c = udp_microcoap_wrapper_get();
    c->ops->handle_udp_coap_message(c);
    app_loop();
}
