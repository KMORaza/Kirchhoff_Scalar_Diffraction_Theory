#include "SourceAperture.h"
SourceAperture::SourceAperture(const std::function<double(double, double)>& amplitudeFunction)
    : amplitudeFunction(amplitudeFunction) {}
double SourceAperture::getAmplitude(double x, double y) const {
    return amplitudeFunction(x, y);
}
