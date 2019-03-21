#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
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
	
	vector<int> GetPath(int root) {
		dfs(root);
		reverse(path.begin(),path.end());
		return path;
	}
};

class HalfGraph {
	public:
	
	vector <string> compute(vector <string> a) {
		UndirectedEulerPath<50> uep;
		int N=a.size();
		int i,j;
		int sum=0;
		FOR(i,N) {
			int num=0;
			FOR(j,N) if(a[i][j]=='1') {
				num++;
				if(i<j) uep.add_path(i,j);
			}
			if(num%2) return {};
			sum+=num;
		}
		if(sum%4) return {};
		
		FOR(i,N) if(uep.E[i].size()) {
			auto v=uep.GetPath(i);
			FOR(i,v.size()-1) if(i%2) a[v[i]][v[i+1]]=a[v[i+1]][v[i]]='0';
		}
		
		return a;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"000",
 "000",
 "000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"000", "000", "000" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, compute(Arg0)); }
	void test_case_1() { string Arr0[] = {"01111",
 "10111",
 "11011",
 "11101",
 "11110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"00011", "00110", "01001", "11000", "10100" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, compute(Arg0)); }
	void test_case_2() { string Arr0[] = {"010",
 "101",
 "010"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, compute(Arg0)); }
	void test_case_3() { string Arr0[] = {"01111",
 "10100",
 "11000",
 "10001",
 "10010"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"00011", "00100", "01000", "10000", "10000" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, compute(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  HalfGraph ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

