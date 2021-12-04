/**
 * @file SourcePosition.cpp
 * @author Catherine Xu
 */

#include "pch.h"
#include "SourcePosition.h"
#include "SinkPosition.h"

/**
 * Set the sink position
 * @param position
 */
void SourcePosition::SetSinkPosition(wxPoint position)
{

    for (auto sinks : mSinks)
    {
        sinks->SetPosition(position);
    }

}

/**
 * Add sink to the rotator
 * @param sink
 */
void SourcePosition::AddSink(SinkPosition *sink)
{
    mSinks.push_back(sink);
    // sink->SetSource(this);
}