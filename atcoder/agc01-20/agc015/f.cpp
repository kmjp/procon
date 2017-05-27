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

int Q;
ll F[91];
ll X,Y;

vector<pair<ll,ll>> cand[91];
ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	F[0]=F[1]=1;
	for(i=2;i<=89;i++) {
		F[i]=F[i-1]+F[i-2];
		for(j=2;j<=i+1;j++) {
			ll a=1,b=1;
			for(x=2;x<=i;x++) {
				ll c=b+a;
				if(x==j) c+=a;
				b=a;
				a=c;
			}
			cand[i].push_back({a,a+b});
			cand[i].push_back({a+b,a});
		}
	}
	
	
	cin>>Q;
	while(Q--) {
		cin>>X>>Y;
		
		if(X>Y) swap(X,Y);
		if(X==1 || (X==2&&Y==2)) {
			cout<<1<<" "<<(X*Y)%mo<<endl;
			continue;
		}
		
		int k=0;
		while(F[k+1]<=X && F[k+2]<=Y) k++;
		ll ret=0;
		FORR(r,cand[k]) if(X>=r.first && Y>=r.second) {
			(ret += 1+(Y-r.second)/r.first)%=mo;
		}
		cout<<k<<" "<<ret<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
