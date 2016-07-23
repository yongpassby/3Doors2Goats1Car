#include<iostream>
#include<time.h>
#include<stdlib.h>

void randomGenerate(int *);
int rndOpenDoor(int *,int *);

int main(){
    int a[3];
    int select=-1;
    int doorNumber[3];
    do{
        randomGenerate(a);
        std::cout<<"Choice door = ?\n";
        std::cin>>select;
        int looper=0;
        if(select==0||select==1||select==2){
            for(int i=0;i<3;i++){
                if(i==select){doorNumber[2]=select;}
                else{doorNumber[looper++]=i;}
            }
            int hostTell=doorNumber[rndOpenDoor(a,doorNumber)];
            std::cout<<"hostTell=["<<hostTell<<"]\n";
        }else{break;}
        std::cout<<a[0]<<'\n'<<a[1]<<'\n'<<a[2]<<'\n';
    }while(1);
    return 0;
}

void randomGenerate(int * input){
    srandom(time(0));
    int prizedoor=random()%3;
    for(int i=0;i<3;i++){
        if(i==prizedoor){input[i]=1;}
        else{input[i]=0;}
    }
}

int rndOpenDoor(int * door,int * doorNum){
    srandom(time(0));
    int rndNum=random()%2;
    if(door[doorNum[rndNum]]==0){return rndNum;}
    else{return 1-rndNum;}
}
