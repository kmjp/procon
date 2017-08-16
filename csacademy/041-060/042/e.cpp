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
int A[2020],B[2020];
vector<int> X,Y;
int ma;

void dfs(int d,int XL,int XR,int YL,int YR) {
	int XM=XL;
	int YM=YL;
	
	if(XR<=XL || YR<=YL) return;
	if(XR-XL==1 && YR-YL==1) {
		ma=max(ma,X[XL]^Y[YL]);
		return;
	}
	
	while(XM<XR && (X[XM]&(1<<d))==0) XM++;
	while(YM<YR && (Y[YM]&(1<<d))==0) YM++;
	dfs(d-1,XL,XM,YM,YR);
	dfs(d-1,XM,XR,YL,YM);
	if(ma>=(1<<d)) return;
	dfs(d-1,XL,XM,YL,YM);
	dfs(d-1,XM,XR,YM,YR);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	srand(i);
	
	FOR(i,N) cin>>A[i];
	FOR(x,N) {
		int t=0;
		for(j=1;x+j<=N;j++) {
			t^=A[x+j-1];
			if(j%2==0) ma=max(ma,t);
			else X.push_back(t);
		}
	}
	FOR(i,M) cin>>B[i];
	FOR(x,M) {
		int t=0;
		for(j=1;x+j<=M;j++) {
			t^=B[x+j-1];
			if(j%2==0) ma=max(ma,t);
			else Y.push_back(t);
		}
	}
	
	sort(ALL(X));
	sort(ALL(Y));
	X.erase(unique(ALL(X)),X.end());
	Y.erase(unique(ALL(Y)),Y.end());
	dfs(29,0,X.size(),0,Y.size());
	
	cout<<ma<<endl;

}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
