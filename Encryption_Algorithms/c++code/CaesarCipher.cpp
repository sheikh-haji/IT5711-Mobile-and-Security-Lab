#include<iostream>
#include<ctype.h>
using namespace std;
// n->keysize
string encrypt(string str,int n){
   n=n%26;
   for(int i=0;i<str.length();i++){
      if(isalpha(str[i])==false){
         continue;
      }
      char temp=str[i]+n;
      if(isalpha(temp)){
        str[i]=temp;

      }
      else{
        str[i]=(char)((int)str[i]+n-26);
      }


   }
   return str;
}
string decrypt(string str,int n){
  n=n%26;
  for(int i=0;i<str.length();i++){
    if(isalpha(str[i])==false){
       continue;
    }
    char temp=(char)((int)str[i]-n);
    if(isalpha(temp)){
      str[i]=temp;

    }
    else{
      cout<<"NOT CHARACTER";
      str[i]=(char)((int)str[i]-n+26);
    }

  }
  return str;
}
int main(){
 string str;
 int n;
 cout<<"Enter the string to be encrypted:";
 cin>>str;
 cout<<"Enter the key size:";
 cin>>n;
 string cipher=encrypt(str,n);
 cout<<"cipher:"<<cipher<<endl;
 cout<<"The decrypted text is"<<endl;
 string plaintext=decrypt(cipher,n);
 cout<<plaintext<<endl;


  return 0;
}
