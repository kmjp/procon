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
int A[1<<10][1<<10];

template<int MV> class UndirectedEulerPath {
public:
	int NV;
	vector<int> path;
	multiset<int> E[MV];
	void add_path(int x,int y) { E[x].insert(y); E[y].insert(x); }

	
	void init(int NV){
		this->NV=NV;
		for(int i=0;i<NV;i++) E[i].clear();
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
		assert(NV);
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
				FOR(i,NV) if(E[i].size()) root=i;
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
UndirectedEulerPath<1<<10> uep;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	if(N==1) {
		cout<<"No"<<endl;
		return;
	}
	uep.init(1<<N);
	FOR(x,1<<N) FOR(y,x) if(__builtin_popcount(x^y)==1) uep.add_path(x,y);
	if(uep.GetPath()) {
		FOR(i,uep.path.size()-1) {
			x=uep.path[i];
			y=uep.path[i+1];
			A[x][y]=1;
			A[y][x]=-1;
		}
		cout<<"Yes"<<endl;
		FOR(x,1<<N) {
			FOR(y,1<<N) {
				cout<<A[x][y]<<" ";
			}
			cout<<endl;
		}
		return;
	}
	N--;
	uep.init(1<<N);
	FOR(x,1<<N) FOR(y,x) if(__builtin_popcount(x^y)==1) uep.add_path(x,y);
	uep.GetPath();
	FOR(i,uep.path.size()-1) {
		x=uep.path[i];
		y=uep.path[i+1];
		A[x][y]=1;
		A[y][x]=-1;
		x^=1<<N;
		y^=1<<N;
		A[x][y]=-1;
		A[y][x]=1;
	}
	for(i=0;i<1<<N;i+=2) {
		x=i;
		y=i+1;
		if(A[x][y]==1) {
			A[x][y]++;
			A[y][x]--;
			A[x+(1<<N)][y+(1<<N)]--;
			A[y+(1<<N)][x+(1<<N)]++;
			
			A[x][(1<<N)+x]--;
			A[(1<<N)+x][x]++;
			A[y][(1<<N)+y]++;
			A[(1<<N)+y][y]--;
		}
		else {
			A[x][y]--;
			A[y][x]++;
			A[x+(1<<N)][y+(1<<N)]++;
			A[y+(1<<N)][x+(1<<N)]--;
			A[x][(1<<N)+x]++;
			A[(1<<N)+x][x]--;
			A[y][(1<<N)+y]--;
			A[(1<<N)+y][y]++;
		}
	}
	N++;
		cout<<"Yes"<<endl;
		FOR(x,1<<N) {
			FOR(y,1<<N) {
				cout<<A[x][y]<<" ";
			}
			cout<<endl;
		}
		
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
