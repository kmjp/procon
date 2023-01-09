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

int state[10101];

class Solution {
public:
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
		ZERO(state);
        set<pair<int,int>> L,R;
        int i;
        FOR(i,k) L.insert({-time[i][0]-time[i][2],-i});
        map<int,vector<pair<int,int>>> ev;
        // 0->pickold 1->putnew 2->moved
        ev[0].push_back({0,-1});
        int o=0,ret=n;
        while(ev.size()) {
			int tim=ev.begin()->first;
			auto v=ev.begin()->second;
			
			ev.erase(ev.begin());
			FORR(evs,v) {
				int e=evs.first;
				int x=evs.second;
				if(e==2) {
					if(state[x]==0) {
						ev[tim+time[x][1]].push_back({0,x});
					}
					else {
						ev[tim+time[x][3]].push_back({1,x});
					}
					state[x]^=1;
					o=0;
				}
				else if(e==0&&x>=0) {
					R.insert({-time[x][0]-time[x][2],-x});
				}
				else if(e==1) {
					L.insert({-time[x][0]-time[x][2],-x});
				}
			}
			if(o==0&&R.size()) {
				ret--;
				int x=-R.begin()->second;
				R.erase(R.begin());
				ev[tim+time[x][2]].push_back({2,x});
				if(ret==0) return tim+time[x][2];
				o=1;
			}
			else if(o==0&&L.size()&&n) {
				n--;
				int x=-L.begin()->second;
				L.erase(L.begin());
				ev[tim+time[x][0]].push_back({2,x});
				o=1;
			}
		}
		return 0;
    }
};
