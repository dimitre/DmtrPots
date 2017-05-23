// Copiado direto do Dmtr Audio
class pot {
  public:
    //int index;
    bool set = false;
    int pin;
    int val;
    float valFloat;
    pot() {}
    pot(int p) : pin(p) {
      set = true;
    }
    int tolerancia = 8;
    bool changed = true;

    void update() {
      if (set) {

        if (abs(val - analogRead(pin)) > tolerancia) {

          val = analogRead(pin);
          valFloat = analogRead(pin) / 1024.0;
          changed = true;
          Serial.println("Pot Changed :: PIN :: " + String(pin) + " :: " + String(valFloat));
        } else {
          //changed = false;
        }
      }
    }
};
