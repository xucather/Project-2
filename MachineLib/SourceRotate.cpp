/**
 * @file SourceRotate.cpp
 * @author Catherine Xu
 */

#include "pch.h"
#include "SourceRotate.h"
#include "SinkRotation.h"

/**
 * Set the sink rotation
 * @param rotation
 */
void SourceRotate::SetSinkRotation(double rotation)
{

    for (auto sinks : mSinks)
    {
        sinks->SetRotationRatio(rotation);
    }

}

/**
 * Add sink to the rotator
 * @param sink
 */
void SourceRotate::AddSink(SinkRotation *sink)
{
    mSinks.push_back(sink);
    sink->SetSource(this);
}