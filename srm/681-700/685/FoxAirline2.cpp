#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

template<int um> class UF {
	public:
	vector<int> par,rank,cnt;
	UF() {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit() {int i; FOR(i,um) rank[i]=0,cnt[i]=1,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};

int A[51],B[51];

class FoxAirline2 {
	public:
	int N,M;
	int ok;
	
	void dfs(int cur,UF<10>& uf1,UF<10>& uf2) {
		if(cur==M) {
			if(uf1.count(0)==N && uf2.count(0)==N) ok=1;
			return;
		}
		
		if(uf1[A[cur]]!=uf1[B[cur]]) {
			UF<10> ufa=uf1;
			ufa(A[cur],B[cur]);
			dfs(cur+1,ufa,uf2);
		}
		if(uf2[A[cur]]!=uf2[B[cur]]) {
			UF<10> ufa=uf2;
			ufa(A[cur],B[cur]);
			dfs(cur+1,uf1,ufa);
		}
		if(uf1[A[cur]]==uf1[B[cur]] && uf2[A[cur]]==uf2[B[cur]]) dfs(cur+1,uf1,uf2);
	}
	
	string isPossible(int n, vector <int> a, vector <int> b) {
		int i;
		N=n;
		M=a.size();
		FOR(i,M) A[i]=a[i],B[i]=b[i];
		UF<10> uf1,uf2;
		ok=0;
		dfs(0,uf1,uf2);
		if(ok) return "Possible";
		else return "Impossible";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arr1[] = {0,0,0,1,1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3,2,3,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Possible"; verify_case(0, Arg3, isPossible(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 6; int Arr1[] = {0,0,0,0,1,1,1,2,2,3,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3,4,2,3,4,3,4,4,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Impossible"; verify_case(1, Arg3, isPossible(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 5; int Arr1[] = {0,0,0,1,1,2,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,4,2,4,3,4,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Possible"; verify_case(2, Arg3, isPossible(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 2; int Arr1[] = {0,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,0,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Possible"; verify_case(3, Arg3, isPossible(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 10; int Arr1[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 7, 7, 8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 2, 3, 4, 5, 6, 7, 8, 9, 3, 4, 5, 6, 7, 8, 9, 4, 5, 6, 7, 8, 9, 5, 6, 7, 8, 9, 6, 7, 8, 9, 7, 8, 9, 8, 9, 9}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Possible"; verify_case(4, Arg3, isPossible(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 2; int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Impossible"; verify_case(5, Arg3, isPossible(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  FoxAirline2 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
