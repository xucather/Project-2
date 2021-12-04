/**
 * @file MachineDerived.h
 * @author Catherine Xu
 *
 * Derived system class for a Machine
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINEDERIVED_H
#define CANADIANEXPERIENCE_MACHINEDERIVED_H

#include "Machine.h"

class ActualMachine;

/**
 * Derived system class for a Machine
 */
class MachineDerived: public Machine {
private:

    /// Underlying machine
    std::shared_ptr<ActualMachine> mActual = nullptr;

public:

    MachineDerived();

    void DrawMachine(std::shared_ptr<wxGraphicsContext> graphics) override;

    void SetLocation(wxPoint location) override;

    void SetMachineFrame(int frame) override;

    void SetFrameRate(double rate) override;

    void SetSpeed(double speed) override;

    void SetMachineNumber(int machine) override;

    int GetMachineNumber() override;

    double GetMachineTime() override;

    wxPoint GetLocation() override;

};

#endif //CANADIANEXPERIENCE_MACHINEDERIVED_H
