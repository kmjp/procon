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
    bool splitString(string s) {
		int i,j;
		for(i=1;i<=s.size()-1;i++) {
			ll cur=0;
			FOR(j,i) {
				cur=cur*10+s[j]-'0';
				if(cur>1LL<<40) break;
			}
			if(cur>1LL<<40) continue;
				
			int pos=i;
			cout<<"!"<<i<<" "<<cur<<endl;
			cur--;
			while(pos<s.size()) {
				ll tar=0;
				if(cur<0) {
					pos=-1;
					break;
				}
				
				if(cur==0) {
					while(pos<s.size()) {
						if(s[pos]!='0') break;
						pos++;
					}
					break;
				}
				
				tar=s[pos]-'0';
				pos++;
				while(pos<s.size()&&tar<cur) {
					tar=tar*10+s[pos]-'0';
					pos++;
				}
				cout<<tar<<" "<<pos<<" "<<cur<<endl;
				if(tar!=cur) {
					pos=-1;
					break;
				}
				cur--;
				
			}
			if(pos==s.size()) return 1;
			
		}
		return 0;
		
        
    }
};
