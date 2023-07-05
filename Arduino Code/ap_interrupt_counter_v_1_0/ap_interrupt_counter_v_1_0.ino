/******************************************************
   Circuit
 *******************************************************/
/*

          _____  __________
         /  _  \ \______   \
        /  /_\  \ |     ___/
       /    |    \|    |
       \____|__  /|____|
               \/


    Device      Adduino
    SW             D02

*/

/******************************************************
   Global Variables
*******************************************************/

#define pushSW 2

//--- Variables ---//
int count_limit = 2;
int count = 0;
boolean int_chnage = false;

/******************************************************
   SETUP
*******************************************************/
void setup() {

  //--- Serial Monitor ---//
  Serial.begin(9600);

  //--- For Interrupt ---//
  pinMode(pushSW, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pushSW), int_exe, RISING);

}


/******************************************************
   MAIN LOOP
*******************************************************/
void loop() {

  if (int_chnage) {
    if (count == 0) {
      Serial.println("Zero");
    }
    else if (count == 1) {
      Serial.println("One");
    }
    else if (count == 2) {
      Serial.println("Two");
    }
    int_chnage = false;
  }


  Serial.println(count);
  delay(20);
}


/******************************************************
   int_exe
*******************************************************/
void int_exe() {
  if (!int_chnage) {
    count++;
    if (count > count_limit) count = 0;
    int_chnage = true;
    delay(500);
  }
  //Serial.println("INT");
}
