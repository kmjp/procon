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
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
		vector<pair<int,int>> V;
		int N=position.size();
		int i;
		FOR(i,N) {
			if(i<N-1&&position[i]+distance>=position[i+1]) continue;
			V.push_back({position[i],speed[i]});
		}
		int mi=1<<30;
		int num=0;
		for(i=V.size()-1;i>=0;i--) {
			if(V[i].second<=mi) {
				num++;
				mi=V[i].second;
			}
		}
		return num;
    }
};
