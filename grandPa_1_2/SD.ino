char name[7]="30.WAV";
#define SLOW_INTERVAL 100
#define FAST_INTERVAL 50
//#include <wiring.c>
boolean rec, recording;
int blinkCounter;
boolean blinkState;
unsigned char recSound;
boolean thru;
unsigned char indexedHash[5];
uint32_t seekPosition;
boolean indexed(unsigned char _sound){
  return bitRead(indexedHash[_sound/8],_sound%8);
}
void indexed(unsigned char _sound,boolean _state){
  bitWrite(indexedHash[_sound/8],_sound%8,_state);
}

long index[36];

void clearIndexes(){
  for(uint8_t i=0;i<5;i++) indexedHash[i]=0;
}
void initSdCardAndReport(){
  if (!card.init()) errorLoop();
  if (!vol.init(&card)) errorLoop();// error("vol ");
  if (!root.openRoot(&vol)) errorLoop();// error("root");
  /*
  uint8_t bpc = vol.blocksPerCluster();
   //  PgmPrint("BlocksPerCluster: ");
   
   //Serial.println(bpc, DEC);
   
   uint8_t align = vol.dataStartBlock() & 0X3F;
   // PgmPrint("Data alignment: ");
   //Serial.println(align, DEC);
   
   //  PgmPrint("sdCard size: ");
   //Serial.print(card.cardSize()/2000UL);
   
   
   if (align || bpc < 64) {
   //   PgmPrintln("\nFor best results use a 2 GB or larger card.");
   //// PgmPrintln("Format the card with 64 blocksPerCluster and alignment = 0.");
   // PgmPrintln("If possible use SDFormater from www.sdcard.org/consumers/formatter/");
   }
   if (!card.eraseSingleBlockEnable()) {
   // PgmPrintln("\nCard is not erase capable and can't be used for recording!");
   }
   */
}
uint8_t actualIndex;
uint8_t playBegin(char* name,unsigned char _sound) {
  uint8_t _index;
  if(name[1]>58) _index=name[1]-55;
   else _index=name[1]-48;
   
   return play(_index);
   
   /*
  if(indexed(_sound)){
    if (!file.open(&root, index[_sound], O_READ)) {
    //  errorLoop();
   
      return false;
    }
   //else  Serial.println(index[_sound]);
  }
  else{
    //name
    if (!file.open(&root,name, O_READ)) { 
     // errorLoop();
      return false;
    }
    else{
      index[_sound]=root.curPosition()/32-1;
      indexed(_sound,true); 
      //indexed(_sound,false); 
    }



  }
*/

  /*
  if (!file.open(&root, name, O_READ)) { 
   // index[_sound
   // if (!file.open(&root, index, O_READ))
   //  PgmPrint("Can't open: ");
   // Serial.println(name);
   return false;
   }
   */
/* novinka
  if (!wave.play(&file)) {
    //  PgmPrint("Can't play: ");
    // Serial.println(name);
    file.close();
    return false;
  }
  */
  
 // loadValuesFromMemmory(activeSound);

 
}

bool play(uint8_t _index){
  while(!indexed(_index)){
   _index++;
    _index=_index%36;
  }
 
  actualIndex=_index;
  if(indexed(_index)){
      if (!file.open(&root, index[_index], O_READ)) {
    //  errorLoop();
   
      return false;
    }
   }
   else{
     
     //name[1]--;
     //playBegin(name,_sound);
   }
    if (!wave.play(&file)) { //,uint32_t _pos=0
    //  PgmPrint("Can't play: ");
    // Serial.println(name);
    file.close();
    return false;
  }
  
  //wave.pause(); //novinka
  return true;
}


void error(char* str) {
  //  hw.initialize();
  hw.displayText(str);
  while(1){
    hw.updateDisplay(); 
  }
}

//#define COUNTER_THRESHOLD 255
//int counter;
// record a track
unsigned char updt;

void trackRecord(unsigned char _sound,unsigned char _preset) {

  chacha();
  // restoreAnalogRead();
  //  no();
  //  Serial.begin(MIDI_BAUD);
  // Serial.flush();
  //recorded=255;
}



void chacha(){
  storePreset(currentBank,currentPreset);
  EEPROM.write(1001,currentBank);
  EEPROM.write(1002,currentPreset);
  EEPROM.write(1000,1),software_Reset(); 
}





