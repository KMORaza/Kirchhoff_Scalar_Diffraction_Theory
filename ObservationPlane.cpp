#include "ObservationPlane.h"
ObservationPlane::ObservationPlane(int numPoints) : field(numPoints, 0.0) {}
void ObservationPlane::setField(int index, const std::complex<double>& value) {
    field[index] = value;
}
std::complex<double> ObservationPlane::getField(int index) const {
    return field[index];
}
int ObservationPlane::getNumPoints() const {
    return static_cast<int>(field.size());
}
