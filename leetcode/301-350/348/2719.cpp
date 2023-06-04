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

string decdec(string A) {
	for(int i=A.size()-1;i>=0;i--) {
		if(A[i]--!='0') break;
		A[i]='9';
	}
	A=A.substr(A[0]=='0');
	if(A.empty()) A="0";
	return A;
}
const ll mo=1000000007;
string S;
ll memo[23][2][404];

ll hoge(int d,int le,int lef) {
	if(lef<0) return 0;
	if(d==-1) return lef==0;
	if(memo[d][le][lef]>=0) return memo[d][le][lef];
	int i;
	ll ret=0;
	FOR(i,10) {
		if(i>lef) continue;
		if(le==0&&i>S[d]-'0') continue;
		ret+=hoge(d-1,le||(i<S[d]-'0'),lef-i);
	}
	return memo[d][le][lef]=ret%mo;
}

class Solution {
public:
    int count(string num1, string num2, int min_sum, int max_sum) {
		num1=decdec(num1);
		reverse(ALL(num1));
		reverse(ALL(num2));
		while(num1.size()<=23) num1+='0';
		while(num2.size()<=23) num2+='0';
		
		S=num2;
		MINUS(memo);
		ll ret=0;
		for(int i=min_sum;i<=max_sum;i++) ret+=hoge(22,0,i);
		S=num1;
		MINUS(memo);
		for(int i=min_sum;i<=max_sum;i++) ret+=mo-hoge(22,0,i);
		
		return ret%mo;
		
        
    }
};
