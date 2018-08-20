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
int A[101010],B[101010],C[101010],D[101010];
map<pair<int,int>,vector<int>> M;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i]>>B[i];
		M[{A[i],B[i]}].push_back(i);
	}
	
	FOR(i,N) {
		if(i==0) {
			if(A[i]) return _P("-1\n");
		}
		else {
			C[i]=1;
			if(M.count({A[i]-1,B[i]-1})+M.count({A[i]-1,B[i]})+M.count({A[i]-1,B[i]+1})==0) return _P("-1\n");
		}
		if(i==1) {
			if(B[i]) return _P("-1\n");
		}
		else {
			D[i]=1;
			if(M.count({A[i]-1,B[i]-1})+M.count({A[i],B[i]-1})+M.count({A[i]+1,B[i]-1})==0) return _P("-1\n");
		}
	}
	
	int ret=2*N-2;
	FORR(m,M) {
		auto a=m.first;
		a.first++;
		a.second--;
		y=0;
		FORR(x,m.second) {
			if(C[x]&&D[x]&&M.count({A[x]-1,B[x]-1})) {
				ret--;
				C[x]=D[x]=0;
			}
			if(D[x]&&M.count(a)&&y<M[a].size()) {
				C[M[a][y]]=0;
				ret--;
				y++;
			}
			
		}
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
