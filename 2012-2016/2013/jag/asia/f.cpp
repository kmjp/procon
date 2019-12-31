#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

string S;
vector<ll> V;
ll mo=1000000007;
int ptr;

ll hoge_term();
ll hoge_expr(ll pre) {
	ll a = hoge_term();
	ll v;
	
	if(pre==-1) v=a;
	else if(a<=60) v=pre>>a;
	else v=0;
	
	if(V[ptr]==-2 && V[ptr+1]==-2 && (ptr+2<V.size() && V[ptr+2]!=-2)) {
		ptr+=2;
		return hoge_expr(v);
	}
	else {
		return v;
	}
}
ll hoge_term() {
	if(V[ptr]==-1) {
		ptr++;
		ll v=hoge_expr(-1);
		ptr++;
		return v*v%mo;
	}
	else {
		ll v=V[ptr];
		ptr++;
		return v;
	}
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	while(1) {
		getline(cin,S);
		if(S[0]=='#') break;
		V.clear();
		FORR(c,S) {
			if(c=='S') V.push_back(-1);
			if(c=='>') V.push_back(-2);
			if(c>='0' && c<='9') {
				if(V.empty()||V.back()<0) V.push_back(0);
				V.back()=V.back()*10+c-'0';
			}
		}
		ptr=0;
		cout<<hoge_expr(-1)<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
