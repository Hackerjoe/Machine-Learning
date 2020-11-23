#include "KNearestNeighbors.h"
#include "DataPoint.h"

#include <algorithm>
#include <map>

KNearestNeighbors::KNearestNeighbors()
    : DataSet()
{
}

KNearestNeighbors::~KNearestNeighbors()
{
    DataSet.clear();
}

void KNearestNeighbors::AddData(const DataPoint& NewDataPoint)
{
    // TODO Check if same point already is contained in data set.
    DataSet.push_back(NewDataPoint);
}

void KNearestNeighbors::NormalizeDataSet()
{
    for (auto& Data : DataSet)
    {
        Data.Normalize();
    }
}

unsigned int KNearestNeighbors::Evaluate(const DataPoint& PointToTest, unsigned int K)
{
    // Maybe can optimize this...
    NormalizeDataSet();

    // Copy test point and normalize it.
    DataPoint CopiedTestPoint = PointToTest;
    CopiedTestPoint.Normalize();

    // Go through every point and calculate the distance.
    std::vector<std::pair<DataPoint*, float>> DistanceArray;
    for (auto& Point : DataSet)
    {
        const float Distance = CopiedTestPoint.GetDistance(Point);
        DistanceArray.push_back(std::pair<DataPoint*, float>(&Point, Distance));
    }

    // Sort the array by distance.
    std::sort(DistanceArray.begin(), DistanceArray.end(), [=](std::pair<DataPoint*, float>& a, std::pair<DataPoint*, float>& b)
    {
        return a.second < b.second;
    }
    );

    // Get the K nearest neighbors 
    std::map<int, int> ClassificationCounts;
    for (size_t i = 0; i < K; ++i)
    {
        if (i >= DistanceArray.size())
        {
            break;
        }

        // Grab classifications.
        const DataPoint& Point = *DistanceArray[i].first;

        // Up the count for this classification.
        ClassificationCounts[Point.GetClassification()] += 1;
    }

    // Find the best classification in the map.
    int BestClassification = -1;
    int BestClassificationCount = -1;
    for (auto& Pair : ClassificationCounts)
    {
        if (Pair.second > BestClassificationCount)
        {
            BestClassification = Pair.first;
            BestClassificationCount = Pair.second;
        }
        else if (Pair.second == BestClassificationCount)
        {
            // TODO Tie Breaker?
        }
    }

    return BestClassification;
}
