#include<iostream>
#include<vector>
using namespace std;

int n;
/// <value,weight>
vector<pair<int,int>>items;

///memoization
int memo[1000][1000];

///item_no: currently working item's index
///rem_weight: remaining weight in the knapsack
int solve(int rem_weight, int item_no)
{
    ///impossible case
    if(rem_weight<0)
    {
        return -10000000;
    }
    ///base case (no item is there and rem_weight is valid)
    if(item_no==n && rem_weight>=0)
        return 0;

    /// use the memoization array first if the problem was solved previously
    if(memo[rem_weight][item_no]!=-10000000)
        return memo[rem_weight][item_no];

    int left=-10000000, right=-10000000;

    /// item taken
    if(rem_weight>=items[item_no].second)
        left=solve(rem_weight-items[item_no].second,item_no+1)
             +items[item_no].first;
    /// item not taken
    right=solve(rem_weight,item_no+1);
    int ans=max(left,right);

    ///memoization update
    memo[rem_weight][item_no]=ans;
    return ans;

}


int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int value, weight;
        cin>>value>>weight;
        items.push_back({value,weight});
    }
    int rem_weight; ///capacity
    cin>>rem_weight;

    /// memoization  initialization
    for(int i=0;i<=rem_weight;i++)
    {
        for(int j=0;j<=n;j++)
        {
            memo[i][j]=-10000000; /// to say that this problem is not yet solved
        }
    }

    int ans=solve(rem_weight,0);
    cout<<ans<<endl;


}
