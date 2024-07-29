// https: // leetcode.com/problems/meeting-rooms-iii/description/

class Solution
{
public:
    int mostBooked(int n, vector<vector<int>> &meetings)
    {
        vector<int> ans(n, 0);
        vector<long long> times(n, 0);
        sort(meetings.begin(), meetings.end());

        for (auto v : meetings)
        {
            int start = v[0], end = v[1];
            bool flag = false;

            int minInd = -1;
            long long val = LONG_MAX;

            for (int j = 0; j < n; j++)
            {
                if (times[j] < val)
                {
                    val = times[j];
                    minInd = j;
                }
                if (times[j] <= start)
                {
                    flag = true;
                    ans[j]++;
                    times[j] = end;
                    break;
                }
            }
            if (!flag)
            {
                ans[minInd]++;
                times[minInd] += (1ll * (end - start));
            }
        }
        int num = -1, maxx = -1;
        for (int i = 0; i < n; i++)
        {
            if (ans[i] > maxx)
            {
                maxx = ans[i];
                num = i;
            }
        }
        return num;
    }
};
