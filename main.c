

// The Code Implementation Without Bluetooth Module To Output Sound // 

void ADCfunction(){
  ADCSRA = 0x00;             // clear ADCSRA register
  ADCSRB = 0x00;             // clear ADCSRB register
  // A0 as Input
  // Left Allign
  // set reference voltage
  ADMUX |= (0 & 0x07)|(1 << REFS0)|(1 << ADLAR);  
  // Sampling rate = 76.9 KHZ
  // auto trigger
  // enable ADC, interrupts, and adc measurements
  ADCSRA |= (1 << ADPS2)|(1 << ADATE)|(1 << ADIE)|(1 << ADEN)|(1 << ADSC);  
 }
 void setup(){
  DDRD = 0xFF;   // Sets PORTD as a output
  ADCfunction(); // inits ADC registers   
}

ISR(ADC_vect){
  PORTD = ADCH; // OUTPUT the Results to 8-bit DAC
}

void loop(){  
}
