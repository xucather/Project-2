/**
 * @file MachineDerived.cpp
 * @author Catherine Xu
 */

#include "pch.h"

#include <wx/xrc/xmlres.h>
#include <wx/stdpaths.h>
#include <memory>

#include "MachineDerived.h"
#include "ActualMachine.h"
#include "MachineOneFactory.h"
#include "MachineTwoFactory.h"

/// Directory within the resources that contains the images.
const std::wstring ImagesDirectory = L"images";


/**
 * Constructor
 */
MachineDerived::MachineDerived() : Machine()
{

    SetMachineNumber(1);

}

/**
 * Set the identifying number for the machine,
 * and creating the appropriate machine
 * @param machine
 */
void MachineDerived::SetMachineNumber(int machine)
{

    switch (machine)
    {

    case 1:
    {
    default:
        MachineOneFactory factory;
        mActual = factory.CreateMachineOne(ImagesDirectory);
        mActual->SetNumber(1);
        break;
    }
    case 2:
    {
        MachineTwoFactory factoryTwo;
        mActual = factoryTwo.CreateMachineTwo(ImagesDirectory);
        mActual->SetNumber(2);
        break;
    }

    }

}



/**
 * Draws the entire machine
 * @param graphics
 */
void MachineDerived::DrawMachine(std::shared_ptr<wxGraphicsContext> graphics)
{
    mActual->Draw(graphics);
}

/**
 * Sets the location for the entire Machine
 * @param location
 */
void MachineDerived::SetLocation(wxPoint location)
{
    mActual->SetLocation(location);
}

/**
 * Setting frame on machine is what drives machine
 * @param frame on timeline
 */
void MachineDerived::SetMachineFrame(int frame)
{
    mActual->SetMachineFrame(frame);
}

/**
 * Set the rate of frames per second
 * @param rate Frames per second
 */
void MachineDerived::SetFrameRate(double rate)
{
   mActual->SetFrameRate(rate);
}

/**
 * Set the speed of motion for Machine
 * @param speed of motor rotation, and entire machine
 */
void MachineDerived::SetSpeed(double speed)
{
    mActual->SetSpeed(speed);
}

/**
 * Returns the identifying machine number
 * @return number of machine
 */
int MachineDerived::GetMachineNumber()
{
    return mActual->GetNumber();
}

/**
 * Returns where Machine is on timeline (from ActualMachine)
 * @return
 */
double MachineDerived::GetMachineTime()
{
    return mActual->GetTime();
}

/**
 * Get the location of the Machine in screen coordinates
 * @return Machine screen location
 */
wxPoint MachineDerived::GetLocation()
{
    return mActual->GetLocation();
}