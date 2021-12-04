/**
 * @file Shape.h
 * @author Catherine Xu
 *
 * A Simple component that can be rotated
 *
 */

#ifndef CANADIANEXPERIENCE_SHAPE_H
#define CANADIANEXPERIENCE_SHAPE_H

#include "Component.h"

#include "SinkRotation.h"

/**
 * A Simple component that can be rotated
 */
class Shape: public Component {
private:

    /// Component for rotating Shape
    SinkRotation mRotationSink;

public:

    Shape();

    /// Copy constructor (disabled)
    Shape(const Shape &) = delete;

    /// Assignment operator
    void operator=(const Shape &) = delete;


    /**
     * Return the sink
     * @return Associated sink for gear
     */
    SinkRotation *GetSink() {return &mRotationSink;}

    void Update();


};

#endif //CANADIANEXPERIENCE_SHAPE_H
