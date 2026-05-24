#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare (pair<int,int>&a,pair<int,int>&b)
{
    // sort based on the second element
    if(a.second < b.second )
    {
        // no swap
        return true;
    }
    else
        return false;
}

int main()
{
    int n;
    vector<pair<int,int>>activities;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int startTime, endTime;
        cin>>startTime>>endTime;
        activities.push_back({startTime,endTime});
    }
    // step-1: sorting
    sort(activities.begin(),activities.end(),compare);
    for(int i=0;i<n;i++)
    {
        cout<<activities[i].first<<" "<<activities[i].second<<endl;
    }


    //step-2: choose activity
    /// finish time: when I will be free
    int count=0, current_finish_time=-1;

    for(int i=0;i<n;i++)
    {
        /// check if the next work starts after the current work
        if(current_finish_time<activities[i].first)
        {
            /// the activity is chosen, update the finish time.
            count++;
            current_finish_time=activities[i].second;
        }
    }
    cout<<" total works done: "<<count<<endl;




}
