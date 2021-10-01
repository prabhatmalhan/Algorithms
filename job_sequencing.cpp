#include<bits/stdc++.h>

using namespace std;

bool compare(pair<int,int> a,pair<int,int> b)
{
    return a.first>b.first;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    vector<pair<int,int>> job;
    int max_end_time=INT_MIN;
    for(int i=0 ; i<n ; ++i)
    {
        int p,d;
        cin>>p>>d;
        job.push_back(make_pair(p,d));
        max_end_time=max(max_end_time,d);
    }
    sort(job.begin(),job.end(),compare);
    vector<bool> visited(max_end_time,false);
    int max_profit=0,count=0;
    for(int i=0 ; i<n ; ++i)
    {
        int p=job[i].first,d=job[i].second-1;
        while(d>=0 && visited[d])
            d--;
        if(d>=0 && !visited[d])
        {
            visited[d]=true;
            count++;
            max_profit+=p;
        }
    }
    cout<<"Max Jobs Sequenced : "<<count<<endl;
    cout<<"Maximum profit : "<<max_profit<<endl;
    return 0;
}