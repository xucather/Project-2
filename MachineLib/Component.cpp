/**
 * @file Component.cpp
 * @author Catherine Xu
 */

#include "pch.h"
#include "Component.h"
#include "ActualMachine.h"

/**
 * Constructor
 */
Component::Component()
{

}

/**
 * Set ActualMachine for this component
 * @param machine
 */
void Component::SetActualMachine(ActualMachine *machine)
{
    mMachine = machine;
}

/**
 * Draw the component based on the given machine screen location
 * @param graphics
 * @param x machine location
 * @param y machine location
 */
void Component::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    DrawPolygon(graphics, x+mCenter.x, y+mCenter.y);
}

