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
vector<string> S;
int O[26];

const int NUMC=26;
class Trie {
public:
	vector<vector<int> > V;
	vector<int> num,P,I,D;
	int find(string s) {
		int cur=0;
		ITR(it,s) if((cur=V[cur][*it+1])==0) return -1;
		return cur;
	}
	void create(vector<string> S) { // 0 is for backtrack
		V.push_back(vector<int>(NUMC+1));
		num.push_back(0);
		P.push_back(0);
		I.push_back(-1);
		D.push_back(0);
		sort(S.begin(),S.end());
		ITR(it,S) {
			int cur=0;
			ITR(c,(*it)) {
				if(V[cur][*c+1]==0) {
					V.push_back(vector<int>(NUMC+1));
					V[cur][*c+1]=V.size()-1;
					num.push_back(0);
					P.push_back(cur);
					I.push_back(-1);
					D.push_back(D[cur]+1);
				}
				cur=V[cur][*c+1];
			}
		}
	}
	
	void compress(int cur,int pre) {
		int i,to=0,tar;
		FOR(i,NUMC) if(V[cur][i+1]) to++,tar=V[cur][i+1];
		
		if(to==1 && I[cur]==-1 && cur) {
			V[P[cur]][pre] = tar;
			P[tar]=P[cur];
			compress(tar,pre);
		}
		else {
			FOR(i,NUMC) if(V[cur][i+1]) compress(V[cur][i+1],i+1);
		}
		
	}
	void dfs(int cur) {
		int i;
		FOR(i,NUMC) if(V[cur][i+1]) dfs(V[cur][i+1]), num[cur] += num[V[cur][i+1]];
		
	}
	
	int query(int tar,int cur) {
		int ret=0,i;
		if(I[cur]==tar) return 1;
		char c=S[tar][D[cur]];
		FOR(i,NUMC) if(V[cur][i+1]) {
			if(O[i]<O[c]) ret += num[V[cur][i+1]];
			if(O[i]==O[c]) ret += query(tar,V[cur][i+1]);
		}
		return ret+(I[cur]>=0);
	}
	
};

Trie T;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>s;
		FORR(c,s) c-='a';
		S.push_back(s);
	}
	
	T.create(S);
	FOR(i,N) T.I[T.find(S[i])]=i, T.num[T.find(S[i])]++;
	T.compress(0,-1);
	T.dfs(0);
	
	cin>>Q;
	while(Q--) {
		cin>>x>>s;
		FOR(i,26) O[s[i]-'a']=i;
		cout<<T.query(x-1,0)<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
