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

map<ll,pair<ll,ll>> A,B;
ll p3[25];
vector<int> V;
class ThreeWaySplit {
	public:
	void dfs1(int cur,ll mask,ll sa,ll sb) {
		if(cur==12) {
			ll d=sa-sb;
			if(A.count(d)==0||sa>A[d].first) {
				A[d]={sa,mask};
			}
			return;
		}
		dfs1(cur+1,mask+p3[cur]*0,sa+V[cur],sb);
		dfs1(cur+1,mask+p3[cur]*1,sa,sb+V[cur]);
		dfs1(cur+1,mask+p3[cur]*2,sa,sb);
		
	}
	void dfs2(int cur,ll mask,ll sa,ll sb) {
		if(cur==24) {
			ll d=sa-sb;
			if(B.count(d)==0||sa>B[d].first) {
				B[d]={sa,mask};
			}
			return;
		}
		dfs2(cur+1,mask+p3[cur]*0,sa+V[cur],sb);
		dfs2(cur+1,mask+p3[cur]*1,sa,sb+V[cur]);
		dfs2(cur+1,mask+p3[cur]*2,sa,sb);
		
		
	}
	
	string split(vector <int> L) {
		int O=L.size();
		while(L.size()<24) L.push_back(0);
		V=L;
		
		int i;
		p3[0]=1;
		FOR(i,24) p3[i+1]=p3[i]*3;
		
		A.clear();
		B.clear();
		dfs1(0,0,0,0);
		dfs2(12,0,0,0);
		ll ma=0;
		ll tm=p3[24]-1;
		FORR(a,A) {
			ll d=a.first;
			ll sa=a.second.first;
			ll mask=a.second.second;
			if(B.count(-d)) {
				sa+=B[-d].first;
				mask+=B[-d].second;
				if(sa>ma) {
					cout<<sa<<endl;
					ma=sa, tm=mask;
				}
			}
		}
		string S;
		FOR(i,24) S+='A'+tm/p3[i]%3;
		S.resize(O);
		return S;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {4, 7, 53}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "CCC"; verify_case(0, Arg1, split(Arg0)); }
	void test_case_1() { int Arr0[] = {1, 1, 1, 4, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "BBBAB"; verify_case(1, Arg1, split(Arg0)); }
	void test_case_2() { int Arr0[] = {47, 47, 47}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "CBA"; verify_case(2, Arg1, split(Arg0)); }
	void test_case_3_() { int Arr0[] = {1, 2, 3, 4, 5, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "CBBABA"; verify_case(3, Arg1, split(Arg0)); }
	void test_case_3() { int Arr0[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388607}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "CBBABA"; verify_case(3, Arg1, split(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ThreeWaySplit ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

