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

const ll mo=1000000007;
ll memo[101][10][2][2];
string C;
int N;

string decdec(string A) {
	for(int i=A.size()-1;i>=0;i--) {
		if(A[i]--!='0') break;
		A[i]='9';
	}
	A=A.substr(A[0]=='0');
	if(A.empty()) A="0";
	return A;
}

ll hoge(int d,int pre,int lead,int le) {
	if(d>=C.size()) return 1;
	if(memo[d][pre][lead][le]>=0) return memo[d][pre][lead][le];
	
	ll ret=0;
	int i;
	FOR(i,10) {
		if(i==0&&lead==1) {
			ret+=hoge(d+1,0,1,1);
		}
		else {
			if(le==0&&i>C[d]-'0') continue;
			if(lead==0&&abs(pre-i)!=1) continue;
			ret+=hoge(d+1,i,0,le|(i<C[d]-'0'));
		}
	}
	return memo[d][pre][lead][le]=ret%mo;
}

class Solution {
public:
    int countSteppingNumbers(string low, string high) {
		MINUS(memo);
		C=high;
		ll ret=hoge(0,0,1,0);
		
		MINUS(memo);
		C=decdec(low);
		ret+=mo-hoge(0,0,1,0);
		
		return ret%mo;
		
        
    }
};
