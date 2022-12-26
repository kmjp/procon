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

int Q;
int ok[2020];
vector<int> T[16];
vector<vector<int>> E;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	srand(time(NULL));
	FOR(i,Q) {
		cin>>x;
		//x=rand()%1999+1;
		ok[x]=1;
	}
	
	for(i=1;i<=2000;) {
		if(ok[i]==0) {
			i++;
		}
		else {
			int mask=0;
			mask |= ok[i++]<<0;
			mask |= ok[i++]<<1;
			mask |= ok[i++]<<2;
			mask |= ok[i++]<<3;
			T[mask].push_back(i-4);
		}
	}
	
	int best=1010,need=1010;
	for(i=1;i<=1010;i++) {
		int tot=0;
		for(j=1;j<=15;j++) tot+=(T[j].size()+i-1)/i;
		if(tot+i<need) {
			best=i;
			need=tot+i;
		}
	}
	
	need+=4;
	E.push_back({0,1,1});
	E.push_back({0,2,2});
	E.push_back({0,3,3});
	int cur=4,end=4+(need-best-4);
	for(i=1;i<=15;i++) if(T[i].size()) {
		FOR(x,T[i].size()) {
			if(x%best==0) FOR(j,4) if(i&(1<<j)) E.push_back({j,cur+(x/best),0});
			E.push_back({cur+(x/best),end+x%best,T[i][x]});
		}
		
		cur+=(T[i].size()+best-1)/best;
	}
	for(i=end;i<need-1;i++) E.push_back({i,need-1,0});
	
	cout<<need<<" "<<E.size()<<endl;
	FORR(e,E) cout<<e[0]+1<<" "<<e[1]+1<<" "<<e[2]<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
