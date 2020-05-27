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

ll W,H,V,T,X,Y,P,Q;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>W>>H>>V>>T>>X>>Y>>P>>Q;
	vector<ll> Xs,Ys;
	for(i=-1000000;i<=1000000;i++) {
		if(i%2==0) {
			Xs.push_back(P+i*W-X);
			Ys.push_back(Q+i*H-Y);
		}
		else {
			Xs.push_back(i*W+W-P-X);
			Ys.push_back(i*H+H-Q-Y);
		}
	}
	V*=T;
	ll ret=0;
	FORR(x,Xs) if(abs(x)<=V) {
		ll d=sqrt(V*V-x*x);
		while(d*d+x*x>V*V) d--;
		while((d+1)*(d+1)+x*x<=V*V) d++;
		ret+=lower_bound(ALL(Ys),d+1)-lower_bound(ALL(Ys),-d);
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
