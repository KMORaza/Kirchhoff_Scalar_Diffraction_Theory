#ifndef SOURCE_APERTURE_H
#define SOURCE_APERTURE_H
#include <functional>
#include <cmath>
class SourceAperture {
private:
    std::function<double(double, double)> amplitudeFunction;
public:
    SourceAperture(const std::function<double(double, double)>& amplitudeFunction);
    double getAmplitude(double x, double y) const;
};
#endif
