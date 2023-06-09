#ifndef _LCD_I2C_H
#define _LCD_I2C_H

#include <avr/io.h>
#include <stdint.h>
#include <stdbool.h>

/* set CPU speed*/
#ifndef F_CPU
#define F_CPU 16000000UL
#endif

// commands
#define LCD_CLEARDISPLAY 0x01
#define LCD_RETURNHOME 0x02
#define LCD_ENTRYMODESET 0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_CURSORSHIFT 0x10
#define LCD_FUNCTIONSET 0x20
#define LCD_SETCGRAMADDR 0x40
#define LCD_SETDDRAMADDR 0x80

// masks for display entry mode
#define LCD_ENTRYRIGHT 0x00
#define LCD_ENTRYLEFT 0x02
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYSHIFTDECREMENT 0x00

// masks for display on/off control
#define LCD_DISPLAYON 0x04
#define LCD_DISPLAYOFF 0x00
#define LCD_CURSORON 0x02
#define LCD_CURSOROFF 0x00
#define LCD_BLINKON 0x01
#define LCD_BLINKOFF 0x00

// masks for display/cursor shift
#define LCD_DISPLAYMOVE 0x08
#define LCD_CURSORMOVE 0x00
#define LCD_MOVERIGHT 0x04
#define LCD_MOVELEFT 0x00

// masks for function set
#define LCD_8BITMODE 0x10
#define LCD_4BITMODE 0x00
#define LCD_2LINE 0x08
#define LCD_1LINE 0x00
#define LCD_5x10DOTS 0x04
#define LCD_5x8DOTS 0x00

// masks for backlight control
#define LCD_BACKLIGHT 0x08
#define LCD_NOBACKLIGHT 0x00

#define LCD_ENABLE_BIT 0x04			 // Enable bit
#define LCD_READ_WRITE_BIT 0x02		 // Read/Write bit
#define LCD_REGISTER_SELECT_BIT 0x01 // Register select bit

// extra chars
#define PERCENT 37 //%
#define DEGREE 223 // °

typedef struct LiquidCrystalDevice_t
{
	uint8_t Address;
	uint8_t Columns;
	uint8_t Rows;
	uint8_t Backlight;
	uint8_t DisplayFunction;
	uint8_t DisplayControl;
	uint8_t DisplayMode;
} LiquidCrystalDevice_t;

// Port expander addr, column and row count, 5x8 or 5x10 dots
struct LiquidCrystalDevice_t lcd_init(uint8_t address, uint8_t columns, uint8_t rows, uint8_t dotSize);

void lcd_clear(struct LiquidCrystalDevice_t *device);
void lcd_setCursor(struct LiquidCrystalDevice_t *device, uint8_t row, uint8_t column);
void lcd_returnHome(struct LiquidCrystalDevice_t *device);
void lcd_turnOnBacklight(struct LiquidCrystalDevice_t *device);
void lcd_turnOffBacklight(struct LiquidCrystalDevice_t *device);
void lcd_print(struct LiquidCrystalDevice_t *device, char *value);
void lcd_printChar(struct LiquidCrystalDevice_t *device, char value);
void lcd_printDouble(struct LiquidCrystalDevice_t *device, double value, int precision);
void lcd_printInt(struct LiquidCrystalDevice_t *device, int value);
void lcd_turnOnDisplay(struct LiquidCrystalDevice_t *device);
void lcd_turnOffDisplay(struct LiquidCrystalDevice_t *device);
void lcd_turnOnCursor(struct LiquidCrystalDevice_t *device);
void lcd_turnOffCursor(struct LiquidCrystalDevice_t *device);
void lcd_turnOnBlink(struct LiquidCrystalDevice_t *device);
void lcd_turnOffBlink(struct LiquidCrystalDevice_t *device);
void lcd_scrollDisplayLeft(struct LiquidCrystalDevice_t *device);
void lcd_scrollDisplayRight(struct LiquidCrystalDevice_t *device);
void lcd_leftToRight(struct LiquidCrystalDevice_t *device);
void lcd_rightToLeft(struct LiquidCrystalDevice_t *device);
void lcd_turnOnAutoscroll(struct LiquidCrystalDevice_t *device);
void lcd_turnOffAutoscroll(struct LiquidCrystalDevice_t *device);
void lcd_createChar(struct LiquidCrystalDevice_t *device, uint8_t slot, uint8_t charmap[8]);
void lcd_sendCommand(struct LiquidCrystalDevice_t *device, uint8_t command);
void lcd_writeDeviceByte(struct LiquidCrystalDevice_t *device, uint8_t value, uint8_t mode);
void lcd_writeDevice4Bits(struct LiquidCrystalDevice_t *device, uint8_t value);
void lcd_writeDevicePulse(struct LiquidCrystalDevice_t *device, uint8_t value);
void lcd_transmitI2C(struct LiquidCrystalDevice_t *device, uint8_t value);

#endif /* _LCD_I2C_H */