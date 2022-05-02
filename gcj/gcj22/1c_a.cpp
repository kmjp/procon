#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;
typedef signed long long ll;

#undef _P
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
string S[101];

template<int MV> class DirectedEulerPath {
public:
	int NV;
	vector<int> path;
	vector<vector<int>> paths;
	vector<int> E[MV];
	vector<int> deg;
	void add_path(int x,int y) { E[x].push_back(y);}
	
	void init(int NV){
		this->NV=NV;
		for(int i=0;i<NV;i++) E[i].clear();
		path.clear();
	}
	void dfs(int cur) {
		while(E[cur].size()) {
			int e=E[cur].back();
			deg[cur]--;
			deg[e]++;
			E[cur].pop_back();
			dfs(e);
		}
		path.push_back(cur);
	}
	
	bool GetPath() {
		assert(NV);
		int te=0,i,j;
		deg.resize(NV);
		FOR(i,NV) {
			te += E[i].size();
			deg[i]+=E[i].size();
			FORR(e,E[i]) deg[e]--;
		}
		paths.clear();
		FOR(j,NV) {
			FOR(i,NV) {
				if(deg[i]==1) {
					path.clear();
					dfs(i);
					paths.push_back(path);
				}
			}
		}
		FOR(i,NV) if(deg[i]==0) {
			path.clear();
			dfs(i);
			paths.push_back(path);
		}
		
		FOR(i,NV) if(E[i].size()) return 0;
		return 1;
	}
};

void solve(int _loop) {
	int f,i,j,k,l,x,y;

	DirectedEulerPath<26> dep;
	vector<int> C[26][26];
	dep.init(26);
	cin>>N;
	FOR(i,N) {
		cin>>S[i];
		dep.add_path(S[i][0]-'A',S[i].back()-'A');
		C[S[i][0]-'A'][S[i].back()-'A'].push_back(i);
	}
	
	FOR(i,26) {
		int num=0;
		FOR(x,26) if(i!=x) num+=C[i][x].size();
		if(num>1) break;
		num=0;
		FOR(x,26) if(i!=x) num+=C[x][i].size();
		if(num>1) break;
	}
	
	
	if(i!=26||dep.GetPath()==0) {
		cout<<"Case #"<<_loop<<": IMPOSSIBLE"<<endl;
		return;
	}
	string T;
	FORR(path,dep.paths) {
		reverse(ALL(path));
		FOR(x,path.size()-1) {
			y=C[path[x]][path[x+1]].back();
			C[path[x]][path[x+1]].pop_back();
			T+=S[y];
		}
	}
	int mask=0,pre=-1;
	FORR(c,T) {
		if(c==pre) continue;
		if(mask&(1<<(c-'A'))) {
			mask=-1;
			break;
		}
		mask |= (1<<(c-'A'));
		pre=c;
	}
	if(mask!=-1) {
		cout<<"Case #"<<_loop<<": "<<T<<endl;
		return;
	}
	
	
	cout<<"Case #"<<_loop<<": IMPOSSIBLE"<<endl;
	//_P("Case #%d:\n",_loop);
}

void init() {
}

int main(int argc,char** argv){
	int loop,loops;
	long long span;
	char tmpline[1000];
	struct timeval start,end,ts;
	
	if(argc>1) freopen(argv[1], "r", stdin);
	gettimeofday(&ts,NULL);
	cin>>loops;
	init();
	
	for(loop=1;loop<=loops;loop++) {
		gettimeofday(&start,NULL); solve(loop); gettimeofday(&end,NULL);
		span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
		fprintf(stderr,"Case : %d                                     time: %lld ms\n",loop,span/1000);
	}
	
	start = ts;
	span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
	fprintf(stderr,"**Total time: %lld ms\n",span/1000);
	
	return 0;
}


