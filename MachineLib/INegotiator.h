/**
 * @file INegotiator.h
 * @author Catherine Xu
 *
 * Negotiator interface for rod/piston and rod/lever negotiations
 *
 */

#ifndef CANADIANEXPERIENCE_INEGOTIATOR_H
#define CANADIANEXPERIENCE_INEGOTIATOR_H

class Rod;

/**
 * Negotiator interface for rod/piston and rod/lever negotiations
 */
class INegotiator {
private:

public:

    /**
     * Negotiate with a rod to come up with a mutual rotation solution
     * @param rod
     */
    virtual void Negotiate(Rod *rod) = 0;

};


#endif //CANADIANEXPERIENCE_INEGOTIATOR_H
