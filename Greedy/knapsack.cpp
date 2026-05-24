#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare (pair<int,int>&a,pair<int,int>&b)
{
    // sort based on value/price ==> first/second
    if(1.0*a.first/a.second < 1.0*b.first/b.second)
    {
        // swap
        return false;
    }
    else
        return true;
}

int main()
{
    int n;
    vector<pair<int,int>>items;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int value, price;
        cin>>value>>price;
        items.push_back({value,price});
    }
    // step-1: sorting
    sort(items.begin(),items.end(),compare);

    cout<<"after sorting========"<<endl;

    for(int i=0;i<n;i++)
    {
        cout<<items[i].first<<" "<<items[i].second<<endl;
    }


    //step-2: choose item

    /// remaining price: the limit we can spend
    /// total value: total gain after spending
    int remaining_price,total_value=0;
    cin>>remaining_price;

    for(int i=0;i<n;i++)
    {
        if(remaining_price>0)
        {
            /// full item can be chosen : no fraction
            if(items[i].second<=remaining_price)
            {
                total_value+=items[i].first;
                remaining_price-=items[i].second;

            }
            /// fraction
            else{
                float fraction=1.0*remaining_price/items[i].second;
                remaining_price=0;
                total_value+=1.0*items[i].first*fraction;

            }
        }

    }
    cout<<" total value: "<<total_value<<endl;




}

