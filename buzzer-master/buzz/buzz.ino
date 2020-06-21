/*  Buzzer Prank

    A small and simple prank. It's a buzzer that will buzz a random
    number of times in a two second period, this burst will occur 
    randomly every few minutes.

    The reason we designed it to buzz a random number of times in a
    limited (2 second) window was to limit the time people have to
    locate it until it stops. Otherwise if a random number of same
    length buzzes would occur, it would be buzz for a greater time
    overall, giving more time to track.

    Uses a disconnected ('floating') analog pin to set a random
    seed which makes the 'random' numbers more random. Not really
    needed, mostly just there to be extra.
*/

const int buzzer = LED_BUILTIN; // Pin the buzzer is connect to

const int minWaitTime = 360;  // Minimum time between bursts (seconds)
const int maxWaitTime = 780;  // Maximum time between bursts (seconds)
unsigned long waitTime;       // Used to store the time in seconds between bursts

const int burstLength = 2000; // Stores the buzz period length
const int minBuzzes = 2;      // Minimum number of buzzes in a burst
const int maxBuzzes = 14;     // Maximum number of buzzes in a burst
int burstNum;             // Number of buzzes in the next burst
double burstPeriod;       // Used to store the period of each buzz in ms

const bool debugMode = true;  // Are we in a debugging/trsting phase?
// This will print statements for the buzzer to the computer when true



void setup() {
  pinMode(buzzer, OUTPUT);
  
  if (debugMode) Serial.begin(9600); // Serial to print statements to computer
  
  randomSeed(analogRead(A0));
  // Use the random noise to get a more 'random' set of numbers
}



void loop() {
  // Pick a random number of buzzes (note upper limit is exclusive, hence the +1)
  burstNum = random(minBuzzes, maxBuzzes + 1);       
  burstPeriod = burstLength / burstNum; // Determine period of each buzz

  // Generate a random wait time, within the predefined limits
  waitTime = rand() % (maxWaitTime - minWaitTime) + minWaitTime;

  if (debugMode) {
    // Print all details to verify over serial
    // Useful for testing, but not needed
    Serial.print("Time till next buzz:\t");
    Serial.println(waitTime);
    Serial.print("Number of buzzes:\t");
    Serial.println(burstNum);
    Serial.print("Time between buzzes:\t");
    Serial.println((double)(burstPeriod / 1000));
    Serial.print("Waiting for: \t");
    Serial.println(waitTime);
  }

  // Delay uses ms so we need to convert waitTime accordingly
  delay(waitTime * 1000);

  // Run the buzzer, buzzer is only on for 50% of its period
  for (int i = 0; i < burstNum; i++) {
    digitalWrite(buzzer, HIGH);
    delay((int)burstPeriod / 2);
    digitalWrite(buzzer, LOW);
    delay((int)burstPeriod / 2);
  }

  digitalWrite(buzzer, LOW); // Turn off buzzer, to save power
}
