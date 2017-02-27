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
map<int,int> M;
map<int,set<int>> C;
vector<int> V;

void add(int y) {
	V.push_back(y);
	C[M[y]].erase(y);
	if(C[M[y]].size()==0) C.erase(M[y]);
	M[y]--;
	if(M[y]==0) {
		M.erase(y);
	}
	else {
		C[M[y]].insert(y);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		M[x]++;
	}
	FOR(i,100001) if(M.count(i)) C[M[i]].insert(i);
	
	V.push_back(0);
	FOR(i,N) {
		x = C.rbegin()->first;
		if(x+x-1>N-i) return _P("-1");
		if(x+x-1==N-i) {
			y = *C.rbegin()->second.begin();
			if(V.back()==y) return _P("-1");
			add(y);
		}
		else {
			int tar=-1;
			FORR(r,M) {
				if(V.back()==r.first) continue;
				tar=r.first;
				break;
			}
			add(tar);
		}
	}
	
	for(i=1;i<=N;i++) _P("%d%c",V[i],(i==N)?'\n':' ');
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
