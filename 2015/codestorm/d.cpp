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

int win(int num) {
	vector<int> V;
	int i;
	for(i=1;i<=num;i++) V.push_back(i);
	int x=0;
	while(V.size()>1) {
		if(x>=V.size()) x=0;
		if(V.size()%2==1) {
			V.erase(V.begin()+x);
		}
		else {
			V.erase(V.begin()+(x+V.size()/2)%V.size());
			if(x<(V.size()+1)/2) x++;
		}
	}
	return V.back();
}

int T;
int num[1010];

ll dodo(ll N) {
	ll a=1;
	ll v=1;
	while(N > a+v*4) a+=v*4, v*=4;
	N -= a;
	if(N>a) N += (N-a)/2;
	return N;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	//for(i=2;i<=1000;i++) num[i]=win(i), _P("%d %d %d\n",i,num[i],num[i]==dodo(i));
	cin>>T;
	while(T--) {
		ll N;
		cin>>N;
		cout<<dodo(N)<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
