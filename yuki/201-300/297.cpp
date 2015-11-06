#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


ll getma(vector<int> D,int P,int M) {
	ll v=0;
	while(M--) v-=D[0], D.erase(D.begin());
	while(P--) v+=D[0], D.erase(D.begin());
	ll a=0;
	while(D.size()) a=a*10+D.back(), D.pop_back();
	return v+a;
}

ll getmi(vector<int> D,int P,int M) {
	int i;
	ll v=0,a=0;
	
	if(M==0) {
		reverse(ALL(D));
		ll c=1;
		FOR(i,D.size()) {
			v+=D[i]*c;
			if((i+1)%(P+1)==0) c*=10;
		}
	}
	else {
		v+=D[0];
		D.erase(D.begin());
		while(P--) v+=D[0], D.erase(D.begin());
		while(M-->1) v-=D[0], D.erase(D.begin());
		while(D.size()) a=a*10+D.back(), D.pop_back();
	}
	return v-a;
}

void solve() {
	string s;
	int i,N;
	vector<int> D;
	int P=0,M=0;
	
	cin>>N;
	FOR(i,N) {
		cin>>s;
		if(isdigit(s[0])) D.push_back(s[0]-'0');
		if(s[0]=='+') P++;
		if(s[0]=='-') M++;
	}
	sort(ALL(D));
	_P("%lld %lld\n",getma(D,P,M),getmi(D,P,M));
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
