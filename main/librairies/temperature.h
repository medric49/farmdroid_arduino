const int PIN_ANALOG_CAP_TEMP_1 = 4;
const int PIN_ANALOG_CAP_TEMP_2 = 3;

const int PIN_ANALOG_CAP_HUM = 2;

void active_arrosage(int *flag_arrosage) {
    *flag_arrosage = 1;
    bluetooth_envoyer_arrosage_flag(*flag_arrosage);
}

void desactive_arrosage(int *flag_arrosage) {
    *flag_arrosage = 0;
    bluetooth_envoyer_arrosage_flag(*flag_arrosage);
}

void manivelle_temperature_humidite(int *arrosage_autorise, int *arrosage_active, double *temperature_max,
                                    double *humidite_max, int *flag_arrosage) {
    double val1 = analogRead(PIN_ANALOG_CAP_TEMP_1);
    double val2 = analogRead(PIN_ANALOG_CAP_TEMP_2);

    val1 = val1 * (500.0 / 1023);
    val2 = val1 * (500.0 / 1023);

    double val_temperature = (val1 + val2) / 2;

    double val_humidite = 0;

    bluetooth_envoyer_temperature(val_temperature);

    bluetooth_envoyer_humidite(val_humidite);

    Serial.print((*temperature_max));
    Serial.print('|');
    if (*arrosage_autorise == 1) {
        if (val_temperature > *temperature_max || val_humidite < *humidite_max) {
            active_arrosage(flag_arrosage);
        } else {
            desactive_arrosage(flag_arrosage);
        }
    } else {

        if (*arrosage_active == 1) {
            active_arrosage(flag_arrosage);
        } else {
            desactive_arrosage(flag_arrosage);
        }

    }


}
