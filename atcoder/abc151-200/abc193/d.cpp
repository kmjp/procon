#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

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

int K;
string S,T;
ll C[10];

ll score(string S) {
	ll pat[10];
	int i;
	FOR(i,10) pat[i]=i;
	FORR(c,S) pat[c-'0']*=10;
	ll sum=0;
	FOR(i,10) sum+=pat[i];
	return sum;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K;
	FOR(i,10) C[i]=K;
	cin>>S>>T;
	FOR(i,4) {
		C[S[i]-'0']--;
		C[T[i]-'0']--;
	}
	ll tot=0;
	ll win=0;
	for(x=1;x<=9;x++) if(C[x]) {
		C[x]--;
		for(y=1;y<=9;y++) if(C[y]) {
			ll pat=0;
			if(x==y) pat=C[y]*(C[y]+1);
			else pat+=(C[x]+1)*C[y];
			tot+=pat;
			S[4]='0'+x;
			T[4]='0'+y;
			ll a=score(S);
			ll b=score(T);
			
			if(a>b) win+=pat;
		}
		C[x]++;
	}
	_P("%.12lf\n",win*1.0/tot);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
