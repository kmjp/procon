#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

template<int MV> class UndirectedEulerPath {
public:
	vector<int> path;
	multiset<int> E[MV];
	void add_path(int x,int y) { E[x].insert(y); E[y].insert(x); }
	
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
		FOR(i,MV) {
			np += E[i].size();
			if(E[i].size()%2) odd++, fo=(fo==-1)?i:fo;
		}
		//閉路なら奇数を許容しないようにしておく
		if(odd!=0 && odd!=2) return false;
		if(root==-1) {
			root=odd?fo:0;
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

class ManhattanSnowPlow {
	public:
	string plow(int H, int W) {
		UndirectedEulerPath<50*50> uep;
		
		int y,x;
		FOR(y,H) FOR(x,W-1) uep.add_path(y*W+x,y*W+x+1);
		FOR(y,H-1) FOR(x,W) uep.add_path(y*W+x,y*W+x+W);
		vector<pair<int,int>> cand;
		for(x=1;x+1<W-1;x+=2) {
			cand.push_back({0*W+x,0*W+x+1});
			cand.push_back({(H-1)*W+x,(H-1)*W+x+1});
		}
		for(y=1;y+1<H-1;y+=2) {
			cand.push_back({y*W+0,(y+1)*W+0});
			cand.push_back({y*W+W-1,(y+1)*W+W-1});
		}
		if(H%2==0&&W%2==0) {
			if(cand.size()) cand.pop_back();
		}
		else if(H%2&&W%2) {
			cand.push_back({(H-1)*W+(W-2),(H-1)*W+(W-1)});
			cand.push_back({(H-2)*W+(W-1),(H-1)*W+(W-1)});
		}
		FORR(c,cand) uep.add_path(c.first,c.second);
		
		assert(uep.GetPath());
		string S;
		int i;
		FOR(i,uep.path.size()-1) {
			if(uep.path[i]-uep.path[i+1]==1) S+="E";
			if(uep.path[i]-uep.path[i+1]==-1) S+="W";
			if(uep.path[i]-uep.path[i+1]==W) S+="N";
			if(uep.path[i]-uep.path[i+1]==-W) S+="S";
		}
		return S;
		
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; string Arg2 = "ENWS"; verify_case(0, Arg2, plow(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 3; string Arg2 = "ENWSWNE"; verify_case(1, Arg2, plow(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 4; string Arg2 = "WNNSENWNEEESWNWSESWSEENNSWS"; verify_case(2, Arg2, plow(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ManhattanSnowPlow ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

