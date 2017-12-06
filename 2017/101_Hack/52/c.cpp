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

int N,Q;
int A[101010];
int nex[101010];
int L[101010],R[101010];

int nexid[1010101];
ll ret[101010];
const int DI=350;
vector<pair<int,int>> ev[350];
int del[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) cin>>A[i];
	FOR(i,1010100) nexid[i]=N;
	nex[N]=N-1;
	for(i=N-1;i>=0;i--) {
		nex[i]=min(nexid[A[i]]-1,nex[i+1]);
		nexid[A[i]]=i;
	}
	FOR(i,Q) {
		cin>>L[i]>>R[i];
		L[i]--,R[i]--;
		ev[L[i]/DI].push_back({R[i],i});
	}
	FOR(i,340) if(ev[i].size()) {
		ZERO(del);
		sort(ALL(ev[i]));
		ll tot=0;
		int num=0;
		int LL=0,RR=0;
		FORR(e,ev[i]) {
			x=e.second;
			while(RR<=R[x]) {
				num++;
				del[nex[RR]]++;
				tot+=num;
				num-=del[RR];
				RR++;
			}
			while(LL<L[x]) {
				if(nex[LL]<RR) {
					tot-=(nex[LL]-LL)+1;
				}
				else {
					tot-=RR-LL;
					del[nex[LL]]--;
					num--;
				}
				LL++;
			}
			while(LL>L[x]) {
				LL--;
				if(nex[LL]<RR) {
					tot+=(nex[LL]-LL)+1;
				}
				else {
					tot+=RR-LL;
					del[nex[LL]]++;
					num++;
				}
			}
			ret[x]=tot;
		}
		
		
	}
	FOR(i,Q) cout<<ret[i]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
