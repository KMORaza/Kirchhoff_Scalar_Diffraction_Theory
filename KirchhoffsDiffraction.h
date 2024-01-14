#ifndef KIRCHHOFFS_DIFFRACTION_H
#define KIRCHHOFFS_DIFFRACTION_H
#include <complex>
#include "SourceAperture.h"
#include "ObservationPlane.h"
class KirchhoffsDiffraction {
private:
    const double wavelength;
    const double distance;
public:
    KirchhoffsDiffraction(double wavelength, double distance);
    void calculateDiffractionPattern(const SourceAperture& source, ObservationPlane& observation);
};
#endif
