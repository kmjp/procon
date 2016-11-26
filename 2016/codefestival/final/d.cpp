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
int num[101010];
set<int> E[2][101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>x, num[x]++;
	int ret=0;
	x=y=0;
	FOR(i,100001) if(num[i]) {
		if(i%M==0) {
			x+=num[i];
			num[i]=0;
		}
		else if(M%2==0 && i%(M/2)==0) {
			y += num[i];
			num[i]=0;
		}
		else {
			E[num[i]%2][i%M].insert(i);
		}
	}
	ret = x/2+y/2;
	for(i=1;i<M;i++) {
		j=M-i;
		while(E[1][i].size()) {
			x=*E[1][i].begin();
			r=-1;
			if(E[1][j].size()) r=1;
			else if(E[0][j].size()) r=0;
			if(r==-1) break;
			
			y=*E[r][j].begin();
			E[1][i].erase(E[1][i].begin());
			E[r][j].erase(E[r][j].begin());
			num[x]--;
			num[y]--;
			ret++;
			if(num[x]>0) E[0][i].insert(x);
			if(num[y]>0) E[num[y]%2][j].insert(y);
		}
	}
	FOR(i,100001) ret+=num[i]/2;
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
