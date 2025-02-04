#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int L[202020],R[202020];
ll S[202020];
class Solution {
	public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int N=endTime.size();
        int i;
        FOR(i,N) L[i+1]=startTime[i];
        FOR(i,N) R[i+1]=endTime[i];
        L[N+1]=R[N+1]=eventTime;
        multiset<int> dif;
        dif.insert(-1);
        FOR(i,N+1) dif.insert(L[i+1]-R[i]);
		ll ma=0;
		for(i=0;i+2<=N+1;i++) {
			ll a=L[i+2]-R[i];
			ll b=R[i+1]-L[i+1];
			ma=max(ma,a-b);
			dif.erase(dif.find(L[i+1]-R[i]));
			dif.erase(dif.find(L[i+2]-R[i+1]));
			if(*dif.rbegin()>=b) ma=max(ma,a);
			dif.insert(L[i+1]-R[i]);
			dif.insert(L[i+2]-R[i+1]);
			
		}
		return ma;
    }
};



