#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
    cout<<"\t\t\tRANDOM NUMBER GUESSING GAME"<<endl;
    cout<<"--------------------------------------------------------------------------------------"<<endl;
    int between_range;
    cout<<"Enter your range:";
    cin>>between_range;
    srand((unsigned int)time(NULL));
    int number=(rand()%between_range)+1;
    
    int guess=0;
    do{
      cout<<"Enter Guess"<<"(1-"<<between_range<<")";
      cin>>guess;
      if(guess > number)
      {
        cout<<"Guess lower!!"<<endl;
        // cout<<"move up"<<guess-number<<"To win"<<endl;
      }
      else if(guess < number){
        cout<<"Guess is high!!!"<<endl;
        // cout<<"move down"<<number-guess<<"To win"<<endl;
      }
      else{
        cout<<"You Win!!";
      }
    }while(guess!=number);

    
}

