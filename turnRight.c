// Code for Turning left //
#pragma config(Sensor, dgtl1,  rightEncoder,        sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,         sensorQuadEncoder)
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
	int turnDistance = 5;
	int leftEncoder = SensorValue(leftEncoder);

	//resetMotorEncoder(leftMotor);		//Reset the current position in the motor encoder to zero.
	//resetMotorEncoder(rightMotor);

	setMotorSpeed(leftMotor, 0);
	setMotorSpeed(rightMotor, 0);

  while (SensorValue(leftEncoder) > (turnDistance+leftEncoder))
	{
		setMotorSpeed(leftMotor, turnSpeed);
		displayTextLine(1, "Left Motor: %d", SensorValue(leftEncoder));
		sleep(50);
	}


}
