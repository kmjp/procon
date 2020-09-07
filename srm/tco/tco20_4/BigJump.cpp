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

template<int MV> class DirectedEulerPath {
public:
	int NV;
	vector<int> path;
	vector<int> E[MV];
	void add_path(int x,int y) { E[x].push_back(y);}
	
	void init(int NV){
		this->NV=NV;
		for(int i=0;i<NV;i++) E[i].clear();
		path.clear();
	}
	void dfs(int cur) {
		while(E[cur].size()) {
			int e=E[cur].back();
			E[cur].pop_back();
			dfs(e);
		}
		path.push_back(cur);
	}
	
	bool GetPath() {
		assert(NV);
		int te=0,i;
		vector<int> deg(NV);
		FOR(i,NV) {
			te += E[i].size();
			deg[i]+=E[i].size();
			FORR(e,E[i]) deg[e]--;
		}
		int d0=0,s=0;
		FOR(i,NV) {
			if(deg[i]>1 || deg[i]<-1) return false;
			if(deg[i]==0) d0++;
			if(deg[i]==1) s=i;
		}
		if(d0!=NV && d0+2!=NV) return false;
		dfs(s);
		reverse(path.begin(),path.end());
		return path.size()==te+1;
	}
};


class BigJump {
	public:
	vector <int> construct(int N) {
		int i;
		if(N==2) return {0,1};
		DirectedEulerPath<2020> dep;
		dep.init(N/2);
		FOR(i,N/2) {
			dep.add_path(i,i*2%(N/2));
			dep.add_path(i,(i*2+N-1)%(N/2));
		}
		assert(dep.GetPath());
		vector<int> V,P=dep.path;
		int cur=0;
		V.push_back(0);
		for(i=1;i<N;i++) {
			if(cur*2%N==P[i]) cur=P[i];
			else if(cur*2%N==P[i]+(N/2)) cur=P[i]+(N/2);
			else if((cur*2+N-1)%N==P[i]) cur=P[i];
			else if((cur*2+N-1)%N==P[i]+(N/2)) cur=P[i]+(N/2);
			V.push_back(cur);
		}
		cout<<endl;
		
		
		
		return V;
		
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 6; int Arr1[] = {0, 5, 4, 1, 2, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, construct(Arg0)); }
	void test_case_1() { int Arg0 = 12; int Arr1[] = {0, 11, 10, 8, 4, 7, 1, 2, 3, 5, 9, 6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, construct(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  BigJump ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

