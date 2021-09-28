#include<bits/stdc++.h>

using namespace std;

typedef vector<pair<int,int>> pairv;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    pairv activity;
    int n;
    cin>>n;
    for(int i=0 ; i<n ; ++i)
    {
        int s,e;
        cin>>s>>e;
        activity.push_back(make_pair(e,s));
    }
    sort(activity.begin(),activity.end());
    int count=0,presentEnd=-1;
    for(int i=0 ; i<n ; ++i)
    {
        if(activity[i].second>presentEnd)
        {
            count++;
            presentEnd=activity[i].first;
        }
    }
    cout<<count<<endl;
    return 0;
}