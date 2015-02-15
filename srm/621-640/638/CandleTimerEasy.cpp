#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

set<int> S;
int dist[202][202];
vector<int> E[202];
int dist3[202];

class CandleTimerEasy {
	public:
	int N;
	vector <int> A,B,len;
	
	int maxdist() {
		int i,x,y,j;
		int ma=0;
		
		priority_queue<pair<int,int> > P;
		FOR(i,N) if(dist3[i]==0) P.push(make_pair(0,i));
		
		while(P.size()) {
			pair<int,int> p=P.top();
			P.pop();
			int cur=p.second;
			if(p.first!=-dist3[p.second]) continue;
			FOR(i,E[cur].size()) if(dist3[E[cur][i]]>dist3[cur]+dist[cur][E[cur][i]]) {
				dist3[E[cur][i]] = dist3[cur]+dist[cur][E[cur][i]];
				P.push(make_pair(-dist3[E[cur][i]],E[cur][i]));
			}
		}
		
		FOR(i,N-1) {
			if(max(dist3[A[i]],dist3[B[i]])-min(dist3[A[i]],dist3[B[i]])>=len[i]){
				ma=max(ma,min(dist3[A[i]],dist3[B[i]])+len[i]);
			}
			else {
				ma=max(ma,(dist3[A[i]]+dist3[B[i]]+len[i])/2);
			}
		}
		return ma;
	}
	
	int differentTime(vector <int> A, vector <int> B, vector <int> len) {
		int i,x,y,z,j;
		
		N=A.size();
		FOR(i,N) len[i]*=2;
		
		this->A=A;
		this->B=B;
		this->len=len;
		
		
		S.clear();
		
		FOR(x,N+1) FOR(y,N+1) dist[x][y]=1<<29;
		FOR(i,N+1) E[i].clear();
		FOR(i,N) dist[A[i]][B[i]]=dist[B[i]][A[i]]=len[i];
		FOR(i,N) E[A[i]].push_back(B[i]),E[B[i]].push_back(A[i]);
		
		N++;
		
		FOR(i,N) dist[i][i]=0;
		FOR(i,N) FOR(x,N) FOR(y,N) dist[x][y]=min(dist[x][y],dist[x][i]+dist[i][y]);
		
		FOR(x,N) FOR(y,N) if(E[x].size()==1 && E[y].size()==1 && x!=y) {
			ll ma=dist[x][y];
			if(S.count(ma)) continue;
			
			FOR(i,N) dist3[i]=1<<29;
			FOR(i,N) if(E[i].size()==1 && dist[x][y]<=dist[i][y]) dist3[i]=0;
			
			if(maxdist()==ma) S.insert(ma);
		}
		
		FOR(x,N) for(y=x+1;y<N;y++) if(E[x].size()==1 && E[y].size()==1) {
			ll ma=dist[x][y]/2;
			if(S.count(ma)) continue;
			FOR(i,N-1) if(min(dist[x][A[i]],dist[x][B[i]])+len[i]+min(dist[y][A[i]],dist[y][B[i]])==dist[x][y]) {
				if(min(dist[x][A[i]],dist[x][B[i]])<=ma && min(dist[y][A[i]],dist[y][B[i]])<=ma) break;
			}
			int h1=A[i],h2=B[i];
			FOR(i,N) dist3[i]=1<<29;
			FOR(i,N) if(E[i].size()==1) {
				if(dist[i][h1]<dist[i][h2] && min(dist[x][h1],dist[y][h1])<=dist[i][h1]) dist3[i]=0;
				if(dist[i][h1]>dist[i][h2] && min(dist[x][h2],dist[y][h2])<=dist[i][h2]) dist3[i]=0;
			}
			if(maxdist()==ma) S.insert(ma);
		}
		
		
		return S.size();
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(0, Arg3, differentTime(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(1, Arg3, differentTime(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(2, Arg3, differentTime(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {0,1,1,2,3,3,2,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5,6,7,8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5,3,2,4,6,8,7,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 7; verify_case(3, Arg3, differentTime(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {123,456,789,1000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 8; verify_case(4, Arg3, differentTime(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(5, Arg3, differentTime(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  CandleTimerEasy ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
