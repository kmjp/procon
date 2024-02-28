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

template<int MV> class DirectedEulerPath {
public:
	int NV;
	vector<int> path;
	vector<int> E[MV];
	void add_path(int x,int y) { E[x].push_back(y);}
	
	void init(int NV){
		this->NV=NV;
		for(int i=0;i<NV;i++) E[i].clear();
		path.clear();
	}
	void dfs(int cur) {
		while(E[cur].size()) {
			int e=E[cur].back();
			E[cur].pop_back();
			dfs(e);
		}
		path.push_back(cur);
	}
	
	bool GetPath() {
		assert(NV);
		int te=0,i;
		vector<int> deg(NV);
		FOR(i,NV) {
			te += E[i].size();
			deg[i]+=E[i].size();
			FORR(e,E[i]) deg[e]--;
		}
		int d0=0,s=0;
		FOR(i,NV) {
			if(deg[i]>1 || deg[i]<-1) return false;
			if(deg[i]==0) d0++;
			if(deg[i]==1) s=i;
		}
		if(d0!=NV && d0+2!=NV) return false;
		dfs(s);
		reverse(path.begin(),path.end());
		return path.size()==te+1;
	}
};

class MergingNumbers {
	public:
	vector<int> Vs;
	DirectedEulerPath<606> dep;
	int ok(vector<pair<int,int>>& V) {
		dep.init(Vs.size());
		FORR2(a,b,V) dep.add_path(a,b);
		return dep.GetPath();
		
	}
	
	
	
	int solve(vector <int> numbers) {
		int i;
		if(numbers.size()==1) return 0;
		vector<pair<int,int>> V;
		set<int> A,B;
		Vs.clear();
		FORR(a,numbers) {
			if(a<100) return -1;
			int y=a%1000;
			int x=a;
			while(x>=1000) x/=10;
			V.push_back({x,y});
			Vs.push_back(x);
			Vs.push_back(y);
		}
		sort(ALL(Vs));
		Vs.erase(unique(ALL(Vs)),Vs.end());
		FORR2(x,y,V) {
			x=lower_bound(ALL(Vs),x)-Vs.begin();
			y=lower_bound(ALL(Vs),y)-Vs.begin();
			A.insert(x);
			if(Vs[y]>=100) B.insert(y);
		}
		
		if(ok(V)) return 0;
		FORR(a,A) FORR(b,B) {
			V.push_back({b,a});
			if(ok(V)) return Vs[b]*1000+Vs[a];
			V.pop_back();
		}
		return -1;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 1234567 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, solve(Arg0)); }
	void test_case_1() { int Arr0[] = { 12345, 78901, 3456789 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, solve(Arg0)); }
	void test_case_2() { int Arr0[] = { 22222, 22222, 22222, 22222, 22222, 22222, 22222 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, solve(Arg0)); }
	void test_case_3() { int Arr0[] = {1, 2, 3, 11, 22, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(3, Arg1, solve(Arg0)); }
	void test_case_4() { int Arr0[] = {1234, 3456}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2345; verify_case(4, Arg1, solve(Arg0)); }
	void test_case_5() { int Arr0[] = {1234, 5678, 3456}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(5, Arg1, solve(Arg0)); }
	void test_case_6() { int Arr0[] = {123123123, 1234, 1234, 1234, 1234, 1234, 234890123, 234890123}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(6, Arg1, solve(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MergingNumbers ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

