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


ll A[202020];

ll C[11*11*11*11*11*11];
ll p10[7],p11[7];

ll ret[7];
static const int N_=10;
static ll C_[N_][N_];

class SimilarNumberPairs {
	public:
	long long count(int N, int S, vector <int> Aprefix, int seed) {
		int i,j;
		FOR(i,Aprefix.size()) A[i]=Aprefix[i];
		ll state = seed;
		for(i=Aprefix.size();i<N;i++) {
		    state = (state * 1103515245 + 12345) %(1LL<<31);
			A[i] = (state % 1000000);
		}
		p10[0]=p11[0]=1;
		FOR(i,6) p10[i+1]=p10[i]*10,p11[i+1]=p11[i]*11;
		
	
		FOR(i,N_) C_[i][0]=C_[i][i]=1;
		for(i=1;i<N_;i++) for(j=1;j<i;j++) C_[i][j]=(C_[i-1][j-1]+C_[i-1][j]);

		ZERO(C);
		FOR(i,N) {
			int mask;
			FOR(mask,1<<6) {
				ll v=0;
				FOR(j,6) {
					if(mask&(1<<j)) v=v*11+10;
					else v=v*11+A[i]/p10[j]%10;
				}
				//cout<<mask<<" "<<A[i]<<" "<<v<<endl;
				C[v]++;
			}
		}
		
		ZERO(ret);
		FOR(i,p11[6]) {
			int match=0;
			FOR(j,6) if(i/p11[j]%11!=10) match++;
			ret[match]+=1LL*C[i]*(C[i]-1)/2;
		}
		for(i=6;i>=0;i--) {
			FOR(j,i) ret[j]-=ret[i]*C_[i][j];
		}
		
		ll sum=0;
		FOR(i,7) {
			cout<<ret[i]<<endl;
			sum+=ret[i];
		}
		assert(sum==1LL*N*(N-1)/2);
		return ret[S];
		
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 2; int Arr2[] = {112233, 114455, 72255}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 47; long long Arg4 = 3LL; verify_case(0, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 7; int Arg1 = 6; int Arr2[] = {42, 42, 42, 42, 42, 42, 42}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 47; long long Arg4 = 21LL; verify_case(1, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 7; int Arg1 = 5; int Arr2[] = {111111, 111112, 111122, 111222, 112222, 122222, 222222}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 47; long long Arg4 = 6LL; verify_case(2, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 7; int Arg1 = 3; int Arr2[] = {111111, 111112, 111122, 111222, 112222, 122222, 222222}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 47; long long Arg4 = 4LL; verify_case(3, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 10; int Arg1 = 1; int Arr2[] = {123456, 234567}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 5678; long long Arg4 = 10LL; verify_case(4, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 3; int Arg1 = 0; int Arr2[] = {123456, 3789, 56789}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; long long Arg4 = 1LL; verify_case(5, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SimilarNumberPairs ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

