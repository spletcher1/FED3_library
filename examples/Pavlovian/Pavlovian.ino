/*
  Feeding experimentation device 3 (FED3)
  Pavlovian Pellet Drop
  This script will delivery a conditioned stimulus, wait 5 seconds, and then drop a pellet
  After the pellet has been taken, it will complete a timeout of N seconds and repeat from the beginning

  alexxai@wustl.edu
  December, 2020
*/

#include <FED3.h>                                       //Include the FED3 library 
String sketch = "Pavlov";                               //Unique identifier text for each sketch (this will show up on the screen and in log file)
FED3 fed3 (sketch);                                     //Start the FED3 object
int Pellet_delay = 2;                                   //How long to wait between conditioned stimulus and pellet (note, this variable is created in this script so it does not need to be preceeded by fed3. to use it!)

void setup() {
  fed3.begin();                                         //Setup the FED3 hardware
  fed3.DisplayPokes = false;                            //Customize the DisplayPokes option to 'false' to not display the poke indicators
  fed3.timeout = 10;                                    //Set a timeout period (in seconds) to wait before starting a new trial after each pellet is taken
}

void loop() {
  fed3.run();                                           //Call fed.run at least once per loop
  fed3.ConditionedStimulus();                           //Play conditioned stimulus (light and tones)
  delay (Pellet_delay*1000);                            //delay
  fed3.Feed();                                          //Drop pellet
  
  while (digitalRead (PELLET_WELL) == LOW) {            //Wait here while there's a pellet in the well
    delay (10);
  }
}
