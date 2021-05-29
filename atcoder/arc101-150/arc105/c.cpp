#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


int N,M;
int W[8];
int L[101010],V[101010];
int D[10][10];
pair<int,int> P[101010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>W[i];
	ll ma=*max_element(W,W+N);
	FOR(i,M) {
		cin>>L[i]>>V[i];
		if(V[i]<ma) return _P("-1\n");
		P[i]={V[i],L[i]};
	}
	sort(P,P+M);
	for(i=1;i<M;i++) {
		P[i].second=max(P[i].second,P[i-1].second);
	}
	
	int mi=1<<30;
	vector<int> A;
	FOR(i,N) A.push_back(i);
	
	do {
		ZERO(D);
		FOR(x,N) {
			int ls=0;
			for(y=x;y<N;y++) {
				ls+=W[A[y]];
				j=lower_bound(P,P+M,make_pair(ls,0))-P;
				if(j>0) {
					D[x][y]=max(D[x][y],P[j-1].second);
				}
				
				
			}
		}
		
		FOR(i,8) {
			FOR(x,N) for(int z=x+1;z<N;z++) for(y=z+1;y<N;y++) {
				D[x][y]=max(D[x][y],D[x][z]+D[z][y]);
			}
		}
		mi=min(mi,D[0][N-1]);
		
	} while(next_permutation(ALL(A)));
	
	cout<<mi<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
