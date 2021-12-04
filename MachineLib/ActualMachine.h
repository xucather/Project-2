/**
 * @file ActualMachine.h
 * @author Catherine Xu
 *
 * Underlying Machine carrying out mechanics
 *
 */

#ifndef CANADIANEXPERIENCE_ACTUALMACHINE_H
#define CANADIANEXPERIENCE_ACTUALMACHINE_H

class Component;
class Motor;

/**
 * Underlying Machine carrying out mechanics
 */
class ActualMachine {
private:

    /// The identifying number of the ActualMachine
    int mNumber = 1;

    /// Location on Screen
    wxPoint mLocation = wxPoint(0,0);

    /// Components that make up the machine
    std::vector<std::shared_ptr<Component>> mComponents;

    /// Motor that drives the machine
    std::shared_ptr<Motor> mMotor = nullptr;

    /// Speed of the machine
    double mSpeed = 1; // 1 revolution per second

    /// Frames per second
    double mFrameRate = 30; // Default 30 frames per second

    /// Total time on timeline
    double mTime = 0;

    /// Frame the current machine is at
    double mFrame = 0;


public:

    ActualMachine();

    /// Copy constructor (disabled)
    ActualMachine(const ActualMachine &) = delete;

    /// Assignment operator
    void operator=(const ActualMachine &) = delete;

    /**
     * Set the ActualMachine Number
     * @param number
     */
    void SetNumber(int number) {mNumber = number;}

    /**
     * Get the machine number
     * @return machine number
     */
    int GetNumber() {return mNumber;}

    /**
     * Set the location on screen
     * @param location
     */
    void SetLocation(wxPoint location) {mLocation = location;}

    /**
     * Get the location of machine on screen
     * @return
     */
    wxPoint GetLocation(){return mLocation;}

    void AddComponent(std::shared_ptr<Component> component);

    void Draw(std::shared_ptr<wxGraphicsContext> graphics);

    void SetMotor(std::shared_ptr<Motor> motor);

    void SetMachineFrame(int frame);

    void SetSpeed(double speed);

    double GetTime();

    /**
     * Set the frame rate for ActualMachine
     * @param rate of Frames per second
     */
    void SetFrameRate(double rate) {mFrameRate = rate;}

};

#endif //CANADIANEXPERIENCE_ACTUALMACHINE_H
