// Print all the duplicates in the input string

// Write an efficient program to print all the duplicates and their counts in the input string 

#include<iostream>
#include<cstring>
#include<unordered_map>
using namespace std;

void findDups(string str, int len){
    unordered_map<char,int> map;
    for(int i=0;i<len;i++){
        if(map[str[i]]){
            if(map[str[i]]==1)
            cout<<str[i]<<" ";
        }
        map[str[i]]++;
    }
}

int main(){
    string str;
    cout<<"Enter string\n";
    cin>>str;
    findDups(str,str.length());
}