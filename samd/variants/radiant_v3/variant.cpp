/*
 * The early guys might need external pullups ( sad face )
 * but I'm hoping I can put a portion in the bootloader's run
 * section which reads their value and configures the pin
 * as an output with its previous value.
 * If that doesn't work they might need external caps to ground
 * to extend their hold time.
 *
 * TPS54[48]24: float => enable (2.6V/3.1V)
 * TPS62147: float => ???? (leakage = 100 nA max, 0.7V falling,
 *                          2 pF board capacitance, maybe 50 us?
 */

// NOTE NOTE NOTE -
// THIS NEEDS TO BE FIXED, ITS ALL MESSED UP

/* + Pin number |  PIN  | Label      | Comments
 * +------------+-------+------------+-------------------
 * | 0          | PB02  | EN1V0      | restore-to-output
 * | 1          | PA02  | EN2V6      | restore-to-output
 * | 2          | PB08  | EN3V1      | restore-to-output
 * | 3          | PA04  | EN1V8      | restore-to-output
 * | 4          | PA06  | EN2V5      | restore-to-output
 * | 5          | PB12  | ENMGT      | restore-to-output
 * | 6          | PA12  | ENVINMON   | restore-to-output
 * | 7          | PB01  | VINMON     | analog
 * | 8          | PB03  | PG1V0      | input with pullup
 * | 9          | PB07  | PG2V6      | input with pullup
 * | 10         | PB09  | PG3V1      | input with pullup
 * | 11 (mistake pin)
 * | 12 (mistake pin)
 * | 13 (mistake pin)
 * | 14         | PA05  | PG1V8      | input with pullup
 * | 15         | PA07  | PG2V5      | input with pullup
 * | 16         | PB13  | \MGTDET    | input with pullup
 * | 17         | PA03  | 1V0        | analog
 * | 18         | PB04  | 1V8        | analog
 * | 19         | PB05  | 2V5        | analog
 * | 20         | PB06  | QUAD2_MON  | analog
 * | 21         | PB00  | QUAD3_MON  | analog
 * | 22         | PB31  | BM_EN_10MHZ| output
 * | 23         | PB15  | SD_DETECT  | input with pullup
 * | 24         | PB14  | FPGA_PROGB | input with pullup
 * | 25         | PA20  | FPGA_DONE  | input with pullup
 * | 26         | PB23  | LEDX27     | digital
 * | 27         | PB22  | LEDX28     | digital
 * | 28         | PA21  | BM_INTR    | input with pullup
 * | 29         | PB17  | TDO        | digital
 * | 30         | PB16  | TDI        | digital
 * | 31         | PA19  | TMS        | digital
 * | 32         | PA18  | TCK        | digital
 * | 33         | PA28  | BMGPIO2    | digital
 * | 34         | PA27  | BMGPIO3    | digital
 * | 35         | PA08  | SPI0_MOSI  | digital
 * | 36         | PA09  | SPI0_SCK   | digital
 * | 37         | PA14  | SPI0_MISO  | digital
 * | 38         | PA13  | SPI0_CS0   | digital
 * | 39         | PA15  | SPI0_CS1   | digital
 * | 40         | PB15  | SD_DETECT  | digital with pullup
 * | 41         | PA10  | FPGA_TX    | digital
 * | 42         | PA11  | FPGA_RX    | digital
 * | 43         | PA00  | CB_TX      | digital
 * | 44         | PA01  | CB_RX      | digital
 * | 45         | PA17  | DBG_RX     | digital
 * | 46         | PA16  | DBG_TX     | digital
 * | 47         | PA22  | SDA        | digital
 * | 48         | PA23  | SCL        | digital
 * | 49         | PB11  | BM_SCLK    | digital
 * | 50         | PB10  | BM_MOSI    | digital
 * | 51         | PA24  | USB_D-     | usb
 * | 52         | PA25  | USB_D+     | usb
 * +------------+-------+------------+--------------------
 */

#include "variant.h"

const PinDescription g_APinDescription[] = {
					    /*
					    { PORTB, 2, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // 0
					    { PORTA, 2, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // 1
					    { PORTB, 8, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // 2
					    { PORTA, 4, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // 3
					    { PORTA, 6, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // 4
					    */
					    // This keeps the numbering the same, but the first 5 are excluded so Arduino doesn't eff with them.
					    { NOT_A_PORT, 0, PIO_NOT_A_PIN, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
					    { NOT_A_PORT, 0, PIO_NOT_A_PIN, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
					    { NOT_A_PORT, 0, PIO_NOT_A_PIN, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
					    { NOT_A_PORT, 0, PIO_NOT_A_PIN, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
					    { NOT_A_PORT, 0, PIO_NOT_A_PIN, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
					    
					    
					    { PORTB,12, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // 5
					    { PORTA,12, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // 6
					    { PORTB, 1, PIO_DIGITAL, PIN_ATTR_DIGITAL, ADC_Channel9, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // 7

					    { PORTB, 3, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // 8
					    { PORTB, 7, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // 9
					    { PORTB, 9, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // 10

					    // OOPS
					    { PORTB, 5, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // 11
					    { PORTB, 7, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // 12
					    { PORTB, 9, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // 13
					    // END OOPS
					    
					    { PORTA, 5, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // 14
					    { PORTA, 7, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // 15

					    { PORTB,13, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // 16
					    { PORTA, 3, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel1, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },     // 17
					    { PORTB, 4, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel12, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },    // 18
					    { PORTB, 5, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel13, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },    // 19

					    { PORTB, 6, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel14, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },    // 20
					    { PORTB, 0, PIO_ANALOG, PIN_ATTR_ANALOG, ADC_Channel8, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },     // 21
					    { PORTB,31, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // 22
					    { PORTB,15, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // 23

					    { PORTB,14, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // 24
					    { PORTA,20, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // 25
					    { PORTB,23, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // 26
					    { PORTB,22, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // 27
					    
					    { PORTA,21, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_5 },    // 28
					    { PORTB,17, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // 29
					    { PORTB,16, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // 30
					    { PORTA,19, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // 31

					    { PORTA,18, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // 32
					    { PORTA,28, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // 33
					    { PORTA,27, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // 34
					    { PORTA, 8, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // 35

					    { PORTA, 9, PIO_SERCOM_ALT, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // 36
					    { PORTA,14, PIO_SERCOM, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },     // 37
					    { PORTA,13, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },    // 38
					    { PORTA,15, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },    // 39

					    { PORTB,15, PIO_DIGITAL, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },    // 40
					    { PORTA,10, PIO_SERCOM, PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },     // 41
					    { PORTA,11, PIO_SERCOM,  PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },    // 42
					    { PORTA, 0, PIO_SERCOM_ALT,  PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },// 43
					    
					    { PORTA, 1, PIO_SERCOM_ALT,  PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },// 44
					    { PORTA,17, PIO_SERCOM_ALT,  PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },// 45
					    { PORTA,16, PIO_SERCOM_ALT,  PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },// 46
					    { PORTA,22, PIO_SERCOM_ALT,  PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },// 47

					    { PORTA,23, PIO_SERCOM_ALT,  PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // 48
					    { PORTB,11, PIO_SERCOM_ALT,  PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // 49
					    { PORTB,10, PIO_SERCOM_ALT,  PIN_ATTR_DIGITAL, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // 50
					    { PORTA, 24, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // USB/DM
					    { PORTA, 25, PIO_COM, PIN_ATTR_NONE, No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // USB/DP
};

SERCOM sercom0(SERCOM0);
SERCOM sercom1(SERCOM1);
SERCOM sercom2(SERCOM2);
SERCOM sercom3(SERCOM3);
SERCOM sercom4(SERCOM4);
SERCOM sercom5(SERCOM5);

Uart Serial(&PERIPH_SERIAL, PIN_SERIAL_RX, PIN_SERIAL_TX, PAD_SERIAL_RX, PAD_SERIAL_TX);
Uart Serial1(&PERIPH_SERIAL1, PIN_SERIAL1_RX, PIN_SERIAL1_TX, PAD_SERIAL1_RX, PAD_SERIAL1_TX);
Uart Serial2(&PERIPH_SERIAL2, PIN_SERIAL2_RX, PIN_SERIAL2_TX, PAD_SERIAL2_RX, PAD_SERIAL2_TX);

void SERIAL_IT_HANDLER() {
  Serial.IrqHandler();
}

void SERIAL1_IT_HANDLER() {
  Serial1.IrqHandler();
}

void SERIAL2_IT_HANDLER() {
  Serial2.IrqHandler();
}
