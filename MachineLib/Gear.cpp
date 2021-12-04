/**
 * @file Gear.cpp
 * @author Catherine Xu
 */


#include "pch.h"

#include "Gear.h"

/**
 * Constructor
 */
Gear::Gear() : Component()
{
    mRotationSink.SetComponent(this);
}

/**
 * Change the rotation of the Gear told by Sink
 */
void Gear::Update()
{
    // Placeholder
    //this->SetRotation(mRotationSink.GetRotationRatio());

    SetRotation(mRotationSink.GetRotationRatio());
    mRotationSource.SetSinkRotation(mRotationSink.GetRotationRatio());


}

/**
 * Change sink gear speed and offset
 * @param gear
 * @param phase
 */
void Gear::Drive(std::shared_ptr<Gear> gear, double phase)
{
    auto sink = gear->GetSink();

    sink->SetRatio(-(double) mNumTeeth/(double) gear->mNumTeeth);
    sink->SetPhase(phase);
}
