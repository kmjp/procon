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

int X;
int F[2020202];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X;
	for(i=1;i<=X;i++) {
		for(j=i;j<=X;j+=i) {
			F[j]++;
		}
	}
	for(i=1;i<=X;i++) F[i]=i-F[i];
	
	int mi=X+1;
	vector<int> V;
	for(i=1;i<X;i++) {
		if(abs(F[i]-F[X-i])<mi) mi=abs(F[i]-F[X-i]), V.clear();
		if(abs(F[i]-F[X-i])==mi) V.push_back(i);
	}
	
	FORR(v,V) cout<<v<<" "<<X-v<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
