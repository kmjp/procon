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

int N,M;
vector<string> S;

string R;

const int NUMC=26;
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
		V.push_back(vector<int>(NUMC+3));
		sort(S.begin(),S.end());
		int i;
		FOR(i,S.size()) {
			string s=S[i];
			int cur=0;
			FORR(c,s) {
				V[cur][NUMC+1]++;
				if(V[cur][c+1]==0) {
					V.push_back(vector<int>(NUMC+3));
					V[cur][c+1]=V.size()-1;
				}
				cur=V[cur][c+1];
			}
			V[cur][NUMC+2]++;
		}
	}
};
Trie t;

void dfs(int cur,int sub) {
	sub+=t.V[cur][NUMC+2];
	if(sub<=N-M) {
		if(sub+t.V[cur][NUMC+1]<=N-M) {
			cout<<"Yes"<<endl;
			cout<<R<<endl;
			exit(0);
			return;
		}
		int i;
		FOR(i,26) {
			if(t.V[cur][i+1]==0) {
				t.V.push_back(vector<int>(NUMC+3));
				t.V[cur][i+1]=t.V.size()-1;
			}
			R+='a'+i;
			dfs(t.V[cur][i+1],sub);
			R.pop_back();
		}
	}
	
	
	sub-=t.V[cur][NUMC+2];
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>s;
		FORR(c,s) c-='a';
		S.push_back(s);
	}
	t.create(S);
	
	
	dfs(0,0);
	cout<<"No"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
