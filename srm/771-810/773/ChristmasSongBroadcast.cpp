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

int D[50][50];
ll C[51];
const ll mo=1000000007;
template<int um> class UF {
	public:
	vector<int> par,rank;
	UF() {rank=vector<int>(um,0); for(int i=0;i<um;i++) par.push_back(i);}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};
class ChristmasSongBroadcast {
	public:
	int minimizeCost(int T, vector <int> A, vector <int> B, vector <string> directCost) {
		UF<51> uf;
		
		vector<vector<int>> cand;
		int N=directCost.size();
		int y,x,i;
		FOR(y,N) FOR(x,y) {
			cand.push_back({directCost[y][x],y,x});
		}
		FOR(i,N) {
			ll cur=0;
			ll S=B[i];
			C[i]=B[i];
			while(cur<T) {
				C[i]=min(C[i],S);
				ll add=min(T-cur,(mo-S+A[i]-1)/A[i]);
				S+=add*A[i];
				S%=mo;
				cur+=add;
			}
			cand.push_back({(int)C[i],i,N});
		}
		sort(ALL(cand));
		ll ret=0;
		FORR(c,cand) {
			if(uf[c[1]]!=uf[c[2]]) {
				ret+=c[0];
				uf(c[1],c[2]);
			}
		}
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1000000007; int Arr1[] = {1, 10, 100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {7, 7, 7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"-AA",
 "A-A",
 "AA-"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 0; verify_case(0, Arg4, minimizeCost(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 1; int Arr1[] = {1, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1600, 1500, 1700}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"-01",
 "0-A",
 "1A-"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1597; verify_case(1, Arg4, minimizeCost(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 2; int Arr1[] = {100, 100, 100, 100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 35, 999999910, 123456789}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"-01z",
 "0-Az",
 "1A-z",
 "zzz-"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 160; verify_case(2, Arg4, minimizeCost(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 1; int Arr1[] = {47}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1000000006}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"-"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1000000006; verify_case(3, Arg4, minimizeCost(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ChristmasSongBroadcast ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

