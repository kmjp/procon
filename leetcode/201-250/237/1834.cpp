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
    vector<int> getOrder(vector<vector<int>>& tasks) {
		vector<int> R;
        int i;
        map<int,vector<int>> cand;
        FOR(i,tasks.size()) cand[tasks[i][0]].push_back(i);
        ll pre=0;
        set<pair<int,int>> S;
        FORR(m,cand) {
			int cur=m.first;
			
			while(pre<cur&&S.size()) {
				auto p=*S.begin();
				S.erase(S.begin());
				R.push_back(p.second);
				pre+=p.first;
			}
			if(S.empty()&&pre<cur) pre=cur;
			FORR(c,m.second) S.insert({tasks[c][1],c});
		}
		while(S.size()) {
			auto p=*S.begin();
			S.erase(S.begin());
			R.push_back(p.second);
			pre+=p.first;
		}
		return R;
		
		
        
    }
};
