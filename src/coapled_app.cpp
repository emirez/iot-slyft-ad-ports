#include "Arduino.h"
#include "microcoap/coap.h"
#include "coapled_app.h"
#include "digital.h"
#include "main.h"
#include <stdio.h>
#include <string.h>

void app_loop(){

}

bool TUT1__coapled__post___digital(
    struct TUT1__coapled__post___digital_req *req,
    struct TUT1__coapled__post___digital_resp *resp){

    int port_nr;
    strncpy(resp->data.digital_205.port, req->data.digital.port, sizeof(resp->data.digital_205.port));
     if(strcmp(req->data.digital.port,"D1")==0){port_nr = D1;}
else if(strcmp(req->data.digital.port,"D3")==0){port_nr = D3;}
else if(strcmp(req->data.digital.port,"D5")==0){port_nr = D5;}
else if(strcmp(req->data.digital.port,"D7")==0){port_nr = D7;}

    pinMode(port_nr, INPUT_PULLUP);
    resp->data.digital_205.value = digitalRead(port_nr);
    Serial.print("req->data.digital.port: ");
    Serial.println(req->data.digital.port);
    Serial.print("req->data.digital.value: ");
    Serial.println(resp->data.digital_205.value);

    resp->response_code = COAP_RSPCODE_CONTENT;
    return true;
}
