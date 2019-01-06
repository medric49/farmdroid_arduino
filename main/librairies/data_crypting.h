const char CODE_SEND_TEMPERATURE_VAL = 'a';
const char CODE_SEND_HUMIDITE_VAL = 'b';
const char CODE_SEND_ACIDITE_VAL = 'c';
const char CODE_SEND_LUMINOSITE_VAL = 'd';
const char CODE_SEND_DISTANCE_VAL = 'e';


const char CODE_CONFIG_AUTORISATION_ARROSAGE = 'f';
const char CODE_CONFIG_AUTORISATION_LUMIERE = 'l';
const char CODE_CONFIG_AUTORISATION_DISTANCE = 'm';

const char CODE_CONFIG_ACTIVE_ARROSAGE = 'n';
const char CODE_CONFIG_ACTIVE_LUMIERE = 'o';

const char CODE_CONFIG_TEMPERATURE_MAX = 'g';
const char CODE_CONFIG_HUMIDITE_MAX = 'h';
const char CODE_CONFIG_ACIDITE_MAX = 'i';
const char CODE_CONFIG_LUMINOSITE_MAX = 'j';
const char CODE_CONFIG_DISTANCE_MAX = 'k';

const char CODE_SEND_ARROSAGE_FLAG = 'p';
const char CODE_SEND_LUMIERE_FLAG = 'q';
const char CODE_SEND_ACIDITE_FLAG = 'r';
const char CODE_SEND_DISTANCE_FLAG = 's';

void createCryptedString(char type, double value,char** string) {
  char result[100] =  {0};

  char t[100];
  sprintf(t,dtostrf(value,3,2,"%f"));

  sprintf(result,"%c%s@\0",type, t );
  *string = result;
}


void substring(char* string,char** result,int c) {
    int length = (int) strlen(string);
    if(c <length)
    {
        char subbuff[length-c+1];
        memcpy(subbuff, &string[c], (size_t) (length - c));
        subbuff[length-c] = '\0';
        *result = subbuff;
    }
}

double getCryptedValue(char* chaine) {
    return atof(&chaine[1]);
}

