#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int H[3001];
int M[3001],S[3001],E[3001];
int vis[3001];
pair<int,int> P[3001];
map<int,int> MM[3000];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>H[i];
	FOR(i,N) cin>>M[i]>>S[i]>>E[i];
	FOR(i,N) P[i]=make_pair(S[i],i);
	sort(P,P+N);
	
	int ma=0;
	FOR(i,N) {
		x=P[i].second;
		map<int,int> TM;
		TM[-1]=H[0];
		ZERO(vis);
		for(j=i-1;j>=0;j--) if(E[P[j].second]<=S[x]) {
			if(vis[M[P[j].second]]) continue;
			vis[M[P[j].second]]=1;
			if(M[x]!=M[P[j].second]) {
				ITR(it,MM[j]) TM[-1]=max(TM[-1],it->second+H[0]);
			}
			else {
				ITR(it,MM[j]) TM[-it->first-1]=max(TM[-it->first-1],it->second+H[it->first]);
			}
		}
		int tma=0;
		ITR(it,TM) if(it->second>tma) MM[i][-it->first]=tma=it->second;
		ma=max(ma,tma);
	}
	cout << ma << endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
