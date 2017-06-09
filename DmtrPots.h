//#define DEBUG 1 

class pot {
public:
	bool set = false;
	uint8_t pin;
	uint16_t val = 4000; //um numero arbitrario pra forcar o update no inicio do software
	float valFloat;
	uint8_t valByte;

	int * pInt = NULL;
	double min = 0;
	double max = 10;
	int lastVal;

	float * pFloat = NULL;
	float lastFloat;
	double * pDouble = NULL;
	double lastDouble;

	String name;

	pot() {}
	pot(uint8_t p) : pin(p) {
		set = true;
	}
	uint8_t tolerance = 5;

	void addFloat(float * var, String n, float mi, float ma) {
		name = n;
		pFloat = var;
		min = mi;
		max = ma;
	}

	void addInt(int * var, String n, int mi, int ma) {
		name = n;
		pInt = var;
		min = mi;
		max = ma;
	}

	void addDouble(double * var, String n, int mi, int ma) {
		name = n;
		pDouble = var;
		min = mi;
		max = ma;
	}

	void update() {
		if (set) {
			if (abs(val - analogRead(pin)) > tolerance) {
				val = analogRead(pin);
				valFloat = analogRead(pin) / 1024.0;
				valByte = map(analogRead(pin), 0, 1023, 0, 255);
				if (pInt != NULL) {
//					*pInt = map(analogRead(pin), 0, 1023, min, max);
					*pInt = constrain(map(analogRead(pin), 0, 1023, min, max+1), min, max);
					if (lastVal != *pInt) {
						Serial.println(name + " :: " + String(*pInt));
						lastVal = *pInt;
					}
				}

				if (pFloat != NULL) {
					*pFloat = map(analogRead(pin), 0, 1023, min, max);
					if (lastFloat != *pFloat) {
						Serial.println(name + " :: " + String(*pFloat));
						lastFloat = *pFloat;
					}
				}

				if (pDouble != NULL) {
					*pDouble = map(analogRead(pin), 0, 1023, min * 100.0, max * 100.0) / 100.0;
					if (lastDouble != *pDouble) {
						Serial.println(name + " :: " + String(*pDouble));
						lastDouble = *pDouble;
					}
				}
				//changed = true;
#ifdef  DEBUG                
				Serial.println("Pot Changed :: PIN :: " + String(pin) + " :: " + String(valFloat) + " :: " + String(valByte));
#endif                
			} else {
				//changed = false;
			}
		}
	}
};