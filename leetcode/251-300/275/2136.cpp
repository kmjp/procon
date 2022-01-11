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
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
		vector<pair<int,int>> V;
		int i;
		FOR(i,plantTime.size()) V.push_back({-growTime[i],plantTime[i]});
		sort(ALL(V));
		int ma=0;
		int cur=0;
		FORR(a,V) {
			cur+=a.second;
			ma=max(ma,cur-a.first);
		}
		return ma;
        
    }
};
