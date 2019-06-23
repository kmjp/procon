#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

class Solution {
public:
	string A;
    set<string> hoge(int L,int R){
		//cout<<L<<" "<<R<<" "<<A.substr(L,R-L)<<endl;
		set<string> S;
		if(L>=R) return S;
		int i;
		if(A[L]=='{') {
			int num=1;
			int pre=L;
			for(i=L+1;i<=R;i++) {
				if(A[i]=='{') num++;
				if(A[i]=='}') num--;
				
				if(num==1 && A[i]==',') {
					auto t=hoge(pre+1,i);
					FORR(v,t) S.insert(v);
					pre=i;
				}
				if(num==0) {
					auto t=hoge(pre+1,i);
					FORR(v,t) S.insert(v);
					break;
				}
			}
			//cout<<"!"<<i<<" "<<R<<endl;
			if(i+1==R) return S;
			auto T=hoge(i+1,R);
			set<string> V;
			FORR(s,S) FORR(t,T) V.insert(s+t);
			return V;
		}
		else {
			S.insert(string(1,A[L]));
			if(L+1==R) return S;
			auto T=hoge(L+1,R);
			set<string> V;
			FORR(s,S) FORR(t,T) V.insert(s+t);
			return V;
		}
		
		
		
		
	}
    vector<string> braceExpansionII(string expression) {
		int i;
		A.clear();
		A="{"+expression+"}";
		auto v=hoge(0,A.size());
		vector<string> S;
		FORR(s,v) S.push_back(s);
		return S;
        
    }
};

int main(int argc,char** argv){
	Solution s;
	//cout<<argv[1]<<endl;
	auto a=s.braceExpansionII(argv[1]);
	FORR(v,a) cout<<v<<" ";
	cout<<endl;
	return 0;
}

