#include <SoftwareSerial.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

#include "librairies/data_crypting.h"
#include "librairies/bluetooth.h"
#include "librairies/constante.h"
#include "librairies/lumiere.h"
#include "librairies/temperature.h"
#include "librairies/securite.h"
#include "librairies/acidite.h"


int lumiere_autorise = 1;
int lumiere_active = 0;
double lumiere_max = 30;
int flag_lumiere = 0;

double temperature_max = 30;
double humidite_max = 20;
int arrosage_autorise = 1;
int arrosage_active = 0;
int flag_arrosage = 0;


double acidite_max = 7;
int flag_acidite = 0;


double distance_max = 1;
int distance_autorise = 1;
int flag_distance = 0;


char bluetooth_response[100] = {0};

void setup() {
    Serial.begin(9600);
    mybluetooth.begin(9600);


    pinMode(LUM_DIGITAL_PIN, OUTPUT);
    digitalWrite(LUM_DIGITAL_PIN, LOW);
    pinMode(PIN_DIGITAL_ULTRASON_TRIGGER,OUTPUT);
    pinMode(PIN_DIGITAL_ULTRASON_ECHO,INPUT);
}

void loop() {

    manivelle_lumiere(&lumiere_autorise, &lumiere_active, &lumiere_max, &flag_lumiere);
    manivelle_temperature_humidite(&arrosage_autorise, &arrosage_active, &temperature_max, &humidite_max, &flag_lumiere);
    manivelle_securite(&distance_autorise, &distance_max, &flag_distance);
    manivelle_acidite(&acidite_max, &flag_acidite);

    if (mybluetooth.available()) {
        int i = 0;
        int flag = 0;
        do {
            char x = (char)mybluetooth.read();
            if (x != '\0')
                bluetooth_response[i++] = x;
            else
                flag = 1;
            delay(5);
        } while (mybluetooth.available() && (flag==0));


        manivelle_bluetooth_lumiere(&lumiere_autorise, &lumiere_active, &lumiere_max, &flag_lumiere, bluetooth_response);
        manivelle_bluetooth_temperature_humidite(&arrosage_autorise, &arrosage_active, &temperature_max, &humidite_max, &flag_arrosage, bluetooth_response);
        manivelle_bluetooth_acidite(&acidite_max, &flag_acidite, bluetooth_response);
        manivelle_bluetooth_distance(&distance_autorise, &distance_max, &flag_distance, bluetooth_response);
    }
    delay(500);
}
