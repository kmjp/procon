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

class VisitN {
	public:
	string visit(int n, int r, int c) {
		vector<int> V;
		int y=0,x=0;
		while(x<29) V.push_back(y*30+x), x++;
		while(y<29) V.push_back(y*30+x), y++;
		V.push_back(29*30+29);
		for(y=29;y>=1;y--) {
			if(y%2==1) for(x=28;x>=0;x--) V.push_back(y*30+x);
			else for(x=0;x<=28;x++) V.push_back(y*30+x);
		}
		FOR(x,900) V.push_back(V[x]);
		
		string S;
		int i=0;
		FOR(i,900) if(V[i]==r*30+c) break;
		while(n>1) {
			if(V[i+1]-V[i]==1) S+="E";
			if(V[i+1]-V[i]==-1) S+="W";
			if(V[i+1]-V[i]==30) S+="S";
			if(V[i+1]-V[i]==-30) S+="N";
			i++;
			n--;
		}
		return S;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 4; int Arg2 = 7; string Arg3 = ""; verify_case(0, Arg3, visit(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 4; int Arg2 = 7; string Arg3 = "N"; verify_case(1, Arg3, visit(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 0; int Arg2 = 17; string Arg3 = "W"; verify_case(2, Arg3, visit(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 1; int Arg2 = 1; string Arg3 = "NWEE"; verify_case(3, Arg3, visit(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 141; int Arg1 = 29; int Arg2 = 29; string Arg3 = "NWSSEENNSSWS"; verify_case(4, Arg3, visit(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  VisitN ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

