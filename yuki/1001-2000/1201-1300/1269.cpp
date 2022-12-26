#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
ll L,R;
ll F[150];

const int NUMC=10;
class Trie {
public:
	vector<vector<int> > V;
	int find(string s) {
		int cur=0;
		ITR(it,s) if((cur=V[cur][*it+1])==0) return -1;
		return cur;
	}
	void create(vector<string> S) { // 0 is for backtrack
		V.clear();
		V.push_back(vector<int>(NUMC+1));
		sort(S.begin(),S.end());
		ITR(it,S) {
			int cur=0;
			ITR(c,(*it)) {
				if(V[cur][*c+1]==0) V.push_back(vector<int>(NUMC+1)),V[cur][*c+1]=V.size()-1;
				cur=V[cur][*c+1];
			}
		}
	}
};

class ACmatch_num {
public:
	Trie t;
	vector<int> acc;
	int ma;
	void create(vector<string> S) {
		int i;
		ma=S.size();
		t.create(S);
		acc.clear();
		acc.resize(t.V.size());
		FOR(i,S.size()) acc[t.find(S[i])]++;
		queue<int> Q;
		FOR(i,NUMC) if(t.V[0][i+1]) t.V[t.V[0][i+1]][0]=0, Q.push(t.V[0][i+1]);
		
		while(!Q.empty()) {
			int k=Q.front(); Q.pop();
			FOR(i,NUMC) if(t.V[k][i+1]) {
				Q.push(t.V[k][i+1]);
				int pre=t.V[k][0];
				while(pre && t.V[pre][i+1]==0) pre=t.V[pre][0];
				t.V[t.V[k][i+1]][0]=t.V[pre][i+1];
				acc[t.V[k][i+1]] += acc[t.V[pre][i+1]];
			}
		}
	}
	int nex(int cur,int c) {
		while(cur && t.V[cur][c+1]==0) cur=t.V[cur][0];
		return t.V[cur][c+1];
	}
};
ACmatch_num ac;

ll from[1010];
ll to[1010];
const ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	vector<string> NG;
	cin>>N>>L>>R;
	F[0]=F[1]=1;
	for(i=1;i<=140;i++) {
		if(i>=2) F[i]=F[i-1]+F[i-2];
		
		if(F[i]>R) break;
		if(F[i]>=L) NG.push_back(to_string(F[i]));
	}
	
	FORR(s,NG) FORR(c,s) c-='0';
	ac.create(NG);
	from[0]=1;
	while(N--) {
		ZERO(to);
		FOR(i,ac.t.V.size()) {
			FOR(j,10) {
				x=ac.nex(i,j);
				if(ac.acc[x]==0) (to[x]+=from[i])%=mo;
			}
		}
		swap(from,to);
	}
	ll ret=mo-1;
	FOR(i,ac.t.V.size()) ret+=from[i];
	cout<<ret%mo<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
