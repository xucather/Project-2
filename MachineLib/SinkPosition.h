/**
 * @file SinkPosition.h
 * @author Catherine Xu
 *
 *
 */

#ifndef CANADIANEXPERIENCE_SINKPOSITION_H
#define CANADIANEXPERIENCE_SINKPOSITION_H


class SourcePosition;
class Component;

/**
 * Handles position change from a SourcePosition component
 */
class SinkPosition {
private:

    /// The source of rotation for sink
    SourcePosition *mSource;

    /// Position of the source
    wxPoint mPosition = wxPoint(0,0);

    /// Associated component for sink
    Component * mComponent = nullptr;

public:

    SinkPosition();

    /// Copy constructor (disabled)
    SinkPosition(const SinkPosition &) = delete;

    /// Assignment operator
    void operator=(const SinkPosition &) = delete;


    /**
     * Set the component for the sink
     * @param component Pointer to associated component
     */
    void SetComponent(Component * component) {mComponent = component;}

    void SetPosition(wxPoint position);

    /**
     * Get the position in sink for component
     * @return the position for component
     */
    wxPoint GetNewPosition() {return mPosition;}

    /**
     * Set the source of the rotation
     * @param source that set rotation for sink
     */
    void SetSource(SourcePosition * source) {mSource = source;}



};

#endif //CANADIANEXPERIENCE_SINKPOSITION_H
