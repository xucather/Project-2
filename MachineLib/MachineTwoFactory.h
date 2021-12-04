/**
 * @file MachineTwoFactory.h
 * @author Catherine Xu
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINETWOFACTORY_H
#define CANADIANEXPERIENCE_MACHINETWOFACTORY_H

class ActualMachine;

/**
 * Factory that creates the second machine
 */
class MachineTwoFactory {
private:

public:

    MachineTwoFactory();

    /// Copy constructor (disabled)
    MachineTwoFactory(const MachineTwoFactory &) = delete;

    /// Assignment operator
    void operator=(const MachineTwoFactory &) = delete;

    std::shared_ptr<ActualMachine> CreateMachineTwo(std::wstring imagesDir);
};

#endif //CANADIANEXPERIENCE_MACHINETWOFACTORY_H
