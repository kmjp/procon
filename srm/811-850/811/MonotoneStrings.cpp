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

ll from[404][3];
ll to[404][3];
const ll mo=1000000007;

class MonotoneStrings {
	public:
	int count(int S, string pattern) {
		string T=pattern;
		int i,N=pattern.size(),j,x;
		FOR(i,N) {
			if(pattern[i]=='?') continue;
			if(pattern[i]=='+') continue;
			if(pattern[i]=='-') continue;
			FOR(j,i) if(pattern[j]==pattern[i]) break;
			if(j==i) continue;
			for(x=j+1;x<i;x++) {
				T[x]=T[i];
				if(pattern[x]=='?') continue;
				if(pattern[x]=='+') continue;
				if(pattern[x]=='-') continue;
				if(pattern[x]!=pattern[i]) return 0;
			}
		}
		
		vector<int> C;
		string W;
		int lef=S;
		FORR(c,T) {
			if(c=='?'||c=='+'||c=='-') {
				W+=c;
			}
			else {
				if(W.size()&&W.back()==c) continue;
				C.push_back(W.size());
				W+=c;
				lef--;
			}
		}
		
		ZERO(from);
		from[lef][1]=1;
		FOR(j,W.size()) {
			int num=0;
			if(W[j]=='?') num=1;
			if(W[j]=='-') num=10;
			if(W[j]=='+') num=100;
			if(num==0) {
				FOR(x,S+1) {
					from[x][0]=(from[x][0]+from[x][1]+from[x][2])%mo;
					from[x][1]=from[x][2]=0;
				}
			}
			else {
				if(j==0) {
					ZERO(from);
					if(lef) from[lef-1][1]=lef;
					from[lef][2]=1;
					num--;
				}
				while(num--) {
					FOR(i,S+1) {
						// 1->2
						from[i][2]+=from[i][1];
						if(from[i][2]>=mo) from[i][2]-=mo;
						if(i) {
							// 0->1
							// 1->1
							(from[i-1][1]+=i*(from[i][0]+from[i][1]))%=mo;
						}
						// 0->2
						from[i][2]+=from[i][0];
						if(from[i][2]>=mo) from[i][2]-=mo;
						
						//cout<<num<<" "<<i<<" "<<from[i][0]<<" "<<from[i][1]<<" "<<from[i][2]<<endl;
					}
				}
			}
			
			
			
		}
		
		ll ret=0;
		FOR(i,S+1) ret+=from[i][0]+from[i][1];
		
		return ret%mo;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 26; string Arg1 = "te?th"; int Arg2 = 0; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 1; string Arg1 = "++++++++++"; int Arg2 = 1; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; string Arg1 = "++++++++++++++++++++"; int Arg2 = 952039775; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 370; string Arg1 = "?4?"; int Arg2 = 136531; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 30; string Arg1 = "ll??as"; int Arg2 = 786; verify_case(4, Arg2, count(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MonotoneStrings ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

