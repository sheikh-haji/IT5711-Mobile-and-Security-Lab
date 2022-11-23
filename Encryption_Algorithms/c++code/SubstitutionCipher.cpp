#include<iostream>
#include<map>
using namespace std;

void constructMap(map<char,char> &m){
  char value='Z';
  for(char a='a';a<='z';a++){
     m.insert({a,value});
     value--;
  }

}
void constructReverseMap(map<char,char> &m){
  char value='a';
  for(char a='Z';a>='A';a--){
     m.insert({a,value});
     value++;
  }

}
string encrypt(map<char,char> m,string temp){
  for(int i=0;i<temp.length();i++){
    temp[i]=m[temp[i]];
    cout<<m[i];
  }
  return temp;
}
string decrypt(map<char,char> m,string cipher){
  for(int i=0;i<cipher.length();i++){
     cipher[i]=m[cipher[i]];
  }
  return cipher;
}
int main(){
   map<char,char> enmap;
   constructMap(enmap);
   map<char,char> demap;
   constructReverseMap(demap);
   string temp;
   cout<<"enter text to encrypt"<<endl;
   cin>>temp;
   // cout<<temp<<endl;
   string cipher=encrypt(enmap,temp);
   cout<<"cipher:"<<cipher<<endl;
   cout<<"plaintext:"<<decrypt(demap,cipher)<<endl;





  return 0;
}
