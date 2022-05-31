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


string OK[]={
	".-|",
	"-...|",
	"-.-.|",
	"-..|",
	".|",
	"..-.|",
	"--.|",
	"....|",
	"..|",
	".---|",
	"-.-|",
	".-..|",
	"--|",
	"-.|",
	"---|",
	".--.|",
	"--.-|",
	".-.|",
	"...|",
	"-|",
	"..-|",
	"...-|",
	".--|",
	"-..-|",
	"-.--|",
	"--..|",
};

string from[5050][2];
int fromid[5050][2];
int cost[5050][2];



class MorseCodeCorrector {
	public:
	string fix(string message) {
		vector<string> cand[8];
		int i;
		message+="|";
		FOR(i,26) {
			cand[OK[i].size()].push_back(OK[i]);
		}
		int N=message.size();
		MINUS(fromid);
		FOR(i,N+1) cost[i][0]=cost[i][1]=1<<20;
		cost[0][0]=0;
		int j,k,id;
		
		FOR(i,N) FOR(id,2) if(cost[i][id]<1<<20) {
			
			if(id==1) {
				int co=cost[i][id]+(message[i]!='|');
				if(cost[i+1][0]>co) {
					cost[i+1][0]=co;
					from[i+1][0]="|";
					fromid[i+1][0]=1;
				}
			}
			
			for(j=1;i+j<=N&&j<=7;j++) {
				
				FORR(s,cand[j]) {
					int dif=0;
					FOR(k,j) dif+=message[i+k]!=s[k];
					if(cost[i+j][1]>cost[i][id]+dif) {
						cost[i+j][1]=cost[i][id]+dif;
						from[i+j][1]=s;
						fromid[i+j][1]=id;
					}
				}
			}
		}
		
		string ret;
		int cur=N;
		id=1;
		while(cur) {
			ret=from[cur][id]+ret;
			int ncur=cur-from[cur][id].size();
			int nid=fromid[cur][id];
			cur=ncur;
			id=nid;
		}
		ret.pop_back();
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "-..."; string Arg1 = "-..."; verify_case(0, Arg1, fix(Arg0)); }
	void test_case_1() { string Arg0 = "---."; string Arg1 = "-.-."; verify_case(1, Arg1, fix(Arg0)); }
	void test_case_2() { string Arg0 = "-.-.-"; string Arg1 = "-.|.-"; verify_case(2, Arg1, fix(Arg0)); }
	void test_case_3() { string Arg0 = ".||-"; string Arg1 = ".||-"; verify_case(3, Arg1, fix(Arg0)); }
	void test_case_4() { string Arg0 = "-|---|.--.||-.-.|---|-..|.|.-."; string Arg1 = "-|---|.--.||-.-.|---|-..|.|.-."; verify_case(4, Arg1, fix(Arg0)); }
	void test_case_5() { string Arg0 = "....||||||-----|||||."; string Arg1 = "....||.|.|--|--||.||."; verify_case(5, Arg1, fix(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MorseCodeCorrector ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

