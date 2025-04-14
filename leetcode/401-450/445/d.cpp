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

string decdec(string A) {
	for(int i=A.size()-1;i>=0;i--) {
		if(A[i]--!='0') break;
		A[i]='9';
	}
	A=A.substr(A[0]=='0');
	if(A.empty()) A="0";
	return A;
}




pair<string,int> divmod(string A,int b) {
	string V;
	int cur=0;
	FORR(a,A) {
		cur=cur*10+a-'0';
		int m=cur/b;
		if(V.size()||m) V.push_back('0'+m);
		cur%=b;
	}
	if(V.empty()) V="0";
	return {V,cur};
}

// 10êiêîÇÃAÇbêiêîÇ…ïœä∑
string conv_base(string A,int b) {
	string B;
	if(A=="0") return A;
	while(A!="0") {
		auto p=divmod(A,b);
		B+='0'+p.second;
		A=p.first;
	}
	reverse(ALL(B));
	return B;
	
}

ll hoge(string s,int b) {
	ll dp[400][2][10]={}; // dig ,less, pre;
	dp[0][0][0]=1;
	int i,le,pre,cur;
	FOR(i,s.size()) {
		FOR(le,2) FOR(pre,b) FOR(cur,b) {
			if(cur<pre) continue;
			if(le==0&&cur>s[i]-'0') continue;
			(dp[i+1][le|(cur<s[i]-'0')][cur]+=dp[i][le][pre])%=mo;
		}
	}
	
	ll ret=0;
	FOR(le,2) FOR(pre,b) ret+=dp[s.size()][le][pre];
	cout<<s<<" "<<ret<<endl;
	return ret%mo;
	
	
}


class Solution {
public:
    int countNumbers(string l, string r, int b) {
        r=conv_base(r,b);
        l=conv_base(decdec(l),b);
        ll ret=hoge(r,b)-hoge(l,b)+mo;
        return ret%mo;
        
    }
};
