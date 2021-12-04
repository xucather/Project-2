/**
 * @file MachineFactory.cpp
 *
 * @author Charles Owen
 *
 * You are allowed to change this file.
 */

#include "pch.h"
#include "MachineFactory.h"
#include "Machine.h"
#include "MachineDerived.h"


/**
 * Constructor
 * @param imagesDir Directory to load images from
 */
MachineFactory::MachineFactory(std::wstring imagesDir) : mImagesDir(imagesDir)
{
}


/**
 * Create a machine object
 *
 * Do not change the return type of this function!
 *
 * @return Object of type Machine
 */
std::shared_ptr<Machine> MachineFactory::CreateMachine()
{
    return std::make_shared<MachineDerived>();
}


