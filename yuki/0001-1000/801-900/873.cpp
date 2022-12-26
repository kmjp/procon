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

vector<int> W;
string ret;
int N;

int len[303030];

string hoge() {
	string S;
	multiset<int> V;
	FORR(v,W) V.insert(v);
	int i;
	int nex=0;
	while(V.size()) {
		if(nex==0) {
			FORR(v,V) {
				if(v%2==1) {
					FOR(i,v) S+=(char)('0'+(i%2));
					V.erase(V.find(v));
					goto out;
				}
			}
			auto v=*V.rbegin();
			V.erase(V.find(v));
			FOR(i,v) S+=(char)('0'+(i%2));
			nex=1;
		}
		else {
			int odd=0;
			FORR(v,V) {
				if(v%2==0) {
					FOR(i,v) S+=(char)('1'-(i%2));
					V.erase(V.find(v));
					nex=0;
					goto out;
				}
			}
			auto v=*V.rbegin();
			V.erase(V.find(v));
			FOR(i,v) S+=(char)('1'-(i%2));
			nex=1;
		}
		
		out:;
	}
	return S;
}


void dfs(int cur,int v) {
	if(cur==N) {
		ret=min(ret,hoge());
		return;
	}
	if(cur+v*v>N) return;
	if(cur+v*v<=N && len[cur]+v+len[N-(cur+v*v)]==len[N]) {
		W.push_back(v);
		dfs(cur+v*v,v);
		W.pop_back();
	}
	dfs(cur,v+1);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	FOR(i,N+1) len[i]=i;
	
	for(i=1;i<=600;i++) for(j=0;j+i*i<=N;j++) len[j+i*i]=min(len[j+i*i],len[j]+i);
	
	ret="z";
	dfs(0,1);
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
