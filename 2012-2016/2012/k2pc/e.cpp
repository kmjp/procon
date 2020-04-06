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
ll mo;
vector<ll> V[1010101];
ll PP[1010101];
int A[1010101];
int L[101010],R[101010];
vector<pair<int,int>> ev[350];
ll ret[101010];
int cnt[1010101];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q>>mo;
	FOR(i,1000001) PP[i]=1, V[i].push_back(0);
	FOR(i,N) {
		cin>>A[i];
		x=A[i];
		PP[x]=PP[x]*x%mo;
		V[x].push_back(PP[x]);
	}
	FOR(i,Q) {
		cin>>L[i]>>R[i];
		L[i]--;
		ev[L[i]/350].push_back({R[i],i});
	}
	
	FOR(i,350) if(ev[i].size()) {
		ZERO(cnt);
		sort(ALL(ev[i]));
		int CL=i*350,CR=CL;
		ll cur=0;
		FORR(e,ev[i]) {
			while(CR<e.first) {
				x=A[CR];
				cnt[x]++;
				cur+=V[x][cnt[x]];
				CR++;
			}
			while(L[e.second]<CL) {
				CL--;
				x=A[CL];
				cnt[x]++;
				cur+=V[x][cnt[x]];
			}
			while(CL<L[e.second]) {
				x=A[CL];
				cur-=V[x][cnt[x]];
				cnt[x]--;
				CL++;
			}
			while(e.first<CR) {
				CR--;
				x=A[CR];
				cur-=V[x][cnt[x]];
				cnt[x]--;
			}
			cur=(cur%mo+mo)%mo;
			ret[e.second]=cur;
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
