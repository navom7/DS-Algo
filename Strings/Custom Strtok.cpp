#include <iostream>
#include<cstring>
using namespace std;

char *mystrtok(char *str, char delim){
    
    //static char array that will store the last present string after removing the token
    static char * input = NULL;
    
    if(str != NULL){
        input = str;
    }
    if(input == NULL){
        return NULL;
    }
    
    char *token = new char(strlen(input)+1);
    int i = 0;
    
    for( ; input[i] != '\0'; i++){
        if(input[i] != delim){
            token[i] = input[i];
        } else {
            token[i] = '\0';
            //keeping input pointer to the starting of next token
            input = input + i + 1;
            return token;
        }
    }
    token[i] = '\0';
    input = NULL;
    
    return token;
}


int main() {
    char input[100];
    cin.getline(input, 100);
    
    char* token = mystrtok(input, ' ');
    
    while(token != NULL){ 
        cout << token << endl;
        token = mystrtok(NULL, ' ');
    }
    
    return 0;
}












