#pragma once

#include <vector>

/**
 * Data point has a vector that has N elements and has a classification.
 */
class DataPoint
{
public:
    DataPoint();
    ~DataPoint();

    DataPoint(const DataPoint& OtherPoint);
    DataPoint(const std::vector<float> Data);
    void operator=(const DataPoint& OtherPoint);

    /**
     * Copy vector values into internal vector.
     * @param OtherVector The vector to copy values from.
     */
    void CopyVector(const std::vector<float>& OtherVector);

    /**
     * A quick way to insert data into the internal vector.
     */
    void InsertData(unsigned int Count, ...);

    /** Normalize the vector. */
    void Normalize();

    /**
     * Get the distance between two vectors.
     * @param OtherPoint The point to test against.
     */ 
    float GetDistance(const DataPoint& OtherPoint) const;

    /** Get the size of the vector. For example <10.0f, 5.0f> size would be 2.*/
    size_t GetVectorSize() const { return Vector.size(); }


    /** Set the Classification of this data point. */
    void SetClassification(int NewClassification) { Classification = NewClassification; }

    /** Get the Classification of this data point. */
    int GetClassification() const { return Classification; }

protected:
    // The vector data point with feature components.
    std::vector<float> Vector;

    // Used to classify what this data point is.
    int Classification;
};