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
ll T;
ll X[101010],D[101010];
ll stop[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>T>>Q;
	FOR(i,N) cin>>X[i]>>D[i];
	int left=N;
	for(i=N-1;i>=0;i--) {
		if(D[i]==2) left=i;
		else {
			if(left==N) stop[i]=1LL<<61;
			else stop[i]=(X[left-1]+X[left])/2;
		}
	}
	int right=-1;
	FOR(i,N) {
		if(D[i]==1) right=i;
		else {
			if(right==-1) stop[i]=-1LL<<61;
			else stop[i]=(X[right]+X[right+1])/2;
		}
	}
	
	FOR(i,Q) {
		cin>>x;
		x--;
		if(D[x]==1) cout<<min(stop[x],X[x]+T)<<endl;
		else cout<<max(stop[x],X[x]-T)<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
