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

int H,W,K;
vector<int> A[101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K;
	
	FOR(y,H) {
		FOR(x,W) A[y].push_back(y*W+x+1);
		int cur=y;
		while(cur && K>=W) {
			swap(A[cur],A[cur-1]);
			cur--;
			K-=W;
		}
	}
	
	FOR(y,H) {
		vector<int> R;
		FORR(r,A[y]) {
			R.push_back(r);
			int cur=R.size()-1;
			while(K && cur) {
				swap(R[cur],R[cur-1]);
				cur--;
				K--;
			}
		}
		A[y]=R;
	}
	
	FOR(y,H) FOR(x,W) _P("%d%c", A[y][x],(x==(W-1))?'\n':' ');
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
