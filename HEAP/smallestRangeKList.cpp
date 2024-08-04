class cell
{
public:
    int data;
    int row;
    int col;
};

class compare
{
public:
    bool operator()(cell a, cell b)          // sort heap according to data
    {
        return a.data > b.data;
    }
};

class Solution
{
public:
    pair<int, int> findSmallestRange(int arr[][N], int n, int k)
    {
        priority_queue<cell, vector<cell>, compare> pq;

        int minn = INT_MAX, maxx = INT_MIN;
        for (int i = 0; i < k; i++)                 // storing every list first element
        {
            maxx = max(maxx, arr[i][0]);
            minn = min(minn, arr[i][0]);
            cell newCell;
            newCell.data = arr[i][0];
            newCell.row = i;
            newCell.col = 0;
            pq.push(newCell);
        }

        int start = minn, end = maxx;

        while (!pq.empty())
        {
            auto temp = pq.top();
            pq.pop();

            int data = temp.data, row = temp.row, col = temp.col;
            minn = data;

            if (maxx - minn < end - start)
            {
                start = minn;
                end = maxx;
            }

            if (col + 1 < n)
            {
                maxx = max(maxx, arr[row][col + 1]);
                cell newCell;
                newCell.data = arr[row][col + 1];
                newCell.row = row;
                newCell.col = col + 1;
                pq.push(newCell);
            }                      // if list ends
            else
                break;
        }
        return {start, end};
    }
};

// https://www.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1