/* IDMS.h - Infrared Distance Measuring Sensor Library
 * 
 * Author: Márcio Pessoa <marcio@pessoa.eti.br>
 * Contributors: none
 * 
 * Sensor technical specification
 *   GP2Y0A21YK0F (default)
 *     Range: 10cm ~ 80cm
 *     Connector: 3-JST
 *     This SHARP distance sensor bounces IR off objects to determine how far
 *     away they are. It returns an analog voltage that can be used to 
 *     determine how close the nearest object is.
 *     The analog voltage out will range from 3V when an object is only 
 *     4" (10 cm) away and 0.4V when the object is 32" (80 cm) away.
 * 
 *         Front view
 *       ╭───┬┬───────╮
 *       │ o ││     0 │
 *       ╰───┴┼──┬────╯
 *            └──┘
 *            1 2 3
 * 
 *       1 - Signal
 *       2 - GND
 *       3 - Vcc
 * 
 *   GP2Y0A02YK
 *     Range: 20cm ~ 150cm
 *     Connector: 3-JST
 *     This SHARP distance sensor bounces IR off objects to determine how far
 *     away they are. It returns an analog voltage that can be used to 
 *     determine how close the nearest object is.
 *     **** The analog voltage out will range from 3V when an object is only 
 *     4" (10 cm) away and 0.4V when the object is 32" (80 cm) away. **** Need corretion
 * 
 *        Front view
 *       ╭───╮ ╭───╮
 *       │ o ╞═╡ O │
 *       ╰───┼─┼───╯
 *           └─┘
 *          1 2 3
 * 
 *       1 - Signal
 *       2 - GND
 *       3 - Vcc
 * 
 *   GP2Y0A41
 * 
 *   GP2Y0A60SZLF
 * 
 *   GP2Y0D810Z0F
 *     Range: 2cm ~ 10cm
 * 
 * Change log
 * 2015-05-14
 *         Improvement: Library renamed from Infrared to IDMS to solve library
 *                      name conflict with oficial Arduino libraries.
 * 
 * 2015-05-14
 *         Experimental version.
 */

#ifndef IDMS_h
#define IDMS_h

#include "Arduino.h"

#define GP2Y0A21YK0F 0
#define GP2Y0A02YK 1

class IDMS
{
  public:
    IDMS();
    void attach(byte pin);
    void type(byte sensor_type = GP2Y0A21YK0F);
    float read();
  private:
    byte _pin;
    byte _type;
    int _range;
};

#endif
