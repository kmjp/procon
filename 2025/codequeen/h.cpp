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

UndirectedEulerPath<101*101> uep;
int H,W;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	H++,W++;
	uep.init(H*W);
	FOR(y,H) FOR(x,W) {
		if(x+1<W) uep.add_path(y*W+x,y*W+x+1);
		if(y+1<H) uep.add_path(y*W+x,(y+1)*W+x);
	}
	vector<int> cand;
	for(x=1;x<W-1;x++) cand.push_back(x);
	for(y=1;y<H-1;y++) cand.push_back(y*W+(W-1));
	for(x=W-2;x>=1;x--) cand.push_back((H-1)*W+x);
	for(y=H-2;y>=1;y--) cand.push_back(y*W);
	FOR(i,cand.size()/2) uep.add_path(cand[i*2],cand[i*2+1]);
	uep.GetPath(0);
	
	string S;
	FOR(i,uep.path.size()-1) {
		int cy=uep.path[i]/W;
		int cx=uep.path[i]%W;
		int ty=uep.path[i+1]/W;
		int tx=uep.path[i+1]%W;
		if(cy<ty) S+="D";
		if(cy>ty) S+="U";
		if(cx<tx) S+="R";
		if(cx>tx) S+="L";
	}
	cout<<S<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
