
void turnRightBackJunction();
void turnLeftJunctionBack();

				//turning onto straight portion from state 5

				case(70):
	  	  turnRightBackJunction();
	  	  state++;
	  	  break;

	  	  //following line until T junction
	  	  case(71):
	  	  lineBackTracker();
	  	  state++;
	  	  break;

	  	  //turning at T junction
	  	  case(72):
	  	  turnLeftJunctionBack();
	  	  state++;
	  	  break;


void turnRightBackJunction()
{
	turnRightBack(motorMEDIUM)
	 wait1Msec(300);
	 stopMotor();
}

void turnLeftJunctionBack()
{

	  		while (SensorValue(lineTrackerRight) < 2500)
	  		{
	  		//moveBackward(motorMEDIUM);
	  			turnLeft(motorMEDIUM);
	  			wait1Msec(500);
     	    moveForward(motorMEDIUM);
     	    wait1Msec(5);
     	  }

	  		stopMotor();
	  		wait1Msec(2000);
}
