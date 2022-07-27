// 12. Integer to Roman

// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
// Given an integer, convert it to a roman numeral.

class Solution {
public:
    string intToRoman(int num) {
        string s=""; int i=0;
        int arr[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string roman[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        
        while(num){
            if(num-arr[i]>=0){
                s+=roman[i];
                num-=arr[i];
            }
            else
                i++;
        }
        return s;
    }
};