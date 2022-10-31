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
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
		map<string,ll> sum;
		map<string,pair<int,string>> best;
		
		int i;
		ll ma=0;
		FOR(i,views.size()) {
			sum[creators[i]]+=views[i];
			ma=max(ma,sum[creators[i]]);
			if(best.count(creators[i])==0) best[creators[i]]={-1,""};
			auto a=best[creators[i]];
			if(a.first<views[i]||(a.first==views[i]&&a.second>ids[i])) best[creators[i]]={views[i],ids[i]};
		}
        
        vector<vector<string>> ret;
        FORR(a,sum) {
			if(a.second==ma) {
				ret.push_back({a.first,best[a.first].second});
			}
		}
        return ret;
    }
};


