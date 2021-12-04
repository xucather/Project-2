/**
 * @file Arm.h
 * @author Catherine Xu
 *
 * Rotating arm component
 *
 */

#ifndef CANADIANEXPERIENCE_ARM_H
#define CANADIANEXPERIENCE_ARM_H

#include "Component.h"
#include "SinkRotation.h"
#include "SourcePosition.h"

/**
 * Rotating arm component
 */
class Arm: public Component {
private:

    /// Component that rotates the arm
    SinkRotation mRotationSink;

    /// Component for rotating sinks
    SourcePosition mPositionSource;

    /// How long the length of the arm is
    double mLength;

public:

    Arm();

    /// Copy constructor (disabled)
    Arm(const Arm &) = delete;

    /// Assignment operator (disabled)
    void operator=(const Arm &) = delete;

    /**
     * Return the rotating source component
     * @return Associated source for arm
     */
    SourcePosition *GetSource() {return &mPositionSource;}

    /**
     * Return the sink
     * @return Associated sink for arm
     */
    SinkRotation* GetSink() {return &mRotationSink;}

    void Update() override;

    /**
     * Set the length of the arm
     * @param length double
     */
    void SetLength(double length) {mLength = length;}

};

#endif //CANADIANEXPERIENCE_ARM_H
