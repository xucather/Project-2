/**
 * @file Gear.h
 * @author Catherine Xu
 *
 * Gear that rotates and is rotated
 *
 */

#ifndef CANADIANEXPERIENCE_GEAR_H
#define CANADIANEXPERIENCE_GEAR_H

#include "Component.h"
#include "SinkRotation.h"
#include "SourceRotate.h"

/**
 * Gear that rotates and is rotated
 */
class Gear: public Component {
private:

    /// Number of teeth the Gear has
    double mNumTeeth;

    /// Radius of the Gear
    double mRadius;

    /// Component that rotates gear
    SinkRotation mRotationSink;

    /// Component for rotating sinks
    SourceRotate mRotationSource;


public:

    Gear();

    /// Copy constructor (disabled)
    Gear(const Gear &) = delete;

    /// Assignment operator
    void operator=(const Gear &) = delete;

    /**
     * Set the number of teeth for Gear
     * @param teeth
     */
    void SetTeeth(double teeth) {mNumTeeth = teeth;}

    /**
     * Set the radius for the Gear
     * @param radius
     */
    void SetRadius(double radius) {mRadius = radius;}

    /**
     * Return the sink
     * @return Associated sink for gear
     */
    SinkRotation *GetSink() {return &mRotationSink;}

    void Update() override;

    void Drive(std::shared_ptr<Gear> gear, double phase);

    /**
     * Return the rotating source component
     * @return Associated source for gear
     */
    SourceRotate *GetSource() {return &mRotationSource;}


};

#endif //CANADIANEXPERIENCE_GEAR_H
