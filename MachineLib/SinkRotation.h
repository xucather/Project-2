/**
 * @file SinkRotation.h
 * @author Catherine Xu
 *
 * Handles rotation from a SourceRotate component
 *
 */

#ifndef CANADIANEXPERIENCE_SINKROTATION_H
#define CANADIANEXPERIENCE_SINKROTATION_H

class SourceRotate;
class Component;

/**
 * Handles rotation from a SourceRotate component
 */
class SinkRotation {
private:

    /// The source of rotation for sink
    SourceRotate * mSource;

    /// Rotation from source
    double mRotationRatio;

    /// Associated Component
    Component *mComponent = nullptr;

    /// Personal speed of the component
    double mRatio = 1;

    /// Personal offset to make the component mesh
    double mPhase = 0;


public:

    SinkRotation();

    /// Copy constructor (disabled)
    SinkRotation(const SinkRotation &) = delete;

    /// Assignment operator
    void operator=(const SinkRotation &) = delete;


    /**
     * Get the rotation in sink for component
     * @return the rotation change for component
     */
    double GetRotationRatio() {return mRotationRatio;}

    void SetRotationRatio(double rotationRatio);

    /**
     * Set the component for the sink
     * @param component Pointer to associated component
     */
    void SetComponent(Component * component) {mComponent = component;}

    /**
     * Set the speed for the Gear
     * @param speed
     */
    void SetRatio(double speed) {mRatio = speed;}

    /**
     * Set the offset for the Gear
     * @param phase
     */
    void SetPhase(double phase) {mPhase = phase;}

    /**
     * Set the source of the rotation
     * @param source that set rotation for sink
     */
    void SetSource(SourceRotate * source) {mSource = source;}

};

#endif //CANADIANEXPERIENCE_SINKROTATION_H
