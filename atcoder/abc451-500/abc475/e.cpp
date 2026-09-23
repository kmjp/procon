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

int N,M,K,Q;
string T,S[303030];
int QA[505050],QB[505050];

const int NUMC=2;
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
		V.push_back(vector<int>(NUMC+2));
		sort(S.begin(),S.end());
		int i;
		FOR(i,S.size()) {
			string s=S[i];
			int cur=0;
			FORR(c,s) {
				if(V[cur][c+1]==0) {
					V.push_back(vector<int>(NUMC+2));
					V[cur][c+1]=V.size()-1;
				}
				cur=V[cur][c+1];
			}
		}
	}
	void add(string S,int v) {
		int cur=0;
		V[cur][NUMC+1]+=v;
		FORR(c,S) {
			cur=V[cur][c+1];
			V[cur][NUMC+1]+=v;
		}
	}
	int check(string S,int v) {
		int cur=0;
		int i;
		FOR(i,S.size()) {
			char c=S[i];
			if(c==1) {
				cur=V[cur][c+1];
				if(V[cur][NUMC+1]<=v) return 1;
			}
			else {
				if(V[cur][1+1]) v-=V[V[cur][1+1]][NUMC+1];
				if(v<=0) return 0;
				cur=V[cur][c+1];
			}
		}
		return 0;
	}
	
};
Trie t;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	cin>>T;
	vector<string> V;
	FOR(i,N) {
		cin>>S[i];
		FOR(x,K) S[i][x]=T[x]==S[i][x];
		V.push_back(S[i]);
	}
	cin>>Q;
	FOR(i,Q) {
		cin>>QA[i]>>QB[i];
		QA[i]--;
		QB[i]--;
		S[QA[i]][QB[i]]^=1;
		V.push_back(S[QA[i]]);
	}
	FOR(i,Q) {
		S[QA[i]][QB[i]]^=1;
	}
	t.create(V);
	FOR(i,N) t.add(S[i],1);
	FOR(i,Q) {
		t.add(S[QA[i]],-1);
		S[QA[i]][QB[i]]^=1;
		t.add(S[QA[i]],1);
		if(t.check(S[QA[i]],M)) {
			cout<<"Yes"<<endl;
		}
		else {
			cout<<"No"<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
