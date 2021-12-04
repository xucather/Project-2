/**
 * @file Shape.cpp
 * @author Catherine Xu
 */

#include "pch.h"
#include "Shape.h"

/**
 * Constructor
 */
Shape::Shape() : Component()
{
    mRotationSink.SetComponent(this);
}

/**
 * Change the rotation of the Gear told by Sink
 */
void Shape::Update()
{
    this->SetRotation(mRotationSink.GetRotationRatio());
}
