#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &v, int start, int end)
{
    int mid = (start + end) / 2;
    vector<int> sorted;
    vector<int> l, r; // l is the left sorted array, r is the right sorted array
    for (int i = start; i <= mid; i++)
        l.push_back(v[i]);
    for (int i = mid + 1; i <= end; i++)
        r.push_back(v[i]);
    int i = 0, j = 0;

    while (i < l.size() && j < r.size()) // inside the range
    {
        if (l[i] < r[j])
        {
            sorted.push_back(l[i]);
            i++;
        }
        else
        {
            sorted.push_back(r[j]);
            j++;
        }
    }
    if (i >= l.size()) // if L array is fully copied into sorted vector, i is out of range
    {
        while (j < r.size())
        {
            sorted.push_back(r[j]);
            j++;
        }
    }
    if (j >= r.size()) // if R array is fully copied into sorted vector, j is out of range
    {
        while (i < l.size())
        {
            sorted.push_back(l[i]);
            i++;
        }
    }

    for (int i = 0; i < sorted.size(); i++)
    {
        v[start + i] = sorted[i]; // copy the sorted array------------
    }
}

void merge_sort(vector<int> &v, int start, int end)
{
    // base case=============
    if (start == end) // size 1------
        return;
    if (end - start == 1) // size 2-------
    {
        if (v[start] > v[end])
            swap(v[start], v[end]);
    }
    // divide===================
    int mid = (start + end) / 2;
    merge_sort(v, start, mid);
    merge_sort(v, mid + 1, end);

    // merge=================
    merge(v, start, end);
}

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    merge_sort(v, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
}