const int PIN_DIGITAL_BLUETOOTH_RX = 12;
const int PIN_DIGITAL_BLUETOOTH_TX = 11;

SoftwareSerial mybluetooth(PIN_DIGITAL_BLUETOOTH_RX,PIN_DIGITAL_BLUETOOTH_TX); // (RX, TX) (pin Rx BT, pin Tx BT)


void bluetooth_envoyer_arrosage_flag(int flag) {
    char* string;
    createCryptedString(CODE_SEND_ARROSAGE_FLAG,flag,&string);
    mybluetooth.print(string);
}

void bluetooth_envoyer_lumiere_flag(int flag) {
    char* string;
    createCryptedString(CODE_SEND_LUMIERE_FLAG,flag,&string);
    mybluetooth.print(string);
}

void bluetooth_envoyer_acidite_flag(int flag) {
    char* string;
    createCryptedString(CODE_SEND_ACIDITE_FLAG,flag,&string);
    mybluetooth.print(string);
}

void bluetooth_envoyer_distance_flag(int flag) {
    char* string;
    createCryptedString(CODE_SEND_DISTANCE_FLAG,flag,&string);
    mybluetooth.print(string);
}


void bluetooth_envoyer_temperature(double value) {
    char* string;
    createCryptedString(CODE_SEND_TEMPERATURE_VAL,value,&string);
    mybluetooth.print(string);
    Serial.println(string);
}


void bluetooth_envoyer_humidite(double value) {
    char* string;
    createCryptedString(CODE_SEND_HUMIDITE_VAL,value,&string);
    mybluetooth.print(string);
    Serial.println(string);
}

void bluetooth_envoyer_acidite(double value) {
    char* string;
    createCryptedString(CODE_SEND_ACIDITE_VAL,value,&string);
    mybluetooth.print(string);
}

void bluetooth_envoyer_luminosite(double value) {
    char* string;
    createCryptedString(CODE_SEND_ACIDITE_VAL,value,&string);
    mybluetooth.print(string);
    Serial.println(string);
}

void bluetooth_envoyer_position(double value) {
    char* string;
    createCryptedString(CODE_SEND_DISTANCE_VAL,value,&string);
    mybluetooth.print(string);
}



void manivelle_bluetooth_lumiere(int* lumiere_autorise,int* lumiere_active,double* lumiere_max,int* flag_lumiere,char* bluetooth_response){
    double value = getCryptedValue(bluetooth_response);

    switch (bluetooth_response[0]) {
        case CODE_CONFIG_AUTORISATION_LUMIERE:
            *lumiere_autorise = (int)value;
            break;

        case CODE_CONFIG_ACTIVE_LUMIERE:
            *lumiere_active = (int)value;
            break;

        case CODE_CONFIG_LUMINOSITE_MAX:
            *lumiere_max = (int)value;
            break;
    }

}

void manivelle_bluetooth_temperature_humidite(int* arrosage_autorise,int* arrosage_active,double* temperature_max,double* humidite_max,int* flag_arrosage,char* bluetooth_response){
    double value = getCryptedValue(bluetooth_response);

    switch (bluetooth_response[0]) {
        case CODE_CONFIG_AUTORISATION_ARROSAGE:
            *arrosage_autorise = (int)value;
            break;

        case CODE_CONFIG_ACTIVE_ARROSAGE:
            *arrosage_active = (int)value;
            break;

        case CODE_CONFIG_TEMPERATURE_MAX:
            *temperature_max = value;
            break;

        case CODE_CONFIG_HUMIDITE_MAX:
            *humidite_max = value;
            break;
    }
}

void manivelle_bluetooth_acidite(double* acidite_max,int* flag_acidite,char* bluetooth_response) {
    double value = getCryptedValue(bluetooth_response);

    switch (bluetooth_response[0]) {
        case CODE_CONFIG_ACIDITE_MAX:
            *acidite_max = value;
            break;
    }
}

void manivelle_bluetooth_distance(int* distance_autorise,double* distance_max,int* flag_distance,char* bluetooth_response) {
    double value = getCryptedValue(bluetooth_response);

    switch (bluetooth_response[0]) {
        case CODE_CONFIG_AUTORISATION_DISTANCE:
            *distance_autorise = (int)value;
            break;

        case CODE_CONFIG_DISTANCE_MAX:
            *distance_max = value;
            break;
    }
}
