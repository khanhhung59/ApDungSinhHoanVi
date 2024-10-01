#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
int main()
{
    //freopen("FIND.INP", "r", stdin);
    //freopen("FIND.OUT", "w", stdout);
    long long N;
    cin>>N;
    pair<long long,long long> B[N];
    for(long long i = 0 ; i < N; i++)
    {
        long long L, R;
        cin>>L>>R;
        if(L <= R){
            B[i] = {L,R};
        }
        else if( R <= L){
            B[i] = {R,L};
        }
    }
    sort(B, B + N);
    long long MAX = 0;
    long long Cuoi = B[0].second;
    long long Dau = B[0].first;
    for(long long i = 1 ; i < N; i++)
    {
       if(B[i].first <= Cuoi)
       {
           MAX = max(MAX,B[i].second  - Dau);
           Cuoi = B[i].second;
       }
       else
       {
           Cuoi = B[i].second;
           Dau = B[i].first;
           MAX = max(MAX, Cuoi - Dau);
       }
    }
    MAX = max(MAX,Cuoi - Dau);
    cout<<MAX;
    return 0;
}
