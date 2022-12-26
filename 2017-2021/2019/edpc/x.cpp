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
int W[1010],S[1010],V[1010];
pair<int,int> P[1010];

ll from[10101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>W[i]>>S[i]>>V[i];
		P[i]={W[i]+S[i],i};
	}
	sort(P,P+N);
	ll ma=0;
	FOR(i,N) {
		j=P[i].second;
		for(x=S[j];x>=0;x--) {
			ll v=from[x]+V[j];
			ma=max(ma,v);
			if(x+W[j]<=10000) from[x+W[j]]=max(from[x+W[j]],v);
		}
	}
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
