#include <iostream>
void swap(int *p,int *q){
    int *temp;
    temp=p;p=q;q=temp;
    return;
}

int main(){
    int p,q;
    using namespace std;
    cout<<"Enter p:"<<endl;
    cin>>p;
    cout<<"Enter q:"<<endl;
    cin>>q;
    swap(p,q);
    cout<<"p="<<p<<" q="<<q<<endl;
}