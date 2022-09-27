#include <bits/stdc++.h>
using namespace std;
string IntToString(int len){
    string ans;
    while(len>0){
        ans.push_back(len%10+'0');
        len=len/10;
    }
    int start=0;
    int end=ans.size()-1;
    while(start<end){
        swap(ans[start],ans[end]);
        start++;
        end--;
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    while(n>0){
        n--;
        string s;
        cin >> s;
        if(s.size()<=10){
            cout << s << endl;
        }else{
            int len=s.size()-2;
            string help=IntToString(len);
            string ans;
            ans.push_back(s[0]);
            ans=ans+help;
            ans.push_back(s[s.size()-1]);
            cout << ans << endl;
        }
    }
    return 0;
}
