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



int A[50505];

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
		ZERO(A);
		int N=roads.size();
		FORR(r,roads) A[r[0]]++, A[r[1]]++;
		int i;
		sort(A,A+n);
		ll ret=0;
		FOR(i,n) {
			ret+=1LL*(i+1)*A[i];
		}
		return ret;
		
        
    }
};
