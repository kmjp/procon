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

int nex[42][101010];
ll num[42][101010];
ll sum[101010];


class Solution {
public:
    long long getMaxFunctionValue(vector<int>& receiver, long long k) {
		ZERO(num);
		ZERO(nex);
		int i,j;
		int N=receiver.size();
		FOR(i,N) {
			nex[0][i]=i;
			num[0][i]=i;
			nex[1][i]=receiver[i];
			num[1][i]=i+receiver[i];
		}
		for(j=1;j<=40;j++) {
			FOR(i,N) {
				nex[j+1][i]=nex[j][receiver[nex[j][i]]];
				num[j+1][i]=num[j][i]+num[j][receiver[nex[j][i]]];
			}
		}
		ll ma=0;
		k++;
		FOR(i,N) {
			int cur=i;
			ll s=0;
			FOR(j,40) if(k&(1LL<<j)) {
				s+=num[j][cur];
				cur=receiver[nex[j][cur]];
			}
			ma=max(ma,s);
		}
		return ma;
    }
};
