#include <string>
#include <iostream>
#include <chrono>
using namespace std;


class account{
          unsigned long int account_id;

          string name;
          long int balance;
          long int overdraft;



  public :

          string get_name(){return name;}

          account(unsigned long int id, string s);
          account(unsigned long int id, string s, long int b);


          string statement() {return "ID:"+to_string(account_id)+" "+name+":"+to_string(balance);}
          long int deposit(long int x);
          long int withdraw(long int x);
          void print();

          void apply_interest(double rate);


};

account::account(unsigned long int id, string s) : account_id(id),
                                                    name(s),
                                                    balance(0),
                                                    overdraft(500){}
account::account(unsigned long int id, string s, long int b) : account_id(id),
                                                      name(s),
                                                      balance(b),
                                                      overdraft(500){}

long int account::deposit(long int x){
    // cout<<(x<0)<<(x<=(LONG_MAX-balance))<<endl;

    if(x>=0 && x <= LONG_MAX && (balance<0 || x<=(LONG_MAX-balance)))
      balance += x;
    return balance;
}

long int account::withdraw(long int x){
    if(x>=0 && x <= LONG_MAX && x<=(overdraft+balance))
        balance = balance -(long int)x;
    return balance;
}

void account::print(){
    cout<<statement()<<endl;
}

void account::apply_interest(double rate){
  balance = balance*rate;
  cout << "HELLO" << '\n';

}
