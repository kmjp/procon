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
ll A[2010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,2*N) cin>>A[i];
	sort(A,A+2*N);
	
	for(i=1;i<2*N;i++) {
		int X=A[i]-A[0];
		if(X==0) continue;
		vector<int> R;
		int cnt[2020]={};
		cnt[0]=1;
		cnt[i]=2;
		R.push_back(A[i]);
		for(x=1,y=i+1;x<2*N;x++) {
			if(cnt[x]) continue;
			while(y<2*N && (cnt[y] || A[y]-A[x]<X)) y++;
			if(y==2*N) break;
			if(A[y]!=A[x]+X) break;
			cnt[x]=1;
			cnt[y]=2;
			R.push_back(A[y]);
			y++;
		}
		
		if(x==2*N) {
			_P("%d\n",X);
			FOR(i,R.size()) _P("%d%c",R[i],(i==R.size()-1)?'\n':' ');
			return;
		}
	}
	_P("-1\n");
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
