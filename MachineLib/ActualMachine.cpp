/**
 * @file ActualMachine.cpp
 * @author Catherine Xu
 */

#include "pch.h"

#include <memory>

#include "ActualMachine.h"
#include "Component.h"
#include "Motor.h"

using namespace std;

/**
 * Constructor
 */
ActualMachine::ActualMachine()
{

}

/**
 * Add component to ActualMachine
 * @param component
 */
void ActualMachine::AddComponent(std::shared_ptr<Component> component)
{
    mComponents.push_back(component);
    component->SetActualMachine(this);

}

/**
 * Draws the ActualMachine and calls each Component to draw
 * @param graphics
 */
void ActualMachine::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    for (auto component : mComponents)
    {
        component->Draw(graphics, mLocation.x, mLocation.y);
    }

}


/**
 * Set the motor for this ActualMachine
 * @param motor
 */
void ActualMachine::SetMotor(std::shared_ptr<Motor> motor)
{
    mMotor = motor;

}

/**
 *
 * @param frame
 */
void ActualMachine::SetMachineFrame(int frame)
{

    // Calculate time based on frame
    mTime = frame/mFrameRate;
    mFrame = frame;
    // Call motor to move entire machine
    mMotor->SetTime(mTime, mSpeed);

}

/**
 * Set the speed for ActualMachine
 * @param speed revolutions per second
 */
void ActualMachine::SetSpeed(double speed)
{
    mSpeed = speed;
}


/**
 * Get the time of the ActualMachine
 * @return time
 */
double ActualMachine::GetTime()
{
    mTime = mFrame/mFrameRate;
    return mTime;
}