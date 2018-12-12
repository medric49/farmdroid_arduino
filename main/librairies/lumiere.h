const int PIN_ANALOG_CAP_LUM = 5;
const int LUM_DIGITAL_PIN = 2;

void active_lum(int *flag_lumiere) {
    digitalWrite(LUM_DIGITAL_PIN, HIGH);
    *flag_lumiere = 1;
    bluetooth_envoyer_lumiere_flag(*flag_lumiere);
}

void desactive_lum(int *flag_lumiere) {
    digitalWrite(LUM_DIGITAL_PIN, LOW);
    *flag_lumiere = 0;
    bluetooth_envoyer_lumiere_flag(*flag_lumiere);
}

void manivelle_lumiere(int *lumiere_autorise, int *lumiere_active, double *lumiere_max, int *flag_lumiere) {
    double val_cap_lum = 0;
    val_cap_lum = analogRead(PIN_ANALOG_CAP_LUM);
    val_cap_lum = map(val_cap_lum, VAL_CAPTEUR_MIN, VAL_CAPTEUR_MAX, 0, 100);


    bluetooth_envoyer_luminosite(val_cap_lum);

    if (*lumiere_autorise == 1) {
        if (val_cap_lum < *lumiere_max) {
            active_lum(flag_lumiere);
        } else {
            desactive_lum(flag_lumiere);
        }
    } else {
        if (*lumiere_active == 1) {
            active_lum(flag_lumiere);
        } else {
            desactive_lum(flag_lumiere);
        }
    }

}
