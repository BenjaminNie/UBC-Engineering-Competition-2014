// Code for Turning left //

#pragma config(Motor,  motor1,          leftMotor,     tmotorVexIQ, openLoop, encoder)
#pragma config(Motor,  motor6,          rightMotor,    tmotorVexIQ, openLoop, reversed, encoder)

void turnRight(turnSpeed);

task main()
{
	int turnSpeed = 50;
turnRight(turnSpeed);
}

void turnRight(turnSpeed)
{
	int turnDistance = 3;
	int leftEncoder = getMotorEncoder(leftMotor);

	//resetMotorEncoder(leftMotor);		//Reset the current position in the motor encoder to zero.
	//resetMotorEncoder(rightMotor);

	setMotorSpeed(leftMotor, 0);
	setMotorSpeed(rightMotor, 0);

  while (getMotorEncoder(leftMotor) > (turnDistance+leftEncoder))
	{
		setMotorSpeed(leftMotor, turnSpeed);
		displayTextLine(1, "Left Motor: %d", getMotorEncoder(leftMotor));
		sleep(50);
	}


}
