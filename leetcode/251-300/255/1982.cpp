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
    vector<int> recoverArray(int n, vector<int>& sums) {
		vector<int> R;
		multiset<int> M;
		FORR(a,sums) M.insert(a);
		while(M.size()>1) {
			auto it=M.begin();
			int x=*it;
			int y=*++it;
			
			int d=x-y;
			
			multiset<int> S,T;
			while(M.size()) {
				int a=*M.begin();
				M.erase(M.begin());
				auto it=M.find(a-d);
				S.insert(*it);
				T.insert(a);
				M.erase(it);
			}
			
			if(S.count(0)) {
				R.push_back(d);
				M=S;
			}
			else {
				R.push_back(-d);
				M=T;
			}
		}
		
		return R;
        
    }
};
