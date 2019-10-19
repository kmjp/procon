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
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        
        sort(ALL(slots1));
        sort(ALL(slots2));
        deque<vector<int>> A,B;
        FORR(s,slots1) A.push_back(s);
        FORR(s,slots2) B.push_back(s);
        
        while(A.size()&&B.size()) {
			auto a=A.front();
			auto b=B.front();
			if(min(a[1],b[1])-max(a[0],b[0])>=duration) {
				return {max(a[0],b[0]),max(a[0],b[0])+duration};
			}
			if(a<b) A.pop_front();
			else B.pop_front();
		}
        
        return {};
    }
};




