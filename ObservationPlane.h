#ifndef OBSERVATION_PLANE_H
#define OBSERVATION_PLANE_H
#include <vector>
#include <complex>
class ObservationPlane {
private:
    std::vector<std::complex<double>> field;
public:
    ObservationPlane(int numPoints);
    void setField(int index, const std::complex<double>& value);
    std::complex<double> getField(int index) const;
    int getNumPoints() const;
};
#endif
