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

int N,Q;
ll X,Y;
vector<string> S;


const int NUMC=26;
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

class ACmatch_enum {
public:
	Trie t;
	vector<ll> pos,lef,cost,ok;
	int ma;
	ll dfs(int cur) {
		int i;
		FOR(i,NUMC) if(t.V[cur][i+1]) lef[cur]=min(lef[cur],dfs(t.V[cur][i+1])+1);
		return lef[cur];
	}
	void create(vector<string> S) {
		int i,j;
		ma=S.size();
		t.create(S);
		lef.resize(t.V.size(),1LL<<30);
		pos.resize(t.V.size(),-1);
		cost.resize(t.V.size(),1LL<<60);
		pos[0]=0;
		FOR(i,S.size()) {
			int cur=0;
			FOR(j,S[i].size()) {
				cur=t.V[cur][S[i][j]+1];
				assert(pos[cur]==-1||pos[cur]==j+1);
				pos[cur]=j+1;
			}
			lef[cur]=0;
		}
		queue<int> Q;
		FOR(i,NUMC) if(t.V[0][i+1]) t.V[t.V[0][i+1]][0]=0, Q.push(t.V[0][i+1]);
		
		while(!Q.empty()) {
			int k=Q.front(); Q.pop();
			FOR(i,NUMC) if(t.V[k][i+1]) {
				Q.push(t.V[k][i+1]);
				int pre=t.V[k][0];
				while(pre && t.V[pre][i+1]==0) pre=t.V[pre][0];
				t.V[t.V[k][i+1]][0]=t.V[pre][i+1];
			}
		}
		dfs(0);
		FOR(i,t.V.size()) cost[i]=lef[i]*Y-pos[i]*X;
		
		Q.push(0);
		while(!Q.empty()) {
			int k=Q.front(); Q.pop();
			cost[k]=min(cost[k],cost[t.V[k][0]]);
			FOR(i,NUMC) if(t.V[k][i+1]) {
				Q.push(t.V[k][i+1]);
				cost[t.V[k][i+1]]=min(cost[t.V[k][i+1]],cost[k]);
			}
		}
		
	}

};
ACmatch_enum ac;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q>>X>>Y;
	FOR(i,N) {
		cin>>s;
		FORR(c,s) c-='a';
		S.push_back(s);
	}
	ac.create(S);
	while(Q--) {
		cin>>s;
		ll L=s.size();
		ll ret=L*X+ac.cost[0];
		int cur=0;
		ll del=0;
		//cout<<"!"<<ret<<endl;
		FOR(i,L) {
			char c=s[i]-'a';
			while(cur && ac.t.V[cur][c+1]==0) cur=ac.t.V[cur][0];
			cur=ac.t.V[cur][c+1];
			
			ret=min(ret,ac.cost[cur]+L*X);
			//cout<<"!"<<cur<<" "<<ac.pos[cur]<<" "<<ret<<" "<<ac.acc[cur]<<"  "<<(i+1-ac.pos[cur])*X+ac.acc[cur]*Y+(L-1-i)*X<<endl;
		}
		cout<<ret<<endl;
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
