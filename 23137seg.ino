/* Simple Attiny2313 4 Digit Common Anode 7-Segment.
 * by : Mochamad Ways Alqorni.
 * Flip the bit to use common cathode.
 * 7Seg : PORTB
 * A:PB0
 * B:PB1
 * C:PB2
 * D:PB3
 * E:PB4
 * F:PB5
 * G:PB6
 * DP:PB7
 * Base digit:PD0
 * Tens digit:PD1
 * Hundred digit:PD2
 * Thousand digit:PD3
 */

#define num0 B11000000 //.GFEDCBA arrangement
#define num1 B11111001 //.GFEDCBA arrangement
#define num2 B10100100 //.GFEDCBA arrangement
#define num3 B10110000 //.GFEDCBA arrangement
#define num4 B10011001 //.GFEDCBA arrangement
#define num5 B10010010 //.GFEDCBA arrangement
#define num6 B10000010 //.GFEDCBA arrangement
#define num7 B11111000 //.GFEDCBA arrangement
#define num8 B10000000 //.GFEDCBA arrangement
#define num9 B10010000 //.GFEDCBA arrangement
#define dp   B01111111 //.GFEDCBA arrangement
#define base_num B00000001 // base digit
#define tens_num B00000010 // tens digit
#define hund_num B00000100 // hundred digit
#define thsn_num B00001000 // thousand digit

uint8_t number[] = {num0,num1,num2,num3,num4,num5,num6,num7,num8,num9,dp};
uint8_t digit [] = {thsn_num,hund_num,tens_num,base_num};
int base = 0;
int tens = 0;
int hund = 0;
int thsn = 0;
void setup()
{
  DDRB = 0xFF; // All PORTB as outputs
  DDRD = 0b00001111; // PORTD 0-3 as output
  
}

void loop()
{ 
  int a = 5436; //display this number
  base = a%10;
  tens = a/10%10;
  hund = a/100%10;
  thsn = a/1000%10;

  PORTD = B00001111; //Blanking Signal
  PORTB = B11111111; //Blanking Signal
  delay(5); //note : don't add too much unless you want blinking 7segment...
  
  PORTD = digit[0];
  PORTB = number[base];
  delay(1); 
  PORTD = digit[1];
  PORTB = number[tens];
  delay(1); 
  PORTD = digit[2];
  PORTB = number[hund];
  delay(1); 
  PORTD = digit[3];
  PORTB = number[thsn];
  delay(1); 
}
