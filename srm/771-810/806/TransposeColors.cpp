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

int A[44][44];

class TransposeColors {
	public:
	vector <int> move(int N) {
		DirectedEulerPath<80> ep;
		if(N==1) return {};
		
		int x,y;
		FOR(x,N) FOR(y,N) A[y][x]=y;
		
		ep.init(N);
		FOR(y,N) FOR(x,N) if(x!=y) {
			ep.add_path(x,y);
		}
		assert(ep.GetPath());
		vector<int> V=ep.path;
		vector<int> ret;
		
		
		int i;
		int B=A[V[0]][V[1]];
		
		ret.push_back(V[0]*N+V[1]);
		
		for(i=1;i<V.size()-1;i++) {
			ret.push_back(V[i]*N+V[i+1]);
			A[V[i-1]][V[i]]=A[V[i]][V[i+1]];
		}
		ret.push_back(N*N);
		A[V[V.size()-2]][V[V.size()-1]]=B;
		
		FOR(y,N) {
			FOR(x,N) cout<<A[y][x]<<" ";
			cout<<endl;
		}
			
		
		
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 1; int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, move(Arg0)); }
	void test_case_1() { int Arg0 = 2; int Arr1[] = {2, 1, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, move(Arg0)); }
	void test_case_2() { int Arg0 = 40; int Arr1[] = {1, 5, 6, 2, 7, 3, 9 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, move(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TransposeColors ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

