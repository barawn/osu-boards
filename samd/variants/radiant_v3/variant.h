#ifndef _VARIANT_RADIANT_V3_
#define _VARIANT_RADIANT_V3_

#define ARDUINO_SAMD_VARIANT_COMPLIANCE 10610

#define VARIANT_MCK			  (48000000ul)
#define VARIANT_MAINOSC		(32768ul)
#define CRYSTALLESS

#include "WVariant.h"

#include "WVariant.h"

#ifdef __cplusplus
#include "SERCOM.h"
#include "Uart.h"
#endif // __cplusplus

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

#ifdef __cplusplus
  extern "C" unsigned int PINCOUNT_fn();
#endif

#define PINS_COUNT (PINCOUNT_fn())
  // These DO NOT INCLUDE the power enables, since they'll get screwed with.
  // Those we access via SAMD functions.
#define NUM_DIGITAL_PINS (47u)
#define NUM_ANALOG_PINS (5u)
#define NUM_ANALOG_OUTPUTS (0u)

#define digitalPinToPort(P)        ( &(PORT->Group[g_APinDescription[P].ulPort]) )
#define digitalPinToBitMask(P)     ( 1 << g_APinDescription[P].ulPin )
//#define analogInPinToBit(P)        ( )
#define portOutputRegister(port)   ( &(port->OUT.reg) )
#define portInputRegister(port)    ( &(port->IN.reg) )
#define portModeRegister(port)     ( &(port->DIR.reg) )
#define digitalPinHasPWM(P)        ( g_APinDescription[P].ulPWMChannel != NOT_ON_PWM || g_APinDescription[P].ulTCChannel != NOT_ON_TIMER )

#define PIN_LED 26
#define PIN_LED2 27

static const uint8_t A0 = 17; // 1V0
static const uint8_t A1 = 18; // 1V8
static const uint8_t A2 = 19; // 2V5
static const uint8_t A3 = 20; // LQ
static const uint8_t A4 = 21; // RQ
static const uint8_t A5 = 7; // VINMON
  
// Serial (SERCOM1) is CB RX/TX (PA00/PA01). PA00 = TX, PA01 = RX.
#define PIN_SERIAL_RX (44u)
#define PIN_SERIAL_TX (43u)
#define PAD_SERIAL_TX (UART_TX_PAD_0)
#define PAD_SERIAL_RX (SERCOM_RX_PAD_1)
#define PERIPH_SERIAL sercom1
#define SERIAL_IT_HANDLER SERCOM1_Handler
  
  // Serial1 (SERCOM0) is the FPGA. PA11 = RX, PA10 = TX.
#define PIN_SERIAL1_RX (42u)
#define PIN_SERIAL1_TX (41u)
#define PAD_SERIAL1_TX (UART_TX_PAD_2)
#define PAD_SERIAL1_RX (SERCOM_RX_PAD_3)
#define PERIPH_SERIAL1 sercom0
#define SERIAL1_IT_HANDLER SERCOM0_Handler

  // Serial2 (SERCOM3) is the debug RX/TX (test points only) PA17 = RX, PA16 = TX.
#define PIN_SERIAL2_RX (45u)
#define PIN_SERIAL2_TX (46u)
#define PAD_SERIAL2_TX (UART_TX_PAD_0)
#define PAD_SERIAL2_RX (SERCOM_RX_PAD_1)
#define PERIPH_SERIAL2 sercom3
#define SERIAL2_IT_HANDLER SERCOM3_Handler

  // Wire is on PA22 (SDA) & PA23 (SCL)  
#define WIRE_INTERFACES_COUNT 1
#define PIN_WIRE_SDA (47u)
#define PIN_WIRE_SCL (48u)
#define PERIPH_WIRE sercom5
#define WIRE_IT_HANDLER SERCOM5_Handler

static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;

#define PIN_USB_DM (51u)
#define PIN_USB_DP (52u)

#define SPI_INTERFACES_COUNT 2

  // This is the literal SPI flash, which is on sercom2.
  // SCK (PA09)
  // MOSI (PA08)
  // MISO (PA14)
  // flash CS (PA13)
  // SD CS (PA15)
#define PIN_SPI_MISO (37u)
#define PIN_SPI_MOSI (35u)
#define PIN_SPI_SCK (36u)
#define PIN_SPI_FLASHCS (38u)
#define PIN_SPI_SDCS (39u)
#define PERIPH_SPI sercom2
#define PAD_SPI_TX SPI_PAD_0_SCK_1
#define PAD_SPI_RX SERCOM_RX_PAD_2

  // SERCOM4 is onboard SPI.
  // We don't have MISO but fake it via ENVINMON (which we drive with pullups)
  // BM_SCLK = PB11
  // BM_MOSI = PB10
  // ENVINMON = PA12
#define PIN_SPI1_SCK (49u)
#define PIN_SPI1_MOSI (50u)
#define PIN_SPI1_MISO (6u)
#define PERIPH_SPI1 sercom4
#define PAD_SPI1_TX SPI_PAD_2_SCK_3
#define PAD_SPI1_RX SERCOM_RX_PAD_0
  
static const uint8_t SS = PIN_SPI_FLASHCS;
static const uint8_t MOSI = PIN_SPI_MOSI;
static const uint8_t MISO = PIN_SPI_MISO;
static const uint8_t SCK = PIN_SPI_SCK;

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

extern SERCOM sercom0;
extern SERCOM sercom1;
extern SERCOM sercom2;
extern SERCOM sercom3;
extern SERCOM sercom4;
extern SERCOM sercom5;

extern Uart Serial;
extern Uart Serial1;
extern Uart Serial2;

#endif


#endif
