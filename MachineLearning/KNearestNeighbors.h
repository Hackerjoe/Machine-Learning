#pragma once

#include <vector>

class DataPoint;

class KNearestNeighbors
{
public:
    KNearestNeighbors();
    ~KNearestNeighbors();

    /**
     * Add a data point to our data set.
     * @param
     */
    void AddData(const DataPoint& NewDataPoint);

    /**
     * With a test point evaluate what is classification would be based on K Nearest Neighbors.
     * @param PointToTest The point to evaluate.
     * @param K The number of nearest neighbors to use in classification.
     */
    unsigned int Evaluate(const DataPoint& PointToTest, unsigned int K = 3);

protected:
    /** Normalize every data point in the data set. */
    void NormalizeDataSet();

protected:
    // The data set holds data points which have a vector and a classification.
    std::vector<DataPoint> DataSet;
};