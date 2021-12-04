/**
 * @file SinkPosition.cpp
 * @author Catherine Xu
 */

#include "pch.h"
#include "SinkPosition.h"
#include "Component.h"

/**
 * Constructor
 */
SinkPosition::SinkPosition()
{

}


/**
 * Set the position of the source
 * @param position
 */
void SinkPosition::SetPosition(wxPoint position)
{
    mPosition =  position;
    mComponent->Update();
}
