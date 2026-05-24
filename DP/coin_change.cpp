#include<iostream>
#include<vector>
using namespace std;

/// coin type
int n;
vector<int>coins;

int memo[10000];

/// returns the count of how many coins have been used
int solve(int amount)
{
    /// impossible case
    if(amount<0)
        return 10000000;

    ///base case
    if(amount==0)
        return 0; /// paying is done. no more coin is needed

    /// memoization check
    if(memo[amount]!=10000000)
        return memo[amount];


    int ans=10000000;
    for(int i=0;i<n;i++)
    {
        /// i-th coin is taken
        int temp=solve(amount-coins[i]);
        ans=min(ans,temp+1); /// +1 because we have taken a coin
    }

    /// memoization update
    memo[amount]= ans;

    return ans;



}



int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int coin;
        cin>>coin;
        coins.push_back(coin);
    }
    int amount;
    cin>>amount;

    /// memoization initialization
    for(int i=0;i<=amount;i++)
        memo[i]=10000000;

    int ans=solve(amount);

    if(ans==10000000)
        cout<<"impossible"<<endl;
    else
        cout<<ans<<endl;

}








