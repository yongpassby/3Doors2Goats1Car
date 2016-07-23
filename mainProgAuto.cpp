#include<iostream>
#include<time.h>
#include<stdlib.h>

const int MAX=100000;

void randomGenerate(int *,int);
int rndOpenDoor(int *,int *);

int main(){
    int counter=MAX;
    int wincount(0);
    int a[3];
    int select(-1);
    int doorNumber[3];
    while(counter--){
        randomGenerate(a,counter);
        //std::cout<<"Choice door = ?\n";
        srandom(counter+5);
        select=random()%3;
        //std::cin>>select;
        int looper=0;
        if(select==0||select==1||select==2){
            for(int i=0;i<3;i++){
                if(i==select){doorNumber[2]=select;}
                else{doorNumber[looper++]=i;}
            }
            int hostTell=doorNumber[rndOpenDoor(a,doorNumber)];
            //std::cout<<"I'd select="<<select<<'\t'<<"hostTell=["<<hostTell<<"]\t";
        }else{break;}
        //std::cout<<a[0]<<'\t'<<a[1]<<'\t'<<a[2]<<'\n';
        if(a[select]){wincount++;}
    }
    std::cout<<"Total Exp Rounds="<<MAX<<"\nAlwaysNoChange,Win="<<wincount<<'\n';
    return 0;
}

void randomGenerate(int * input,int rndseed){
    srandom(rndseed*5);
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
