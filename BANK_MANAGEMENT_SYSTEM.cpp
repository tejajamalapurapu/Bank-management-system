#include<iostream>
#include<stdio.h>
#include<fstream>
#include<windows.h>
using namespace std;
class bank{
  private:
    int pinn;
    string name,Fname,Ph_no,Ac_no,mail,pass;
    float balance;
  public:
  void Menu();
  void bank_management();            //class which contains important functions
  void Atm_management();
  void new_user();
  void Already_user();
  void deposit_amount();
  void withdraw_amount();
  void payment();
  void transfer_amount();
  void User_record();
  void Delete_Userrecord();
  void Edit_Userrecord();
  void Allrecords();
  void Allpayments();
  void atmcheckbalance(string Accno);
  void atmwithdraw();
  void atm_accdetails(string Accno);
  
  
};

void bank::Menu(){           //MENU
  system("cls");
  p:
   int password,pin;
   string Email;
     int choice;
      cout<<"\n\n\t\t\t\t\t\t\tCONTROL PANEL";
      cout<<"\n\nWELCOME!";
      cout<<"\n\n1.Bank Management";       //menu options
      cout<<"\n\n2.Atm Management";
      cout<<"\n\n3.Exit";
      cout<<"\nEnter your choice:";
      cin>>choice;


      switch(choice){
        case 1:
             system("cls");
           cout<<"\n\n\tEnter your E-mail:";
           cin>>Email;
           cout<<"\n\n\tEnter your password:";     //ACCOUNTANT CAN ACCESS
           cin>>password;
           cout<<"\n\n\tEnter your pin:";
           cin>>pin;
           if(Email=="teja.jamalapurapu12@gmail.com"&&password==124298&&pin==8760){
              bank_management();
           }
           else{
             cout<<"ERROR YOU ENTERED WRONG password and pin..... "<<endl;
             goto p;
           }
           break;
        case 2:
        system("cls");                                  //cases for menu options
        Atm_management();
        break;
        case 3:
         exit(0);
         
         
      }

}


void bank::bank_management(){    //BANK MANAGEMENT FUNCTION which contains so many sub functions
         p:
          system("cls");
          int choice1;
        
        cout<<"\n\n\n\t\t\t\t\t\tWelcome to bank management";
        cout<<"\n\n\nYou can select the follwing options";
        cout<<"\n\n1.New User";
        cout<<"\n\n2.Already User";
        cout<<"\n\n3.Deposit amount";
        cout<<"\n\n4.Withdraw amount";
        cout<<"\n\n5.Transfer amount";      //options for user in bank management option
        cout<<"\n\n6.payment";
        cout<<"\n\n7.Search user record";
        cout<<"\n\n8.Edit user record";
        cout<<"\n\n9.Delete user record";
        cout<<"\n\n10.Show all records";
        cout<<"\n\n11.All payment records";
        cout<<"\n\nEnter your choice:";
        cin>>choice1;
        switch(choice1){
             case 1:
               new_user();   //adding the new user
                break;
             case 2:
               Already_user();  //logging into user(checking whether he has account or not)
             break;
             case 3:
               deposit_amount(); //depositing the amount by the user
             break;
             case 4:
               withdraw_amount();
             break;
             case 5:
               transfer_amount();
             break;
             case 6:
              payment();
             break;
             case 7:
              User_record();
             break;
             case 8:
              Edit_Userrecord();
             break;
             case 9:
             Delete_Userrecord();
             break;
             case 10:
             Allrecords();
             break;
             case 11:
              Allpayments();
             break;
             default:
              cout<<"You entered wrong choice...please try again.....";
              goto p;

             
        }


}



void bank::Atm_management(){
      p:
     system("cls");
        int choice2;
        string Accno,passwordd;
        cout<<"Enter your Account number:";
        cin>>Accno;
        cout<<"Enter your password:";
        cin>>passwordd;
        bool found=false;

        ifstream inmode("C:/Users/tejaj/OneDrive/Desktop/c++ projects/bank.txt");
        while(inmode>>name>>Ac_no>>Fname>>pass>>pinn>>mail>>Ph_no>>balance){
      if(Ac_no==Accno&&pass==passwordd){
         system("cls");
         found=true;
         cout<<"\n\n\n\t\t\t\t\tAtm management"<<endl;
        cout<<"--YOU HAVE LOGGED IN SUCCESSFULLY--"<<endl;
        cout<<"\n\n\n"<<endl;

       
      
       cout<<"\n\n1.Check balance";
       cout<<"\n\n2.Withdraw amount";
       cout<<"\n\n3.Account details";
       cout<<"\n\n4.Go back";                  //options for user for atm option
       cout<<"\n\nEnter your choice:";
       cin>>choice2;
       switch(choice2){
            case 1:
              atmcheckbalance(Accno);
            break;
            case 2:
              atmwithdraw();
            break;
            case 3:
            atm_accdetails(Accno);
  
            break;
            case 4:
            Menu();
            break;
            default:
              cout<<"You entered wrong choice...please try again.....";
              goto p;
       }
      }
      if(!found){
  cout<<"Invalid account number or password";
  goto p;
}
          }   
}


void bank::new_user(){     //ADDING THE NEW USER
          system("cls");
          p:
          ofstream myfile;
       cout<<"\n\n\n\t\t\t\t\tAdd New User:";
       cout<<"\n\n1.Enter your name:";
       cin>>name;
       cout<<"\n\n1.Enter your Account number:";
       cin>>Ac_no;
       cout<<"\n\n2.Enter your fathers name:";
       cin>>Fname;
       cout<<"\n\n3.Enter your password:";        //new user option1
       cin>>pass;
       cout<<"\n\n4.Enter your pin:";
       cin>>pinn;
       cout<<"\n\n5.Enter your Email:";
       cin>>mail;
       cout<<"\n\nEnter your phone number:";
       cin>>Ph_no;
       cout<<"Enter the balance:";
       cin>>balance;
       
       myfile.open("C:/Users/tejaj/OneDrive/Desktop/c++ projects/bank.txt",ios::out|ios::app);

       if(!myfile){
           cout<<"error while opening the file"<<endl;
           return;
       }

       myfile<<name<<" "<<Ac_no<<" "<<Fname<<" "<<pass<<" "<<pinn<<" "<<mail<<" "<<Ph_no<<" "<<balance<<endl;

       cout<<"user record saved successfully"<<endl;
       cin.ignore();
       cin.get();
       myfile.close();
       goto p;


}


void bank::Already_user(){     //CHECKING USER HAS ACCOUNT OR NOT
    p:
     system("cls");
     cout<<"\n\n\n\t\tChecking user Account";
     string i,pa;
     int a;
     cout<<"\nenter the id number:";
     cin>>i;
     cout<<"\nEnter the password: ";
     cin>>pa;
     bool found=false;
     fstream myfile;
     myfile.open("C:/Users/tejaj/OneDrive/Desktop/c++ projects/bank.txt",ios::in);
     if(!myfile.is_open()){
       cout<<"Error unable to open file...";
     }
     else{
      while(myfile>>name>>Ac_no>>Fname>>pass>>pinn>>mail>>Ph_no>>balance){
             if(Ac_no == i&&pass == pa){
                 found=true;
                 cout<<"Login successful";
                 break;
             }

             
      }
      myfile.close();
      if(!found){
              cout<<"Invalid Account number and password...";
                }
     }
     cout<<"\nEnter 1 to check again or 2 to goto menu:";
     cin>>a;
     if(a==1){
      goto p;
     }
     else{
      Menu();
     }

}


void bank::deposit_amount(){  //DEPOSITING THE AMOUNT OF THE USER
     p:
     system("cls");
     
     ifstream inmode("C:/Users/tejaj/OneDrive/Desktop/c++ projects/bank.txt");
     ofstream outmode("C:/Users/tejaj/OneDrive/Desktop/c++ projects/temp.txt");
     ofstream opayment("payment_records.txt");
     string Account_number,password_number;
     float bal;
     int a;
     bool found=false;
     cout<<"Enter your account number:";
     cin>>Account_number;
     cout<<"Enter your account password:";
     cin>>password_number;
     

     while(inmode>>name>>Ac_no>>Fname>>pass>>pinn>>mail>>Ph_no>>balance){
       if(Ac_no==Account_number&&pass==password_number){
            cout<<"Enter the deposit amount:";
            cin>>bal;
            balance+=bal;
            cout<<"Amount deposited successfully"<<endl;
             found=true;
           opayment<<"Rs"<<bal<<" deposited in "<<name<<" Account"<<endl;
       }
        outmode<<name<<" "<<Ac_no<<" "<<Fname<<" "<<pass<<" "<<pinn<<" "<<mail<<" "<<Ph_no<<" "<<balance<<endl;
           
       
       }
       
       inmode.close();
       outmode.close();
       opayment.close();
       remove("C:/Users/tejaj/OneDrive/Desktop/c++ projects/bank.txt");
       rename("C:/Users/tejaj/OneDrive/Desktop/c++ projects/temp.txt","C:/Users/tejaj/OneDrive/Desktop/c++ projects/bank.txt");

       if(!found){
        cout<<"Error ID,PASSWORD incorrect..."<<endl;
        cout<<"Try Again.."<<endl;
        cout<<"\nEnter 1 to Try again or 2 to goto menu:";
        cin>>a;
        if(a==1){
        goto p;
        } 
         else{
        Menu();
          }

 }
}


void bank::withdraw_amount(){
    p:
     system("cls");
     
     ifstream imode("C:/Users/tejaj/OneDrive/Desktop/c++ projects/bank.txt");
     ofstream omode("C:/Users/tejaj/OneDrive/Desktop/c++ projects/temp.txt");
     ofstream opayment("payment_records.txt");
     int amount;
     int a;
     string Account_number,password_number;
     bool found=false;
     cout<<"Enter your account number:";
     cin>>Account_number;
     cout<<"Enter your account password:";
     cin>>password_number;
     

     while(imode>>name>>Ac_no>>Fname>>pass>>pinn>>mail>>Ph_no>>balance){
       if(Ac_no==Account_number&&pass==password_number){
            cout<<"Enter the withdraw amount:";
            cin>>amount;
            found=true;
            if(balance>=amount){
            balance-=amount;
            cout<<"Amount withdrawn successfully"<<endl;

            opayment<<"Rs"<<amount<<" withdrawn from "<<name<<" Account"<<endl;
             
            }
            else{
                cout<<"Sorry! Insufficient balance in your Account."<<endl;
            }
           
       }
        omode<<name<<" "<<Ac_no<<" "<<Fname<<" "<<pass<<" "<<pinn<<" "<<mail<<" "<<Ph_no<<" "<<balance<<endl;
           
       
       }
       
       imode.close();
       omode.close();
       opayment.close();
       remove("C:/Users/tejaj/OneDrive/Desktop/c++ projects/bank.txt");
       rename("C:/Users/tejaj/OneDrive/Desktop/c++ projects/temp.txt","C:/Users/tejaj/OneDrive/Desktop/c++ projects/bank.txt");

       if(!found){
        cout<<"Error ID,PASSWORD incorrect..."<<endl;
        cout<<"Try Again.."<<endl;
        cout<<"\nEnter 1 to Try again or 2 to goto menu:";
        cin>>a;
        if(a==1){
        goto p;
        } 
         else{
        Menu();
          }
        }
}



void bank::payment(){
  p:
  system("cls");
  ifstream imode("C:/Users/tejaj/OneDrive/Desktop/c++ projects/bank.txt");
  ofstream omode("C:/Users/tejaj/OneDrive/Desktop/c++ projects/temp.txt");
  ofstream opayment("payment_records.txt");
   string  account_no;
   string input_pass;
   int loan_bill;
   int EMI;
   float gas_bill;
   float current_bill;
    int choice,a;
    bool found=false;
    
    cout<<"Enter your account number:";
      cin>>account_no;
      cout<<"Enter your account password:";
      cin>>input_pass;

   

   while(imode>>name>>Ac_no>>Fname>>pass>>pinn>>mail>>Ph_no>>balance){
       if(Ac_no==account_no&&pass==input_pass){
         cout<<"Enter the choice\n1.loan bill\n2.Emi\n3.Gas bill\n4.Current bill";
         cin>>choice;
         if(choice==1){
            cout<<"Enter the amount to pay loan:";
            cin>>loan_bill;
            if(balance>=loan_bill){
                 balance -=loan_bill;
                 cout<<"The loan has been payed!thank you!"<<endl;
                 opayment<<"Rs"<<loan_bill<<" loan bill payed from "<<name<<"'s Account"<<endl;
            }
            else{
              cout<<"Your bank balace is not sufficient"<<endl;
            }
         }
         else if(choice==2){
            cout<<"Enter the amount to pay EMI:";
            cin>>EMI;
            if(balance>=EMI){
                 balance -=EMI;
                 cout<<"The EMI has been payed!thank you!"<<endl;
                 opayment<<"Rs"<<EMI<<" EMI bill payed from "<<name<<"'s Account"<<endl;
            }
            else{
              cout<<"Your bank balace is not sufficient"<<endl;
            }

         }
         else if(choice==3){
             cout<<"Enter the amount to pay gas bill:";
             cin>>gas_bill;
             if(balance>=gas_bill){
                 balance -=gas_bill;
                 cout<<"The gas bill has been payed!thank you!"<<endl;
                 opayment<<"Rs"<<gas_bill<<" GAS bill payed from "<<name<<"'s Account"<<endl;
            }
            else{
              cout<<"Your bank balace is not sufficient"<<endl;
            }
             
         }
         else if(choice==4){
          cout<<"Enter the amount to pay current bill:";
          cin>>current_bill;
          if(balance>=current_bill){
                 balance -=current_bill;
                 cout<<"The current bill has been payed!thank you!"<<endl;
                 cout<<"The total amount payed is:"<<current_bill<<endl;
                 opayment<<"Rs"<<current_bill<<" current bill payed from "<<name<<"'s Account"<<endl;
            }
            else{
              cout<<"Your bank balace is not sufficient"<<endl;
            }
         }
       }
       omode<<name<<" "<<Ac_no<<" "<<Fname<<" "<<pass<<" "<<pinn<<" "<<mail<<" "<<Ph_no<<" "<<balance<<endl;
      }

        imode.close();
        omode.close();
        opayment.close();
        remove("C:/Users/tejaj/OneDrive/Desktop/c++ projects/bank.txt");
        rename("C:/Users/tejaj/OneDrive/Desktop/c++ projects/temp.txt","C:/Users/tejaj/OneDrive/Desktop/c++ projects/bank.txt");
            
    
        
        cout<<"\nEnter 1 to Try again or 2 to goto menu:";
        cin>>a;
        if(a==1){
        goto p;
        } 
        else{
        Menu();
          }
        
  

}


void bank ::transfer_amount(){
  p:
    system("cls");
    string acc1,input_pass1,acc2,input_pass2;
    int amount,sender_found=false,receiver_found=false,a,sender_balance=0;
    cout<<"\nEnter the Amount:";
    cin>>amount;
    cout<<"Enter the user1 account number:";
    cin>>acc1;
    cout<<"Enter the user1 password:";
    cin>>input_pass1;
    cout<<"Enter the user2 account number:";
    cin>>acc2;
    cout<<"Enter the user2 password:";
    cin>>input_pass2;

    ifstream imode("C:/Users/tejaj/OneDrive/Desktop/c++ projects/bank.txt");
    ofstream omode("C:/Users/tejaj/OneDrive/Desktop/c++ projects/temp.txt");
    while(imode>>name>>Ac_no>>Fname>>pass>>pinn>>mail>>Ph_no>>balance){
         if(Ac_no==acc1&&pass==input_pass1){
          sender_found=true;
           if(balance>=amount){
              balance-=amount;
              sender_balance=balance;
           }
           else{
           imode.close();
           omode.close();
           remove("C:/Users/tejaj/OneDrive/Desktop/c++ projects/bank.txt");
           cout << "\nEnter 1 to Try Again or 2 to Go to Menu: ";
                cin >> a;
                if (a == 1) 
                goto p;
                else
                 Menu();
           }
              
         }
         else if(Ac_no==acc2&&pass==input_pass2){
           receiver_found = true;
            balance += amount;
            cout << "\nAmount " << amount << " successfully transferred to " << name << "!\n";
         }
        
        omode<<name<<" "<<Ac_no<<" "<<Fname<<" "<<pass<<" "<<pinn<<" "<<mail<<" "<<Ph_no<<" "<<balance<<endl;
    }

          imode.close();
          omode.close();
         if(sender_found && receiver_found){
            remove("C:/Users/tejaj/OneDrive/Desktop/c++ projects/bank.txt");
           rename("C:/Users/tejaj/OneDrive/Desktop/c++ projects/temp.txt","C:/Users/tejaj/OneDrive/Desktop/c++ projects/bank.txt");
            
           cout << "\nTransfer Completed Successfully!"<<endl;
           cout<<"The remaining in "<<acc1<<"is"<<sender_balance<<endl;
         }
         else{
          cout<<"Transfer failed!Invalid users details";
          remove("C:/Users/tejaj/OneDrive/Desktop/c++ projects/temp.txt");
         }
            
    
     cout<<"\nEnter 1 to Try again or 2 to goto menu:";
      cin>>a;
      if(a==1){
      goto p;
      } 
      else{
      Menu();
        }
}


void bank::User_record(){
  p:
    system("cls");
    string Account_number,pass_word;
    cout<<"Enter the Account number:";
    cin>>Account_number;
    cout<<"Enter the password:";
    cin>>pass_word;
    int a;
    bool isfound=false;

    ifstream imode("C:/Users/tejaj/OneDrive/Desktop/c++ projects/bank.txt");
    while(imode>>name>>Ac_no>>Fname>>pass>>pinn>>mail>>Ph_no>>balance){
         if(Ac_no==Account_number&&pass==pass_word){
           isfound=true;
            cout<<"The user details found:"<<endl;
            cout<<"Name: "<<name<<"\n"<<"Account number:"<<Ac_no<<"\n"<<"Father's name:"<<Fname<<"\n"<<"Phone number:"<<Ph_no<<"\n"<<
            "Email:"<<mail<<"\n"<<"Current balance:"<<balance<<endl;
         }
         
    }
     imode.close();
     if(!isfound){
      cout<<"USER RECORD NOT FOUND"<<endl;
     }

    cout<<"\nEnter 1 to Try again or 2 to goto menu:";
      cin>>a;
      if(a==1){
      goto p;
      } 
      else{
      Menu();
        }
}




void bank::Delete_Userrecord(){
  p:
  system("cls");
  string Account_number;
  cout<<"Enter the Account number:";
  cin>>Account_number;
  int a;
  bool isdeleted=false;

   ifstream imode("C:/Users/tejaj/OneDrive/Desktop/c++ projects/bank.txt");
   ofstream omode("C:/Users/tejaj/OneDrive/Desktop/c++ projects/temp.txt");

   while(imode>>name>>Ac_no>>Fname>>pass>>pinn>>mail>>Ph_no>>balance){
            if(Ac_no==Account_number){
               isdeleted=true;
            }
            else{
              omode<<name<<" "<<Ac_no<<" "<<Fname<<" "<<pass<<" "<<pinn<<" "<<mail<<" "<<Ph_no<<" "<<balance<<endl;
            }
   }

   imode.close();
   omode.close();

           remove("C:/Users/tejaj/OneDrive/Desktop/c++ projects/bank.txt");
           rename("C:/Users/tejaj/OneDrive/Desktop/c++ projects/temp.txt","C:/Users/tejaj/OneDrive/Desktop/c++ projects/bank.txt");
  if(isdeleted){
    cout<<"THE USER RECORD DELETED";
  }
  else{
    cout<<"THE USER RECORD NOT FOUND";
  }
  
   cout<<"\nEnter 1 to Try again or 2 to goto menu:";
      cin>>a;
      if(a==1){
      goto p;
      } 
      else{
      Menu();
        }
  
}




void bank::Edit_Userrecord(){
  p:
   system("cls");

   string Account_num;
   string Name,Fathername,password,EmailAddress,phonenumber;
   int pinnumber;
   bool isEdited=false;
   int a;
   cout<<"Enter User Account number:";
   cin>>Account_num;

   ifstream imode("C:/Users/tejaj/OneDrive/Desktop/c++ projects/bank.txt");
   ofstream omode("C:/Users/tejaj/OneDrive/Desktop/c++ projects/temp.txt");

  while(imode>>name>>Ac_no>>Fname>>pass>>pinn>>mail>>Ph_no>>balance){
    if(Ac_no==Account_num){
      isEdited=true;
      int choice;
      cout<<"Enter which part you want to change:"<<endl;
      cout<<"1.Name\n2.Fathername\n3.password\n4.pin number\n5.Email Address\n6.Phone number"<<endl;
      cin>>choice;
      switch(choice){
        case 1:
           cout<<"Enter the new name:";
           cin>>Name;
           name=Name;
           break;
        case 2:
          cout<<"Enter the Fathers name:";
          cin>>Fathername;
          Fname=Fathername;
          break;
        case 3:
         cout<<"Enter the new password:";
         cin>>password;
         pass=password;
         break;
         case 4:
          cout<<"Enter the new pin number:";
          cin>>pinnumber;
          pinn=pinnumber;
          break;
        case 5:
          cout<<"Enter the new Email Address:";
          cin>>EmailAddress;
          mail=EmailAddress;
          break;
        case 6:
           cout<<"Enter the new phone number:";
           cin>>phonenumber;
           Ph_no=phonenumber;
           break;
        default:
           cout<<"~YOU HAVE ENTERED WRONG CHOICE~";
           cout<<"\nEnter 1 to Try again or 2 to goto menu:";
            cin>>a;
            if(a==1){
            goto p;
            } 
            else{
            Menu();
              }

      }

    }
     omode<<name<<" "<<Ac_no<<" "<<Fname<<" "<<pass<<" "<<pinn<<" "<<mail<<" "<<Ph_no<<" "<<balance<<endl;
  }

 imode.close();
 omode.close();
        remove("C:/Users/tejaj/OneDrive/Desktop/c++ projects/bank.txt");
        rename("C:/Users/tejaj/OneDrive/Desktop/c++ projects/temp.txt","C:/Users/tejaj/OneDrive/Desktop/c++ projects/bank.txt");
   if(isEdited){
     cout<<"The changes done successfully"<<endl;
     
   }

    cout<<"\nEnter 1 to Try again or 2 to goto menu:";
    cin>>a;
    if(a==1){
    goto p;
    } 
    else{
    Menu();
      }

}



void bank::Allrecords(){
  p:
  system("cls");
  int a, count=0;
    ifstream imode("C:/Users/tejaj/OneDrive/Desktop/c++ projects/bank.txt");
     cout<<"SHOWING ALL THE RECORDS"<<endl;
    while(imode>>name>>Ac_no>>Fname>>pass>>pinn>>mail>>Ph_no>>balance){
        count++;
      cout<<name<<" "<<Ac_no<<" "<<Fname<<" "<<pass<<" "<<pinn<<" "<<mail<<" "<<Ph_no<<" "<<balance<<endl;
      cout<<"\n";

    }
    imode.close();
    cout<<"Total "<<count<<" Records are present"<<endl;

    cout<<"\nEnter 1 to Try again or 2 to goto menu:";
    cin>>a;
    if(a==1){
    goto p;
    } 
    else{
    Menu();
      }
}




void bank::Allpayments(){
    p:
     system("cls");
     ifstream payments("payment_records.txt");
     string line;
     int a;
     
     while(getline(payments,line)){
         cout<<line<<endl;
     }

     payments.close();


    cout<<"\nEnter 1 to Try again or 2 to goto menu:";
    cin>>a;
    if(a==1){
    goto p;
    } 
    else{
    Menu();
      }
}




void bank::atmcheckbalance(string Accno){
   p:
       system("cls");
       bool isfound=false;
       int a;
   ifstream bal("bank.txt");
   while(bal>>name>>Ac_no>>Fname>>pass>>pinn>>mail>>Ph_no>>balance){
        if(Ac_no==Accno){
          isfound=true;
          cout<<"YOUR BALANCE AMOUNT IS Rs"<<balance<<endl;

        }
        
   }
   bal.close();
    cout<<"\n\nEnter 1 to Try again or 2 to goto menu:";
    cin>>a;
    if(a==1){
    goto p;
    } 
    else{
    Menu();
      }
}




void bank::atmwithdraw() {
p:
    system("cls");
    int a, pin, amount;
    bool found = false;

    cout << "Enter your pin: ";
    cin >> pin;
    cout << "Enter the amount to withdraw: ";
    cin >> amount;

    ifstream imode("bank.txt");
    ofstream omode("temp.txt");

    while (imode >> name >> Ac_no >> Fname >> pass >> pinn >> mail >> Ph_no >> balance) {
        if (pinn == pin) {
            found = true;
            if (balance >= amount) {
                balance -= amount;
                cout << "\nThe amount Rs " << amount << " withdrawn successfully.\n";
                cout << "Remaining balance: Rs " << balance << endl;
            } else {
                cout << "\nInsufficient balance! Please check your balance.\n";
            }
        }
        omode << name << " " << Ac_no << " " << Fname << " " << pass << " "
              << pinn << " " << mail << " " << Ph_no << " " << balance << endl;
    }

    imode.close();
    omode.close();

    if (!found) {
        cout << "\nInvalid PIN entered. Please try again.\n";
    }

    
    ifstream tempIn("temp.txt");
    ofstream bankOut("bank.txt");

    string line;
    while (getline(tempIn, line)) {
        bankOut << line << "\n";
    }

    tempIn.close();
    bankOut.close();

    remove("temp.txt"); 

  
    cout << "\n\nEnter 1 to Try again or 2 to go to Menu: ";
    cin >> a;
    if (a == 1)
        goto p;
    else
        Menu();
}



void bank::atm_accdetails(string Accno){
  p:
  int a;
  system("cls");
  ifstream imode("bank.txt");

   while (imode >> name >> Ac_no >> Fname >> pass >> pinn >> mail >> Ph_no >> balance) {
        if(Ac_no==Accno){
          cout<<"The account details are:\n\n";
           cout << name << " " << Ac_no << " " << Fname << " " << pass << " "
              << pinn << " " << mail << " " << Ph_no << " " << balance << endl;
        }
    }
    imode.close();
    cout << "\n\nEnter 1 to Try again or 2 to go to Menu: ";
    cin >> a;
    if (a == 1)
        goto p;
    else
        Menu();
}
  

     

int main(){
      system("color 7A");
      bank obj;
      obj.Menu();
  return 0;
}