#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
struct Price{
    int code;
    double cost;
};
struct In{
    char name[30];
    int code;
    int count;
};
struct Out{
    int code;
    char name[30];
    int count;
    double sum;
};
void inputPrice(Price p[],int n){
    for(int i=0;i<n;i++){
        cout<<"Код товару: ";
        cin>>p[i].code;
        cout<<"Ціна: ";
        cin>>p[i].cost;
    }
}
void inputIn(In a[],int n){
    for(int i=0;i<n;i++){
        cout<<"Назва: ";
        cin>>a[i].name;
        cout<<"Код: ";
        cin>>a[i].code;
        cout<<"Кількість: ";
        cin>>a[i].count;
    }
}
double findCost(Price p[],int n,int code){
    for(int i=0;i<n;i++){
        if(p[i].code==code)return p[i].cost;
    }
    return 0;
}
int makeOut(In in[],int ni,Price p[],int np,Out out[]){
    int k=0;
    for(int i=0;i<ni;i++){
        int f=-1;
        for(int j=0;j<k;j++){
            if(out[j].code==in[i].code)f=j;
        }
        if(f==-1){
            out[k].code=in[i].code;
            strcpy(out[k].name,in[i].name);
            out[k].count=in[i].count;
            out[k].sum=in[i].count*findCost(p,np,in[i].code);
            k++;
        }else{
            out[f].count+=in[i].count;
            out[f].sum+=in[i].count*findCost(p,np,in[i].code);
        }
    }
    return k;
}
void sortOut(Out a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(a[j].code>a[j+1].code){
                Out t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
}
void printOut(Out a[],int n){
    cout<<setw(10)<<"Код"<<setw(20)<<"Назва"<<setw(30)<<"Кількість"<<setw(15)<<"Сума"<<endl;
    for(int i=0;i<n;i++){
        cout<<setw(10)<<a[i].code<<setw(20)<<a[i].name<<setw(15)<<a[i].count<<setw(15)<<a[i].sum<<endl;
    }
}
int main(){
    int np,ni;
    cout<<"Кількість товарів у довіднику: ";
    cin>>np;
    Price *p=new Price[np];
    inputPrice(p,np);
    cout<<"Кількість надходжень: ";
    cin>>ni;
    In *in=new In[ni];
    inputIn(in,ni);
    Out *out=new Out[ni];
    int no=makeOut(in,ni,p,np,out);
    sortOut(out,no);
    printOut(out,no);
    delete[]p;
    delete[]in;
    delete[]out;
    return 0;
}
