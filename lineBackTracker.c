// move backwards

void lineBackTracker();
void turnLeftBack(int speed);
void turnRightBack(int speed);


void lineBackTracker()
{

  //Create and set the threshold for the Line Tracking Sensors.
  int threshold = 2500;

  // sensor values for debugging purposes
  int leftLineSensor;
	int rightLineSensor;
	int centerLineSensor;

  while(1)
  {
    leftLineSensor = SensorValue(lineTrackerLeft);
    rightLineSensor = SensorValue(lineTrackerRight);
    centerLineSensor = SensorValue(lineTrackerCenter);

    if ( ((leftLineSensor > threshold) && (centerLineSensor > threshold)) ||\
    		 ((rightLineSensor > threshold) && (centerLineSensor > threshold)) ||\
    	   ((rightLineSensor > threshold) && (centerLineSensor > threshold) && (leftLineSensor > threshold)) ||\
    	   ((rightLineSensor > threshold) && (leftLineSensor > threshold)) )
    {
       stopMotor();
       wait1Msec(3000);
       return;
    }

    //If the center sensor sees dark...
    if (SensorValue(lineTrackerCenter) > threshold) {
    	 moveBackward(motorMEDIUM);
    }

    //If the left sensor sees dark...
  	else if(SensorValue(lineTrackerLeft) > threshold) {
			 while (SensorValue(lineTrackerCenter) < threshold) {
  		    turnLeftBack(motorFAST);
    	    wait1Msec(15);
     	    moveBackward(motorMEDIUM);
     	    wait1Msec(5);

    if ( ((leftLineSensor > threshold) && (centerLineSensor > threshold)) ||\
    		 ((rightLineSensor > threshold) && (centerLineSensor > threshold)) ||\
    	   ((rightLineSensor > threshold) && (centerLineSensor > threshold) && (leftLineSensor > threshold)) ||\
    	   ((rightLineSensor > threshold) && (leftLineSensor > threshold)) )
    {
       stopMotor();
       wait1Msec(3000);
       return;
    }

       }
    }

    //If the right sensor sees dark...
    else if(SensorValue(lineTrackerRight) > threshold) {
       while (SensorValue(lineTrackerCenter) < threshold) {
    	 	  turnRightBack(motorFAST);
     	    wait1Msec(15);
     	    moveBackward(motorMEDIUM);
     	    wait1Msec(5);

    if ( ((leftLineSensor > threshold) && (centerLineSensor > threshold)) ||\
    		 ((rightLineSensor > threshold) && (centerLineSensor > threshold)) ||\
    	   ((rightLineSensor > threshold) && (centerLineSensor > threshold) && (leftLineSensor > threshold)) ||\
    	   ((rightLineSensor > threshold) && (leftLineSensor > threshold)) )
    {
       stopMotor();
       wait1Msec(3000);
       return;
    }

       }
    }

  	else {
  		moveBackward(motorMEDIUM);
    }
   }
}

void turnLeftBack(int speed)
{
	 motor[leftMotor] = 0;
	 motor[rightMotor] = speed * -1;
}

void turnRightBack(int speed)
{
	 motor[leftMotor] = speed;
	 motor[rightMotor] = 0;
}
