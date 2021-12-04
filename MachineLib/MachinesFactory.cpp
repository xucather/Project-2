/**
 * @file MachinesFactory.cpp
 * @author Charles B. Owen
 */

#include "pch.h"
#include "MachinesFactory.h"
#include "WorkingMachine.h"
#include "Shape.h"
#include "Motor.h"
#include "Gear.h"
#include "Arm.h"
#include "Lever.h"
#include "Rod.h"

using namespace std;

/**
 * Create a machine
 * @param machine Machine number to create
 * @return Pointer to newly created machine
 */
std::shared_ptr<WorkingMachine> MachinesFactory::Create(int machine)
{
	switch (machine)
	{
	case 1:
	default:
		return Create1();

	case 2:
		return Create2();

	case 10:	// Shapes
		return Create10();

	case 11:	// Motors
		return Create11();

	case 12:	// Gears
		return Create12();

	case 13:	// Arms
		return Create13();

	case 14:	// Rods
		return Create14();

	case 15:    // Checkpoint
		return Create15();

	case 16:
		return Create16();

	case 17:
		return Create17();
	}
}

/**
 * Create Machine #1
 * @return Newly created machine
 */
std::shared_ptr<WorkingMachine> MachinesFactory::Create1()
{
    // The machine itself
    // In this solution the machine number is passed
    // to the working machine constructor so it knows
    // its number.
    auto machine = make_shared<WorkingMachine>(1);

    // The base
    auto base = make_shared<Shape>();
    int wid = 550;
    base->Rectangle(-wid/2, -1, wid, 40);
    base->SetImage(mImagesDir + L"/base.png");
    machine->AddPart(base);

    // The motor
    auto motor = make_shared<Motor>(mImagesDir);
    motor->SetPosition(100, -38);
    motor->SetSpeed(1.0);
    machine->AddPart(motor);

    // The gear driven by the motor
    // Radius=20pixels, 10 teeth
    auto gear1 = make_shared<Gear>(20, 10);
    gear1->SetImage(mImagesDir + L"/iron.png");
    gear1->SetPosition(100, -38 - Motor::Size / 2);
    machine->AddPart(gear1);

    motor->GetSource()->AddSink(gear1->GetSink());

    // A post that holds the larger gear
    auto gear2post = make_shared<Shape>();
    gear2post->Rectangle(-10, 0, 20, 30);
    gear2post->SetPosition(gear1->GetX() + 55, -40);
    gear2post->SetColor(wxColour(0, 128, 0));
    machine->AddPart(gear2post);

    // The second gear
    // Radius=40pixels, 20 teeth
    auto gear2 = make_shared<Gear>(40, 20);
    gear2->SetImage(mImagesDir + L"/hammered-copper.png");
    gear2->SetPosition(gear1->GetX() + 55, gear1->GetY());
    machine->AddPart(gear2);

    gear1->Drive(gear2, 0.1);

    // The arm attached to the second gear
    // 50 pixels long
    auto arm = make_shared<Arm>(50);
    arm->SetImage(mImagesDir + L"/arm1.png");
    arm->SetPosition(gear2->GetPosition());
    machine->AddPart(arm);

    gear2->GetSource()->AddSink(arm->GetSink());

    // The column that holds the lever
    auto column = make_shared<Shape>();
    column->Rectangle(-20, -40, 40, 220);
    column->SetImage(mImagesDir + L"/column.png");

    // The lever
    auto lever = make_shared<Lever>(400);
    lever->SetPosition(0, -232);
    lever->SetImage(mImagesDir + L"/lever.png");
    lever->SetDriveEnd(185);
    machine->AddPart(lever);

    // The flag attached to the lever
    // Adding the points allows (0,0) be at the end
    // of the flagpole, so it rotates around that point.
    auto flag = make_shared<Shape>();
    flag->AddPoint(-50, 0);
    flag->AddPoint(-50, -100);
    flag->AddPoint(5, -100);
    flag->AddPoint(5, 0);
    flag->SetImage(mImagesDir + L"/flag.png");
    flag->SetPosition(lever->GetPosition());
    machine->AddPart(flag);
    lever->GetRotationSource()->AddSink(flag->GetSink());

    // Column is added after the lever so it is in front
    machine->AddPart(column);

    // Rod from arm to lever
    // 150 pixels long, 7 pixels wide
    auto rod1 = make_shared<Rod>(150);
    int gray = 50;
    rod1->SetColor(wxColour(gray, gray, gray));
    machine->AddPart(rod1);

    arm->GetRodSource()->AddComponent(rod1);
    rod1->SetRodSink(lever->GetRodSink());

    // Rod from lever to Piston
    // 50 pixels long, 5 pixels wide
    auto rod2 = make_shared<Rod>(50, 5);
    rod2->SetColor(wxColour(gray, gray, gray));

    lever->GetPositionSource()->AddComponent(rod2);

    // Piston
    // The points are added so that (0,0) is
    // the attachment point for the rod.
    auto piston = make_shared<Shape>();
    double pistonH = 90;
    double pistonW = 0.386 * pistonH;
    double pistonC = 13.0 / 215.0 * pistonH;
    piston->AddPoint(-pistonW / 2, -pistonC);
    piston->AddPoint(pistonW / 2, -pistonC);
    piston->AddPoint(pistonW / 2, -pistonC + pistonH);
    piston->AddPoint(-pistonW / 2, -pistonC + pistonH);
    piston->SetImage(mImagesDir + L"/piston.png");
    piston->SetPosition(-175, -150);
    machine->AddPart(piston);
    rod2->SetRodSink(piston->GetRodSink());

    machine->AddPart(rod2);

    // Cylinder
    auto cylinder = make_shared<Shape>();
    cylinder->Rectangle(-30, 0, 60, 120);
    cylinder->SetPosition(-175, -38);
    cylinder->SetImage(mImagesDir + L"/cylinder.png");
    machine->AddPart(cylinder);

    return machine;
}

/**
 * Create machine 2
 * @return Newly created machine
 */
std::shared_ptr<WorkingMachine> MachinesFactory::Create2()
{
	auto machine = make_shared<WorkingMachine>(2);

	int wid = 520;
	int wid2 = 150;
	auto back = make_shared<Shape>();
	back->AddPoint(-wid / 2, -60);
	back->AddPoint(-wid2 / 2, -350);
	back->AddPoint(wid2 / 2, -350);
	back->AddPoint(wid / 2, -60);
	back->SetImage(mImagesDir + L"/rust.png");
	machine->AddPart(back);

	wid = 520;
	auto base = make_shared<Shape>();
	base->Rectangle(-wid / 2, 0, wid, 60);
	base->SetColor(wxColour(24, 69, 59));
	machine->AddPart(base);

	auto motor = make_shared<Motor>(mImagesDir, Motor::Types::Basic);
	motor->SetPosition(-210, -60);
	machine->AddPart(motor);

	motor = make_shared<Motor>(mImagesDir, Motor::Types::Basic);
	motor->SetSpeed(-1);
	motor->SetPosition(-100, -60);
	machine->AddPart(motor);

	auto gear1 = make_shared<Gear>(20, 10);
	gear1->SetColor(wxColour(0, 255, 255));
	gear1->SetPosition(-100, -110);
	machine->AddPart(gear1);

	motor->GetSource()->AddSink(gear1->GetSink());

	auto gear2 = make_shared<Gear>(40, 20);
	gear2->SetColor(*wxYELLOW);
	gear2->SetPosition(gear1->GetX() + 55, gear1->GetY());
	machine->AddPart(gear2);

	gear1->Drive(gear2, 0.1);

	auto gear3 = make_shared<Gear>(60, 30);
    gear3->SetImage(mImagesDir + L"/hammered-copper.png");
	gear3->RelativeTo(gear2, -0.78);
	machine->AddPart(gear3);

	gear2->Drive(gear3, -0.038);

	auto gear4 = make_shared<Gear>(15, 8);
	gear4->SetColor(*wxBLUE);
	gear4->RelativeTo(gear3, 1);
	machine->AddPart(gear4);

	gear3->Drive(gear4, -0.0);

	auto gear5 = make_shared<Gear>(80, 40);
	gear5->SetColor(*wxGREEN);
	gear5->RelativeTo(gear3, -1.5);
	machine->AddPart(gear5);

	gear3->Drive(gear5, -0.02);

	auto gear6 = make_shared<Gear>(20, 10);
	gear6->SetColor(*wxRED);
	gear6->SetPosition(gear5->GetX(), gear5->GetY());
	machine->AddPart(gear6);

	gear5->GetSource()->AddSink(gear6->GetSink());

	auto gear7 = make_shared<Gear>(80, 40);
    gear7->SetImage(mImagesDir + L"/iron.png");

	gear7->RelativeTo(gear6, 3);
	machine->AddPart(gear7);

	gear6->Drive(gear7, -0.005);

	auto flag = make_shared<Shape>();
	flag->AddPoint(-5, 0);
	flag->AddPoint(-5, -120);
	flag->AddPoint(65, -120);
	flag->AddPoint(66, 0);
	flag->SetImage(mImagesDir + L"/msu-flag.png");
	flag->SetPosition(gear7->GetPosition());
	machine->AddPart(flag);
	gear7->GetSource()->AddSink(flag->GetSink());

	return machine;
}


/**
 * Shape demonstration machine.
 * @return WorkingMachine object
 */
std::shared_ptr<WorkingMachine> MachinesFactory::Create10()
{
	auto machine = make_shared<WorkingMachine>(10);

	auto shape1 = make_shared<Shape>();
	shape1->Rectangle(-20, 0, 40, 100);
	shape1->SetColor(*wxGREEN);
	machine->AddPart(shape1);
	shape1->SetPosition(-300, 0);

	auto flag = make_shared<Shape>();
	flag->AddPoint(-50, 0);
	flag->AddPoint(-50, -100);
	flag->AddPoint(5, -100);
	flag->AddPoint(5, 0);
	flag->SetImage(mImagesDir + L"/flag.png");
	flag->SetPosition(-100, 0);
	machine->AddPart(flag);

	auto shape2 = make_shared<Shape>();
	shape2->AddPoint(0, 0);
	shape2->AddPoint(-50, -50);
	shape2->AddPoint(0, -100);
	shape2->AddPoint(50, -50);
	shape2->SetColor(*wxRED);
	machine->AddPart(shape2);
	shape2->SetPosition(100, 0);

	auto shape3 = make_shared<Shape>();
	shape3->AddPoint(0, 0);
	shape3->AddPoint(50, -50);
	shape3->AddPoint(-20, -100);
	shape3->AddPoint(70, -80);
	shape3->AddPoint(82, -35);
	shape3->SetPosition(300, 0);
	shape3->SetColor(wxColour(127, 255, 212));
	machine->AddPart(shape3);

	double x = -400;
	double angle = 0;
	for (int i = 0; i < 5; i++)
	{
		auto house = make_shared<Shape>();
		house->AddPoint(-50, 0);
		house->AddPoint(-50, -100);
		house->AddPoint(0, -150);
		house->AddPoint(50, -100);
		house->AddPoint(50, 0);
		house->SetImage(mImagesDir + L"/luke.jpg");
		house->SetRotation(angle);

		house->SetPosition((int)x, -250);
		machine->AddPart(house);

		x += 190;
		angle += 0.1;
	}


	return machine;
}

/**
* Motors demonstration machine.
* @return WorkingMachine object
*/
std::shared_ptr<WorkingMachine> MachinesFactory::Create11()
{
	auto machine = make_shared<WorkingMachine>(11);

	auto motor1 = make_shared<Motor>(mImagesDir, Motor::Types::Vintage);
	motor1->SetPosition(0, 0);
	motor1->SetSpeed(1.0);
	machine->AddPart(motor1);

	auto motor2 = make_shared<Motor>(mImagesDir, Motor::Types::Basic);
	motor2->SetPosition(-200, 0);
    motor2->SetSpeed(2.0);
	machine->AddPart(motor2);


	auto motor3 = make_shared<Motor>(mImagesDir, Motor::Types::Modern);
	motor3->SetPosition(200, 0);
    motor3->SetSpeed(0.5);
	machine->AddPart(motor3);

	return machine;
}


/**
* Gears demonstration machine.
* @return WorkingMachine object
*/
std::shared_ptr<WorkingMachine> MachinesFactory::Create12()
{
	auto machine = make_shared<WorkingMachine>(12);

	auto motor = make_shared<Motor>(mImagesDir, Motor::Types::Basic);
	motor->SetPosition(-200, 0);
	machine->AddPart(motor);

	auto gear1 = make_shared<Gear>(20, 10);
	gear1->SetImage(mImagesDir + L"/iron.png");
	gear1->SetPosition(-200, -50);
	machine->AddPart(gear1);

	motor->GetSource()->AddSink(gear1->GetSink());

	auto gear2 = make_shared<Gear>(40, 20);
	gear2->SetImage(mImagesDir + L"/hammered-copper.png");
	gear2->SetPosition(gear1->GetX() + 55, gear1->GetY());
	machine->AddPart(gear2);

	gear1->Drive(gear2, 0.1);

	auto gear3 = make_shared<Gear>(60, 30);
	gear3->SetColor(*wxRED);
	gear3->RelativeTo(gear2, -0.78);
	machine->AddPart(gear3);

	gear2->Drive(gear3, -0.038);

	auto gear4 = make_shared<Gear>(15, 8);
	gear4->SetColor(*wxBLUE);
	gear4->RelativeTo(gear3, 1);
	machine->AddPart(gear4);

	gear3->Drive(gear4, -0.0);

	auto gear5 = make_shared<Gear>(80, 40);
	gear5->SetColor(*wxGREEN);
	gear5->RelativeTo(gear3, -.2);
	machine->AddPart(gear5);

	gear3->Drive(gear5, -0.0);

	auto gear6 = make_shared<Gear>(20, 10);
	gear6->SetColor(*wxCYAN);
	gear6->SetPosition(gear5->GetX(), gear5->GetY());
	machine->AddPart(gear6);

	gear5->GetSource()->AddSink(gear6->GetSink());

	auto gear7 = make_shared<Gear>(80, 40);
	gear7->SetColor(wxColour(255, 0, 255));
	gear7->RelativeTo(gear6, 0.4);
	machine->AddPart(gear7);

	gear6->Drive(gear7, 0.002);

	return machine;
}


/**
* Motors demonstration machine.
* @return WorkingMachine object
*/
std::shared_ptr<WorkingMachine> MachinesFactory::Create13()
{
	auto machine = make_shared<WorkingMachine>(13);

//	auto motor = make_shared<Motor>(Motor::Basic);
//	motor->SetPosition(-400, 0);
//	machine->AddPart(motor);
//
//	auto arm = make_shared<Arm>(50);
//	arm->SetImage(mImagesDir + L"/arm1.png");
//	arm->SetPosition(-100, -100);
//	machine->AddPart(arm);
//
//	motor->GetSource()->AddSink(arm->GetSink());
//
//	auto arm2 = make_shared<Arm>(50);
//	arm2->SetColor(Color::Green);
//	arm2->SetPosition(0, -100);
//	machine->AddPart(arm2);
//
//	motor->GetSource()->AddSink(arm2->GetSink());
//
//	auto arm3 = make_shared<Arm>(100);
//	arm3->SetImage(mImagesDir + L"/arm1.png");
//	arm3->SetPosition(200, -100);
//	machine->AddPart(arm3);
//
//	motor->GetSource()->AddSink(arm3->GetSink());
//
//	auto arm4 = make_shared<Arm>(50);
//	arm4->SetImage(mImagesDir + L"/arm1.png");
//	arm4->SetPosition(0, -300);
//	machine->AddPart(arm4);
//
//	motor->GetSource()->AddSink(arm4->GetSink());
//
//	auto rod1 = make_shared<Rod>(150);
//	BYTE gray = 50;
//	rod1->SetColor(Color(gray, gray, gray));
//	machine->AddPart(rod1);
//
//	arm4->GetRodSource()->AddPart(rod1);

	return machine;
}


/**
* Motors demonstration machine.
* @return WorkingMachine object
*/
std::shared_ptr<WorkingMachine> MachinesFactory::Create14()
{
	auto machine = make_shared<WorkingMachine>(14);

//	auto motor = make_shared<Motor>(Motor::Basic);
//	motor->SetPosition(-400, 0);
//	machine->AddPart(motor);
//
//	auto arm = make_shared<Arm>(50);
//	arm->SetImage(mImagesDir + L"/arm1.png");
//	arm->SetPosition(200, -200);
//	machine->AddPart(arm);
//
//	motor->GetSource()->AddSink(arm->GetSink());
//
//	auto rod1 = make_shared<Rod>(100);
//	BYTE gray = 50;
//	rod1->SetColor(Color(gray, gray, gray));
//
//	arm->GetRodSource()->AddPart(rod1);
//
//	auto lever = make_shared<Lever>(400);
//	lever->SetPosition(0, -300);
//	lever->SetImage(mImagesDir + L"/lever.png");
//	lever->SetDriveEnd(185);
//	machine->AddPart(lever);
//	rod1->SetRodSink(lever->GetRodSink());
//
//	auto rod2 = make_shared<Rod>(100);
//	rod2->SetColor(Color(gray, gray, gray));
//
//	arm->GetRodSource()->AddPart(rod2);
//
//	/*
//	* Piston
//	*/
//	auto piston = make_shared<Shape>();
//	double pistonH = 90;
//	double pistonW = 0.386 * pistonH;
//	double pistonC = 13.0 / 215.0 * pistonH;
//	piston->AddPoint(-pistonW / 2, -pistonC);
//	piston->AddPoint(pistonW / 2, -pistonC);
//	piston->AddPoint(pistonW / 2, -pistonC + pistonH);
//	piston->AddPoint(-pistonW / 2, -pistonC + pistonH);
//	piston->SetImage(mImagesDir + L"/piston.png");
//	piston->SetPosition(200, -100);
//	machine->AddPart(piston);
//	rod2->SetRodSink(piston->GetRodSink());
//
//	/*
//	* Piston
//	*/
//	auto piston2 = make_shared<Shape>();
//	piston2->AddPoint(-pistonW / 2, -pistonC);
//	piston2->AddPoint(pistonW / 2, -pistonC);
//	piston2->AddPoint(pistonW / 2, -pistonC + pistonH);
//	piston2->AddPoint(-pistonW / 2, -pistonC + pistonH);
//	piston2->SetImage(mImagesDir + L"/piston.png");
//	piston2->SetPosition(-150, -100);
//	machine->AddPart(piston2);
//	//rod2->SetRodSink(piston->GetRodSink());
//
//	auto rod3 = make_shared<Rod>(100);
//	rod3->SetColor(Color(gray, gray, gray));
//	rod3->SetRodSink(piston2->GetRodSink());
//
//	lever->GetPositionSource()->AddPart(rod3);
//
//
//	machine->AddPart(rod1);
//	machine->AddPart(rod2);
//	machine->AddPart(rod3);

	return machine;
}


/**
* Arm/rod demonstration machine.
* @return WorkingMachine object
*/
std::shared_ptr<WorkingMachine> MachinesFactory::Create15()
{
    // The machine itself
    // In this solution the machine number is passed
    // to the working machine constructor so it knows
    // its number.
    auto machine = make_shared<WorkingMachine>(15);

    // The base
    auto base = make_shared<Shape>();
    int wid = 550;
    base->Rectangle(-wid/2, -1, wid, 40);
    base->SetImage(mImagesDir + L"/base.png");
    machine->AddPart(base);

    // The motor
    auto motor = make_shared<Motor>(mImagesDir, Motor::Types::Basic);
    motor->SetPosition(100, -38);
    motor->SetSpeed(1.0);
    machine->AddPart(motor);



    return machine;
}

/**
* Motors demonstration machine.
* @return WorkingMachine object
*/
std::shared_ptr<WorkingMachine> MachinesFactory::Create16()
{
	auto machine = make_shared<WorkingMachine>(16);

//	auto motor = make_shared<Motor>(Motor::Basic);
//	motor->SetPosition(-400, 0);
//	machine->AddPart(motor);
//
//	auto arm = make_shared<Arm>(50);
//	arm->SetImage(mImagesDir + L"/arm1.png");
//	arm->SetPosition(200, -200);
//	machine->AddPart(arm);
//
//	motor->GetSource()->AddSink(arm->GetSink());
//
//	auto rod1 = make_shared<Rod>(100);
//	BYTE gray = 50;
//	rod1->SetColor(Color(gray, gray, gray));
//
//	arm->GetRodSource()->AddPart(rod1);
//
//	auto lever = make_shared<Lever>(400);
//	lever->SetPosition(0, -300);
//	lever->SetImage(mImagesDir + L"/lever.png");
//	lever->SetDriveEnd(185);
//	machine->AddPart(lever);
//	rod1->SetRodSink(lever->GetRodSink());
//
//	machine->AddPart(rod1);
//
//	auto flag = make_shared<Shape>();
//	flag->AddPoint(-50, 0);
//	flag->AddPoint(-50, -100);
//	flag->AddPoint(5, -100);
//	flag->AddPoint(5, 0);
//	flag->SetImage(mImagesDir + L"/flag.png");
//	flag->SetPosition(lever->GetPosition());
//	machine->AddPart(flag);
//	lever->GetRotationSource()->AddSink(flag->GetSink());


	return machine;
}




/**
* Motors demonstration machine.
* @return WorkingMachine object
*/
std::shared_ptr<WorkingMachine> MachinesFactory::Create17()
{
	auto machine = make_shared<WorkingMachine>(17);

//	auto motor = make_shared<Motor>(Motor::Basic);
//	motor->SetPosition(-400, 0);
//	machine->AddPart(motor);
//
//	auto arm = make_shared<Arm>(50);
//	arm->SetImage(mImagesDir + L"/arm1.png");
//	arm->SetPosition(200, -200);
//	machine->AddPart(arm);
//
//	motor->GetSource()->AddSink(arm->GetSink());
//
//	auto rod1 = make_shared<Rod>(100);
//	BYTE gray = 50;
//	rod1->SetColor(Color(gray, gray, gray));
//
//	arm->GetRodSource()->AddPart(rod1);
//
//	auto lever = make_shared<Lever>(400);
//	lever->SetPosition(0, -300);
//	lever->SetImage(mImagesDir + L"/lever.png");
//	lever->SetDriveEnd(185);
//	machine->AddPart(lever);
//	rod1->SetRodSink(lever->GetRodSink());
//
//	double pistonH = 90;
//	double pistonW = 0.386 * pistonH;
//	double pistonC = 13.0 / 215.0 * pistonH;
//
//	/*
//	* Piston
//	*/
//	auto piston2 = make_shared<Shape>();
//	piston2->AddPoint(-pistonW / 2, -pistonC);
//	piston2->AddPoint(pistonW / 2, -pistonC);
//	piston2->AddPoint(pistonW / 2, -pistonC + pistonH);
//	piston2->AddPoint(-pistonW / 2, -pistonC + pistonH);
//	piston2->SetImage(mImagesDir + L"/piston.png");
//	piston2->SetPosition(-150, -150);
//	machine->AddPart(piston2);
//	//rod2->SetRodSink(piston->GetRodSink());
//
//	auto rod3 = make_shared<Rod>(100);
//	rod3->SetColor(Color(gray, gray, gray));
//	//rod3->SetRodSink(piston2->GetRodSink());
//
//	lever->GetPositionSource()->AddPart(rod3);
//
//
//	machine->AddPart(rod1);
//	machine->AddPart(rod3);

	return machine;
}
