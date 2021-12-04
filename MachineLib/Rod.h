/**
 * @file Rod.h
 * @author Catherine Xu
 *
 * Rod class that is driven by arm or lever
 *
 */

#ifndef CANADIANEXPERIENCE_ROD_H
#define CANADIANEXPERIENCE_ROD_H

#include "Component.h"
#include "SinkPosition.h"
#include "SinkRotation.h"
#include "SourcePosition.h"

class INegotiator;

/**
 * Rod class that is driven by arm or lever
 */
class Rod: public Component {
private:

    /// Component that moves rod by position
    SinkPosition mPositionSink;

//    /// Component that moves other end of rod by rotation
//    SinkRotation mRotationSink;

    /// Component for rotating sinks
    SourcePosition mPositionSource;

    /// Length of the rod
    double mLength;

    /// If Rod is moving a component, then set a negotiator
    std::shared_ptr<INegotiator> mNegotiator = nullptr;


public:

    Rod();

    /// Copy constructor (disabled)
    Rod(const Rod &) = delete;

    /// Assignment operator (disabled)
    void operator=(const Rod &) = delete;

    /**
     * Return the rotating source component
     * @return Associated source for gear
     */
    SourcePosition *GetSource() {return &mPositionSource;}

    /**
     * Return the sink
     * @return Associated sink for rod
     */
    SinkPosition *GetSink() {return &mPositionSink;}

    void Update() override;

    /**
     * Set the length of the rod
     * @param length double
     */
    void SetLength(double length) {mLength = length;}

    /**
    * Get the length of the rod
    * @return length double
    */
    double GetLength() {return mLength;}

    /**
     * Set negotiator for rod
     * @param negotiator connected to rod
     */
     void SetNegotiator(std::shared_ptr<INegotiator> negotiator) {mNegotiator = negotiator;}


};

#endif //CANADIANEXPERIENCE_ROD_H
