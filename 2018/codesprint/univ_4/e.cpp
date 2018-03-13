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
int nex[1010101];
int pre[1010101];
int Q,L[1010101],R[1010101],ret[1010101];
vector<pair<int,int>> E[1015];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	map<int,int> p;
	cin>>N;
	for(i=1;i<=N;i++) {
		cin>>x;
		if(p.count(x)) {
			nex[p[x]]=i;
			pre[i]=p[x];
		}
		else {
			pre[i]=-1;
		}
		nex[i]=N+1;
		p[x]=i;
	}
	
	cin>>Q;
	FOR(i,Q) {
		cin>>L[i]>>R[i];
		E[L[i]/1000].push_back({R[i],i});
	}
	FOR(i,1010) if(E[i].size()) {
		int LL,RR;
		LL=RR=i*1000;
		int cnt=0;
		sort(ALL(E[i]));
		FORR(r,E[i]) {
			x=r.second;
			while(RR<=R[x]) {
				if(pre[RR]<LL) cnt++;
				else if(pre[pre[RR]]<LL) cnt--;
				RR++;
			}
			while(L[x]<LL) {
				LL--;
				if(nex[LL]>=RR) cnt++;
				else if(nex[nex[LL]]>=RR) cnt--;
			}
			while(LL<L[x]) {
				if(nex[LL]<RR) {
					if(nex[nex[LL]]>=RR) cnt++;
				}
				else cnt--;
				LL++;
			}
			ret[x]=cnt;
		}
		
		
	}
	FOR(i,Q) _P("%d\n",ret[i]);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
