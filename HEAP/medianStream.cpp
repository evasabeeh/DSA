class MedianFinder
{
public:
    priority_queue<int> maxHeap;                            // smaller elements than median
    priority_queue<int, vector<int>, greater<int>> minHeap; // larger elements than median

    MedianFinder() {}
    void addNum(int num)
    {
        if (minHeap.empty() && maxHeap.empty())
            maxHeap.push(num);
        else if (num < maxHeap.top())
            maxHeap.push(num);
        else
            minHeap.push(num);

        if (minHeap.size() > maxHeap.size() + 1)
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        if (maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    double findMedian()
    {
        if (maxHeap.size() == minHeap.size())
            return ((maxHeap.top() + minHeap.top()) / 2.0);
        else if (maxHeap.size() < minHeap.size())
            return minHeap.top();
        else
            return maxHeap.top();
    }
};

// https://leetcode.com/problems/find-median-from-data-stream/