/**
 * @file MachineOneFactory.h
 * @author Catherine Xu
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINEONEFACTORY_H
#define CANADIANEXPERIENCE_MACHINEONEFACTORY_H

class ActualMachine;
class Gear;

/**
 * Factory that creates Machine 1
 */
class MachineOneFactory {
private:

public:

    MachineOneFactory();

    /// Copy constructor (disabled)
    MachineOneFactory(const MachineOneFactory &) = delete;

    /// Assignment operator
    void operator=(const MachineOneFactory &) = delete;

    std::shared_ptr<ActualMachine> CreateMachineOne(std::wstring imagesDir);

    void CreateGear(std::shared_ptr<Gear> gear, double radius, double numTeeth);
};

#endif //CANADIANEXPERIENCE_MACHINEONEFACTORY_H
