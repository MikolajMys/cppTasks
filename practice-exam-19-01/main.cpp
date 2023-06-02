#include <iostream>
#include <cstring>
using namespace std;

void null_set(void* arr1, void* arr2, int n, int sizen){

    for(int i=0; i<n; ++i){
        if((float)arr1[i]==(float)arr2[i]){
            arr1[i]=0;
            arr2[i]=0;
        }
    }
}

int main()
{
    const int n=4;
    int sizen=sizeof(float);
    float arr1[n]={8.0, 9.3, 10.7, 11.0};
    float arr2[n]={8.0, 3.1, 10.7, 4.2};

    null_set(arr1, arr2, n, sizen);

    for(int i=0; i<n; ++i){
        cout<<arr1[i]<<endl;
    }
    cout<<endl;
    for(int i=0; i<n; ++i){
        cout<<arr2[i]<<endl;
    }
    return 0;
}
