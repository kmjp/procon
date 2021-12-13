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
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
		vector<int> X;
		vector<ll> S;
		S.push_back(0);
		FORR(a,fruits) {
			X.push_back(a[0]);
			S.push_back(S.back()+a[1]);
		}
		ll ma=0;
		int i;
		FOR(i,X.size()) {
			if(X[i]<=startPos) {
				if(startPos-X[i]>k) continue;
				int t=max(startPos,X[i]+(k-(startPos-X[i])));
				int a=lower_bound(ALL(X),t+1)-X.begin();
				ma=max(ma,S[a]-S[i]);
			}
			else {
				if(X[i]-startPos>k) continue;
				int t=min(startPos,X[i]-(k-(X[i]-startPos)));
				int a=lower_bound(ALL(X),t)-X.begin();
				ma=max(ma,S[i+1]-S[a]);
			}
		}
        return ma;
    }
};
