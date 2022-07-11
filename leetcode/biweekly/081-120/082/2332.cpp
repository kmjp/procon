#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
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



class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(ALL(buses));
        sort(ALL(passengers));
        int N=buses.size();
        int M=passengers.size();
        vector<int> C(N,capacity);
        vector<int> pat;
        int x=0;
        FORR(p,passengers) {
			while(x<N) {
				if(buses[x]<p) {
					x++;
					continue;
				}
				if(C[x]==0) {
					x++;
					continue;
				}
				C[x]--;
				pat.push_back(p);
				break;
			}
			if(x==N) continue;
		}
        ll cur;
        if(C[N-1]) cur=buses.back();
        else cur=pat.back();
        
        while(pat.size()&&cur==pat.back()) {
			cur--;
			pat.pop_back();
		}
        
		return cur;
        
		
        
    }
};
