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
int A[101010],B[101010];
pair<int,int> P[202020];
int ok[101010][2];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i]>>B[i];
		P[i]={A[i],i};
		P[i+N]={B[i],i+N};
	}
	sort(P,P+2*N);
	FOR(i,N) {
		if(P[i].second<N) ok[P[i].second][0]=1;
		else ok[P[i].second-N][1]=1;
	}
	
	int sok[2]={};
	ll sum=0;
	int both=0;
	FOR(i,N) {
		if(ok[i][0]) sum+=A[i],sok[0]++;
		if(ok[i][1]) sum+=B[i],sok[1]++;
		if(ok[i][0]&&ok[i][1]) both=1;
	}
	
	if(both==0 && sok[0] && sok[1]) {
		vector<pair<int,int>> C[2];
		multiset<int> D[2];
		int best=1<<30;
		FOR(i,N) {
			if(ok[i][0]) {
				C[0].push_back({A[i],B[i]});
				D[0].insert(B[i]);
			}
			else {
				C[1].push_back({B[i],A[i]});
				D[1].insert(A[i]);
			}
		}
		FOR(i,2) {
			if(C[i].size()>1) {
				FORR(c,C[i]) {
					x=c.second;
					D[i].erase(D[i].find(x));
					c.second=*D[i].begin();
					D[i].insert(x);
				}
			}
			sort(ALL(C[i]));
		}
		
		FOR(i,2) {
			int L,R=0;
			int SM=1<<30;
			FOR(L,C[0].size()) {
				while(R<C[1].size() && C[1][R].first<=C[0][L].first) {
					SM=min(SM,C[1][R].second);
					R++;
				}
				best=min(best,min(SM,C[0][L].second)-C[0][L].first);
			}
			swap(C[0],C[1]);
		}
		
		sum+=best;
	}
	
	
	cout<<sum<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
