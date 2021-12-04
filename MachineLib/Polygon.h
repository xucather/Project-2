/**
 * @file Polygon.h
 *
 * @author Charles Owen
 *
 * Generic polygon class that is used to make shapes we
 * will use in our project.
 */

#pragma once

#include <vector>
#include <memory>
#include <string>

/**
 * Generic polygon class that is used to make shapes we 
 * will use in our project.
 */
class Polygon
{
private:
    void DrawColorPolygon(std::shared_ptr<wxGraphicsContext> graphics, int x, int y);
    void DrawImagePolygon(std::shared_ptr<wxGraphicsContext> graphics, int x, int y);

    /// Graphics path to use to draw
    wxGraphicsPath mPath;

    /// The points that make up the polygon
    std::vector<wxPoint> mPoints;

    /// A brush to draw the polygon with
    wxBrush mBrush;

    /// The display mode
    enum class Mode {
        Unset, Color, Image
    };

    /// The current mode
    Mode mMode = Mode::Unset;

    /// The basic texture image we load
    std::unique_ptr<wxImage> mImage;

    /// The graphics bitmap we actually draw
    wxGraphicsBitmap mGraphicsBitmap;

    /// The image clip region
    wxRegion mImageClipRegion;

    /// What is the top left point for the clip region?
    wxPoint mImageClipRegionTopLeft;

    /// What is the size of the clip region?
    wxPoint mImageClipRegionSize;

    /// Any amount to rotate the polygon in turns
    /// 0 to 1 is one complete rotation
    double mRotation = 0;

public:
    Polygon();
    virtual ~Polygon();

    /**
     * @param x X value for point in pixels
     * @param y Y value for point in pixels
     */
    void AddPoint(int x, int y);

    /**
     * Add a point to the polygon. Convenience version that accepts doubles.
     * @param x X value for point in pixels
     * @param y Y value for point in pixels
     */
    void AddPoint(double x, double y) { AddPoint((int)x, (int)y); }

    void Rectangle(int x, int y, int wid, int hit);
    void CenteredSquare(int size);

    void SetColor(wxColour color);

    void SetImage(std::wstring filename);

    void DrawPolygon(std::shared_ptr<wxGraphicsContext> graphics, int x, int y);

    /**
     * Set the rotation of the polygon
     * @param rotation Rotation in turns, where 0-1 is one revolution.
     */
    virtual void SetRotation(double rotation) { mRotation = rotation; }

    /**
     * Get the rotation of the polygon
     * @return rotation Rotation in turns, where 0-1 is one revolution.
     */
    double GetRotation() const { return mRotation; }
};

