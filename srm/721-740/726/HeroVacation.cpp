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


class HeroVacation {
	public:
	int N;
	vector<int> E[51];
	vector<int> D[51][51];
	vector<vector<int>> DS[51];
	
	void dfs(int cur,int pre) {
		if(D[cur][pre].size()) return;
		D[cur][pre].push_back(cur);
		FORR(e,E[cur]) if(e!=pre) {
			dfs(e,cur);
			FORR(v,D[e][cur]) D[cur][pre].push_back(v);
		}
	}
	
	vector <int> getPermutation(vector <int> p) {
		int i,j,x,y;
		N=p.size()+1;
		FOR(i,N) E[i].clear();
		FOR(x,N) FOR(y,N) D[x][y].clear();
		FOR(i,N-1) {
			E[p[i]].push_back(i+1);
			E[i+1].push_back(p[i]);
		}
		FOR(i,N-1) dfs(p[i],i+1),dfs(i+1,p[i]);
		
		int mi=1010,id=-1;
		FOR(i,N) {
			int ma=0;
			DS[i].clear();
			FORR(e,E[i]) {
				ma=max(ma,(int)D[e][i].size());
				DS[i].push_back(D[e][i]);
			}
			if(ma<=mi) mi=ma, id=i;
		}
		
		vector<int> R;
		R.push_back(id);
		vector<vector<int>> Ds=DS[id];
		int pre=-1;
		FOR(i,N-1) {
			int ma=0,id=-1;
			FOR(j,Ds.size()) {
				if(Ds[j].size()>ma && pre!=j) ma=Ds[j].size(), id=j;
			}
			pre=id;
			R.push_back(Ds[id].back());
			Ds[id].pop_back();
		}
		
		return R;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {0,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 3, 0, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getPermutation(Arg0)); }
	void test_case_1() { int Arr0[] = {0,1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 0, 4, 1, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getPermutation(Arg0)); }
	void test_case_2() { int Arr0[] = {0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 2, 3, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getPermutation(Arg0)); }
	void test_case_3() { int Arr0[] = {0,1,0,2,0,2,2,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 8, 7, 5, 6, 3, 4, 0, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getPermutation(Arg0)); }
	void test_case_4() { int Arr0[] = {0,0,0,1,1,1,2,2,2,3,3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 6, 9, 12, 5, 8, 11, 4, 7, 10, 1, 2, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, getPermutation(Arg0)); }
	void test_case_5() { int Arr0[] = {0,1,2,0,0,5,6,6,8,9,10,11,11,13,10,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8, 7, 16, 5, 15, 4, 14, 3, 13, 2, 12, 1, 11, 0, 10, 6, 9 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, getPermutation(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  HeroVacation ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

