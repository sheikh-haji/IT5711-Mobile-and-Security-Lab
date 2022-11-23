#include<iostream>
using namespace std;
string encrypt(string message, int key) {
    int n = message.length();
    char rails[key][n];

    for(int i=0;i<key;i++){
      for(int j=0;j<n;j++){
        rails[i][j]='.';
      }
    }

    int row = 0;
    bool down = true;

    for (int i = 0; i < message.length(); i++) {
        if (down) {
            rails[row++][i] = message[i];
            if (row == key) {
                row--;
                down = false;
            }
        } else {
            row--;
            rails[row][i] = message[i];
            if (row == 0) {
                row++;
                down = true;
            }
        }
    }
    cout<<endl;
    string encryptedText = "";
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < n; j++) {
            if (rails[i][j] != '.')
                encryptedText += rails[i][j];
            cout<<rails[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
    return encryptedText;
}
  string decrypt(string encryptedText, int key) {
    int n = encryptedText.length();
    char rails[key][n];
    for(int i=0;i<key;i++){
      for(int j=0;j<n;j++){
        rails[i][j]='.';
      }
    }
    int row = 0;
    bool down = true;

    for (int i = 0; i < encryptedText.length(); i++) {
        if (down) {
            rails[row++][i] = '*';
            if (row == key) {
                row--;
                down = false;
            }
        } else {
            row--;
            rails[row][i] = '*';

            if (row == 0) {
                row++;
                down = true;
            }
        }
    }

    cout<<endl;
    int idx = 0;
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < n; j++) {
            if (rails[i][j] == '*')
                rails[i][j] = encryptedText[idx++];
          cout<<rails[i][j];
        }
      cout<<endl;
    }
  cout<<endl;
  //
    string decryptedText = "";
    row = 0;
    down = true;

    for (int i = 0; i < encryptedText.length(); i++) {
        if (down) {
            if (rails[row][i] != '.')
                decryptedText += rails[row][i];
            row++;
            if (row == key) {
                row--;
                down = false;
            }
        } else {
            row--;
            if (rails[row][i] != '.')
                decryptedText += rails[row][i];
            if (row == 0) {
                row++;
                down = true;
            }
        }
    }

    return decryptedText;

}
int main(){
  cout<<"Enter the message: ";
  string message;
  cin>>message;
  cout<<"Enter the key: ";
  int key;
  cin>>key;
  string encryptedText = encrypt(message, key);
  cout<<"Encrypted Text: " <<encryptedText;

  string decryptText = decrypt(encryptedText, key);
  cout<<"Decrypted Text: "<<decryptText;


  return 0;
}
