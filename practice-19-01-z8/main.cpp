#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int x=-1013, d=3;
    char num1[11], num2[2];
    sprintf(num1,"%d",x);
    sprintf(num2,"%d",d);
    int count = 0;
    for(int i = 0; num1[i] != '\0'; i++) {
        if (num1[i] == num2[0])
            count++;
    }
    cout<<count<<endl;
    return 0;
}
