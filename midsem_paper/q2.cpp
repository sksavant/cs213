/* A valid parenthesis string is defined recursively as follows. The empty
 * string is a valid parenthesis string. If s1 and s2 are valid parenthesis
 * strings then (s1) and s1.s2 are valid parenthesis strings. Here . represents
 * concatenation. Thus ()() and (()) are valid but ())( is not.
 *
 * (a): Describe a O(n) algorithm that takes a parenthesis string as input
 * and determines whether it is valid or not.
 */

#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

bool isvalid(string s)
{
    int no_left=0;
    int no_right=0;
    for (int i=0;i<s.size();++i){
        if (s[i]=='('){
            no_left+=1;
        }else if (s[i]==')'){
            no_right+=1;
        }
        if (no_right>no_left){
            return false;
        }
    }
    if (no_left!=no_right){
        return false;
    }else{
        return true;
    }
}

void test(){
    string teststr1="(()()()))()())";
    string teststr2="()(((((()(()(()(((()(((()())()))()))()))())())()))))";
    string teststr3="()()()";
    string teststr4="(())";
    bool x1,x2,x3,x4;
    x1=isvalid(teststr1);
    x2=isvalid(teststr2);
    x3=isvalid(teststr3);
    x4=isvalid(teststr4);
    cout<<x1<<" "<<x2<<" "<<x3<<" "<<x4<<endl;
}


int main()
{
    test();
    return 0;
}

