#pragma config(Motor,  motor5,          armMotor,     tmotorVexIQ, openLoop, encoder)
#pragma config(Sensor, dgtl1,  bumpSwitch,         sensorTouch)

task main()
{
	int distanceBack = 1;

	if (getBumperValue(bumpSwitch) = 1)
	{
		int rightEncoder = getMotorEncoder(rightMotor);

		while ((getMotorEncoder(rightMotor)) > (getMotorEncoder(rightMotor)-distanceBack))
		{
			moveBackward(SLOW);
		}

  void armClose();

	}

}

//function for closing the arm

void armClose()
{
	moveMotorTarget(armMotor, 100, 75);  //Set motor to run 100 counts at power level 75.
}
