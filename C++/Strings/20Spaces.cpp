#include <iostream>
#include<cstring>
using namespace std;

void replace_space(char *str){
    int spcCount = 0;
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == ' ')
            spcCount++;
    }
    int idx = strlen(str) + 2*spcCount;
    str[idx] = '\0';
    idx--;
    for(int i = strlen(str)-1; i >= 0; i--){
        if(str[i] == ' '){
            str[idx] = '0';
            str[idx-1] = '2';
            str[idx-2] = '%';
            idx = idx-3;
        } else {
            str[idx] = str[i];
            idx--;
        }
    }
}

int main() {
    char input[10000];
    cin.getline(input,1000);
    replace_space(input);
    
    cout << input << endl;
    
    return 0;
}
