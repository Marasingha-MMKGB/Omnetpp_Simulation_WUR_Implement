#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

// Function to initialize ADC
void ADC_Init() {
	// Set ADC prescaler to 128 (for 16MHz clock)
	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
	
	// Set reference voltage to internal 2.56V
	ADMUX |= (1 << REFS1) | (1 << REFS0);
	
	// Enable ADC
	ADCSRA |= (1 << ADEN);
}

// Function to read ADC value from a specific channel
uint16_t ADC_Read(uint8_t channel) {
	// Clear the channel bits
	ADMUX &= 0xF8;
	// Set the channel to read from
	ADMUX |= (channel & 0x07);
	
	// Start the conversion
	ADCSRA |= (1 << ADSC);
	
	// Wait for the conversion to complete
	while (ADCSRA & (1 << ADSC));
	
	// Return the ADC value
	return ADC;
}

int main(void) {
	// Initialize ADC
	ADC_Init();
	
	// Set PC2 and PC3 as output pins
	DDRC |= (1 << PC2) | (1 << PC3);
	
	// Loop indefinitely
	while (1) {
		// Read potentiometer value from ADC channel 7
		uint16_t potValue = ADC_Read(7);
		
		// Calculate motor speed based on potentiometer value
		// Here, we'll map the potentiometer range (0-1023) to a motor speed range (0-255)
		uint8_t motorSpeed = potValue >> 2; // Divide by 4
		
		// Set motor speed by controlling PC2 and PC3 outputs
		if (motorSpeed > 0) {
			PORTC |= (1 << PC2); // Set PC2 (IN1)
			PORTC &= ~(1 << PC3); // Clear PC3 (IN2)
			} else {
			PORTC &= ~(1 << PC2); // Clear PC2 (IN1)
			PORTC &= ~(1 << PC3); // Clear PC3 (IN2)
		}
		
		// Delay for stability (adjust as needed)
		_delay_ms(10);
	}
	
	return 0;
}

