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

int C[101010];

class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        int i;
        FOR(i,n+2) C[i]=0;
        int num=0;
        vector<int> R;
        FORR(q,queries) {
			int x=q[0]+1;
			if(C[x]&&C[x]==C[x-1]) num--;
			if(C[x]&&C[x]==C[x+1]) num--;
			C[x]=q[1];
			if(C[x]&&C[x]==C[x-1]) num++;
			if(C[x]&&C[x]==C[x+1]) num++;
			R.push_back(num);
		}
		return R;
    }
};
