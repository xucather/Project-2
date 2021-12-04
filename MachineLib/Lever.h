/**
 * @file Lever.h
 * @author Catherine Xu
 *
 * Component which sides move up and down around center point
 *
 */

#ifndef CANADIANEXPERIENCE_LEVER_H
#define CANADIANEXPERIENCE_LEVER_H

#include "Component.h"
#include "INegotiator.h"

#include "SourceRotate.h"
#include "SourcePosition.h"
#include "SinkPosition.h"

/**
 * Component which sides move up and down around center point
 */
class Lever: public Component, public INegotiator {
private:

    /// Rotates SinkRotation
    SourceRotate mSourceRotate;

    /// Moves any SinkPosition
    SourcePosition mSourcePosition;

    /// Moves Lever by position
    SinkPosition mSinkPosition;

    // From Center to Lever End
    double mFromCenter;

public:

    Lever();

    /// Copy constructor (disabled)
    Lever(const Lever &) = delete;

    /// Assignment operator
    void operator=(const Lever &) = delete;


    /**
     * Return the position source component
     * @return Associated position source for Lever
     */
    SourcePosition *GetPositionSource() {return &mSourcePosition;}

    /**
     * Return the rotation source component
     * @return Associated position source for Lever
     */
    SourceRotate *GetRotationSource() {return &mSourceRotate;}


    /**
     * Return the  position sink
     * @return Associated sink for arm
     */
    SinkPosition* GetPositionSink() {return &mSinkPosition;}

    void Update() override;

    void Negotiate(Rod *rod) override;

    /**
     * Set length from lever center to end point
     * @param length double
     */
    void SetFromCenterLength(double length) {mFromCenter = length;}


};

#endif //CANADIANEXPERIENCE_LEVER_H
