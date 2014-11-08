// Code for Turning left //

#pragma config(Motor,  motor1,          leftMotor,     tmotorVexIQ, openLoop, encoder)
#pragma config(Motor,  motor6,          rightMotor,    tmotorVexIQ, openLoop, reversed, encoder)

void turnLeft(turnSpeed);

task main()
{

turnLeft(turnSpeed);

}

void turnLeft()
{

	int turnDistance = 3;

	//resetMotorEncoder(leftMotor);		//Reset the current position in the motor encoder to zero.
	//resetMotorEncoder(rightMotor);

	setMotorSpeed(leftMotor, 0);
	setMotorSpeed(rightMotor, 0);
	int rightEncoder = getMotorEncoder(rightMotor);


	wait1Msec(50); //Small delay to allow motors time to start moving before checking

	// moveMotorTarget(leftMotor, 5000, 75);  //Set motor to run 5000 counts at power level 75.
	// moveMotorTarget(rightMotor, 5000, 75);

  while (getMotorEncoder(rightMotor) > (turnDistance+rightEncoder))
	{
		setMotorSpeed(leftMotor, 50);
		displayTextLine(1, "Left Motor: %d", getMotorEncoder(rightMotor));
		sleep(50);
	}


}
