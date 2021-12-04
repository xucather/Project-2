/**
 * @file MachinesFactory.h
 * @author Charles B. Owen
 */
#pragma once

#include <memory>

class WorkingMachine;

/**
 * Factory class to create the machines we use
 */
class MachinesFactory
{
private:
    /// Path to the images directory
    std::wstring mImagesDir;

	std::shared_ptr<WorkingMachine> Create1();
	std::shared_ptr<WorkingMachine> Create2();
	std::shared_ptr<WorkingMachine> Create10();
	std::shared_ptr<WorkingMachine> Create11();
	std::shared_ptr<WorkingMachine> Create12();
	std::shared_ptr<WorkingMachine> Create13();
	std::shared_ptr<WorkingMachine> Create14();
	std::shared_ptr<WorkingMachine> Create15();
	std::shared_ptr<WorkingMachine> Create16();
	std::shared_ptr<WorkingMachine> Create17();

public:
    /**
     * Constructor
     * @param imagesDir Path to images directory
     */
    MachinesFactory(std::wstring imagesDir) : mImagesDir(imagesDir) {}

    std::shared_ptr<WorkingMachine> Create(int machine);
};

