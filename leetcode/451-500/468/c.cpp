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
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
		int N=nums1.size();
		map<vector<int>,int> M;
		queue<vector<int>> Q;
		M[nums1]=0;
		Q.push(nums1);
		while(Q.size()) {
			vector<int> cur=Q.front();
			Q.pop();
			if(cur==nums2) return M[cur];
			for(int S=1;S<N;S++) {
				for(int L=1;L<=S;L++) {
					for(int R=1;S+R<=N;R++) {
						vector<int> V;
						int i;
						FOR(i,S-L) V.push_back(cur[i]);
						FOR(i,R) V.push_back(cur[S+i]);
						FOR(i,L) V.push_back(cur[S-L+i]);
						FOR(i,N-S-R) V.push_back(cur[S+R+i]);
						if(M.count(V)==0) {
							M[V]=M[cur]+1;
							Q.push(V);
						}
					}
					
				}
			}
			
		}
        return 0;
    }
};

