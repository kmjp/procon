#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N;
vector<string> S;

const int NUMC=4;
class Trie {
public:
	vector<vector<int> > V;
	int find(string s) {
		int cur=0;
		FORR(c,s) if((cur=V[cur][c+1])==0) return -1;
		return cur;
	}
	void create(vector<string> S) { // 0 is for backtrack
		V.clear();
		V.push_back(vector<int>(NUMC+1));
		sort(S.begin(),S.end());
		FORR(s,S) {
			int cur=0;
			FORR(c,s) {
				if(V[cur][c+1]==0) V.push_back(vector<int>(NUMC+1)),V[cur][c+1]=V.size()-1;
				cur=V[cur][c+1];
			}
		}
	}
};


class ACmatch_num {
public:
	Trie t;
	
	vector<int> acc;
	map<pair<int,int>,int> memo;
	int ma;
	void create(vector<string> S) {
		int i;
		ma=S.size();
		t.create(S);
		acc.clear();
		acc.resize(t.V.size(),-1);
		memo.clear();
		FOR(i,S.size()) {
			int cur=t.find(S[i]);
			if(acc[cur]==-1||S[i].size()>S[acc[cur]].size()) acc[cur]=i;
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
				if(acc[t.V[k][i+1]]==-1) acc[t.V[k][i+1]] = acc[t.V[pre][i+1]];
				if(acc[t.V[k][i+1]]>-1&&acc[t.V[pre][i+1]]>-1&&S[acc[t.V[pre][i+1]]].size()>S[acc[t.V[k][i+1]]].size()) acc[t.V[k][i+1]] = acc[t.V[pre][i+1]];
			}
		}
	}
	int nex(int cur,int c) {
		if(memo.count({cur,c})) return memo[{cur,c}];
		if(cur && t.V[cur][c+1]==0) return memo[{cur,c}]=nex(t.V[cur][0],c);
		return memo[{cur,c}]=t.V[cur][c+1];
	}
};

vector<int> prefix_index,prefix_len, tables[202020];

ACmatch_num ac;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>s;
		FORR(c,s) c-='A';
		S.push_back(s);
		tables[i].resize(s.size()+1,-1);
	}
	ac.create(S);
	prefix_index.resize(ac.acc.size(),-1);
	prefix_len.resize(ac.acc.size(),-1);
	vector<int> T;
	FOR(i,N) {
		s=S[i];
		vector<int> hist={0};
		int cnt=0;
		FORR(c,s) {
			hist.push_back(ac.nex(hist.back(),c));
			x=ac.acc[hist.back()];
			if(x>-1) {
				cnt++;
				y=S[x].size();
				hist.resize(hist.size()-y);
			}
		}
		if(hist.size()>1) {
			cout<<"Yes"<<endl;
			return;
		}
		else if(cnt==1) {
			T.push_back(i);
		}
	}
	
	FORR(i,T) {
		string t=S[i];
		int cur=0;
		FOR(j,t.size()) {
			char c=t[j];
			cur=ac.nex(cur,c);
			if(prefix_index[cur]==-1) {
				prefix_index[cur]=i;
				prefix_len[cur]=j+1;
			}
			else {
				prefix_index[cur]=-2;
			}
		}
	}
	FORR(i,T) {
		string t=S[i];
		int cur=0;
		FORR(c,t) cur=ac.nex(cur,c);
		while(cur) {
			if(prefix_index[cur]==-2) {
				cout<<"Yes"<<endl;
				return;
			}
			else if(prefix_index[cur]!=-1) {
				if(S[i].size()!=S[prefix_index[cur]].size()) {
					cout<<"Yes"<<endl;
					return;
				}
				tables[i][prefix_len[cur]]=prefix_index[cur];
			}
			cur=ac.t.V[cur][0];
		}
	}
	
	FORR(i,T) {
		for(int len=1;len<S[i].size();len++) {
			x=tables[i][len];
			if(x>-1 && tables[x][S[i].size()-len]!=i) {
				cout<<"Yes"<<endl;
				return;
			}
		}
	}
	cout<<"No"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
