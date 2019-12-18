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

int N;
ll X[4040],Y[4040];


void solve() {
	int i,j,k,l,r,x,y; string s;
	long double pi=4*atan(1);
	
	cin>>N;
	vector<long double> V;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		ll g=__gcd(abs(X[i]),abs(Y[i]));
		if(g==0) {
			i--;
			N--;
			continue;
		}
		X[i]/=g;
		Y[i]/=g;
		V.push_back(atan2(Y[i],X[i]));
		V.push_back(atan2(Y[i],X[i])+2*pi);
		V.push_back(atan2(Y[i],X[i])+4*pi);
	}
	sort(ALL(V));
	ll ret=0;
	FOR(i,N) {
		j=i;
		while(V[j]-V[i]<=pi+1e-12) j++;
		y=j;
		for(x=i+1;x<j;x++) if(V[i]!=V[x]) {
			if(V[x]-V[i]>=pi-1e-12) break;
			while(V[y]-V[x]<pi-1e-12) y++;
			ret+=y-j;
		}
	}
	cout<<ret/3<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
