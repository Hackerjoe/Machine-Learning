#include "DataPoint.h"
#include <cstdarg>
#include <cmath>

DataPoint::DataPoint()
    : Vector()
    , Classification(-1)
{
}

DataPoint::~DataPoint()
{
}


DataPoint::DataPoint(const DataPoint& OtherPoint)
{
    CopyVector(OtherPoint.Vector);
    Classification = OtherPoint.Classification;
}

DataPoint::DataPoint(const std::vector<float> Data)
{
    CopyVector(Data);
}

void DataPoint::operator=(const DataPoint& OtherPoint)
{
    CopyVector(OtherPoint.Vector);
}

void DataPoint::CopyVector(const std::vector<float>& OtherVector)
{
    Vector.clear();
    for (auto& Value : OtherVector)
    {
        Vector.push_back(Value);
    }
}

void DataPoint::InsertData(unsigned int Count, ...)
{
    Vector.clear();

    va_list Args;
    va_start(Args, Count);

    for (unsigned int i = 0; i < Count; ++i)
    {
        float Value = va_arg(Args, double);
        Vector.push_back(Value);
    }

    va_end(Args);
}

void DataPoint::Normalize()
{
    float Length = 0;
    for (auto& Value : Vector)
    {
        Length += Value * Value;
    }

    if (Length == 0)
        return;

    Length = std::sqrt(Length);

    for (auto& Value : Vector)
    {
        Value = Value / Length;
    }
}

float DataPoint::GetDistance(const DataPoint& OtherPoint) const
{
    size_t VectorSize = GetVectorSize();

    if (VectorSize != OtherPoint.GetVectorSize())
    {

        // TODO Maybe log error.
        return -1;
    }

    float SquaredDistance = 0;
    for (size_t i = 0; i < VectorSize; ++i)
    {
        float ComponentA = Vector[i];
        float ComponentB = OtherPoint.Vector[i];

        SquaredDistance += std::pow(ComponentA - ComponentB, 2);
    }

    return std::sqrt(SquaredDistance);
}