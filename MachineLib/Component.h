/**
 * @file Component.h
 * @author Catherine Xu
 *
 *
 */

#ifndef CANADIANEXPERIENCE_COMPONENT_H
#define CANADIANEXPERIENCE_COMPONENT_H

#include "Polygon.h"
#include "ActualMachine.h"


/**
 * Base class of object that is part of the machine
 */
class Component: public Polygon {
private:

    /// Machine that this component is a part of
    ActualMachine *mMachine = nullptr;

    /// Point relative to the machine
    wxPoint mCenter = wxPoint(0,0);

public:

    Component();

    /// Copy constructor (disabled)
    Component(const Component &) = delete;

    /// Assignment operator
    void operator=(const Component &) = delete;


    void SetActualMachine(ActualMachine* machine);

    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y);

    /**
     * Give the component center
     * @return wxPoint for center of component
     */
    wxPoint GetCenter(){return mCenter;}


    /**
     * Set the center of the component relative to machine position
     * @param center of the component
     */
    void SetCenter(wxPoint center) {mCenter = center;}

    /**
     * Component updates position
     */
    virtual void Update() {};


};

#endif //CANADIANEXPERIENCE_COMPONENT_H
