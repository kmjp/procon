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

int N,M;
int A[202020];
int B[202020];
int C[202020];
int D[202020];
vector<int> V[4],AR,BR;
vector<vector<int>> R;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) cin>>x, C[x-1]++;
	FOR(i,M) cin>>x, D[x-1]++;
	
	FOR(i,N) {
		if(C[i]+D[i]<2) return _P("No\n");
		if(D[i]==0) V[0].push_back(i);
		else if(C[i]==0) V[1].push_back(i);
		else V[2].push_back(i);
	}
	
	
	int L=min(V[0].size(),V[1].size());
	if(L==0) {
		FOR(i,V[2].size()) {
			R.push_back({V[2][i],V[2][(i+1)%V[2].size()],1});
			C[V[2][i]]--;
			D[V[2][i]]--;
		}
		
	}
	else {
		FOR(i,L) {
			R.push_back({V[0][i],V[1][i],1});
			C[V[0][i]]--;
			D[V[1][i]]--;
			if(i<L-1) {
				R.push_back({V[0][i+1],V[1][i],0});
				C[V[0][i+1]]--;
				D[V[1][i]]--;
			}
		}
		int last=V[1][L-1];
		FORR(v,V[2]) {
			R.push_back({v,last,0});
			C[v]--;
			D[last]--;
			last=v;
		}
		R.push_back({V[0][0],last,0});
		C[V[0][0]]--;
		D[last]--;
	}
	

	FOR(i,N) FOR(x,C[i]) AR.push_back(i);
	FOR(i,N) FOR(x,D[i]) BR.push_back(i);
	for(i=L;i<V[0].size();i++) {
		x=BR.back();
		BR.pop_back();
		y=BR.back();
		BR.pop_back();
		R.push_back({V[0][i],x,1});
		R.push_back({V[0][i],y,0});
		C[V[0][i]]--;
		C[V[0][i]]--;
		D[x]--;
		D[y]--;
	}
	for(i=L;i<V[1].size();i++) {
		x=AR.back();
		AR.pop_back();
		y=AR.back();
		AR.pop_back();
		R.push_back({x,V[1][i],1});
		R.push_back({y,V[1][i],0});
		D[V[1][i]]--;
		D[V[1][i]]--;
		C[x]--;
		C[y]--;
	}
	
	AR.clear();
	BR.clear();
	FOR(i,N) {
		while(C[i]) C[i]--, AR.push_back(i);
		while(D[i]) D[i]--, BR.push_back(i);
	}
	FOR(i,AR.size()) R.push_back({AR[i],BR[i],0});
	
	assert(R.size()==M);
	cout<<"Yes"<<endl;
	FORR(v,R) cout<<(v[0]+1)<<" "<<(v[2]?"<":">")<<" "<<(v[1]+1)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
