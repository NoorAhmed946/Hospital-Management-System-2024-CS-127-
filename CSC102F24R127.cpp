#include <iostream>
#include<windows.h>
#include<iomanip>
#include<cctype>
#include<string>
#include<fstream>
#include<conio.h>
using namespace std ;

struct doctor{
   string name ;
   string userName ;
   string pwdD ;
   string gender ;
   string category ;
   int idD ;
   int age ;
   bool isDoc ;

};

struct receptionist{
   string name ;
   string userName ;
   string pwdR ;
   string gender ;
   int idR ;
   int age ;
   bool isRec ;
};

struct patient {
    string name ;
    string gender ;
    string disease ;
    int    idP ;
    int    age ;
    bool isPatient ;
};

struct appoint {
   string name ;
   string date ;
   string gender ;
   string disease ;
   int  idA ;
   int  age ;
   bool isConfirmed ;
} ;
void header() ;

void adminD(int dsize,bool &msg , doctor doctors[]) ;
void adminR(receptionist recs[] , int rsize) ;
void adminP(doctor doctors[],patient patients[],appoint appointments[][5] ,int psize , int dsize ) ;
void beds(bool bed[] , int psize , int userType) ;

void recP(patient patients[] , int psize ,bool bed[] ) ;
void recA(appoint appointments[][5], doctor doctors[], int dsize, int maxAppointments, bool &msg) ;
void recB(patient patients[] ,appoint appointments[][5],bool bed[], int psize, int dsize,int oneDay, int appointment );

void docP(appoint appointments[][5],int maxAppointments,int docId  ) ;
void docA(appoint appointments[][5],doctor doctors[] ,  int maxAppointments ,int docId )  ;

void docP2(appoint appointments[][5],int maxAppointments ) ;
void docA2(appoint appointments[][5],doctor doctors[] , int maxAppointments) ;

void docP3(appoint appointments[][5],int maxAppointments ) ;
void docA3(appoint appointments[][5],doctor doctors[] , int maxAppointments) ;

void docList(doctor doctors[] , int dsize) ;
void docListA(doctor doctors[] , int dsize ) ;
void appoinList( appoint appointments[][5],doctor doctors[] ,int dsize) ;

int getValidinput012() ;
int getValidinput0123() ;
int getValidinput05() ;
int getValidinput123() ;
string validGen() ;
int validAge() ;
string validDate(appoint appointments[][5], int inputidD, int maxAppointments,bool update) ;
int toInt(const string &str , int st , int end ) ;
int getInt() ;

string uniqueDocUser(doctor doctors[] , int dsize,bool update ) ;
string uniqueRecUser(receptionist recs[],int rsize,bool update ) ;

void savePatientData(patient patients[] ,   int psize) ;
void saveAppointments(appoint appointments[][5] ,doctor doctors[], int maxAppointments,int dsize ) ;
void saveDoctorsData( doctor doctors[] ,int dsize ) ;
void saveReceptionist(receptionist recs[], int rsize) ;

void loadReceptionistData(receptionist recs[], int rsize) ;
void loadDoctorData(doctor doctors[] ,int dsize) ; 
void loadPatientData(patient patients[] ,  int psize,bool bed[]) ;
void loadAppointments(appoint appointments[][5] , int maxAppointments,int dsize ) ;

int main(){
    const int rsize = 2 ; // Number of Receptionist 
    const int dsize = 10 ; // Number of Doctors 
    const int psize = 1000 ; // Number of Patients 
    const int maxAppointments = 5 ;// max number of appointments 
    const int oneDay = 1000 ;    // one day charges of hospital  
    const int appointment = 1500 ; // appointment charges 
    bool  msg = false  ; // to be sent to  receptionist if Admin changes any record of Doctor 
    
    receptionist recs[rsize] ;  // struct array

    doctor doctors[dsize] ; // struct array 
    
    patient patients[psize] ; // struct array 
    bool    bed[psize] ;

    appoint appointments[dsize][maxAppointments] ;
  
    int input , input1, input2 , input3 , doctorId = 0; 
    int userType ;
    string userName ;
    string pwd ;
       
    for(int i = 0 ; i<dsize ; i++){  // indicating no data about doctors 
       doctors[i] = {"NV","NV","NV","NV","NV",-1,-1,false} ;
    }
   
   
    for(int i = 0 ; i<rsize ; i++){  // indicating no data about receptionist
       recs[i] = {"NV","NV","NV","NV",-1,-1,false} ;
    }
      
    for(int i = 0 ; i<psize ; i++){  // indicating no data about patients
       patients[i] = {"NV","NV","NV",-1,-1,false} ;  
    }

     
      for (int i = 0; i < dsize; i++) {
        for (int j = 0; j < maxAppointments; j++) {
            appointments[i][j] = {"NV", "NV", "NV","NV", -1,-1,false}; 
        }
    }
       // FUNCTIONS TO LOAD ALL DATA IN FILES 
       loadReceptionistData(recs,rsize) ;
       loadDoctorData(doctors,dsize) ;
       loadPatientData(patients,psize,bed) ;
       loadAppointments(appointments,maxAppointments,dsize) ;
       
    do{ 
       header();
       input = getValidinput0123() ; 
       switch(input){
              case 1 : {

                cout<<"\t\t\t\t\t\t\t\t ====================="  <<endl ;
                cout<<"\t\t\t\t\t\t\t\t        ADMIN         "  <<endl ;
                cout<<"\t\t\t\t\t\t\t\t ====================="  <<endl ;
                   
                cout<<"\t\t\t\t\t\t\t\tEnter Username : "  ;
                cin>> userName ;
                
                cout<<"\t\t\t\t\t\t\t\tEnter Password : " ;
                cin>> pwd ;
                  // Password  correct or not 

                if(userName == "admin" && pwd == "pwd") 
                   userType = 1 ;   
                else 
                   userType = -1 ;

                break ;  
              }
              case 2 : {
                bool found = false ;
                cout<<"\t\t\t\t\t\t\t\t ====================="  <<endl ;
                cout<<"\t\t\t\t\t\t\t\t      RECEPTIONIST    "  <<endl ;
                cout<<"\t\t\t\t\t\t\t\t ====================="  <<endl ;

                cout<<"\t\t\t\t\t\t\t\tEnter  Username : "  ;
                cin>> userName ;

                cout<<"\t\t\t\t\t\t\t\tEnter Password :" ;
                cin>> pwd ;

                 // Password  correct or not 
                 for(int i = 0; i<rsize ; i++){
                    if(userName == recs[i].userName && pwd == recs[i].pwdR){
                      found = true ;
                    }
                 }

                found ? userType = 2 : userType = -1 ;
              
                 break ;  
              }
              case 3 : { 
                bool found = false ;
                cout<<"\t\t\t\t\t\t\t\t ====================="  <<endl ;
                cout<<"\t\t\t\t\t\t\t\t         DOCTOR       "    <<endl ;
                cout<<"\t\t\t\t\t\t\t\t ====================="  <<endl ;

                cout<<"\t\t\t\t\t\t\t\tEnter  Username : "  ;

                getline(cin,userName) ;

                cout<<"\t\t\t\t\t\t\t\tEnter Password : " ;
                cin>> pwd ;
                // Password  correct or not 
                for(int i = 0 ; i<dsize ; i++){
                    if(userName == doctors[i].userName && pwd == doctors[i].pwdD){
                       doctorId = doctors[i].idD ;
                       found = true ;
                    }
                } 
                
                found ? userType = 3 : userType = -1 ; 
                break ; 
              }
              case 0 : {
                userType = -5 ;
                cout<<"\t\t\t\t\t\t\t\tSystem Closed ....  " ;
                break ; 
              } 
              default :{ 
                cout<<"\t\t\t\t\t\t\t\tInvalid Input " ;
                break ;
              }

       }
       
       // ADMIN  FUNCTIONALITIES
       if(userType == 1) {
        
         // ADMIN 
         do {
             cout<<'\n' ;
             cout<<"\t\t\t\t\t\t\t\t ====================="  <<endl ;
             cout<<"\t\t\t\t\t\t\t\t         ADMIN         "  <<endl ;
             cout<<"\t\t\t\t\t\t\t\t ====================="  <<endl ; 
             cout<<'\n' ;
             
             cout<<"\t\t\t\t\t\t\t\tChoose the Desired Section  : " <<endl ;
             cout<<"\t\t\t\t\t\t\t\t1. Doctors "                    <<endl ; 
             cout<<"\t\t\t\t\t\t\t\t2. Receptionist "               <<endl ;
             cout<<"\t\t\t\t\t\t\t\t3. Patients List"               <<endl ;
             cout<<"\t\t\t\t\t\t\t\t4. Beds "                       <<endl ;
             cout<<"\t\t\t\t\t\t\t\t0. Exit "                       <<endl ;   

             cout<<"\t\t\t\t\t\t\t\tChoose an option : " ;
             input1 = getValidinput05() ; 
             cout<<endl ;
             switch(input1) {
                   case 1 : {
                      // function call of doctor 
                      adminD(dsize,msg,doctors) ;
                      break ;
                   }
                   case 2 : {
                    // function call of Receptionist 
                      adminR(recs, rsize) ;
                
                     break ;
                   }
                   case 3 : {
                    // function call of Patients 
                      adminP(doctors , patients , appointments ,psize , dsize) ;
                   
                     break ;
                   }
                    case 4 : {
                     // function call of Beds
                     beds(bed,psize,userType) ;
                    
                     break ;
                   }
                    case 0 : {
                    cout<<"\t\t\t\t\t\t\t\tExiting ..." <<endl ;
                    break; 
                   }
                   default :{
                    cout<<"\t\t\t\t\t\t\t\tInvalid Input . Pleae Enter Valid Input (0-4)" <<endl ;
                    break ;
                   }
                  
             }
             

         }while(input1 != 0 ); // admin do while 
         
       }
       // RECEPTIONIST FUNCTIONALITIES 
       else if(userType == 2){
           
            
            do{
            cout<<'\n' ;
            cout<<"\t\t\t\t\t\t\t\t ====================="  <<endl ;
            cout<<"\t\t\t\t\t\t\t\t      RECEPTIONIST    "  <<endl ;
            cout<<"\t\t\t\t\t\t\t\t ====================="  <<endl ;
            cout<<'\n' ;


            cout<<"\t\t\t\t\t\t\t\tChoose the Desire Option :"  <<endl ;
            cout<<"\t\t\t\t\t\t\t\t1. Patient Registration "    <<endl ;
            cout<<"\t\t\t\t\t\t\t\t2. Appointment Scheduling  " <<endl ;
            cout<<"\t\t\t\t\t\t\t\t3. Bed Management "          <<endl ;
            cout<<"\t\t\t\t\t\t\t\t4. Bills    "                <<endl ;
            cout<<"\t\t\t\t\t\t\t\t0. Exit     "                <<endl ;
            cout<<'\n' ;
            cout<<'\n' ;

            cout<<"\t\t\t\t\t\t\t\tChoose Option : " ;
            input2 = getValidinput05(); 

            switch(input2){
                case 1 : {
                    // Patient Registeration Function Call 
                    recP( patients , psize ,bed) ;
                    break ;
                } 
                case 2 : {
                    // Appopinment Scheduling 
                    recA(appointments,doctors,dsize,maxAppointments,msg );
                    break ;
                }
                case 3 : {
                    // Bed Management 
                    beds(bed,psize,userType) ;
                    break ;
                }
                case 4 : { // Bills 
                    recB(patients,appointments,bed,psize,dsize,oneDay,appointment);

                    break ;
                }
                case 0 : {
                    cout<<"\t\t\t\t\t\t\t\tExiting ..." <<endl ;
                    break; 
                }
                default :{
                    cout<<"\t\t\t\t\t\t\t\tInvalid Input . Pleae Enter Valid Input (0-4)" <<endl ;
                    break ;
                   }
               

            }
            }while(input2 !=0); // Receptionist do while 
                   
 
              
       }
       // DOCTOR FUNCTIONALITIES 
       else if(userType == 3 ){
    
            do{  // doctor id 1 
               cout<<'\n' ; 
               cout<<"\t\t\t\t\t\t\t\t ====================="  <<endl ;
               cout<<"\t\t\t\t\t\t\t\t        DOCTOR        "  <<endl ;
               cout<<"\t\t\t\t\t\t\t\t ====================="  <<endl ;
               cout<<'\n' ;


               cout<<"\t\t\t\t\t\t\t\tChoose the Desired Option : " <<endl ;
               cout<<"\t\t\t\t\t\t\t\t1. Appointments"              <<endl ;
               cout<<"\t\t\t\t\t\t\t\t2. Patient Data     "         <<endl ; 
               cout<<"\t\t\t\t\t\t\t\t0. Exit             "         <<endl ;
               cout<<endl ;
               cout<<endl ;

               cout<<"\t\t\t\t\t\t\t\t Choose a option : " ;
               input3 = getValidinput012() ;  
               switch(input3){
                      case 1 : {
                        // Appointments 
                         docA(appointments,doctors,maxAppointments,doctorId ) ;
                         break ;
                      }
                      case 2 : {            
                         // pateint list ;
                         docP(appointments,maxAppointments,doctorId) ;  
                         break ;

                      }
                      case 0 : {
                        cout<<"\t\t\t\t\t\t\t\tExiting ..." <<endl ;
                        break ;
                      }
                      default : {
                        cout<<"\t\t\t\t\t\t\t\tInvalid Input !!" <<endl ;
                        break ;
                      }
               }

            }while(input3 != 0); // doctor do while
            }
            
      //  }
       else if(userType == -1){
            cout<<"\t\t\t\t\t\t\t\tYou have Entered Invalid Credentials!! " <<endl ;   
            getch() ;     
       }   

        


    }while(input!=0) ; // first do  while 

    return 0 ;
}

// FUNCTIONS 

void header(){
  

system("cls") ;  
cout<<"====================================================================================================================================================================================" <<endl;
cout<<"  _  _    ___    ___   ___   ___   _____     _     _        __  __     _     _  _     _      ___   ___   __  __   ___   _  _   _____     ___  __   __  ___   _____   ___   __  __ " <<endl ;
cout<<" | || |  / _ \\  / __| | _ \\ |_ _| |_   _|   /_\\   | |      |  \\/  |   /_\\   | \\| |   /_\\    / __| | __| |  \\/  | | __| | \\| | |_   _|   / __| \\ \\ / / / __| |_   _| | __| |  \\/  | " <<endl ; 
cout<<" | __ | | (_) | \\__ \\ |  _/  | |    | |    / _ \\  | |__    | |\\/| |  / _ \\  | .` |  / _ \\  | (_ | | _|  | |\\/| | | _|  | .` |   | |     \\__ \\  \\ V /  \\__ \\   | |   | _|  | |\\/| |" <<endl ;
cout<<" |_||_|  \\___/  |___/ |_|   |___|   |_|   /_/ \\_\\ |____|   |_|  |_| /_/ \\_\\ |_|\\_| /_/ \\_\\  \\___| |___| |_|  |_| |___| |_|\\_|   |_|     |___/   |_|   |___/   |_|   |___| |_|  |_|" <<endl ;
cout<<"====================================================================================================================================================================================" <<endl; 



cout<<endl ;   
cout<<endl ;   
cout<<endl ;                                                                                                                                                                                 

cout<<"\t\t\t\t\t\t\t\tChoose the Desired Option " <<endl ;
cout<<"\t\t\t\t\t\t\t\t1. Admin " <<endl ;
cout<<"\t\t\t\t\t\t\t\t2. Receptionist " <<endl ;
cout<<"\t\t\t\t\t\t\t\t3. Doctor " <<endl ;
cout<<"\t\t\t\t\t\t\t\t0. Exit " <<endl ;

cout<<"\t\t\t\t\t\t\t\tChoose an Option : " ; 
}

// Doctors Management By admin 

void adminD(int dsize,bool &msg,doctor doctors[]) {
     int input;
     string name , pwd , userName;
     cout<<'\n' ;
     cout<<"\t\t\t\t\t\t\t\t ====================="  <<endl ;
     cout<<"\t\t\t\t\t\t\t\t         ADMIN         "  <<endl ;
     cout<<"\t\t\t\t\t\t\t\t ====================="  <<endl ; 
     cout<<'\n' ;
     
     do{
     cout<<"\t\t\t\t\t\t\t\tChoose the Option : " <<endl ;
     cout<<"\t\t\t\t\t\t\t\t1. Add New Doctor    " <<endl ; 
     cout<<"\t\t\t\t\t\t\t\t2. Delete Doctor Record " <<endl ; 
     cout<<"\t\t\t\t\t\t\t\t3. Update Doctor Record " <<endl ;
     cout<<"\t\t\t\t\t\t\t\t4. Doctor's List " <<endl ;
     cout<<"\t\t\t\t\t\t\t\t0. Exit  " <<endl ;
     cout<<'\n' ;

     cout<<"\t\t\t\t\t\t\t\tChoose an option : "  ;
     input = getValidinput05() ;

     switch(input){
        case 1 :{   //ADD
          bool found = false ;
          for(int i = 0 ;i<dsize ; i++){
              if(! doctors[i].isDoc){
                 
                 cout<<"Enter Doctor's Name : " ;
                 getline(cin,doctors[i].name) ;

                 cout<<"Enter Doctor's Age : " ;
                 doctors[i].age = validAge();

                 cout<<"Enter Doctor's Gender (male/female) : " ;
                 doctors[i].gender = validGen() ; 

                 cout<<"Enter the specialization of the doctor :  " ;
                 getline(cin,doctors[i].category) ;                                  

                 cout<< "Assign UserName (Without Space) : " ;
                 doctors[i].userName  = uniqueDocUser(doctors ,dsize,false) ;
                 

                 cout<<"Assign password :  " ;
                 cin>> doctors[i].pwdD ;

                 doctors[i].idD = i+1 ;

                 doctors[i].isDoc = true ;
                 found = true ;
                 break ;
              }
          }
          found ? cout<<"\t\t\t\t\t\t\t\tSuccesfully Added! " : cout<<"\t\t\t\t\t\t\t\tCannot Add New Doctors Details.Space is full" ;
          cout<<endl ;
          cout<<endl ;
          saveDoctorsData(doctors, dsize) ;
          break ;
        }
        case 2 :{ // Delete
            bool found = false ;
            cout<<"\t\t\t\t\t\t\t\tEnter Doctor's UserName : " ;
            //cin.ignore(100,'\n') ;
            cin>>name ; ;

            for(int i = 0; i< dsize ; i++){
              if(name == doctors[i].userName && doctors[i].isDoc == true){
                doctors[i] = {"NV","NV","NV","NV","NV",-1,-1,false} ;
                found = true ; 
                msg = true ;
                break;
              }
            }
            found ? cout<<"\t\t\t\t\t\t\t\tDeleted Successfully!" : cout<<"\t\t\t\t\t\t\t\tName not Found !" ;
            saveDoctorsData(doctors, dsize) ;
            cout<<endl ;  
            cout<<endl ;
  
          break ;
        }
        case 3 :{ // Update 
             bool found = false ;
            cout<<"\t\t\t\t\t\t\t\tEnter Doctor's UserName : " ;
            cin>>name ;

            for(int i = 0; i< dsize ; i++){
              if(name == doctors[i].userName &&  doctors[i].isDoc == true) {

                 cout<<"Enter Doctor's Name : " ;
                 cin.ignore(100,'\n') ; 
                 getline(cin, doctors[i].name) ;

                 cout<<"Enter Doctor's Age : " ;
                 doctors[i].age = validAge();

                 cout<<"Enter Doctor's Gender (male/female) : " ;
                 doctors[i].gender = validGen() ;   

                 cout<<"Enter the specialization of the doctor :  " ;
                 getline(cin,doctors[i].category) ;                                 

                 cout<< "Assign UserName (Without Space) : " ;
                 doctors[i].userName  = uniqueDocUser(doctors ,dsize,true) ;

                 cout<<"Assign password :  " ;
                 cin>>  doctors[i].pwdD ;
                 msg = true ; 
                 found = true ;
                 break ;
              }
            }
            found ? cout<<"\t\t\t\t\t\t\t\tUpdated Successfully!" : cout<<"\t\t\t\t\t\t\t\tName not Found !!" ;
            saveDoctorsData(doctors, dsize) ;
            cout<<endl ; 
            cout<<endl ;

          break ;
        }
        case 4 :{ // list
          docList(doctors, dsize) ;   
          break ;
        }
        case 0 :{
          cout<<"\t\t\t\t\t\t\t\tExiting From Doctor's Section ." <<endl ;
          saveDoctorsData(doctors, dsize) ;
          break ;
        }
         default :{
            cout<<"\t\t\t\t\t\t\t\tInvalid Input . Pleae Enter Valid Input (0-4)" <<endl ;
            break  ;
         }                   
     }
     }while(input !=0) ;

}

// Receptionists Management by Admin

void adminR(receptionist recs[] , int rsize) {
     int input , counter = 0 ;
     string name , pwd ;
     cout<<'\n' ;
     cout<<"\t\t\t\t\t\t\t\t ====================="  <<endl ;
     cout<<"\t\t\t\t\t\t\t\t         ADMIN         "  <<endl ;
     cout<<"\t\t\t\t\t\t\t\t ====================="  <<endl ; 
     cout<<'\n' ;
     
     do{
     cout<<"\t\t\t\t\t\t\t\tChoose the Option : " <<endl ;
     cout<<"\t\t\t\t\t\t\t\t1. Add New Receptionist " <<endl ; 
     cout<<"\t\t\t\t\t\t\t\t2. Delete Receptionist Record " <<endl ; 
     cout<<"\t\t\t\t\t\t\t\t3. Update Receptionist Record " <<endl ;
     cout<<"\t\t\t\t\t\t\t\t4. Receptionist's List " <<endl ;
     cout<<"\t\t\t\t\t\t\t\t0. Exit  " <<endl ;
     cout<<'\n' ;

     cout<<"\t\t\t\t\t\t\t\tChoose an option : " <<endl ;
     input = getValidinput05() ;

     switch(input){
        case 1 :{ //ADD
            bool found = false ;
            for(int i = 0 ; i<rsize ; i++){
                if(recs[i].isRec == false){
                   cout<<"Enter Receptionist Name : " ;
                   getline(cin,recs[i].name ) ;

                   cout<<"Enter Receptionist Age : " ;
                   recs[i].age = validAge() ;    
                 
                   cout<<"Enter Receptionist Gender (male/female ):" ;
                   recs[i].gender = validGen() ; 

                   cout<<"tAssign Receptionist UserName (without space) : " ;
                   recs[i].userName = uniqueRecUser(recs,rsize,false);

                   cout<<"Assign Password :  " ;
                   cin>> recs[i].pwdR ;

                   recs[i].idR = i + 1 ;
                   recs[i].isRec = true ;
                   found = true ;
                   counter++ ;
                   break ; 
                }
            }
            found ? cout<<"\t\t\t\t\t\t\t\tSuccesfully Added " : cout<<"\t\t\t\t\t\t\t\tThere is no vacancy to add more receptionist " ;
            saveReceptionist(recs, rsize )  ;
            cout<<endl ;
            cout<<endl ;
          break ;
        }
        case 2 :{ // Delete
          bool found = false ;
          cout<<"\t\t\t\t\t\t\t\tEnter Receptionist's UserName : " ;
          cin>>name ;

            for(int i = 0; i< rsize ; i++){
              if(name == recs[i].userName && recs[i].isRec == true){
               recs[i] = {"NV","NV","NV","NV",-1,-1,false} ;
                found = true ; 
                counter-- ;
                break;
              }
            }
            found ? cout<<"\t\t\t\t\t\t\t\tDeleted Successfully!" : cout<<"\t\t\t\t\t\t\t\tName not Found !" ;
            saveReceptionist(recs, rsize )  ;
            cout<<endl ;   
            cout<<endl ; 
          break ;
        }
        case 3 :{
          // Update 
            bool found = false ;
            
            cout<<"\t\t\t\t\t\t\t\tEnter Receptionist's UserName : " ;
            cin>> name ;

            for(int i = 0; i< rsize ; i++){
              if( name == recs[i].userName &&  recs[i].isRec == true) {

                   cout<<"Enter Receptionist Name : " ;
                   cin.ignore() ;
                   getline(cin,recs[i].name ) ;

                   cout<<"Enter Receptionist Age : " ;
                   recs[i].age = validAge() ;    
                 
                   cout<<"Enter Receptionist Gender (male/female ):" ;
                   recs[i].gender = validGen() ; 

                   cout<<"Assign Receptionist UserName (without space) : " ;
                   recs[i].userName = uniqueRecUser(recs,rsize,true);

                   cout<<"tAssign Password :  " ;
                   cin>> recs[i].pwdR ;

                   found = true ;
                   break ; 
              }
            }
              found ? cout<<"\t\t\t\t\t\t\t\tUpdated Successfully!" : cout<<"\t\t\t\t\t\t\t\tName not Found !!"  ;
              saveReceptionist(recs, rsize )  ;
              cout<<endl ; 
              cout<<endl ;
            
          break ;
        }
         case 4 :{
          // List 
          bool found = false ;
           cout<<"==============================================================================================================================================" <<endl ;
           cout<<"No.of \t"<<"Rec's id \t" << " Rec's Name \t\t\t" <<" Rec's Age \t\t" << "Rec's Gender\t\t " << "Rec's UserName \t"<<"Rec's Password " <<endl ; 
           cout<<"==============================================================================================================================================" <<endl ;
          
          for(int i = 0 , j= 1 ; i<rsize ;i++){
               if(recs[i].isRec){
               cout<<left ;   
               cout<<setw(10) << j << setw(15) << recs[i].idR <<setw(32)<< recs[i].name  << setw(25) << recs[i].age <<setw(25) << recs[i].gender <<setw(30) << recs[i].userName << setw(25)<< recs[i].pwdR <<endl ;
               found = true ;   
               j++ ;
               }
          }
          if(!found)
             cout<<"\t\t\t\t\t\t\t\tNo Receptionists Available in Hospital . " <<endl; 
             cout<<endl ;
          break ;
        }
        case 0 :{
          cout<<"\t\t\t\t\t\t\t\tExiting From Receptionist's Section ." <<endl ;
          cout<<endl ;
          break ;
        }
         default :{
           cout<<"\t\t\t\t\t\t\t\tInvalid Input . Pleae Enter Valid Input (0-4)" <<endl ;          
                 break ;
          }
     }
     }while(input !=0) ;

}

//  Admin Function for Patients 

void adminP(doctor doctors[],patient patients[],appoint appointments[][5] ,int psize , int dsize ){
     int input;
     cout<<'\n' ;
     cout<<"\t\t\t\t\t\t\t\t ====================="  <<endl ;
     cout<<"\t\t\t\t\t\t\t\t         ADMIN         "  <<endl ;
     cout<<"\t\t\t\t\t\t\t\t ====================="  <<endl ; 
     cout<<'\n' ;
      
    
     
     do{
       cout<<"\t\t\t\t\t\t\t\tChoose the desired option : " <<endl;
       cout<<"\t\t\t\t\t\t\t\t1.Patients List admiited in Hospital." <<endl ;
       cout<<"\t\t\t\t\t\t\t\t2.Patient list regestered for appointments " <<endl ;
       cout<<"\t\t\t\t\t\t\t\t0.Exit " <<endl ;
       cout<<endl ;
       cout<<"\t\t\t\t\t\t\t\tChoose an option : " ;
       input = getValidinput012() ;

     switch (input) {
        case 1:{ // hospital patients 
          bool found = false ;
          cout<<"=======================================" <<endl;
          cout<<"           Patients  List "              <<endl ;
          cout<<"=======================================" <<endl ;
          cout<<"No.Of\t"<<"Patients Name "               <<endl ; 
          cout<<"=======================================" <<endl ; 
          for(int i = 0 , j= 1 ;i<psize ; i++){
             if(patients[i].isPatient == true ){
             cout<<j<<"\t"<< patients[i].name  <<endl ;
             j++ ;
             found = true ;                
             }
          }
          if(!found){
            cout<<"\t\t\t\t\t\t\t\tNo Patient is admitted  in Hospital ." <<endl ;
            cout<<endl ;
          }
        break ;
        }
        case 2:{  // appointments lists 
          appoinList(appointments,doctors,dsize) ;
          cout<<endl ;
            break;
        }   
        case 0:{
            cout << "\t\t\t\t\t\t\t\tExiting . " << endl;
            cout<<endl ;
            break;
        }
    }
     }while(input != 0);
}

// Beds Function of Admin 

void beds(bool bed[] , int psize , int userType){
     int counter = 0 ;

     switch(userType){

      case 1 : {
     cout<<'\n' ;
     cout<<" ====================="  <<endl ;
     cout<<"         ADMIN        "  <<endl ;
     cout<<" ====================="  <<endl ; 
     cout<<'\n' ;

     for(int i = 0 ; i<psize ; i++){
        if(bed[i] == true )
           counter++ ;  // Count the number of beds
    }
     cout<<"Number of Beds Occupied : " << counter <<endl ;
     cout<<endl ;
     }
     
     case 2 : {
       cout<<'\n' ;
     cout<<" ====================="  <<endl ;
     cout<<"     Receptionist       "  <<endl ;
     cout<<" ====================="  <<endl ; 
     cout<<'\n' ;

     for(int i = 0 ; i<psize ; i++){
        if(bed[i] == true )
           counter++ ;  // Count the number of beds
    }
     cout<<"Number of Beds Occupied : " << counter <<endl ;
     cout<<endl ;
     }
    }     
     }

/////////////   RECEPTIONIST

// Patients 

void recP(patient patients[] , int psize , bool bed[] ) {
     int input ;
     string name ;
     cout<<'\n' ;
     cout<<"\t\t\t\t\t\t\t\t ====================="  <<endl ;
     cout<<"\t\t\t\t\t\t\t\t     Receptionist         "  <<endl ;
     cout<<"\t\t\t\t\t\t\t\t ====================="  <<endl ; 
     cout<<'\n' ;
     
     do{
     cout<<"\t\t\t\t\t\t\t\tChoose the Option : " <<endl ;
     cout<<"\t\t\t\t\t\t\t\t1. Add New Patient " <<endl ; 
     cout<<"\t\t\t\t\t\t\t\t2. Delete Patient Record" <<endl ; 
     cout<<"\t\t\t\t\t\t\t\t3. Update Patient Record " <<endl ;
     cout<<"\t\t\t\t\t\t\t\t4. Patient's List " <<endl ;
     cout<<"\t\t\t\t\t\t\t\t0. Exit  " <<endl ;
     cout<<'\n' ;

     cout<<"\t\t\t\t\t\t\t\tChoose an option : " <<endl ;
     input = getValidinput05() ;

     switch(input){
        case 1 :{  // adding data of new patient
            bool found = false ;
            for(int i = 0 ; i<psize ; i++){
                if(patients[i].isPatient == false){
                  cout<<"Enter Patient's Name : " ;
                  getline(cin,patients[i].name ) ;

                  cout<<"Enter Patient's age :  " ;
                  patients[i].age = validAge() ;

                  cout<<"Enter Gender(male/female) : " ;
                  patients[i].gender = validGen() ;

                  cout<<"Enter Disease : " ;
                  cin>> patients[i].disease ;

                  patients[i].idP = i + 1 ;
                  patients[i].isPatient = true ;
                  bed[i] = true ;
                  found = true ;

                  break ; 
                }
            }
            savePatientData(patients,psize) ;
            found ? cout<<"\t\t\t\t\t\t\t\tSuccesfully Added " : cout<<"\t\t\t\t\t\t\t\tThere is no space to add more Patients " ;
            cout<<endl ;
            cout<<endl ;
               
          break ;
        }
        case 2 :{
          // Delete data of patients
          bool found = false ;
          int id ;
          cout<<"\t\t\t\t\t\t\t\tEnter Patient's ID to delete his/her record : " ;
          id = getInt() ;

            for(int i = 0; i< psize ; i++){
              if(id == patients[i].idP &&  patients[i].isPatient == true){
               patients[i] = {"NV","NV","NV",-1,-1,false} ;  
                found = true ; 
                break;
              }
            }
          savePatientData(patients,psize) ;
            found ? cout<<"\t\t\t\t\t\t\t\tDeleted Successfully!" : cout<<"\t\t\t\t\t\t\t\tName not Found !" ;
            cout<<endl ;  
            cout<<endl ;  
          break ;
        }
        case 3 :{
          // Update  data of patients
            int id ;
            bool found = false ;
            cout<<"Enter Patient's ID to Update his/her record :  " ;
            id = getInt() ;

            for(int i = 0; i< psize ; i++){
              if(id == patients[i].idP && patients[i].isPatient == true) {
                cout<<"Enter Patient's Name : " ;
                cin.ignore();
                getline(cin,patients[i].name ) ;

                cout<<"Enter Patient's age :  " ;
                patients[i].age = validAge() ;

                cout<<"Enter Gender(male/female) : " ;
                patients[i].gender = validGen() ;

                cout<<"Enter Disease : " ;
                cin>> patients[i].disease ;

                found = true ;
                break;
              }
            }
          savePatientData(patients,psize) ;
           found ? cout<<"Updated Successfully!" : cout<<"Name not Found !!" ;
            cout<<endl ; 
            cout<<endl ;
          break ;
        }
        case 4 :{
          // List  of All patients
           bool found = false ;
          cout<<"=========================================================================================================" <<endl ;
          cout<< "No.of \t"<<"Patient's id \t" << " Patient's Name \t\t" << "Patient's Age\t\t" <<"Gender \t\t"<<"Disease" <<endl ; 
          cout<<"=========================================================================================================" <<endl ;
          
          for(int i = 0,j=1 ; i<psize ;i++){
             if(patients[i].isPatient){
              cout<<left ;  
              cout<< setw(10)<< j << setw(20) <<patients[i].idP << setw(30) << patients[i].name << setw(20) <<patients[i].age  <<setw(16) <<  patients[i].gender << setw(30)<<patients[i].disease<<endl ;
              found = true ;
              j++ ;   
             }
          }
          if(!found)
             cout<<"\t\t\t\t\t\t\t\tNo Patients Available in Hospital . " <<endl; 
             cout<<endl ;
          break ;
        }
       
        case 0 :{
          cout<<"\t\t\t\t\t\t\t\tExiting From Patient's Section ." <<endl ;
          cout<<endl ;
          savePatientData(patients,psize) ;
          break ;
        }
         default :{
           cout<<"\t\t\t\t\t\t\t\tInvalid Input . Pleae Enter Valid Input (0-4)" <<endl ;
           break ;       
           }
     }
     }while(input !=0) ;

}

// Appointments 
void recA(appoint appointments[][5], doctor doctors[], int dsize, int maxAppointments, bool &msg) {
    int input, inputIdD;
    cout << '\n';
    cout << "\t\t\t\t\t\t\t\t =====================" << endl;
    cout << "\t\t\t\t\t\t\t\t     Receptionist         " << endl;
    cout << "\t\t\t\t\t\t\t\t =====================" << endl;
    cout << '\n';

    if (msg) {
        cout<<"\t\t\t\t\t\t\t\t**************************************************************************************" <<endl ;
        cout << "\t\t\t\t\t\t\t\tDoctor's Record has been updated. Please update the appointments." ;
        cout<<"\t\t\t\t\t\t\t\t**************************************************************************************" <<endl ;
        cout<<endl ;
    }

    do {
        cout << "\t\t\t\t\t\t\t\tChoose the Option: " << endl;
        cout << "\t\t\t\t\t\t\t\t1. New Appointment  " << endl;
        cout << "\t\t\t\t\t\t\t\t2. Delete Appointment  " << endl;
        cout << "\t\t\t\t\t\t\t\t3. Update Appointment " << endl;
        cout << "\t\t\t\t\t\t\t\t4. Appointments List   " << endl;
        cout << "\t\t\t\t\t\t\t\t5. Doctor's List  " << endl;
        cout << "\t\t\t\t\t\t\t\t0. Exit   " << endl;
        cout << '\n';

        cout << "\t\t\t\t\t\t\t\tChoose an option: ";
        input = getValidinput05();
        cout << endl;

        switch (input) {
            case 1: { // New Appointment
                bool found = false;
                docListA(doctors, dsize); // Display the list of doctors
                cout << endl;

                cout << "\t\t\t\t\t\t\t\tEnter the ID of the doctor you want to select for the appointment: ";
                inputIdD = getValidinput123();
                inputIdD -= 1; // Adjust for zero-based indexing

                for (int j = 0; j < maxAppointments; j++) {
                    if (!appointments[inputIdD][j].isConfirmed) {
                        cout << "Enter Patient Name: ";
                        getline(cin, appointments[inputIdD][j].name);

                        cout<<"Enter Patient's Age : " ;
                        appointments[inputIdD][j].age = validAge() ;

                        cout << "Enter Gender (male/female): ";
                        appointments[inputIdD][j].gender = validGen();

                        cout << "Enter Disease: ";
                        cin.ignore() ;
                        getline(cin, appointments[inputIdD][j].disease);

                        cout << "Enter appointment date (dd-mm-yyyy): ";
                        appointments[inputIdD][j].date = validDate(appointments,inputIdD,maxAppointments,false);

                        appointments[inputIdD][j].idA = j + 1; // Unique ID
                        appointments[inputIdD][j].isConfirmed = true;
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "\t\t\t\t\t\t\t\tAppointments are full. Cannot set new appointments." << endl;
                }
                saveAppointments(appointments,doctors,maxAppointments,dsize) ;  
                break;
            }
            case 2: { // Delete Appointment
                bool found = false;
                int id;
                cout << "\t\t\t\t\t\t\t\tEnter Patient ID to delete their appointment: ";
                id = getInt();

                cout << "\t\t\t\t\t\t\t\tEnter Doctor's ID: ";
                inputIdD = getValidinput123();
                inputIdD -= 1;

                for (int j = 0; j < maxAppointments; j++) {
                    if (appointments[inputIdD][j].idA == id && appointments[inputIdD][j].isConfirmed) {
                        appointments[inputIdD][j] = {"NV", "NV", "NV", "NV", -1,-1, false};
                        cout << "\t\t\t\t\t\t\t\tAppointment deleted successfully." << endl;
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "\t\t\t\t\t\t\t\tAppointment not found for the given ID." << endl;
                }
                saveAppointments(appointments,doctors,maxAppointments,dsize) ; 
                break;
            }
            case 3: { // Update Appointment
                bool found = false;
                int id;
                cout << "\t\t\t\t\t\t\t\tEnter Patient ID to update their appointment: ";
                id = getInt();

                cout << "\t\t\t\t\t\t\t\tEnter Doctor's ID: ";
                inputIdD = getValidinput123();
                inputIdD -= 1;

                for (int j = 0; j < maxAppointments; j++) {
                    if (appointments[inputIdD][j].idA == id && appointments[inputIdD][j].isConfirmed) {
                        cout << "Enter Updated Patient Name: ";
                        getline(cin, appointments[inputIdD][j].name);

                        cout<<"Enter Patient's Age : " ;
                        appointments[inputIdD][j].age = validAge() ;

                        cout << "Enter Updated Gender (male/female): ";
                        appointments[inputIdD][j].gender = validGen();

                        cout << "Enter Updated Disease: ";
                        cin.ignore() ;
                        getline(cin, appointments[inputIdD][j].disease);

                        cout << "Current Appointment Date: " << appointments[inputIdD][j].date << endl;
                        cout << "Enter Updated Appointment Date: ";
                        appointments[inputIdD][j].date = validDate(appointments,inputIdD,maxAppointments,true);

                        found = true;
                        break;
                    }
                }
                
                if (!found) {
                    cout << "\t\t\t\t\t\t\t\tAppointment not found for the given ID." << endl;
                }
                saveAppointments(appointments,doctors,maxAppointments,dsize) ; 
                break;
            }
            case 4: { // Appointments List
               bool found1 = false ;
          bool found2 = false ;
          cout<<"\t\t\t\t\t\t\t\t Enter Doctor's ID to check thier list " ;
          inputIdD = getValidinput123() ;
          inputIdD = inputIdD -1 ;

          cout<<"==============================================" <<endl ; 
          cout<< " Doctor's ID\t\t"<< "Doctor's Name  " <<endl  ;
          cout<<"==============================================" <<endl ;
      
             if(doctors[inputIdD].isDoc == true ){             
             cout<<doctors[inputIdD].idD <<"\t\t\t" << doctors[inputIdD].name << endl ; 
             found1 = true ;
             cout<<endl ;
             cout<<endl ;
             cout<<endl ;
             }
             if(found1){
              cout<<"===========================================================================" <<endl ;
              cout<<left ;
              cout<<setw(20)<< "Patient's Id" <<setw(30) <<"Patient's Name "<< "Appointments" <<endl ;
              cout<<"===========================================================================" <<endl ;
             
             
             for(int j= 0 ;j<maxAppointments ; j++){
             if(appointments[inputIdD][j].isConfirmed == true){
             cout<<left ; 
             cout<<setw(20)<<  appointments[inputIdD][j].idA <<setw(30) <<appointments[inputIdD][j].name << appointments[inputIdD][j].date <<endl;
             found2 = true ;
             }
            }
            }

           if(!found1){
              cout<<"\t\t\t\t\t\t\t\tNo Doctors Have been added yet By Admin ! "<<endl ;
              cout<<endl ;
           }
           if(found1){
           if(!found2){
              cout<<"\t\t\t\t\t\t\t\tThis Doctor has no appointments Scheduled.!" <<endl ;
              cout<<endl ;
           }
           }
          break ;
            }
            case 5: { // Doctor's List
                docListA(doctors, dsize);
                break;
            }
            case 0:
                cout << "Exiting Appointment Section." << endl;
                saveAppointments(appointments,doctors,maxAppointments,dsize) ; 
                break;
            default:
                cout << "Invalid input. Please try again." << endl;
                break;
        }
    } while (input != 0);
}
    

// Bills 
void recB(patient patients[],appoint appointments[][5],bool bed[], int psize, int dsize,int oneDay, int appointment ){
     int input , bill ,days , id , idD;
     
     cout<<'\n' ;
     cout<<"\t\t\t\t\t\t\t\t ====================="  <<endl ;
     cout<<"\t\t\t\t\t\t\t\t     Receptionist         "  <<endl ;
     cout<<"\t\t\t\t\t\t\t\t ====================="  <<endl ; 
     cout<<'\n' ; 
    
    do{
    cout<<"\t\t\t\t\t\t\t\t=========================================="<<endl ;
    cout<<"\t\t\t\t\t\t\t\t        Receptionist Billing Menu:" <<endl  ;
    cout<<"\t\t\t\t\t\t\t\t=========================================="<<endl ;
    cout << "\t\t\t\t\t\t\t\t1. Bill for Admitted Patients" << endl ;
    cout << "\t\t\t\t\t\t\t\t2. Bill for Appointment Patients" << endl;
    cout << "\t\t\t\t\t\t\t\t0. Exit "                          <<endl ;
    cout << "\t\t\t\t\t\t\t\tEnter your choice: ";
    input = getValidinput012();

    switch(input){
       case 1 : {
              bool found1 = false ;
             // Billing for Admitted Patients
            cout << "\t\t\t\t\t\t\t\tEnter Patient Id  for Admitted Patient Billing: ";
            cin >> id; 

            for (int i = 0 ; i < psize; i++) {
                if (patients[i].idP == id  && bed[i]) {
                    cout << "Enter number of days patient stayed: ";
                    days = getInt() ;
                    bill = days * oneDay;
                    cout << "Patient Name: " << patients[i].name << endl;
                    cout << "Number of Days: " << days << endl;
                    cout << "Total Bill (Admitted): " << bill << " Rs" << endl;
                    found1 = true;
                    break;
                }
            }

            if (!found1) {
                cout << "\t\t\t\t\t\t\t\tPatient not found or not admitted." << endl <<endl ;
            }
            break;
       }            
             case 2:{
             bool found2 = false ; 
            // Billing for Appointment Patients
            cout << "\t\t\t\t\t\t\t\tEnter Patient Id  for Appointment Billing: ";
            cin >> id ;
            cout<<"\t\t\t\t\t\t\t\tEnter Patient's Doctor Id (1-3)  : " ;
            idD = getValidinput123() ;
            idD = idD - 1 ;
            
            
                for (int j = 0; j < 5; j++) {
                    if (appointments[idD][j].isConfirmed == true && id == appointments[idD][j].idA) {
                        bill = appointment; 
                        cout << "Patient Name: " << appointments[idD][j].name << endl;
                        cout << "Total Bill (Appointment): " << bill << " Rs" << endl;
                        found2 = true;
                        break;
                    }
                }
          
            if (!found2) {
                cout << "\t\t\t\t\t\t\t\tPatient not found or no appointment record." << endl <<endl ;
            }
            break;
            }
            case 0 :{
              cout<<"\t\t\t\t\t\t\t\tExiting from Billing Section .." <<endl <<endl ;
              break ;
            }

    }
     

}while(input != 0 ) ;
}

// Doctor  1  Patients Details

void docP(appoint appointments[][5],int maxAppointments,int docId){
      docId = docId - 1 ;
      bool found = false ; 
      int id ;
      cout<<'\n' ; 
      cout<<"\t\t\t\t\t\t\t\t ====================="  <<endl ;
      cout<<"\t\t\t\t\t\t\t\t        DOCTOR        "  <<endl ;
      cout<<"\t\t\t\t\t\t\t\t ====================="  <<endl ;
      cout<<'\n' ; 
      cout<<"\t\t\t\t\t\t\t\tEnter Patient ID to see thier details : "  ;
      id =getInt() ;   

      cout<<"======================================================================================================="<<endl ; 
      cout<<"Patient's Id \t"<<" Patient's Name \t\t"<<"  Patient's Age\t\t"<<"Gender\t\t"<<" Disease" <<endl;
      cout<<"======================================================================================================="<<endl ; 
      for(int j= 0 ;j<maxAppointments ;j++){
         if(appointments[docId][j].isConfirmed == true && id == appointments[docId][j].idA){
          cout<<left ;  
          cout<<setw(20)<<appointments[docId][j].idA <<setw(30) <<appointments[docId][j].name<<setw(20)<<appointments[docId][j].age 
          <<setw(20)<<appointments[docId][j].gender<<setw(30)<<appointments[docId][j].disease  <<endl ;
          found = true ;
         }
      }   
      if(!found){
        cout<<"\t\t\t\t\t\t\t\tNo Data!!" <<endl <<endl ;
      }

      
}
// Doctor  1  Appointments lista
void docA(appoint appointments[][5],doctor doctors[] ,  int maxAppointments,int docId){
     docId = docId - 1 ;
     cout<<'\n' ; 
     cout<<"\t\t\t\t\t\t\t\t ====================="  <<endl ;
     cout<<"\t\t\t\t\t\t\t\t        DOCTOR        "  <<endl ;
     cout<<"\t\t\t\t\t\t\t\t ====================="  <<endl ;
     cout<<'\n' ;      
     
     bool found1 = false ;
     bool found2 = false ;
     
     cout<<"==============================================" <<endl ; 
     cout<<"Doctor's ID\t\t"<< "Doctor' Name \t" <<endl  ;
     cout<<"==============================================" <<endl ;
   
     if( doctors [docId].isDoc == true ){
             
     cout<<doctors [docId].idD <<"\t\t\t" << "Dr. "<< doctors [docId].name << endl ; 
            
     found1 = true ;
     }
     if(found1){
        cout<<"=====================================================================" <<endl ;
        cout<<"Patient's Id \t"<<"Patient's Name \t\t"<< "          Appointments" <<endl ;
        cout<<"=====================================================================" <<endl ;
        }
             
      for(int j= 0 ;j<maxAppointments ; j++){
         if(appointments[docId][j].isConfirmed == true){
            cout<<left ;
            cout<<setw(20)<<appointments[docId][j].idA<< setw(30) <<appointments[docId][j].name <<appointments[docId][j].date <<endl;
            found2 = true ;
            }
          }
          if(!found1){
              cout<<"\t\t\t\t\t\t\t\tNo Doctors Have been added yet By Admin ! "<<endl <<endl ;
          }
          if(!found2){
              cout<<"\t\t\t\t\t\t\t\tThis Doctor has no appointments Scheduled.!" <<endl  <<endl ;
         }
    

}
// Doctors List 
void docList(doctor doctors[] , int dsize){
     bool found = false ;
     cout<<"============================================================================================================================================================================================" <<endl ;
     cout<<"No.of \t"<<"Doctor's id \t" << " Doctor's Name \t\t" <<"Doctor's Age \t" << "Doctor's Gender\t "<< "  Doctor's Specialization \t" << "Doctor's UserName \t"<<"Doctor's Password " <<endl ; 
     cout<<"============================================================================================================================================================================================" <<endl ;
          
     for(int i = 0 , j= 1 ; i<dsize ;i++){
         if(doctors[i].isDoc){
         cout<<left ;   
         cout<<setw(10) << j << setw(15) << doctors[i].idD <<setw(25)<<  doctors[i].name << setw(18) << doctors[i].age <<setw(18) << doctors[i].gender<<setw(27)<<doctors[i].category<< setw(24) <<doctors[i].userName<< setw(18)<< doctors[i].pwdD <<endl ;
         found = true ;   
         j++ ;
         }
      }
     if(!found)
     cout<<"\t\t\t\t\t\t\t\tNo Doctors Available in Hospital . " <<endl <<endl ;  
}

//Doctors to be represented in Appointments Section
void docListA(doctor doctors[] , int dsize ){
     bool found = false ;
     cout<<"======================================================================================" <<endl ;
     cout<<"No.of \t"  <<"Doctor's id \t" << "     Doctor's Name \t" << "           Doctor's Specializion "  <<endl ; 
     cout<<"======================================================================================" <<endl ;
          
     for(int i = 0 , j= 1 ; i<dsize ;i++){
         if(doctors[i].isDoc){
         cout<<left ;
         cout<<setw(10) << j <<setw(20) << doctors[i].idD  << setw(30) <<"Dr. " + doctors[i].name << doctors[i].category <<endl ;
         found = true ;   
         j++ ;
         }
      }
     if(!found)
     cout<<"\t\t\t\t\t\t\t\tNo Doctors Available in Hospital . " <<endl <<endl  ;  
}

void appoinList( appoint appointments[][5],doctor doctors[] ,int dsize){

     int inputIdD ;
     bool found1 = false ;
     bool found2 = false ;
     cout<<"\t\t\t\t\t\t\t\t Enter Doctor's ID to check thier list " ;
     inputIdD =  getValidinput123() ;
     inputIdD = inputIdD -1 ;

     cout<<"==============================================" <<endl ; 
     cout<<"Doctor's ID\t\t"<< "Doctor' Name \t" <<endl  ;
     cout<<"==============================================" <<endl ;

          
          
     if(doctors[inputIdD].isDoc == true ){
             
     cout<<doctors[inputIdD].idD <<"\t\t\t" << doctors[inputIdD].name << endl ; 
            
     found1 = true ;
     }
     if(found1){
        cout<<"==============================================" <<endl ;
        cout<<"Patient's Name \t\t"<< "Appointments" <<endl ;
        cout<<"==============================================" <<endl ;
        }
             
      for(int j= 0 ;j<dsize ; j++){
         if(appointments[inputIdD][j].isConfirmed == true){
            cout<<appointments[inputIdD][j].name <<"\t\t\t"<<appointments[inputIdD][j].date <<endl;
            found2 = true ;
            }
          }
          if(!found1){
              cout<<"No Doctors Have been added yet By Admin ! "<<endl <<endl  ;
          }
          if(!found2){
              cout<<"This Doctor has no appointments Scheduled.!" <<endl  <<endl ;
         }
    
}

// VALIDATIONS 

// 012 
int getValidinput012(){
    int num ;
    string input ;
    bool isNumber = false ;

    while(isNumber == false){
    cout<<"\t" ;
    cin>>input ;
    cin.ignore(100,'\n') ;
   
    if((input[0]=='0' || input[0] =='1'|| input[0] =='2' ) && input[1] ==  '\0' ){
         num = input[0] - '0' ;
         isNumber = true  ;
         return num ;
         break ;
    }
    else {
         cout<<"\t\t\t\tInvalid input " <<endl ;  
    }
     
    
  }
}

// it will assure that input is from 0 to 3
int getValidinput0123(){
    int num ;
    string input ;
    bool isNumber = false ;

    while(isNumber == false){
    cout<<"\t" ;
    cin>>input ;
    cin.ignore(100,'\n') ;
     
    if (cin.fail()) {
      cin.clear();
      cout << "\t\t\t\t\t\t\t\tInvalid input. Please try again." << endl;
    }
    else if((input[0]=='0' || input[0] =='1'|| input[0] =='2' || input[0] == '3') && input[1] ==  '\0' ){
         num = input[0] - '0' ;
         isNumber = true  ;
         return num ;
         break ;
    }
    else {
         cout<<"\t\t\t\t\t\t\t\tInvalid input . Please try again. " <<endl ;  
    }
     
    
  }
}

// it will assure that input is from 0 to 5
int getValidinput05(){
    int num ;
    string input ;
    bool isNumber = false ;

    while(isNumber == false){
    cout<<"\t" ;
    cin>>input ;
    cin.ignore(100,'\n') ;

       if((input[0]>='0' && input[0] <='5') && input[1] == '\0' ){
         num = input[0] - '0' ;
         isNumber = true ;
         return num ;
         break ;
       }
       else {
         cout<<"\t\t\t\tInvalid Input ." <<endl ;
       }
     
   
  }
}

// it will assure that input is from 1 to 3
int getValidinput123(){
    int num ;
    string input ;
    bool isNumber = false ;

    while(isNumber == false){
    cout<<"\t" ;
    cin>>input ;
    cin.ignore(100,'\n') ;
   
    if(( input[0] =='1'|| input[0] =='2' || input[0] == '3') && input[1] ==  '\0' ){
         num = input[0] - '0' ;
         isNumber = true  ;
         return num ;
         break ;
    }
    else {
         cout<<"\t\t\t\tInvalid Input.Enter ID (1,2,3): " <<endl ;  
    }
     
    
  }
}

// Ensuring that the user enter male or female
string validGen(){
      bool isGender = false ;
      string gender ;
    
      while(!isGender){
          cin>>gender ;
           for(int i =0 ; i<gender.length() ; i++){
             gender[i] = toupper(gender[i]) ;
           }

          if(gender == "MALE" || gender == "FEMALE" ){
             isGender = true ;   
             return gender ;
          }
          else {
            cout<<"Invalid Input .. Enter (male or female): " <<endl ;
          }

      }
}

// Ensure that tha user Enter reality base age
int validAge(){
    int  age ;

    while(true){
        cin>> age ;   
         if(cin.fail()){
          cin.clear()  ;
          cin.ignore(1000 , '\n') ;
          cout<<"Invalid Input . "<<endl ;
         }
         else {
            if(age > 0 && age < 150 ){
              return age ;
            }
            else{
              cout<< " Age exceeds the valid range. Please enter a realistic age :  "<<endl ;
            }
         }
    }
}

// to convert the string value to integer in date to specify the range 
int toInt(const string &str , int st , int end ){
    int result = 0 ;
    for(int i = st ; i< end ; i++){
        if(! (str[i] >= '0' && str[i] <= '9')  ){
           return -1 ;
        }
        result = result* 10 + (str[i] - '0') ;
    }
    return result ;
}


//Ensure that the user enter valid date in correct format
string validDate(appoint appointments[][5], int inputidD, int maxAppointments,bool update) {
       string date ;
       int daysinMon[] = {31,28,31,30,31,30,31,31,30,31,30,31} ;
       bool dateFound = false ;

       while(true){
            cin>> date ;
            dateFound = false ;
            if(date.length() != 10 || date[2] != '-' || date[5] != '-' ){
              cout<<"Invalid Date input. Please use dd-mm-yyyy : "<<endl ;
              continue; 
            }

            int day = toInt(date , 0 , 2 ) ;
            int month = toInt(date , 3 , 5 ) ;
            int year  = toInt(date,6 , 10 ) ;

            if(year < 2024 ){
               cout<<"INvalid year. Please try Again . " <<endl ;  
               continue;    
            }
            
            if(day == -1 || month == -1 || year == -1 ){
              cout<<"Invalid values in Date . Please try Again . " <<endl ;
              continue; 
            }

            if( !(month >= 1 && month <=12 ) ){
               cout<<"Invalid month. Please try again. "<<endl ;
               continue; 
            }
            
             daysinMon[1] = 28;
            // check leap year 
             if(year % 4 == 0){
               daysinMon[1] = 29 ;
             }

             if( !(day >=1 && day <= daysinMon[month - 1] ) ){
                cout<<"Invalid Day . Please try again.  " <<endl ;
                continue; 
             }

             // loop to check whether the date is already scheduled or not
             if(!update){   
            //  in updation this will not  check whether date exist or not but in new apppointment it will check the
            // dates to avoid collision 
             for(int j =0; j<maxAppointments ; j++){
                if(date == appointments[inputidD][j].date){
                  cout<<"This date is already scheduled . So please select other date ." <<endl ;
                  dateFound = true ;
                  break;                
                  }
             }  
             if(dateFound) continue;
             } 

             return date ;
       }
} 


string uniqueRecUser(receptionist recs[],int rsize,bool update ){
      string userName ;
      bool isUnique = true ;
      
      
      while(isUnique){ 
      bool space = false ;   
      cin.ignore() ;  
      getline(cin,userName) ;
      
      for(int i = 0 ; i< userName.length() ; i++){ // checking for space in userName
         if(userName[i] == static_cast<char> (32)){
           cout<<"Username cannot contain space. Enter Again : " <<endl ;
           space = true ;
         }
      }
      if(space) continue; 
      
      if(!update){ 
      // if update is true means updation process is going and same userName can be used
      // if it is false then a new userName will be assigned which will not a duplicate one  
      for(int i = 0 ; i<rsize ; i++){
        if(userName == recs[i].userName){
           isUnique = false ; 
           break ;       
        }
      }
      if(isUnique) {
        return userName ;
        break ;
      }
      else {
        cout<<"This Username already exist . Enter Again : " ;
        isUnique = true ;
      }
      }
      else return userName ;

      }
    
}

// This Function will ensure that that Doctor userName is specific

string uniqueDocUser(doctor doctors[] , int dsize,bool update ){
      string userName ;
      bool isUnique = true ;
      
      while(isUnique){ 
      bool space = false ;  
      cin.ignore() ;  
      getline(cin,userName)  ;

      for(int i = 0 ; i< userName.length() ; i++){ // checking for space in username
         if(userName[i] == static_cast<char> (32)){
           cout<<"Username cannot contain space. Enter Again : " <<endl ;
           space =true ; 
           break; 
         }
      }
      
      if(space) continue; 
      
      if(!update){
      // if update is true means updation process is going and same userName can be used
      // if it is false then a new userName will be assigned which will not a duplicate one    
      for(int i = 0 ; i<dsize ; i++){
        if(userName == doctors[i].userName){
           isUnique = false ; 
           break ;       
        }
      }
      if(isUnique) 
        return userName ;
      else {
        cout<<"This Username already exist . Enter Again : " ;
        isUnique = true ;
      }
      }
      else return userName ;

      } 
      }
      // it will ensure that user enters only numeric value
int getInt(){
   int  input ;
   bool isInt = false ;
   while(!isInt){
    cin>>input ;
   if(cin.fail()){
     cin.clear() ;
     cin.ignore() ;
     cout<<"Invalid Input . Enter Number Input :  " <<endl ;
   }
   else if(input >= 0 ){
     return input ;
   }  
   }
}

    //    SAVING AND LOADING FUNCTIONS 
// Save Patient Data
void savePatientData(patient patients[] ,  int psize){

     ofstream data ;
     data.open("patients.txt") ;   
     if(data.is_open()){
       for(int i= 0 ; i<psize ; i++){
           if(patients[i].isPatient == true){
              data<< patients[i].idP << "," <<patients[i].name << "," << patients[i].age<< ","
               << patients[i].gender << "," << patients[i].disease <<endl ; 
           }
       }
       data.close() ;
     }
     else {
       cout<<"Failed to open Patients Files !! " <<endl ;
     }   

}
// Save Appointments
void saveAppointments(appoint appointments[][5] ,doctor doctors[] , int maxAppointments,int dsize ){

     ofstream data ;
     data.open("appointments.txt") ;
     if(data.is_open()){
      for(int i = 0 ; i<dsize ; i++){
        for(int j = 0 ; j< maxAppointments ; j++){
          if(appointments[i][j].isConfirmed  )
            data << i+1 << "," << doctors[i].name <<","<<appointments[i][j].idA <<"," <<appointments[i][j].name << "," << appointments[i][j].age <<","<<appointments[i][j].gender <<"," <<appointments[i][j].disease  << ","<<appointments[i][j].date  <<endl ; 
           }
      } 
           data.close() ;
      }
     else{
      cout<<"Failed to open appointments file !! " <<endl ;
     }

}
// save Doctors data
void saveDoctorsData(doctor doctors[] ,int dsize){
      ofstream data ;
      data.open("doctor.txt") ;
      if(data.is_open()){
        for(int i = 0 ; i< dsize ; i++){
           if(doctors[i].isDoc  == true){
             data<< doctors[i].idD <<"," << doctors[i].name <<","<< doctors[i].age<<","<<doctors[i].gender<<","
             << doctors[i].category <<","<<doctors[i].userName<<"," <<doctors[i].pwdD <<endl ;
           } 
        }
        data.close() ;
      }
      else{
        cout<<"Unable to open receptionist file. "<<endl ;
      }
}
// save receptionist data
void saveReceptionist(receptionist recs[], int rsize){
    ofstream data ;
    data.open("receptionist.txt") ;
    if(data.is_open()){
      for(int i= 0; i<rsize ; i++){
         if(recs[i].isRec){
          data<< recs[i].idR <<","<< recs[i].name <<","<<recs[i].age<<","<<recs[i].gender<<","<< recs[i].userName <<","<< recs[i].pwdR <<endl ;
         }
      }
      data.close() ; 
    }
    else{
      cout<<"Unable to open Receptionist File. "<<endl ;
    }
}
// load receptionist data

void loadReceptionistData(receptionist recs[], int rsize){
     ifstream load ;
     load.open("receptionist.txt") ;
     if(load.is_open()){
     for(int i = 0 ;i< rsize ; i++){

        load>> recs[i].idR ;
        load.ignore() ;
        if( getline(load,recs[i].name,',') 
            && load >> recs[i].age
            && load.ignore() 
            && getline(load,recs[i].gender , ',')
            && getline(load,recs[i].userName,',' )
            && getline(load,recs[i].pwdR)){

            recs[i].isRec = true ;
        }
        else break ;
        
     }
     load.close() ;
     }
     else {
      cout<<"Unable to load receptionist Data !!" <<endl ;
     }
}

// load Doctor's Data

void loadDoctorData(doctor doctors[] ,int dsize){
     ifstream load ;
     load.open("doctor.txt") ;
     if(load.is_open()){
     for(int i = 0 ;i< dsize ; i++){

        load>> doctors[i].idD ;
        load.ignore() ;

        if( getline(load, doctors[i].name,',') 
            && load >>  doctors[i].age
            && load.ignore() 
            && getline(load,doctors[i].gender ,',')
            && getline(load,doctors[i].category,',') 
            && getline(load,doctors[i].userName,',') 
            && getline(load,doctors[i].pwdD  ) ){

           doctors[i].isDoc  = true ;

        }
        else{ 
         break ;
        }
        
     }
     load.close() ;
     }
     else {
      cout<<"Unable to load Doctor Data !!" <<endl ;
     }
}

// load patient data
void loadPatientData(patient patients[] ,  int psize , bool bed[]){
    ifstream load ;
    load.open("patients.txt") ;
    if(load.is_open()){
      for(int i = 0; i<psize ; i++){
         load>> patients[i].idP  ;
         load.ignore() ;

         if(
         getline(load,patients[i].name ,',') && 
         load>>patients[i].age  &&
         load.ignore()  && 
         getline(load,patients[i].gender,',') && 
         getline(load,patients[i].disease ) ){
         patients[i].isPatient = true ;
         bed[i] = true ;

         }
         else {
           break ;
         } 
         
      }
      load.close() ;
    }
    else{
      cout<<"Failed to load Patients Data !!" <<endl ;
    }
}
//load appointments Data

void loadAppointments(appoint appointments[][5]  , int maxAppointments,int dsize ) {
    ifstream load("appointments.txt");
    if (load.is_open()) {
        string line;
        while (getline(load, line)) {
            stringstream d(line) ;
            int Id;
            string tempN;

            d >> Id;  
            d.ignore(); 
            Id = Id - 1; 

            if (!getline(d, tempN, ',')) break; 

            for (int j = 0; j < maxAppointments; j++) {
                if (!appointments[Id][j].isConfirmed  ) {
                    string patient , gender , date , disease ;
                    int age ,patientId ;  

                    if (d >> patientId  &&
                        d.ignore()   && 
                        getline(d, patient , ',') &&
                        d >> age  &&
                        d.ignore() &&  
                        getline(d, gender, ',') &&
                        getline(d, disease, ',') &&
                        getline(d, date)) {
                        
                        appointments[Id][j].idA = patientId ;
                        appointments[Id][j].name = patient ;
                        appointments[Id][j].age = age ;
                        appointments[Id][j].gender = gender ;
                        appointments[Id][j].disease = disease ;
                        appointments[Id][j].date = date ;

                       appointments[Id][j].isConfirmed  = true;
                    }
                }
            }
        }
        load.close();
    } else {
        cout << "Failed to load Appointments!!" << endl;
    }
}
