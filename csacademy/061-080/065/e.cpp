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

int H,W;
ll U[10101],V[10101];

ll fromt[10101],tot[10101];
ll fromb[10101],tob[10101];

ll cost(int X,int Y) {
	return (V[X]+(Y+1))^(U[Y]+(X+1));
}

void dfs(int T,int B,int L,int R) {
	if(T==B) {
		while(L<R) {
			cout<<"R";
			L++;
		}
		if(T==H-1) cout<<endl;
		else cout<<"D";
		return;
	}
	
	int M=(T+B)/2;
	int x,y;
	fromt[L]=0;
	for(x=L+1;x<=R;x++) fromt[x]=fromt[x-1]+cost(x,T);
	for(y=T+1;y<=M;y++) {
		tot[L]=fromt[L]+cost(L,y);
		for(x=L+1;x<=R;x++) tot[x]=min(fromt[x],tot[x-1])+cost(x,y);
		swap(fromt,tot);
	}
	
	fromb[R]=0;
	for(x=R-1;x>=L;x--) fromb[x]=fromb[x+1]+cost(x,B);
	for(y=B-1;y>=M+1;y--) {
		tob[R]=fromb[R]+cost(R,y);
		for(x=R-1;x>=L;x--) tob[x]=min(fromb[x],tob[x+1])+cost(x,y);
		swap(fromb,tob);
	}
	int bestx=L;
	for(x=L+1;x<=R;x++) if(fromt[x]+fromb[x]<fromt[bestx]+fromb[bestx]) bestx=x;
	
	dfs(T,M,L,bestx);
	dfs(M+1,B,bestx,R);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(i,H) cin>>U[i];
	FOR(i,W) cin>>V[i];
	dfs(0,H-1,0,W-1);
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
