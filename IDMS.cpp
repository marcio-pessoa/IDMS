/* IDMS.cpp - Infrared Distance Measuring Sensor Library
 * 
 */

#include "Arduino.h"
#include "IDMS.h"

/* IDMS
 * 
 * Description
 *   Infrared distance measuring sensor.
 * 
 *   Infrared ()
 * 
 * Parameters
 *   none
 * 
 * Returns
 *   void
 */
IDMS::IDMS() {
  _type = GP2Y0A21YK0F;
}

/* attach
 * 
 * Description
 *   Set sensor Arduino pin.
 * 
 *   attach (byte pin)
 * 
 * Parameters
 *   pin: Arduino pin connected to Signal sensor output
 * 
 * Returns
 *   void
 */
void IDMS::attach(byte pin) {
  pinMode(pin, INPUT);
  _pin = pin;
}

/* type
 * 
 * Description
 *   Set sensor type.
 * 
 *   sensor.type()
 * 
 * Parameters
 *   type: 
 *     Valid values: GP2Y0A21YK0F (default)
 * 
 * Returns
 *   void
 */
void IDMS::type(byte type) {
  _type = type;
  // 
  switch (_type) {
    default:
    case GP2Y0A21YK0F: {
      _range = 80;
      break;
    }
    case GP2Y0A02YK: {
      _range = 150;
      break;
    }
  }
}

/* read
 * 
 * Description
 *   Get sensor distance.
 * 
 *   sensor.read()
 * 
 * Parameters
 *   none
 * 
 * Returns
 *   float: distance to nearest bulkhead (centimeters)
 */
float IDMS::read() {
  float distance;
  pinMode(_pin, INPUT);
  distance = 27.728 *
             pow(map(analogRead(_pin), 0, 1023, 0, 5000) / 1000.0, -1.2045);
  return distance;
}
