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

class LCMGCD {
	public:
	
	pair<int,int> sp(int v) {
		pair<int,int> a={0,0};
		while(v%2==0) a.first++,v/=2;
		while(v%3==0) a.second++,v/=3;
		return a;
	}
	string isPossible(vector <int> X, int t) {
		string ret[]={"Possible","Impossible"};
		int N=X.size();
		pair<int,int> T=sp(t);
		vector<pair<int,int>> V;
		
		FORR(r,X) V.push_back(sp(r));
		int i,j,x,y;
		FOR(i,N) if(V[i]==T) {
			if(N==1) return ret[0];
			int L=100,R=-1,D=100,U=-1;
			FOR(j,N) if(i!=j) {
				L=min(L,V[j].first);
				R=max(R,V[j].first);
				D=min(D,V[j].second);
				U=max(U,V[j].second);
			}
			if(L<=T.first&&D<=T.second) return ret[0];
			if(T.first<=R&&T.second<=U) return ret[0];
		}
		FOR(i,N) FOR(j,N) if(i!=j && T.first==V[i].first && T.second==V[j].second) {
			if(((V[i].first<V[j].first)&&(V[i].second>V[j].second)) || ((V[i].first>V[j].first)&&(V[i].second<V[j].second))) {
				return ret[0];
			}
			else if(V[i].first<V[j].first && V[i].second<V[j].second) {
				FOR(x,N) if(i!=x && j!=x && V[x].first<=V[i].first && V[x].second>=V[j].second) return ret[0];
			}
			else if(V[i].first>V[j].first && V[i].second>V[j].second) {
				FOR(x,N) if(i!=x && j!=x && V[x].first>=V[i].first && V[x].second<=V[j].second) return ret[0];
			}
		}
		return ret[1];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; string Arg2 = "Possible"; verify_case(0, Arg2, isPossible(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {4,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; string Arg2 = "Impossible"; verify_case(1, Arg2, isPossible(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {6,12,24,18,36,72,54,108,216}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 36; string Arg2 = "Possible"; verify_case(2, Arg2, isPossible(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {6,27,81,729}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; string Arg2 = "Impossible"; verify_case(3, Arg2, isPossible(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; string Arg2 = "Possible"; verify_case(4, Arg2, isPossible(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {72,16,16,16,16,16,27,27,27,27,27,27,27,27,27}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 72; string Arg2 = "Possible"; verify_case(5, Arg2, isPossible(Arg0, Arg1)); }
	void test_case_6() { int Arr0[] = {100663296, 544195584, 229582512, 59049}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 60466176; string Arg2 = "Possible"; verify_case(6, Arg2, isPossible(Arg0, Arg1)); }
//	void test_case_7() { int Arr0[] = {2,4,8,16,32,64}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 256; string Arg2 = "Impossible"; verify_case(7, Arg2, isPossible(Arg0, Arg1)); }
	void test_case_7() { int Arr0[] = {1,2,4,12,36,8,24,48,16}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; string Arg2 = "Impossible"; verify_case(7, Arg2, isPossible(Arg0, Arg1)); }
	
// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  LCMGCD ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
