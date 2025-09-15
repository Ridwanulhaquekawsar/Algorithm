#include<bits/stdc++.h>
using namespace std;
int t; string s,tmp;

void do_this(){
    cin>>t; while(t--){
        tmp.clear(); cin>>s; bool is_inserted=false; if(s.size()==1){if(s[0]!='z'){cout<<s[0]<<char(s[0]+1)<<endl;}else{cout<<s[0]<<char(s[0]-1)<<endl;}}else{
           tmp.push_back(s[0]); for(int i=1; i<s.size(); i++){
               if(s[i]!=s[i-1]){tmp.push_back(s[i]);}else{if(is_inserted){tmp.push_back(s[i]);} else if(!is_inserted){if(s[i]!='z'){tmp.push_back(char(s[i]+1));}else{tmp.push_back(char(s[i]-1));} tmp.push_back(s[i]);  is_inserted=true;}}
           }if(!is_inserted){if(s.back()!='z'){tmp.push_back(char(s.back()+1));}else{tmp.push_back(char(s.back()-1));}} cout<<tmp<<endl;
        }
    }
}

int main(){
    do_this();
    return 0;
}

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------



  #include<bits/stdc++.h>
using namespace std;
int t; string s;

void do_this(){
    cin>>t; while(t--){
        cin>>s; int i; for(i=1; i<s.size(); i++){if(s[i]==s[i-1]){break;}} s[i-1]=='a' ? s.insert(s.begin()+i,'b') : s.insert(s.begin()+i,'a');
        cout<<s<<endl;
    }
}

int main(){
    do_this();
    return 0;
}
