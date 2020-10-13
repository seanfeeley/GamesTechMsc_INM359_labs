#include <string>
#include <iostream>
#include <vector>
// #include "account.cc"
using namespace std;
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

          long int apply_interest(double rate);


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

long int account::apply_interest(double rate){
  // cout << balance*10000 << '\n';
  // cout << (long int)(rate*10000.0) << '\n';
  double increase = (double)balance * rate/100.0;
  balance = balance + (long int) increase;
  return balance;

}

class bank{

          vector<account> accounts;
          double interest_rate;
          string name;

  public :

          bank(string n);
          unsigned long int add_account(string s);
          unsigned long int add_account(string s, long int b);
          long int deposit(unsigned long int account_id, long int v);
          long int withdraw(unsigned long int account_id, long int v);
          void set_interest(double rate);
          void apply_interest();
          void print();
};

bank::bank(string n) : name(n) {}
void bank::print(){
    cout<<name<<endl;
    for(account a:accounts){
      cout<<"    ";
      a.print();
    }
}
unsigned long int bank::add_account(string s){
  unsigned long int account_id = accounts.size();
  accounts.push_back(account(account_id, s));
  return account_id;
}
unsigned long int bank::add_account(string s, long int b){
  unsigned long int account_id = accounts.size();
  accounts.push_back(account(account_id,s,b));
  return account_id;
}
long int bank::deposit(unsigned long int account_id, long int v){
  return accounts[account_id].deposit(v);
}
long int bank::withdraw(unsigned long int account_id, long int v){
  return accounts[account_id].withdraw(v);
}
void bank::set_interest(double rate){
  interest_rate=rate;
}
void bank::apply_interest(){
  for(account &a:accounts)
    a.apply_interest(interest_rate);
}



int main() {
    bank b = bank("Bank of Scotland");

    unsigned long int sean_id = b.add_account("Sean", 100);
    // unsigned long int john_id = b.add_account("John", 100);
    b.deposit(sean_id, 10000);
    // b.deposit(john_id, 10);
    b.set_interest(-10.0);
    b.apply_interest();
    b.print();
    // cout << "HELLO" << '\n';


}
