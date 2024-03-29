/**
 * @file Machine.h
 * @author Charles Owen
 *
 * Class that represents a machine.
 *
 * You are not allowed to change this class in any way!
 */

#ifndef CANADIANEXPERIENCE_MACHINE_H
#define CANADIANEXPERIENCE_MACHINE_H

class MachineStandin;

/**
 * Class that represents a machine.
 *
 * This uses a standin class to provide a way to develop
 * the adapter class first if you so choose.
 *
 * You are not allowed to change this class in any way!
 */
class Machine {
private:
    /**
     * A stand-in machine class.
     *
     * This draws simple stand-in graphics
     * so you can see where the machine will be and what its state
     * is. This makes it easy to develop code that uses the
     * machine before you have the machine working.
     *
     * And no, you may not change this to point to your
     * machine implementation!
     */
    std::shared_ptr<MachineStandin> mStandin;

public:

    /// Constructor
    Machine();

    /// Destructor
    virtual ~Machine() = default;

    /// Copy constructor/disabled
    Machine(const Machine&) = delete;

    /// Assignment operator/disabled
    void operator=(const Machine&) = delete;

    /**
    * Set the position for the root of the machine
    * @param location The x,y location to place the machine
    */
    virtual void SetLocation(wxPoint location);

    /**
     * Get the location of hte machine
     * @return Location x,y in pixels as a point
     */
    virtual wxPoint GetLocation();

    /**
    * Draw the machine at the currently specified location
    * @param graphics Graphics object to render to
    */
    virtual void DrawMachine(std::shared_ptr<wxGraphicsContext> graphics);

    /**
    * Set the current machine animation frame
    * @param frame Frame number
    */
    virtual void SetMachineFrame(int frame);

    /**
     * Set the expected frame rate in frames per second
     * @param rate Frame rate in frames per second
     */
    virtual void SetFrameRate(double rate);

    /**
    * Set  the bend angleGetM
    * @param speed Speed from 0 to 1, where 1 is full speed
    */
    virtual void SetSpeed(double speed);

    /**
    * Set the machine number
    * @param machine An integer number. Each number makes a different machine
    */
    virtual void SetMachineNumber(int machine);

    /**
     * Get the current machine number
     * @return Machine number integer
     */
    virtual int GetMachineNumber();

    /**
     * Get the current machine time.
     * @return Machine time in seconds
     */
    virtual double GetMachineTime();
};


#endif //CANADIANEXPERIENCE_MACHINE_H
