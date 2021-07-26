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
    string maximumNumber(string num, vector<int>& change) {
		int i,j;
		FOR(i,num.size()) {
			int x=num[i]-'0';
			if(change[x]>x) {
				for(j=i;j<num.size();j++) {
					int x=num[j]-'0';
					if(x>change[x]) break;
					x=change[x];
					num[j]='0'+x;
				}
				
				break;
			}
			
		}
        return num;
    }
};
