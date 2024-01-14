#include "KirchhoffsDiffraction.h"
#include <cmath>
KirchhoffsDiffraction::KirchhoffsDiffraction(double wavelength, double distance)
    : wavelength(wavelength), distance(distance) {}
void KirchhoffsDiffraction::calculateDiffractionPattern(const SourceAperture& source, ObservationPlane& observation) {
    int numPoints = observation.getNumPoints();
    double k = 2.0 * M_PI / wavelength;
    for (int i = 0; i < numPoints; ++i) {
        double x = static_cast<double>(i) - numPoints / 2;
        double integral = 0.0;
        for (int j = 0; j < numPoints; ++j) {
            double y = static_cast<double>(j) - numPoints / 2;
            double r = std::sqrt(x * x + y * y + distance * distance);
            integral += source.getAmplitude(x, y) * std::exp(std::complex<double>(0.0, k * r)) / r;
        }
        observation.setField(i, integral);
    }
}
