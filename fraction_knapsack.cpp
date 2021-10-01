#include<bits/stdc++.h>

using namespace std;

bool compare(pair<int,int> a,pair<int,int> b)
{
    return a.second*1.0/a.first>b.second*1.0/b.first;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    vector<pair<int,int>> items;
    for(int i=0 ; i<n ; ++i)
    {
        int w,v;
        cin>>w>>v;
        items.push_back(make_pair(w,v));
    }
    int k;
    cin>>k;
    sort(items.begin(),items.end(),compare);
    float max_profit=0;
    for(int i=0 ; i<n && k>0 ; ++i)
    {
        int w=items[i].first,v=items[i].second;
        if(w<=k)
        {
            k-=w;
            max_profit+=v;
        }
        else
        {
            max_profit+=k*v*1.0/w;
            k=0;
        }
    }
    cout<<max_profit<<endl;
}