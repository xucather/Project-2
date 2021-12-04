/**
 * @file Rod.cpp
 * @author Catherine Xu
 */

#include "pch.h"
#include "Rod.h"
#include "INegotiator.h"

/**
 * Constructor
 */
Rod::Rod() : Component()
{
    mPositionSink.SetComponent(this);


}

/**
 * Change the rotation of the Gear told by Sink
 */
void Rod::Update()
{
    wxPoint sourcePos = mPositionSink.GetNewPosition();

    // calculate delta by sinkPosition - our position
    // Set the position of sinks using delta
    // In this case, only if connected to piston
    // The piston will calculate its new position, which will use to calculate
    // the rotation of the rod to meet it


    // Set the new center of the rod to move it
    SetCenter(mPositionSink.GetNewPosition());
    printf("%d", mPositionSink.GetNewPosition().x);


    // Negotiate rotation of the rod to its INegotiator
    if ( mNegotiator != nullptr)
    {
        mNegotiator->Negotiate(this);
    }


}

