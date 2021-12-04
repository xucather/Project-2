/**
 * @file Lever.cpp
 * @author Catherine Xu
 */

#include "pch.h"
#include "Lever.h"

#include "Rod.h"

/**
 * Constructor
 */
Lever::Lever() : Component(),  INegotiator()
{

}


/**
 * Change the rotation of the Gear told by Sink
 */
void Lever::Update()
{

}

/**
 * Negotiate with rod
 * @param rod
 */
void Lever::Negotiate(Rod *rod)
{
    // get a = lever FromCenter length
    double a = mFromCenter;
    // get b = rod length
    double b = rod->GetLength();


    // x1 y1 = rods center
    wxPoint rodCenter = rod->GetCenter();
    // x2 y2 = levers center
    wxPoint leverCenter = this->GetCenter();

//
//    wxPoint rodCenter = wxPoint(195, -58);
//    wxPoint leverCenter = wxPoint(0, -232);
//
//    double a = 185;
//    double b = 150;


    // calculate c
    auto c = sqrt(pow((leverCenter.y - rodCenter.y),2) + pow((leverCenter.x - rodCenter.x),2));

    // calculate gamma
    auto gamma = atan2(-(leverCenter.y - rodCenter.y), (leverCenter.x - rodCenter.x));

    // calculate alpha
    auto alpha = acos((pow(b,2) + pow(c,2) - pow(a,2))/(2*b*c));

    // calculate theta
    auto theta = gamma - alpha;
    // Set rod rotation to theta
    rod->SetRotation(-theta/ (2 * M_PI));

    // Set rotation of the Lever
    auto endX = rodCenter.x + b *  cos(-theta);
    auto endY = rodCenter.y + b*sin(-theta);
    auto phi = atan2((endY - leverCenter.y), (endX - leverCenter.x));
    this->SetRotation(phi/ (2 * M_PI));


}