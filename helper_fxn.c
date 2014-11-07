//
// WAITING TIME
//

/*
* Waits 1 miliseconds
*/
task waitMSec_A()
{
	wait1Msec(1);
}

/*
* Waits 100 miliseconds
*/
task waitMSec_B()
{
	wait1Msec(100);
}

/*
* Wait 200 miliseconds
*/
task waitMSec_C()
{
	wait1Msec(200);
}

/*
* Wait 500 miliseconds
*/
task waitMSec_D()
{
	wait1Msec(500);
}









//
// LIGHT SENSOR
//












//
// LINE FOLLOWING
//

/*
* Uses 3 files sensors to track lines
*/
task tripleSensorLineFollower()
{
  wait1Msec(2000);          // The program waits for 2000 milliseconds before continuing.

  int threshold = 505;      /* found by taking a reading on both DARK and LIGHT    */
                            /* surfaces, adding them together, then dividing by 2. */
  while(true)
  {
  	
/*
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -+
    displayLCDCenteredString(0, "LEFT  CNTR  RGHT");        //  Display   |
    displayLCDPos(1,0);                                     //  Sensor    |
    displayNextLCDNumber(SensorValue(lineFollowerLEFT));    //  Readings  |
    displayLCDPos(1,6);                                     //  to LCD.   |
    displayNextLCDNumber(SensorValue(lineFollowerCENTER));  //            |
    displayLCDPos(1,12);                                    //  L  C  R   |
    displayNextLCDNumber(SensorValue(lineFollowerRIGHT));   //  x  x  x   |
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -+
*/

    // RIGHT sensor sees dark:
    if(SensorValue(lineFollowerRIGHT) > threshold)
    {
      // counter-steer right:
      motor[leftMotor]  = 63;
      motor[rightMotor] = 0;
    }
    // CENTER sensor sees dark:
    if(SensorValue(lineFollowerCENTER) > threshold)
    {
      // go straight
      motor[leftMotor]  = 63;
      motor[rightMotor] = 63;
    }
    // LEFT sensor sees dark:
    if(SensorValue(lineFollowerLEFT) > threshold)
    {
      // counter-steer left:
      motor[leftMotor]  = 0;
      motor[rightMotor] = 63;
    }
  }
}