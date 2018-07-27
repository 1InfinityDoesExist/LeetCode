/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    bool static comp(Interval &A, Interval &B)
    {
        return A.start < B.start;
    }
    vector<Interval> merge(vector<Interval>& intervals)
    {
        vector<Interval> ans;
        int len = intervals.size();
        if(len == 0)
        {
            return ans;
        }
        sort(intervals.begin(), intervals.end(), comp);
        stack<Interval> s;
        s.push(intervals[0]);
        for(int iter = 1; iter < intervals.size(); iter++)
        {
            Interval topper = s.top();
            if(topper.end < intervals[iter].start)
            {
                s.push(intervals[iter]);
            }
            else if(topper.end < intervals[iter].end)
            {
                topper.end = intervals[iter].end;
                s.pop();
                s.push(topper);
            }
        }
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
