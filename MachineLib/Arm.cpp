/**
 * @file Arm.cpp
 * @author Catherine Xu
 */


#include "pch.h"
#include "Arm.h"

/**
 * Constructor
 */
Arm::Arm() : Component()
{
    mRotationSink.SetComponent(this);
}



/**
 * Change the rotation of the Gear told by Sink
 */
void Arm::Update()
{

    double rotation = mRotationSink.GetRotationRatio();

    SetRotation(rotation);

    // Calculate the position of the end of the arm
    double x = GetCenter().x + mLength * cos(rotation * M_PI * 2);
    double y = GetCenter().y + mLength * sin(rotation * M_PI * 2);

    mPositionSource.SetSinkPosition(wxPoint(x,y));

}

