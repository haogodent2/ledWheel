#include <NS_Rainbow.h>

#define PIN 9
#define N_CELL 8

// Parameter 1 = number of cells (max: 512)
// Parameter 2 = Arduino pin number (default pin: 9)
//NS_Rainbow ns_stick = NS_Rainbow(N_CELL);
NS_Rainbow ns_stick = NS_Rainbow(N_CELL,PIN);

void setup() {
  delay(100);
  ns_stick.begin();
  ns_stick.setBrightness(10);  // range: 0 ~ 255, default: 255  
  Serial.begin(9600);

}

void loop() {


unsigned long start_ms = millis();

for(uint16_t i=0; i<100; i++){  
  uint8_t val = i*10;
  for(uint8_t j = 0; j<8; j++){
      ns_stick.setColor(j, val, val, val);    
  }
  ns_stick.show(); 
}
unsigned long end_ms = millis();
Serial.println((end_ms-start_ms)/100.0);

delay(1000);
}







void rainbow(uint16_t interval) {
  uint16_t n = ns_stick.numCells();

  for(uint16_t j=0; j<255; j++) {  // one cycle 
    for(uint16_t i=0; i<n; i++) {
      byte r_pos = (((i<<8) -  i) / n + j) % 0xFF;
      byte sect = (r_pos / 0x55) % 0x03, pos = (r_pos % 0x55) * 0x03;
  
      switch(sect) {
      case 0: 
        ns_stick.setColor(i,ns_stick.RGBtoColor(0xFF - pos, pos, 0x00)); break;
      case 1: 
        ns_stick.setColor(i,ns_stick.RGBtoColor(0x00, 0xFF - pos, pos)); break;
      case 2:
        ns_stick.setColor(i,ns_stick.RGBtoColor(pos, 0x00, 0xFF - pos)); break;
      }  
    }
    ns_stick.show();
    delay(interval);
  }
}
