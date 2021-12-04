/**
 * @file Motor.cpp
 * @author Catherine Xu
 */

#include "pch.h"
#include "Motor.h"

/**
 * Constructor
 */
Motor::Motor() : Component()
{

}



/**
 * Draw the motor body and wheel
 * @param graphics context to write on
 * @param x Machine x screen location
 * @param y Machine y screen location
 */
void Motor::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{

    // Draw the body
    mBody.DrawPolygon(graphics, x+ GetCenter().x, y+GetCenter().y);

    // Upcall
    Component::Draw(graphics, x, y);

}

/**
 * Calculates rotation and calls all of the sinks
 * @param time on the timeline, used for rotation
 * @param speed of the machine
 */
void Motor::SetTime(double time, double speed)
{

    mRevolution = time * speed;

    SetRotation(mRevolution);

    // Update Sink through rotator
    mRotator.SetSinkRotation(mRevolution);

//    double rotation = ( int(mRevolution * 36000)% 36000)/100.00;


}