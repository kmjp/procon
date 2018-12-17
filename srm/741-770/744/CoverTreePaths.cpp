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

map<ll,ll> M[101010];
vector<int> C[101010];
class CoverTreePaths {
	public:
	long long minimumCost(int n, vector <int> p, vector <int> d, vector <int> c, vector <int> params) {
		int i;
		p.insert(p.begin(),0);
		for(int i=p.size();i<n;i++) {
			p.push_back((params[0]*1LL*p.back()+params[1])%i);
			d.push_back(1+(params[2]*1LL*d.back()+params[3])%params[4]);
			c.push_back(1+(params[5]*1LL*c.back()+params[6])%params[7]);
		}
		FOR(i,n) {
			M[i].clear();
			C[i].clear();
			if(i) {
				d[i]=max(d[i],d[p[i]]);
				C[p[i]].push_back(i);
			}
		}
		for(i=n-1;i>=0;i--) {
			if(i) d[i]-=d[p[i]];
			
			M[i][c[i]]=d[i];
			while(1) {
				int ok=0;
				ll sum=0;
				ll num=1LL<<50;
				FORR(v,C[i]) {
					if(M[v].size()) {
						ok++;
						sum+=M[v].rbegin()->first;
						num=min(num,M[v].rbegin()->second);
					}
				}
				if(ok<=1) break;
				M[i][min((ll)c[i],sum)]+=num;
				FORR(v,C[i]) if(M[v].size()) {
					M[v].rbegin()->second-=num;
					if(M[v].rbegin()->second==0) M[v].erase(M[v].rbegin()->first);
				}
			}
			FORR(v,C[i]) if(M[v].size()) {
				while(M[v].size() && M[v].rbegin()->first>c[i]) {
					M[i][c[i]]+=M[v].rbegin()->second;
					M[v].erase(M[v].rbegin()->first);
				}
				if(M[v].size()>M[i].size()) swap(M[i],M[v]);
				FORR(m,M[v]) M[i][m.first]+=m.second;
				M[v].clear();
			}
		}
		
		ll ret=0;
		FORR(m,M[0]) ret+=m.first*m.second;
		
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arr1[] = {0, 1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 2, 1, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {9, 4, 3, 3}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1, 1, 1, 1, 1, 1, 1, 1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); long long Arg5 = 21LL; verify_case(0, Arg5, minimumCost(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 4; int Arr1[] = {0, 1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 2, 1, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {9, 4, 3, 2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1, 1, 1, 1, 1, 1, 1, 1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); long long Arg5 = 20LL; verify_case(1, Arg5, minimumCost(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 6; int Arr1[] = {0, 0, 0, 0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 2, 2, 7, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2, 4, 5, 6, 1, 1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1, 1, 1, 1, 1, 1, 1, 1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); long long Arg5 = 9LL; verify_case(2, Arg5, minimumCost(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 10; int Arr1[] = {0, 0, 2, 0, 1, 4, 5, 1, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 4, 2, 7, 1, 3, 1, 10, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2, 4, 3, 6, 1, 2, 6, 9, 10, 4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1, 1, 1, 1, 1, 1, 1, 1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); long long Arg5 = 20LL; verify_case(3, Arg5, minimumCost(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 5; int Arr1[] = {0, 1, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 3, 4, 5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {5, 4, 3, 2, 1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1, 1, 1, 1, 1, 1, 1, 1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); long long Arg5 = 15LL; verify_case(4, Arg5, minimumCost(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { int Arg0 = 2; int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {8, 5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {10, 1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1, 1, 1, 1, 1, 1, 1, 1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); long long Arg5 = 80LL; verify_case(5, Arg5, minimumCost(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_6() { int Arg0 = 100; int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {900, 820}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {2, 7, 3, 11, 200, 4, 2, 321}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); long long Arg5 = 58344LL; verify_case(6, Arg5, minimumCost(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  CoverTreePaths ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

