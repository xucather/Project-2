/**
 * @file SourceRotate.h
 * @author Catherine Xu
 *
 *
 */

#ifndef CANADIANEXPERIENCE_SOURCEROTATE_H
#define CANADIANEXPERIENCE_SOURCEROTATE_H

class SinkRotation;

/**
 * Rotates connected SinkRotation
 */
class SourceRotate {
private:

    /// All of the components it rotates
    std::vector<SinkRotation *> mSinks;


public:

    SourceRotate() = default;

    /// Copy constructor (disabled)
    SourceRotate(const SourceRotate &) = delete;

    /// Assignment operator
    void operator=(const SourceRotate &) = delete;

    void SetSinkRotation(double rotation);

    void AddSink(SinkRotation* sink);
};

#endif //CANADIANEXPERIENCE_SOURCEROTATE_H
