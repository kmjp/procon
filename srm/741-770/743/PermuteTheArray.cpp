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


int from[251];
int dif[251];
int cat[503];
int P[255][2];
vector<pair<int,int>> E[255];
int NG;


class PermuteTheArray {
	public:
	
	int ok(int a,int s,vector<pair<int,int>> C) {
		int dp[555]={};
		dp[0]=1;
		
		if(a<0 || s<0) return 0;
		
		int i;
		FORR(c,C) {
			for(i=250;i>=0;i--) if(dp[i]) {
				dp[i+c.first]=1;
				dp[i+c.second]=1;
			}
		}
		return dp[s];
	}
	
	void dfs(int cur,int base,int val) {
		if(dif[cur]>=0) {
			if(val!=dif[cur]) NG=1;
			return;
		}
		
		dif[cur]=val;
		from[cur]=base;
		P[base][val]++;
		FORR(e,E[cur]) dfs(e.first,base,val^e.second);
	}
	
	vector <int> getPermutation(vector <int> A, vector <int> x, vector <int> y, vector <int> d) {
		int N=A.size();
		
		MINUS(from);
		MINUS(dif);
		MINUS(cat);
		ZERO(P);
		
		
		multiset<int> cand[2];
		vector<int> R;
		FORR(a,A) cand[a%2].insert(a);
		int i,j,k;
		
		FOR(i,N) E[i].clear();
		FOR(i,x.size()) {
			E[x[i]].push_back({y[i],d[i]});
			E[y[i]].push_back({x[i],d[i]});
		}
		
		NG=0;
		FOR(i,N) if(from[i]<0) dfs(i,i,0);
		if(NG) return R;
		
		int lef[2]={(int)cand[0].size(),(int)cand[1].size()};
		FOR(i,N) {
			if(cat[i]==-1) {
				vector<pair<int,int>> C;
				
				FOR(j,N) if(i!=j && cat[j]==-1 && P[j][0]>0) C.push_back({P[j][0],P[j][1]});
				
				if(lef[1]==0 || (lef[0] && *cand[0].begin()<*cand[1].begin())) {
					if(ok(lef[0]-P[i][0],lef[1]-P[i][1],C)) {
						cat[i]=0;
					}
					else if(ok(lef[0]-P[i][1],lef[1]-P[i][0],C)) {
						cat[i]=1;
					}
				}
				else {
					if(ok(lef[0]-P[i][1],lef[1]-P[i][0],C)) {
						cat[i]=1;
					}
					else if(ok(lef[0]-P[i][0],lef[1]-P[i][1],C)) {
						cat[i]=0;
					}
				}
				
				if(cat[i]==-1) return vector<int>();
				
				lef[cat[i]]-=P[i][0];
				lef[cat[i]^1]-=P[i][1];
				
				FOR(j,N) {
					if(cat[j]==-1 && from[j]==i) cat[j]=cat[i]^dif[j];
				}
			}
			
			R.push_back(*cand[cat[i]].begin());
			cand[cat[i]].erase(cand[cat[i]].begin());
		}
		
		return R;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {1, 3, 5, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1, 3, 2, 5 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(0, Arg4, getPermutation(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {1, 3, 5, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 0, 1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 3, 3, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 0, 1, 1, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = { }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(1, Arg4, getPermutation(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {1, 3, 2, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 0, 1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 3, 3, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 0, 1, 1, 1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1, 3, 5, 2 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(2, Arg4, getPermutation(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {1, 2, 3, 4, 5, 6, 7, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 1, 5, 6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 2, 6, 7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 0, 0, 0, 1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1, 3, 5, 2, 4, 6, 8, 7 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(3, Arg4, getPermutation(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {20, 546, 23, 20, 4, 573, 1, 3, 665, 32, 329, 54, 23, 9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1, 3, 4, 9, 20, 20, 23, 23, 32, 54, 329, 546, 573, 665 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(4, Arg4, getPermutation(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  PermuteTheArray ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

