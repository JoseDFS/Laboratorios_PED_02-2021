#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

int mayor(int a[],int l,int i,int m){
    if(i==l)
        return m;
    else{
        if(a[i]>m)
            m = a[i];
        mayor(a,l,i+1,m);
    }
}

main(){
    int a[7]= {1,2,3,4,5,6,20};
    int lenght = (sizeof(a)/sizeof(*a));
    cout<<mayor(a,lenght,0,0);

    return 0;
}