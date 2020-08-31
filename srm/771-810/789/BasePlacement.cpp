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

ll from[4063][70];
ll to[4063][70];
map<int,int> T;
const ll mo=1000000007;
class BasePlacement {
	public:
	int count(int R, int C, int B) {
		if(C>R) swap(R,C);
		
		vector<int> cand;
		vector<int> state;
		int i;
		int mask;
		FOR(mask,1<<C) {
			if(mask&(mask<<1)) continue;
			if(mask&(mask<<2)) continue;
			cand.push_back(mask);
		}
		FORR(a,cand) FORR(b,cand) {
			if(a&b) continue;
			if((a<<1)&b) continue;
			if(a&(b<<1)) continue;
			int i;
			int mask2=0;
			int c=1;
			FOR(i,C) {
				if(b&(1<<i)) {
					mask2+=2*c;
				}
				else {
					int num=0;
					if(b&(2<<i)) num++;
					if(i&&(b&(1<<(i-1)))) num++;
					if(a&(1<<i)) num++;
					assert(num<=1);
					mask2+=num*c;
				}
				c*=3;
			}
			state.push_back(mask2);
		}
		
		cout<<cand.size()<<endl;
		cout<<state.size()<<endl;
		sort(ALL(state));
		state.erase(unique(ALL(state)),state.end());
		
		vector<vector<pair<int,int>>> nex;
		nex.resize(state.size());
		int j;
		T.clear();
		FOR(j,state.size()) T[state[j]]=j;
		FOR(j,state.size()) {
			int s=state[j];
			FORR(c,cand) {
				int p=1;
				int t=0,add=0;
				FOR(i,C) {
					int cur=s/p%3;
					
					if(cur==2) {
						if(c&(1<<i)) break;
						if(c&(2<<i)) break;
						if(i&&(c&(1<<(i-1)))) break;
						add+=p;
					}
					else if(cur==1) {
						if(c&(1<<i)) break;
						int num=0;
						if(c&(2<<i)) num++;
						if(i&&(c&(1<<(i-1)))) num++;
						add+=p*num;
					}
					else {
						if(c&(1<<i)) {
							add+=2*p;
							t++;
						}
						else {
							int num=0;
							if(c&(2<<i)) num++;
							if(i&&(c&(1<<(i-1)))) num++;
							add+=p*num;
						}
					}
					p=p*3;
				}
				
				if(i==C) {
					nex[j].push_back({T[add],t});
				}
			}
		}
		
		ZERO(from);
		from[T[0]][0]=1;
		int x,y;
		FOR(y,R) {
			FOR(i,state.size()) FOR(x,R*C/3+3) to[i][x]=0;
			FOR(i,state.size()) FOR(x,R*C/3+3) if(from[i][x]) {
				FORR(n,nex[i]) {
					(to[n.first][x+n.second]+=from[i][x])%=mo;
				}
			}
			swap(from,to);
		}
		
		ll ret=0;
		FOR(i,state.size()) for(j=B;j<=69;j++) ret+=from[i][j];
		return ret%mo;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 1; int Arg3 = 8; verify_case(0, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 8; int Arg1 = 10; int Arg2 = 2; int Arg3 = 744999783; verify_case(1, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 47; int Arg3 = 0; verify_case(2, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_3_() { int Arg0 = 2; int Arg1 = 95; int Arg2 = 48; int Arg3 = 2; verify_case(3, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 8; int Arg1 = 1; int Arg2 = 1; int Arg3 = 2; verify_case(3, Arg3, count(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  BasePlacement ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

