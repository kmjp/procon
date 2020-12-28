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
    int eatenApples(vector<int>& apples, vector<int>& days) {
		multiset<pair<int,int>> M;
		
		int i;
		int ret=0;
		for(i=1;i<=40000;i++) {
			if(apples.size()>=i && apples[i-1]) {
				M.insert({i+days[i-1],apples[i-1]});
			}
			while(M.size()) {
				if(M.begin()->first<=i) M.erase(M.begin());
				else if(M.begin()->second==0) M.erase(M.begin());
				else {
					ret++;
					auto p=*M.begin();
					M.erase(M.begin());
					p.second--;
					if(p.second) M.insert(p);
					break;
				}
			}
		}
		return ret;
		
		
        
    }
};

