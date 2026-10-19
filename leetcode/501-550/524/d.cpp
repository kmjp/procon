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
    int minSelection(vector<vector<int>>& availableIntervals, vector<vector<int>>& targetIntervals) {
		sort(ALL(targetIntervals));
		sort(ALL(availableIntervals));
		vector<vector<int>> T;
		FORR(t,targetIntervals) {
			if(T.empty()||t[0]>T.back()[1]) {
				T.push_back(t);
			}
			else {
				T.back()[1]=max(T.back()[1],t[1]);
			}
		}
		
		int num=0;
		int R=-1;
		int N=availableIntervals.size();
		int cur=0;
		FORR(t,T) {
			int TL=t[0],TR=t[1];
			while(R<TR) {
				int s=max(R,TL);
				int e=R;
				while(cur<N&&availableIntervals[cur][0]<=s) {
					e=max(e,availableIntervals[cur][1]);
					cur++;
					
				}
				
				if(e<=R||e<TL) return -1;
				R=e;
				num++;
			}
		}
		return num;
        
    }
};

