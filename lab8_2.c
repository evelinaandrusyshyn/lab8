#include <iostream>
#include <cstring>
using namespace std;
struct Car{
    char marka[20];
    char color[20];
    char number[15];
    int year;
    char owner[30];
};
struct MarkaCount{
    char marka[20];
    int count;
};
void inputCars(Car* a,int n){
    for(int i=0;i<n;i++){
        cout<<"Авто "<<i+1<<"\n";
        cout<<"Марка: ";
        cin>>a[i].marka;
        cout<<"Колір: ";
        cin>>a[i].color;
        cout<<"Номер: ";
        cin>>a[i].number;
        cout<<"Рік: ";
        cin>>a[i].year;
        cout<<"Власник: ";
        cin>>a[i].owner;
    }
}
void printCars(Car* a,int n){
    cout<<"Марка\tКолір\tНомер\tРік\tВласник\n";
    for(int i=0;i<n;i++){
        cout<<a[i].marka<<"\t"<<a[i].color<<"\t"<<a[i].number<<"\t"<<a[i].year<<"\t"<<a[i].owner<<"\n";
    }
}
int makeMarka(Car* a,int n,MarkaCount* b){
    int k=0;
    for(int i=0;i<n;i++){
        bool found=false;
        for(int j=0;j<k;j++){
            if(strcmp(a[i].marka,b[j].marka)==0){
                b[j].count++;
                found=true;
            }
        }
        if(!found){
            strcpy(b[k].marka,a[i].marka);
            b[k].count=1;
            k++;
        }
    }
    return k;
}
void sortMarka(MarkaCount* b,int k){
    for(int i=0;i<k-1;i++){
        for(int j=0;j<k-1-i;j++){
            if(b[j].count<b[j+1].count){
                MarkaCount t=b[j];
                b[j]=b[j+1];
                b[j+1]=t;
            }
        }
    }
}
void printMarka(MarkaCount* b,int k){
    cout<<"Марка\tКількість\n";
    for(int i=0;i<k;i++){
        cout<<b[i].marka<<"\t"<<b[i].count<<"\n";
    }
}
int main(){
    int n;
    cout<<"Введіть кількість авто: ";
    cin>>n;
    Car* cars=new Car[n];
    inputCars(cars,n);
    printCars(cars,n);
    MarkaCount* m=new MarkaCount[n];
    int k=makeMarka(cars,n,m);
    sortMarka(m,k);
    printMarka(m,k);
    delete[] cars;
    delete[] m;
    return 0;
}
