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

ll A[101010],B[101010],C[101010];
template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bit;
const int DI=350;
vector<pair<int,int>> ev[DI];
const ll mo=1000000007;

class Proximity {
	public:
	int count(int N, int Q, int D, int M, int L, int seed) {
		ll state = seed;
		int i;
		FOR(i,N) {
			state = (state * 1103515245 + 12345)%(1LL<<31);
			C[i] = state%M+123456;
		}
		FOR(i,DI) ev[i].clear();
		FOR(i,Q) {
			state = (state * 1103515245 + 12345)%(1LL<<31);
			ll ql = L + (state % (N-L+1));
			state = (state * 1103515245 + 12345)%(1LL<<31);
			A[i] = state % (N-ql+1);
			B[i] = A[i] + ql;
			ev[A[i]/DI].push_back({B[i],i});
		}
		ll ret=0;
		FOR(i,DI) {
			sort(ALL(ev[i]));
			int L=-1,R=-1;
			ll sum=0;
			FORR(e,ev[i]) {
				int cur=e.second;
				if(L==-1) L=R=A[cur];
				while(R<B[cur]) {
					sum+=bit(C[R]+D)-bit(C[R]-D-1);
					bit.add(C[R],1);
					R++;
				}
				while(A[cur]<L) {
					L--;
					sum+=bit(C[L]+D)-bit(C[L]-D-1);
					bit.add(C[L],1);
				}
				while(L<A[cur]) {
					bit.add(C[L],-1);
					sum-=bit(C[L]+D)-bit(C[L]-D-1);
					L++;
				}
				(ret+=sum)%=mo;
			}
			
			while(L<R) {
				bit.add(C[L],-1);
				L++;
			}
			
		}
		
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 5; int Arg2 = 100; int Arg3 = 100; int Arg4 = 1; int Arg5 = 47; int Arg6 = 27; verify_case(0, Arg6, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 5; int Arg2 = 100; int Arg3 = 100; int Arg4 = 1; int Arg5 = 42; int Arg6 = 78; verify_case(1, Arg6, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 5; int Arg2 = 0; int Arg3 = 100; int Arg4 = 1; int Arg5 = 42; int Arg6 = 0; verify_case(2, Arg6, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 5; int Arg2 = 1; int Arg3 = 100; int Arg4 = 1; int Arg5 = 42; int Arg6 = 4; verify_case(3, Arg6, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_4() { int Arg0 = 99997; int Arg1 = 99993; int Arg2 = 0; int Arg3 = 1; int Arg4 = 99997; int Arg5 = 12345; int Arg6 = 999550455; verify_case(4, Arg6, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Proximity ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

