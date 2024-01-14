// Created: September 2022
#include <iostream>
#include "SourceAperture.h"
#include "ObservationPlane.h"
#include "KirchhoffsDiffraction.h"
int main() {
    double wavelength = 0.5;  // Wavelength of light in micrometers
    double distance = 100.0;  // Observation distance in micrometers
    int numPoints = 256;      // Number of points in the observation plane
    auto amplitudeFunction = [](double x, double y) {
        double radius = 50.0;
        return (x * x + y * y <= radius * radius) ? 1.0 : 0.0;
    };
    SourceAperture source(amplitudeFunction);
    ObservationPlane observation(numPoints);
    KirchhoffsDiffraction diffraction(wavelength, distance);
    diffraction.calculateDiffractionPattern(source, observation);
    std::cout << "Diffraction Pattern:\n";
    for (int i = 0; i < numPoints; ++i) {
        double intensity = std::real(observation.getField(i) * std::conj(observation.getField(i)));
        std::cout << "Intensity at point " << i << ": " << intensity << "\n";
    }
    return 0;
}
