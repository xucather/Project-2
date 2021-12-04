/**
 * @file MachineOneFactory.cpp
 * @author Catherine Xu
 */

#include "pch.h"

#include <memory>

#include "MachineOneFactory.h"
#include "ActualMachine.h"
#include "Polygon.h"
#include "Motor.h"
#include "Shape.h"
#include "Gear.h"
#include "Arm.h"
#include "Rod.h"
#include "Lever.h"


using namespace std;


const double ToothDepth = 5;     ///< Depth of a tooth in pixels
const double ToothWidth = 0.33;  ///< Width of a tooth at the top as fraction of tooth pitch
const double ToothSlope = 0.1;   ///< Fraction of pitch where the tooth slopes up or down

/// PI * 2 constant
const double PI2 = M_PI * 2;



/**
 * Constructor
 */
MachineOneFactory::MachineOneFactory()
{

}

/**
 * Create the first machine
 * @param imagesDir
 * @return Pointer to the first machine
 */
std::shared_ptr<ActualMachine> MachineOneFactory::CreateMachineOne(std::wstring imagesDir)
{

    auto machine = make_shared<ActualMachine>();


    // The base
    auto base = make_shared<Shape>();
    int baseWid = 550;
    base->Rectangle(-baseWid/2, -1, baseWid, 40);
    base->SetImage(imagesDir + L"/base.png");
    // Connections (add to Machine)
    machine->AddComponent(base);


    // Create motor
    auto motor = make_shared<Motor>();
    int wid = 100;
    // motor->Rectangle(-wid/2, -1, wid, 100);
    motor->CenteredSquare(wid);
    motor->SetImage(imagesDir + L"/electric-wheel.png");
    int bodyWid = 150;
    motor->GetBody()->CenteredSquare(bodyWid);
    motor->GetBody()->SetImage(imagesDir + L"/motor-frame.png");
    motor->SetCenter(wxPoint(0,-100));

    // Connections
    machine->SetMotor(motor);
    machine->AddComponent(motor);


    // Create First Gear
    auto gearOne = make_shared<Gear>();
    CreateGear( gearOne, 30, 10);
    gearOne->SetColor(wxColour(100, 200, 50));
    gearOne->SetCenter(wxPoint(0,-100));

    // Connections
    machine->AddComponent(gearOne);
    motor->GetSource()->AddSink(gearOne->GetSink());

    // Create the second gear
    auto gearTwo = make_shared<Gear>();
    CreateGear( gearTwo, 50, 10);
    gearTwo->SetColor(wxColour(10, 0, 40));
    gearTwo->SetCenter(wxPoint(73,-100));

    // Connections
    machine->AddComponent(gearTwo);
    gearOne->GetSource()->AddSink(gearTwo->GetSink());
    gearOne->Drive(gearTwo, -0.3);


    // Create first arm
    auto armOne = make_shared<Arm>();
    int armWid = 10;
    armOne->SetLength(60);
    armOne->Rectangle(0, 0, 60, 10);
    armOne->SetColor(wxColour(100, 0, 50));
    armOne->SetCenter(wxPoint(73,-100));

    // Connections
    machine->AddComponent(armOne);
    gearTwo->GetSource()->AddSink(armOne->GetSink());


    // Create first rod
    auto rodOne = make_shared<Rod>();
    rodOne->Rectangle(0, 0, 107, 10);
    rodOne->SetColor(wxColor(100, 70, 50));
    rodOne->SetLength(100);

    // Connections
    machine->AddComponent(rodOne);
    armOne->GetSource()->AddSink(rodOne->GetSink());

    // Create lever
    auto lever = make_shared<Lever>();
    lever->Rectangle(-256 / 2, 0, 256, 33);
    lever->SetImage(imagesDir + L"/lever.png");
    lever->SetCenter(wxPoint(0,-200));
    lever->SetFromCenterLength(256/2);


    // Connections
    machine->AddComponent(lever);
    rodOne->SetNegotiator(lever);

    return machine;


}

/**
 * Create gear polygon points
 * @param gear
 * @param radius
 * @param numTeeth
 */
void MachineOneFactory::CreateGear( std::shared_ptr<Gear> gear,  double radius, double numTeeth)
{

    double toothStart = 1.0 - ToothWidth - ToothSlope * 2;
    double innerRadius = radius - ToothDepth;

    for (int t = 0; t < numTeeth; t++)
    {
        double angle1 = double(t) / double(numTeeth) * PI2;
        double angle2 = double(t + toothStart) / double(numTeeth) * PI2;
        double angle3 = double(t + toothStart + ToothSlope) / double(numTeeth) * PI2;
        double angle4 = double(t + toothStart + ToothSlope + ToothWidth) / double(numTeeth) * PI2;
        double angle5 = double(t + toothStart + ToothSlope * 2 + ToothWidth) / double(numTeeth) * PI2;

        gear->AddPoint(innerRadius * cos(angle1), innerRadius * sin(angle1));
        gear->AddPoint(innerRadius * cos(angle2), innerRadius * sin(angle2));
        gear->AddPoint(radius * cos(angle3), radius * sin(angle3));
        gear->AddPoint(radius * cos(angle4), radius * sin(angle4));
        gear->AddPoint(innerRadius * cos(angle5), innerRadius * sin(angle5));
    }
}