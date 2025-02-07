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

int T,N;

const int prime_max = 1000000;
vector<int> prime;
int NP,divp[prime_max];

void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime.push_back(i); NP++;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}

int F(int x) {
	if(x%2==1) return x*(x+1)/2+1;
	else return x*(x+1)/2-(x/2-1)+1;
	
}

template<int MV> class UndirectedEulerPath {
public:
	vector<int> path;
	multiset<int> E[MV];
	void add_path(int x,int y) { E[x].insert(y); E[y].insert(x); }
	int NV=MV;
	void init(int NV_) {
		int i;
		NV=NV_;
		FOR(i,NV) E[i].clear();
		path.clear();
	}
	
	void dfs(int cur) {
		while(E[cur].size()) {
			int tar=*E[cur].begin();
			E[cur].erase(E[cur].begin());
			E[tar].erase(E[tar].find(cur));
			dfs(tar);
		}
		path.push_back(cur);
	}
	
	bool GetPath(int root=-1) { // 開始地点を探し、条件を満たすか判定
		int fo=-1,odd=0,i,np=0;
		FOR(i,NV) {
			np += E[i].size();
			if(E[i].size()%2) odd++, fo=(fo==-1)?i:fo;
		}
		//閉路なら奇数を許容しないようにしておく
		if(odd!=0 && odd!=2) return false;
		if(root==-1) {
			if(odd) {
				root=fo;
			}
			else {
				FOR(i,MV) if(E[i].size()) root=i;
			}
		}
		else {
			if(odd==2&&E[root].size()%2==0) return false;
		}
		dfs(root);
		reverse(path.begin(),path.end());
		return path.size()==np/2+1;
	}
};

UndirectedEulerPath<101000> uep;

void solve() {
	int i,j,k,l,r,x,y; string s;
	cprime();
	
	cin>>T;
	while(T--) {
		cin>>N;
		x=1;
		while(F(x)<N) x++;
		uep.init(x);
		if(x%2==1) {
			FOR(i,x) FOR(j,i+1) uep.add_path(i,j);
		}
		else {
			FOR(i,x) {
				uep.add_path(i,i);
				for(j=i+1;j<x;j++) {
					if(i%2==1&&j==i+1) continue;
					uep.add_path(i,j);
				}
			}
		}
		uep.GetPath();
		FOR(i,N) cout<<prime[uep.path[i]]<<" ";
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
