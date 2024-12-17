#include <iostream>
#include <string>
#define num 4
struct student{
    int id;
    std::string name;
    int score_a;
    int score_b;
    int score_c;
    int total;
};

int main(){
    using namespace std;
    student student[num];
    for(int i=0;i<num;i++){
        cout<<"Please enter the "<<i+1<<" student's id"<<endl;
        cin >> student[i].id;
        cout<<"Please enter the "<<i+1<<" student's name"<<endl;
        cin >> student[i].name;
        cout<<"Please enter the "<<i+1<<" student's A score"<<endl;
        cin >> student[i].score_a;
        cout<<"Please enter the "<<i+1<<" student's B score"<<endl;
        cin >> student[i].score_b;
        cout<<"Please enter the "<<i+1<<" student's C score"<<endl;
        cin >> student[i].score_c;
    }
    int average_a=0,average_b=0,average_c=0;
    for(int i=0;i<num;i++){
        average_a=average_a+student[i].score_a;
        average_b=average_b+student[i].score_b;
        average_c=average_c+student[i].score_c;
    }
    average_a=average_a/num;
    average_b=average_b/num;
    average_c=average_c/num;
    int max_a=0,max_b=0,max_c=0;
    for(int i=1;i<num;i++){
        if(student[max_a].score_a<student[i].score_a){
            max_a=i;
        }
        if(student[max_b].score_b<student[i].score_b){
            max_b=i;
        }        
        if(student[max_c].score_c<student[i].score_c){
            max_c=i;
        }
    }
    for(int i=0;i<num;i++){
        student[i].total=student[i].score_a+student[i].score_b+student[i].score_c;
    }
    cout<<"Average of A: "<<average_a<<endl;
    cout<<"Average of B: "<<average_b<<endl;
    cout<<"Average of C: "<<average_c<<endl;
    cout<<"The student with the highest score of A is No."<<max_a+1<<endl;
    cout<<"The student with the highest score of B is No."<<max_b+1<<endl;
    cout<<"The student with the highest score of C is No."<<max_c+1<<endl;
}
