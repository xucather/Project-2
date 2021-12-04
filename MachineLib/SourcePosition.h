/**
 * @file SourcePosition.h
 * @author Catherine Xu
 *
 * Moves a SinkPosition by setting position
 *
 */

#ifndef CANADIANEXPERIENCE_SOURCEPOSITION_H
#define CANADIANEXPERIENCE_SOURCEPOSITION_H

class SinkPosition;

/**
 * Moves a SinkPosition by setting position
 */
class SourcePosition {
private:

    /// All of the components it rotates
    std::vector<SinkPosition *> mSinks;

public:

    SourcePosition() = default;

    /// Copy constructor (disabled)
    SourcePosition(const SourcePosition &) = delete;

    /// Assignment operator
    void operator=(const SourcePosition &) = delete;

    void SetSinkPosition(wxPoint);

    void AddSink(SinkPosition* sink);
};

#endif //CANADIANEXPERIENCE_SOURCEPOSITION_H
