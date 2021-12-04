/**
 * @file MachineTwoFactory.cpp
 * @author Catherine Xu
 */

#include "pch.h"

#include <memory>

#include "MachineTwoFactory.h"
#include "ActualMachine.h"
#include "Motor.h"


using namespace std;


/**
 * Constructor
 */
MachineTwoFactory::MachineTwoFactory()
{

}

/**
 * Create the second machine
 * @param imagesDir
 * @return Pointer to second machine
 */
std::shared_ptr<ActualMachine> MachineTwoFactory::CreateMachineTwo(std::wstring imagesDir)
{

    auto machine = make_shared<ActualMachine>();

    // Create motor

    return machine;

}