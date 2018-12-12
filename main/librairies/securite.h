const int PIN_DIGITAL_ULTRASON_TRIGGER = 10;
const int PIN_DIGITAL_ULTRASON_ECHO = 9;
const unsigned long MEASURE_TIMEOUT =25000UL;

void active_securite(int* flag_distance) {
    *flag_distance = 1;
    bluetooth_envoyer_distance_flag(*flag_distance);
}

void desactive_securite(int* flag_distance) {
    *flag_distance = 0;
    bluetooth_envoyer_distance_flag(*flag_distance);
}

void manivelle_securite(int* distance_autorise,double* distance_max,int* flag_distance) {

    digitalWrite(PIN_DIGITAL_ULTRASON_TRIGGER,HIGH);
    delayMicroseconds(10);
    digitalWrite(PIN_DIGITAL_ULTRASON_TRIGGER,LOW);

    long measure = pulseIn(PIN_DIGITAL_ULTRASON_ECHO, HIGH, MEASURE_TIMEOUT);

    //Retourne la distance en cm
    double val = (measure * 340) / (2.0 * 10000);

    if(*distance_autorise == 1) {
        if(val < *distance_max) {
            active_securite(flag_distance);
        }
        else {
            desactive_securite(flag_distance);
        }

    }

}
