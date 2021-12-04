/**
 * @file Motor.h
 * @author Catherine Xu
 *
 * Motor of the machine,
 * will drive the entire machine
 *
 */

#ifndef CANADIANEXPERIENCE_MOTOR_H
#define CANADIANEXPERIENCE_MOTOR_H

#include "Component.h"
#include "SourceRotate.h"

/**
 * Motor of the machine
 * Will drive the entire machine
 */
class Motor: public Component{
private:


    /// Amount rotated from start
    double mRevolution = 0;

    /// Body of the motor
    Polygon mBody;

    /// Rotator component
    SourceRotate mRotator;


public:

    Motor();

    /// Copy constructor (disabled)
    Motor(const Motor &) = delete;

    /// Assignment operator
    void operator=(const Motor &) = delete;


    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y) override;

    /**
     * Give pointer to body of motor
     * @return Polygon of the motor body
     */
    Polygon *GetBody() {return &mBody;}

    void SetTime(double time, double speed);

    /**
     * Get the source for corresponding gear
     * @return SourceRotate
     */
    SourceRotate *GetSource() { return &mRotator; }


};

#endif //CANADIANEXPERIENCE_MOTOR_H
