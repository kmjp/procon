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
    int minDeletions(string s) {
		vector<int> C(26);
		FORR(c,s) C[c-'a']++;
		ll num=0;
		while(1) {
			sort(ALL(C));
			reverse(ALL(C));
			while(C.size()&&C.back()==0) C.pop_back();
			if(C.empty()||C.size()==1) break;
			int i;
			FOR(i,C.size()-1) {
				if(C[i]==C[i+1]) {
					num++;
					C[i]--;
					break;
				}
			}
			if(i==C.size()-1) break;
			
			
		}
        return num;
    }
};

