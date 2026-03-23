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

int N,K;
vector<string> S;

const int NUMC=3;
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
		V.back().back()=-1;
		sort(S.begin(),S.end());
		int i;
		FOR(i,S.size()) {
			string s=S[i];
			int cur=0;
			FORR(c,s) {
				if(V[cur][c+1]==0) {
					V.push_back(vector<int>(NUMC+2));
					V[cur][c+1]=V.size()-1;
					V.back().back()=-1;
				}
				cur=V[cur][c+1];
			}
			V[cur][NUMC+1]=i;
		}
	}
};

class ACmatch_enum {
public:
	Trie t;
	vector<set<int> > acc;
	int ma;
	void create(vector<string> S) {
		int i;
		ma=S.size();
		t.create(S);
		acc.clear();
		acc.resize(t.V.size());
		FOR(i,S.size()) acc[t.find(S[i])].insert(i);
		queue<int> Q;
		FOR(i,NUMC) if(t.V[0][i+1]) t.V[t.V[0][i+1]][0]=0, Q.push(t.V[0][i+1]);
		//添え字順のアクセスではなくBFS順にすること
		while(!Q.empty()) {
			int k=Q.front(); Q.pop();
			FOR(i,NUMC) if(t.V[k][i+1]) {
				Q.push(t.V[k][i+1]);
				int pre=t.V[k][0];
				while(pre && t.V[pre][i+1]==0) pre=t.V[pre][0];
				t.V[t.V[k][i+1]][0]=t.V[pre][i+1];
				FORR(it,acc[t.V[pre][i+1]]) acc[t.V[k][i+1]].insert(it);
			}
		}
	}

};

string from[51*51][51];
string to[51*51][51];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	S.resize(N);
	FOR(i,N) {
		cin>>S[i];
		if(S[i]=="()") {
			cout<<-1<<endl;
			return;
		}
		FORR(c,S[i]) c-='(';
	}
	ACmatch_enum ac;
	ac.create(S);
	
	from[0][0]="-";
	FOR(i,K) {
		FOR(x,ac.acc.size()+1) FOR(y,K) to[x][y]="";
		FOR(x,ac.acc.size()+1) FOR(y,K) if(from[x][y].size()) {
			int cur=x;
			FOR(k,2) {
				int cur=x;
				if(y==0&&k==1) continue;
				while(cur&&ac.t.V[cur][k+1]==0) cur=ac.t.V[cur][0];
				cur=ac.t.V[cur][k+1];
				if(ac.acc[cur].empty()) {
					to[cur][y+((k==0)?1:-1)]=from[x][y]+(char)('('+k);
				}
			}
		}
		FOR(x,ac.acc.size()+1) FOR(y,K) from[x][y]=to[x][y];
	}
	string ret;
	FOR(x,ac.acc.size()+1) if(from[x][0].size()) ret=from[x][0].substr(1);
	
	if(ret.size()) {
		cout<<1<<endl;
		cout<<ret<<endl;
		cout<<N<<endl;
		FOR(i,N) cout<<i+1<<" ";
		cout<<endl;
	}
	else {
		string A,B;
		vector<int> As,Bs;
		FOR(i,K/2) A+="()";
		FOR(i,K/2) B+="(";
		FOR(i,K/2) B+=")";
		
		FOR(i,N) {
			FORR(c,S[i]) c+='(';
			for(x=0;x+S[i].size()<=K;x++) {
				if(A.substr(x,S[i].size())==S[i]) break;
			}
			if(x+S[i].size()<=K) Bs.push_back(i);
			else As.push_back(i);
		}
		cout<<"2"<<endl;
		cout<<A<<endl;
		cout<<As.size()<<endl;
		FORR(a,As) cout<<a+1<<" ";
		cout<<endl;
		cout<<B<<endl;
		cout<<Bs.size()<<endl;
		FORR(a,Bs) cout<<a+1<<" ";
		cout<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
