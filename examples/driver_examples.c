/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_examples.h"
#include "driver_init.h"
#include "utils.h"

#include <hal_gpio.h>
#include <hal_delay.h>


#define CS_PIN_test			C, 25

 #define _GPIO_set_(port, pin)		(PORT->Group[GPIO_PORT ## port].OUTSET.reg = (1 << pin))
#define GPIO_set(...)				_GPIO_set_(__VA_ARGS__)

// Clear output pin of GPIO port	(Writing to OUTCLR of an input enables PULLDOWN if PULLEN is set in PINCFG[pin])
#define _GPIO_clr_(port, pin)		(PORT->Group[GPIO_PORT ## port].OUTCLR.reg = (1 << pin))
#define GPIO_clr(...)				_GPIO_clr_(__VA_ARGS__)

// Toggle the GPIO pin
#define _GPIO_toggle_(port, pin)		(PORT->Group[GPIO_PORT ## port].OUTTGL.reg = (1 << pin))
#define GPIO_toggle(...)				_GPIO_toggle_(__VA_ARGS__)







/**
 * Example of using SPI_1 to write "Hello World" using the IO abstraction.
 */
static uint8_t example_SPI_1[12] = "Hello World!";
static uint8_t receive_buffer_spi[12];

void SPI_1_example(void)
{
	struct io_descriptor *io;
	spi_m_sync_get_io_descriptor(&SPI_1, &io);
	spi_m_sync_enable(&SPI_1);

	struct spi_xfer spi_transmit_buffer;
	spi_transmit_buffer.txbuf = &example_SPI_1;
	spi_transmit_buffer.size = 12;
	spi_transmit_buffer.rxbuf  = &receive_buffer_spi;
	
	gpio_set_pin_level(PC25, false); //set cs low. Needs to be done manually yes. 
	// GPIO_set(CS_PIN_test);

	spi_m_sync_transfer(&SPI_1, &spi_transmit_buffer);
	//io_write(io, example_SPI_1, 12);
	gpio_set_pin_level(PC25, true); //set cs high.
	// GPIO_clr(CS_PIN_test);

	

	

}

void delay_example(void)
{
	delay_ms(5000);
}
