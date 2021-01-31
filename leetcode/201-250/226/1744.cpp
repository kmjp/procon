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
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
		vector<ll> S;
		S.push_back(0);
		FORR(c,candiesCount) S.push_back(S.back()+c);
		
		vector<bool> R;
		FORR(q,queries) {
			q[1]++;
			ll mi=q[1];
			ll ma=1LL*q[1]*q[2];
			if(mi>S.back()) {
				R.push_back(0);
				continue;
			}
			int s=lower_bound(ALL(S),mi)-S.begin();
			s--;
			int e=lower_bound(ALL(S),ma)-S.begin();
			e--;
			R.push_back(s<=q[0]&&e>=q[0]);
		}
		return R;
		
        
    }
};