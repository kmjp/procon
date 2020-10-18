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
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
		vector<pair<int,int>> V;
		int i;
		FOR(i,scores.size()) V.push_back({ages[i],scores[i]});
        SegTree_1<int,1<<20> st;
        
        sort(ALL(V));
        int ret=0;
        FORR(v,V) {
			int ma=st.getval(0,v.second+1)+v.second;
			ret=max(ret,ma);
			st.update(v.second,ma);
		}
		return ret;
    }
};
