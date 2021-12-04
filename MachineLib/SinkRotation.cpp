/**
 * @file SinkRotation.cpp
 * @author Catherine Xu
 */

#include "pch.h"
#include "SinkRotation.h"
#include "Component.h"


SinkRotation::SinkRotation()
{

}

/**
 * Set the RotationRatio
 * @param rotationRatio
 */
void SinkRotation::SetRotationRatio(double rotationRatio)
{
    mRotationRatio =  rotationRatio * mRatio + mPhase;
    mComponent->Update();
}




