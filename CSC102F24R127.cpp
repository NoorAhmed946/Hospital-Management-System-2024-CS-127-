#include <iostream>
#include<windows.h>
#include<iomanip>
#include<cctype>
#include<string>
#include<fstream>
using namespace std ;
void header() ;

void adminD(string doctor[],string pwdD[],int idD[],bool docFlag[] ,string doctorName [] ,int doctorAge[], string doctorGender[],int dsize,bool &msg) ;
void adminR(string receptionist[] , string pwdR[],int idR[] ,bool recFlag[] ,string receptionistName[],int receptionistAge[], string receptionistGender[], int rsize) ;
void adminP(string patient[],bool pFlag[],string appoPatient[][5],bool appoPFlag[][5],string appoDate[][5],bool appoDFlag[][5],string doctor[],int idD[],bool docFlag[], int psize , int dsize) ;
void beds(bool bed[] , int psize ) ;

void recP(string patient[] ,int ageP[] , bool pFlag[] , int idP[],int &doctorID ,bool bed[],string gender[],string disease[] , int psize ) ;
void recA(string appoPatient[][5],bool appoPFlag[][5],string appoDate[][5],bool appoDFlag[][5],string doctorName[],int idD[],bool docFlag[],string  appoGender[][5] ,string  appoDisease[][5], int appoAge[][5] , int dsize , int maxAppointments , int appoPatientId[][5],bool &msg) ;
void recB(string patient[], bool bed[], int idP[], int ageP[], int psize,  string appoPatient[][5], bool appoPFlag[][5], int dsize,int oneDay, int appointment ,int appoPatientId[][5]);

void docP1(string appoPatient[][5],bool appoPFlag[][5],string  appoGender[][5] ,string  appoDisease[][5] , int appoAge[][5],int maxAppointments,int appoPatientId[][5] ) ;
void docA1(string appoPatient[][5],bool appoPFlag[][5],string appoDate[][5],bool appoDFlag[][5],string doctor[],int idD[],bool docFlag[],int maxAppointments,int appoPatientId[][5] ) ;

void docP2(string appoPatient[][5],bool appoPFlag[][5],string  appoGender[][5] ,string  appoDisease[][5] , int appoAge[][5],int maxAppointments,int appoPatientId[][5]) ;
void docA2(string appoPatient[][5],bool appoPFlag[][5],string appoDate[][5],bool appoDFlag[][5],string doctor[],int idD[],bool docFlag[],int maxAppointments,int appoPatientId[][5]) ;

void docP3(string appoPatient[][5],bool appoPFlag[][5],string  appoGender[][5] ,string  appoDisease[][5] , int appoAge[][5],int maxAppointments,int appoPatientId[][5]) ;
void docA3(string appoPatient[][5],bool appoPFlag[][5],string appoDate[][5],bool appoDFlag[][5],string doctor[],int idD[],bool docFlag[],int maxAppointments,int appoPatientId[][5]) ;

void docList(string doctor[],string pwdD[],int idD[],bool docFlag[] ,string doctorName [] ,int doctorAge[], string doctorGender[],int dsize) ;
void docListA(string doctorName[],int idD[] ,bool docFlag[] , int dsize ) ;
void appoinList(string appoPatient[][5],bool appoPFlag[][5],string appoDate[][5],bool appoDFlag[][5],string doctor[],int idD[],bool docFlag[] , int dsize) ;

int getValidinput012() ;
int getValidinput0123() ;
int getValidinput05() ;
int getValidinput123() ;
string validGen() ;
int validAge() ;
string validDate(string appoDate[][5], int inputidD, int maxAppointments) ;
int getInt() ;
int toInt(const string &str , int st , int end ) ;

string uniqueDocUser(string doctor[] , int dsize ) ;
string uniqueRecUser(string receptionist[],int rsize ) ;

void savePatientData(string patient[] ,int ageP[] , bool pFlag[] , int idP[],string gender[],string disease[] , int psize) ;
void saveAppointments(string appoPatient[][5],bool appoPFlag[][5],string appoDate[][5],bool appoDFlag[][5],string doctor[] ,string  appoGender[][5] ,string  appoDisease[][5] , int appoAge[][5] , int maxAppointments,int dsize , int appoPatientId[][5]) ;
void saveDoctorsData(string doctor[],string pwdD[],int idD[],bool docFlag[] ,string doctorName [] ,int doctorAge[], string doctorGender[],int dsize ) ;
void saveReceptionist(string receptionist[] , string pwdR[],int idR[] ,bool recFlag[] ,string receptionistName[],int receptionistAge[], string receptionistGender[], int rsize) ;

void loadReceptionistData(string receptionist[] , string pwdR[],int idR[] ,bool recFlag[] ,string receptionistName[],int receptionistAge[], string receptionistGender[], int rsize) ;
void loadDoctorData(string doctor[],string pwdD[],int idD[],bool docFlag[] ,string doctorName [] ,int doctorAge[], string doctorGender[],int dsize) ; 
void loadPatientData(string patient[],int idP[],bool pFlag[] , int ageP[],string gender[] , string disease[] , int psize ,bool bed[]) ;
void loadAppointments(string appoPatient[][5] , int appoAge[][5] ,bool appoPFlag[][5],string appoDate[][5],bool appoDFlag[][5] ,string appoGender[][5] ,string appoDisease[][5],int dsize , int maxAppointments,int appoPatientId[][5]) ;
int main(){
    const int rsize = 2 ; // Number of Receptionist 
    const int dsize = 3 ; // Number of Doctors 
    const int psize = 100 ; // Number of Patients 
    const int bsize = 100 ; // Number of Beds
    const int maxAppointments = 5 ;// max number of appointments 
    const int oneDay = 1000 ;    // one day charges of hospital  
    const int appointment = 1500 ; // appointment charges 
    bool  msg = false  ; // to be sent receptionist if Admin changes any record of Doctor 
    
    string receptionist[rsize] ; 
    string pwdR[rsize] ;
    bool   recFlag[rsize] ;
    int    idR[rsize] ;
    string receptionistName[rsize] ;
    int    receptionistAge[rsize] ;
    string receptionistGender[rsize] ;
 
    string doctor[dsize] ;
    bool   docFlag[dsize] ;
    string pwdD[dsize] ;
    int    idD[dsize] ;
    string doctorName[dsize] ;
    int    doctorAge[dsize] ;
    string doctorGender[dsize] ;

    string patient[psize] ;
    bool   pFlag[psize] ;
    int    idP[psize] ;
    int    ageP[psize] ;
    string gender[psize] ;
    string disease[psize] ;
    
    bool    bed[psize] ;

    string  appoPatient[dsize][maxAppointments] ;
    int     appoPatientId[dsize][maxAppointments] ;
    int     appoAge[dsize][maxAppointments] ;
    bool    appoPFlag[dsize][maxAppointments] ;
    string  appoDate[dsize][maxAppointments]  ;
    bool    appoDFlag[dsize][maxAppointments] ; 
    string  appoGender[dsize][maxAppointments] ;
    string  appoDisease[dsize][maxAppointments] ;
    

    int input , input1, input2 , input3 , doctorId = 0; 
    int userType ;
    string userName ;
    string pwd ;
       
    for(int i = 0 ; i<dsize ; i++){  // indicating no data about doctors 
        doctor[i] = "NV" ;   
        pwdD[i] =  "NV" ; 
        idD[i] = -1 ;
        docFlag[i] = false ;
        doctorName[i] = "NV" ;
        doctorAge[i] = -1 ;
        doctorGender[i] = "NV" ;
     }
   
   
      for(int i = 0 ; i<rsize ; i++){
         receptionist[i] = "NV" ;  // indicating no data about receptionist
         pwdR[i] =  "NV" ; 
         idR[i] = -1 ;
         docFlag[i] = false ;
         receptionistName[i] = "NV" ;
         receptionistAge[i] =  -1 ;
         receptionistGender[i] = "NV" ;
      }
      
       for(int i = 0 ; i<psize ; i++){
         patient[i] = "NV" ;        // indicating no data about patients
         idP[i] = -1 ;
         pFlag[i] = false ;
         ageP[i] = 0 ;
         gender[i] = "NV" ;
         disease[i] = "NV" ;
         bed[i] = false ;
      }

     
      for(int i = 0 ;i<dsize ; i++){
          for(int j= 0; j<maxAppointments ; j++){  // indicating  No data about appointments  
              appoPatient[i][j] = "NV" ;   
              appoPatientId[i][j] = -1 ;
              appoPFlag[i][j] = false ;
              appoDate[i][j] = "NV" ;
              appoDFlag[i][j] = false ;
              appoGender[i][j] = "NV" ;
              appoDisease[i][j] = "NV" ;
              appoAge[i][j]  = -1 ;
          }
      }
       // FUNCTIONS TO LOAD AAL DATA IN FILES 
       loadReceptionistData(receptionist,pwdR,idR,recFlag,receptionistName,receptionistAge,receptionistGender, rsize) ;
       loadDoctorData(doctor ,pwdD,idD, docFlag,doctorName,doctorAge,doctorGender, dsize) ;
       loadPatientData(patient,idP,pFlag,ageP,gender,disease,psize,bed) ;
       loadAppointments(appoPatient,appoAge,appoPFlag,appoDate,appoDFlag,appoGender,appoDisease, dsize,maxAppointments,appoPatientId) ;
       
    do{ 
       header();
       input = getValidinput0123() ; 
       switch(input){
              case 1 : {

                cout<<" ====================="  <<endl ;
                cout<<"        ADMIN         "  <<endl ;
                cout<<" ====================="  <<endl ;
                   
                cout<<"Enter Username : "  ;
                cin>> userName ;
                
                cout<<"Enter Password : " ;
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
                cout<<" ====================="  <<endl ;
                cout<<"      RECEPTIONIST    "  <<endl ;
                cout<<" ====================="  <<endl ;

                cout<<"Enter  Username : "  ;
                cin>> userName ;

                cout<<"Enter Password :" ;
                cin>> pwd ;

                 // Password  correct or not 
                 for(int i = 0; i<rsize ; i++){
                    if(userName == receptionist[i] && pwd == pwdR[i]){
                      found = true ;
                    }
                 }

                 found ? userType = 2 : userType = -1 ;
                 break ;  
              }
              case 3 : { 
                bool found = false ;
                cout<<" ====================="  <<endl ;
                cout<<"         DOCTOR       "    <<endl ;
                cout<<" ====================="  <<endl ;

                cout<<"Enter  Username : "  ;

                getline(cin,userName) ;

                cout<<"Enter Password : " ;
                cin>> pwd ;
                // Password  correct or not 
                for(int i = 0 ; i<dsize ; i++){
                    if(userName == doctor[i] && pwd == pwdD[i]){
                       doctorId = idD[i] ;
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
                cout<<"Invalid Input " ;
                break ;
              }

       }
       
       // ADMIN  FUNCTIONALITIES
       if(userType == 1) {
        
         // ADMIN 
         do {
             cout<<'\n' ;
             cout<<" ====================="  <<endl ;
             cout<<"         ADMIN         "  <<endl ;
             cout<<" ====================="  <<endl ; 
             cout<<'\n' ;
             
             cout<<"Choose the Desired Section  : " <<endl ;
             cout<<"1. Doctors "                    <<endl ; 
             cout<<"2. Receptionist "               <<endl ; 
             cout<<"3. Patients Lists    "          <<endl ;
             cout<<"4. Beds   "                <<endl ;
             cout<<"0. Exit   "                     <<endl ;
             cout<<'\n' ;

             cout<<"Choose an option : " ;
             input1 = getValidinput05() ; 
             cout<<endl ;
             switch(input1) {
                   case 1 : {
                      // function call of doctor 
                      adminD(doctor ,pwdD,idD, docFlag,doctorName,doctorAge,doctorGender, dsize,msg) ;
                      break ;
                   }
                   case 2 : {
                    // function call of Receptionist 
                      adminR(receptionist,pwdR,idR,recFlag,receptionistName,receptionistAge,receptionistGender, rsize) ;
                
                     break ;
                   }
                   case 3 : {
                    // function call of Patients 
                      adminP(patient,pFlag,appoPatient,appoPFlag,appoDate,appoDFlag,doctor,idD,docFlag,psize , dsize) ;
                   
                     break ;
                   }
                    case 4 : {
                     // function call of Beds
                     beds(bed,psize) ;
                    
                     break ;
                   }
                    case 0 : {
                    cout<<"Exiting ..." <<endl ;
                    break; 
                   }
                   default :{
                    cout<<"Invalid Input . Pleae Enter Valid Input (0-4)" <<endl ;
                    break ;
                   }
                  
             }
             

         }while(input1 != 0 ); // admin do while 
         
       }
       // RECEPTIONIST FUNCTIONALITIES 
       else if(userType == 2){
           
            
            do{
            cout<<'\n' ;
            cout<<" ====================="  <<endl ;
            cout<<"      RECEPTIONIST    "  <<endl ;
            cout<<" ====================="  <<endl ;
            cout<<'\n' ;


            cout<<"Choose the Desire Option :"  <<endl ;
            cout<<"1. Patient Registration "    <<endl ;
            cout<<"2. Appointment Scheduling  " <<endl ;
            cout<<"3. Bed Management "          <<endl ;
            cout<<"4. Bills    "                <<endl ;
            cout<<"0. Exit     "                <<endl ;
            cout<<'\n' ;
            cout<<'\n' ;

            cout<<"Choose Option : " ;
            input2 = getValidinput05(); 

            switch(input2){
                case 1 : {
                    // Patient Registeration Function Call 
                    recP(patient, ageP , pFlag , idP , doctorId , bed , gender,disease,psize) ;
                    break ;
                } 
                case 2 : {
                    // Appopinment Scheduling 
                    recA(appoPatient , appoPFlag,appoDate,appoDFlag,doctorName,idD,docFlag,appoGender,appoDisease,appoAge ,dsize,maxAppointments,appoPatientId,msg );
                    break ;
                }
                case 3 : {
                    // Bed Management 
                    beds(bed,psize) ;
                    break ;
                }
                case 4 : { // Bills 
                    recB(patient, bed, idP, ageP, psize, appoPatient, appoPFlag, dsize, oneDay, appointment,appoPatientId );

                    break ;
                }
                case 0 : {
                    cout<<"Exiting ..." <<endl ;
                    break; 
                }
                default :{
                    cout<<"Invalid Input . Pleae Enter Valid Input (0-4)" <<endl ;
                    break ;
                   }
               

            }
            }while(input2 !=0); // Receptionist do while 
                   
 
              
       }
       // DOCTOR FUNCTIONALITIES 
       else if(userType == 3 ){
            
            if(doctorId == 1 ){
            do{  // doctor id 1 
               cout<<'\n' ; 
               cout<<" ====================="  <<endl ;
               cout<<"        DOCTOR        "  <<endl ;
               cout<<" ====================="  <<endl ;
               cout<<'\n' ;


               cout<<"Choose the Desired Option : " <<endl ;
               cout<<"1. Appointments"              <<endl ;
               cout<<"2. Patient Data     "         <<endl ; 
               cout<<"0. Exit             "         <<endl ;
               cout<<endl ;
               cout<<endl ;

               cout<<" Choose a option : " ;
               input3 = getValidinput012() ;  
               switch(input3){
                      case 1 : {
                        // Appointments 
                         docA1(appoPatient,appoPFlag,appoDate,appoDFlag,doctor,idD,docFlag,maxAppointments,appoPatientId) ;
                         break ;
                      }
                      case 2 : {            
                         // pateint list ;
                         docP1(appoPatient,appoPFlag,appoGender,appoDisease,appoAge,maxAppointments,appoPatientId) ;  
                         break ;

                      }
                      case 0 : {
                        cout<<"Exiting ..." <<endl ;
                        break ;
                      }
                      default : {
                        cout<<"Invalid Input !!" <<endl ;
                        break ;
                      }
               }


            }while(input3 != 0); // doctor do while
            }
            else if(doctorId == 2 ){ 
            do{  // doctor id 2
               cout<<'\n' ; 
               cout<<" ====================="  <<endl ;
               cout<<"        DOCTOR        "  <<endl ;
               cout<<" ====================="  <<endl ;
               cout<<'\n' ;


               cout<<"Choose the Desired Option : " <<endl ;
               cout<<"1. Appointments"              <<endl ;
               cout<<"2. Patient Data     "         <<endl ; 
               cout<<"0. Exit             "         <<endl ;
               cout<<endl ;
               cout<<endl ;

               cout<<" Choose a option : " ;
               input3 = getValidinput012() ; 
               switch(input3){
                      case 1 : {
                         // Appointments section 
                         docA2(appoPatient,appoPFlag,appoDate,appoDFlag,doctor,idD,docFlag,maxAppointments,appoPatientId) ;
                        
                         break ;
                      }
                      case 2 : {
                          // pateint list ;
                         docP2(appoPatient,appoPFlag,appoGender,appoDisease,appoAge,maxAppointments,appoPatientId) ;
                         break ;

                      }
                      case 0 : {
                        cout<<"Exiting ..." <<endl ;
                        break ;
                      }
                      default : {
                        cout<<"Invalid Input !!" <<endl ;
                        break ;
                      }
               }


            }while(input3 != 0); // doctor do while
            } 
            else {  
            do{  // doctor id 3
               cout<<'\n' ; 
               cout<<" ====================="  <<endl ;
               cout<<"        DOCTOR        "  <<endl ;
               cout<<" ====================="  <<endl ;
               cout<<'\n' ;


               cout<<"Choose the Desired Option : " <<endl ;
               cout<<"1. Appointments"              <<endl ;
               cout<<"2. Patient Data     "         <<endl ; 
               cout<<"0. Exit             "         <<endl ;
               cout<<endl ;
               cout<<endl ;

               cout<<" Choose a option : " ;
               input3 = getValidinput012() ;  
               switch(input3){
                      case 1 : {
                          // Appointments function call          
                         docA3(appoPatient,appoPFlag,appoDate,appoDFlag,doctor,idD,docFlag,maxAppointments,appoPatientId) ;  
                         break ;
                      }
                      case 2 : {
                            // pateint list   
                          docP3(appoPatient,appoPFlag,appoGender,appoDisease,appoAge,maxAppointments,appoPatientId) ;  
                         break ;

                      }
                      case 0 : {
                        cout<<"Exiting ..." <<endl ;
                        break ;
                      }
                      default : {
                        cout<<"Invalid Input !!" <<endl ;
                        break ;
                      }
               }
             


            }while(input3 != 0); // doctor do while
            }
            
       }
       else if(userType == -1){
            cout<<"You have Entered Invalid Credentials!! " <<endl ;        
       }   

        


    }while(input!=0) ; // first do  while 

    return 0 ;
}

// FUNCTIONS 

void header(){
  

  
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

void adminD(string doctor[],string pwdD[],int idD[],bool docFlag[] ,string doctorName [] ,int doctorAge[], string doctorGender[],int dsize,bool &msg) {
     int input;
     int counter = 0 ; 
            
     string name , pwd , userName;
     cout<<'\n' ;
     cout<<" ====================="  <<endl ;
     cout<<"         ADMIN         "  <<endl ;
     cout<<" ====================="  <<endl ; 
     cout<<'\n' ;
     
     do{
     cout<<"Choose the Option : " <<endl ;
     cout<<"1. Add New Doctor    " <<endl ; 
     cout<<"2. Delete Doctor Record " <<endl ; 
     cout<<"3. Update Doctor Record " <<endl ;
     cout<<"4. Doctor's List " <<endl ;
     cout<<"0. Exit  " <<endl ;
     cout<<'\n' ;

     cout<<"Choose an option : " <<endl ;
     input =getValidinput05() ;

     switch(input){
        case 1 :{   //ADD
          bool found = false ;
          for(int i = 0 ;i<dsize ; i++){
              if(docFlag[i] == false){
                 
                 cout<<"Enter Doctor's Name : " ;
                 getline(cin,doctorName[i]) ;

                 cout<<"Enter Doctor's Age : " ;
                 doctorAge[i] = validAge();

                 cout<<"Enter Doctor's Gender (male/female) : " ;
                 doctorGender[i] = validGen() ;                                  

                 cout<< " Assign UserName (Without Space) : " ;
                 doctor[i] = uniqueDocUser(doctor,dsize) ;

                 cout<<" Assign password :  " ;
                 cin>> pwdD[i] ;

                 idD[i] = i+1 ;

                 docFlag[i] = true ;
                 found = true ;
                 counter++ ;
                 break ;
              }
          }
          found ? cout<<"Succesfully Added! " : cout<<"Cannot Add New Doctors Details.Space is full" ;
          cout<<endl ;
          cout<<endl ;
          saveDoctorsData(doctor ,pwdD,idD, docFlag,doctorName,doctorAge,doctorGender, dsize) ;
          break ;
        }
        case 2 :{ // Delete
            bool found = false ;
            cout<<"Enter Doctor's UserName : " ;
            //cin.ignore(100,'\n') ;
            cin>>name ; ;

            for(int i = 0; i< dsize ; i++){
              if(name == doctor[i] && docFlag[i] == true){
                doctor[i] = "NV" ;
                pwdD[i] = "NV" ;
                docFlag[i] = false ;
                idD[i] = -1 ;
                doctorName[i] ="NV" ;
                doctorAge[i] = -1 ;
                doctorGender[i] = "NV";
                found = true ; 
                counter-- ;
                msg = true ;
                break;
              }
            }
            found ? cout<<"Deleted Successfully!" : cout<<"Name not Found !" ;
            saveDoctorsData(doctor ,pwdD,idD, docFlag,doctorName,doctorAge,doctorGender, dsize) ;
            cout<<endl ;  
            cout<<endl ;
  
          break ;
        }
        case 3 :{ // Update 
             bool found = false ;
            cout<<"Enter Doctor's UserName : " ;
            cin>>name ;

            for(int i = 0; i< dsize ; i++){
              if(name == doctor[i] && docFlag[i] == true) {

                 cout<<"Enter Doctor's Name : " ;
                 cin.ignore(100,'\n') ; 
                 getline(cin,doctorName[i]) ;

                 cout<<"Enter Doctor's Age : " ;
                 doctorAge[i] = validAge();

                 cout<<"Enter Doctor's Gender (male/female) : " ;
                 doctorGender[i] = validGen() ;                                  

                 cout<< " Assign UserName (Without Space) : " ;
                 doctor[i] = uniqueDocUser(doctor,dsize) ;

                 cout<<" Assign password :  " ;
                 cin>> pwdD[i] ;
                 msg = true ; 
                 found = true ;
                 break ;
              }
            }
            found ? cout<<"Updated Successfully!" : cout<<"Name not Found !!" ;
            saveDoctorsData(doctor ,pwdD,idD, docFlag,doctorName,doctorAge,doctorGender, dsize) ;
            cout<<endl ; 
            cout<<endl ;

          break ;
        }
        case 4 :{ // list
          docList(doctor ,pwdD,idD, docFlag,doctorName,doctorAge,doctorGender, dsize) ;   
          break ;
        }
        case 0 :{
          cout<<"Exiting From Doctor's Section ." <<endl ;
          saveDoctorsData(doctor ,pwdD,idD, docFlag,doctorName,doctorAge,doctorGender, dsize) ;
          break ;
        }
         default :{
            cout<<"Invalid Input . Pleae Enter Valid Input (0-4)" <<endl ;
            break  ;
         }                   
     }
     }while(input !=0) ;

}

// Receptionists Management by Admin

void adminR (string receptionist[] , string pwdR[],int idR[] ,bool recFlag[] ,string receptionistName[],int receptionistAge[], string receptionistGender[], int rsize) {
     int input , counter = 0 ;
     string name , pwd ;
     cout<<'\n' ;
     cout<<" ====================="  <<endl ;
     cout<<"         ADMIN         "  <<endl ;
     cout<<" ====================="  <<endl ; 
     cout<<'\n' ;
     
     do{
     cout<<"Choose the Option : " <<endl ;
     cout<<"1. Add New Receptionist " <<endl ; 
     cout<<"2. Delete Receptionist Record " <<endl ; 
     cout<<"3. Update Receptionist Record " <<endl ;
     cout<<"4. Receptionist's List " <<endl ;
     cout<<"0. Exit  " <<endl ;
     cout<<'\n' ;

     cout<<"Choose an option : " <<endl ;
     input = getValidinput05() ;

     switch(input){
        case 1 :{ //ADD
            bool found = false ;
            for(int i = 0 ; i<rsize ; i++){
                if(recFlag[i] == false){
                   cout<<"Enter Receptionist Name : " ;
                   getline(cin,receptionistName[i]) ;

                   cout<<"Enter Receptionist Age : " ;
                   receptionistAge[i] = validAge() ;    
                 
                   cout<<"Enter Receptionist Gender (male/female ):" ;
                   receptionistGender[i] = validGen() ; 

                   cout<<"Assign Receptionist UserName (without space) : " ;
                   receptionist[i] = uniqueRecUser(receptionist,rsize) ;

                   cout<<"Assign Password :  " ;
                   cin>> pwdR[i] ;

                   idR[i] = i + 1 ;
                   recFlag[i] = true ;
                   found = true ;
                   counter++ ;
                   break ; 
                }
            }
            found ? cout<<"Succesfully Added " : cout<<"There is no vacancy to add more receptionist " ;
            saveReceptionist(receptionist,pwdR,idR,recFlag,receptionistName,receptionistAge,receptionistGender, rsize )  ;
            cout<<endl ;
            cout<<endl ;
          break ;
        }
        case 2 :{ // Delete
          bool found = false ;
          cout<<"Enter Receptionist's UserName : " ;
          cin>>name ;

            for(int i = 0; i< rsize ; i++){
              if(name == receptionist[i] && recFlag[i] == true){
                receptionist[i] = "NV" ;
                pwdR[i] = "NV" ;
                recFlag[i] = false ;
                idR[i] = -1 ;
                receptionistName[i] = "NV" ;
                receptionistAge[i] = -1 ;
                receptionistGender[i] = "NV" ;
                found = true ; 
                counter-- ;
                break;
              }
            }
            found ? cout<<"Deleted Successfully!" : cout<<"Name not Found !" ;
            saveReceptionist(receptionist,pwdR,idR,recFlag,receptionistName,receptionistAge,receptionistGender, rsize )  ;
            cout<<endl ;   
            cout<<endl ; 
          break ;
        }
        case 3 :{
          // Update 
            bool found = false ;

            cout<<"Enter Receptionist's UserName : " ;
            cin>> name ;

            for(int i = 0; i< rsize ; i++){
              if(name == receptionist[i] && recFlag[i] == true) {

                   cout<<"Enter Receptionist Name : " ; 
                   cin.ignore() ;
                   getline(cin,receptionistName[i]) ;

                   cout<<"Enter Receptionist Age : " ;
                   receptionistAge[i] = validAge() ;    
                 
                   cout<<"Enter Receptionist Gender (male/female ):" ;
                   receptionistGender[i] = validGen() ; 

                   cout<<"Assign Receptionist UserName (without space) : " ;
                   cin>>receptionist[i] ;

                   cout<<"Assign Password :  " ;
                   cin>> pwdR[i] ;

                   found = true ;
                   break ; 
              }
            }
              found ? cout<<"Updated Successfully!" : cout<<"Name not Found !!"  ;
              saveReceptionist(receptionist,pwdR,idR,recFlag,receptionistName,receptionistAge,receptionistGender, rsize )  ;
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
               if(recFlag[i]){
               cout<<left ;   
               cout<<setw(10) << j << setw(15) <<idR[i] <<setw(32)<< receptionistName[i] << setw(25) << receptionistAge[i] <<setw(25) << receptionistGender[i] <<setw(30) <<receptionist[i]<< setw(25)<< pwdR[i] <<endl ;
               found = true ;   
               j++ ;
               }
          }
          if(!found)
             cout<<"No Receptionists Available in Hospital . " <<endl; 
             cout<<endl ;
          break ;
        }
        case 0 :{
          cout<<"Exiting From Receptionist's Section ." <<endl ;
          cout<<endl ;
          break ;
        }
         default :{
           cout<<"Invalid Input . Pleae Enter Valid Input (0-4)" <<endl ;          
                 break ;
          }
     }
     }while(input !=0) ;

}

//  Admin Function for Patients 

void adminP(string patient[],bool pFlag[],string appoPatient[][5],bool appoPFlag[][5],string appoDate[][5],bool appoDFlag[][5],string doctor[3],int idD[],bool docFlag[], int psize , int dsize ){
     int input;
     cout<<'\n' ;
     cout<<" ====================="  <<endl ;
     cout<<"         ADMIN         "  <<endl ;
     cout<<" ====================="  <<endl ; 
     cout<<'\n' ;
      
    
     
     do{
       cout<<"Choose the desired option : " <<endl;
       cout<<"1.Patients List admiited in Hospital." <<endl ;
       cout<<"2.Patient list regestered for appointments " <<endl ;
       cout<<"0.Exit " <<endl ;
       cout<<endl ;
       cout<<"Choose an option : " ;
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
             if(pFlag[i] == true ){
             cout<<j<<"\t"<<patient[i] <<endl ;
             j++ ;
             found = true ;                
             }
          }
          if(!found){
            cout<<"No Patient is admitted  in Hospital ." <<endl ;
            cout<<endl ;
          }
        break ;
        }
        case 2:{  // appointments lists 
          appoinList(appoPatient , appoPFlag,appoDate,appoDFlag,doctor,idD,docFlag,dsize) ;
          cout<<endl ;
            break;
        }   
        case 0:{
            cout << "Exiting . " << endl;
            cout<<endl ;
            break;
        }
    }
     }while(input != 0);
}

// Beds Function of Admin 

void beds(bool bed[] , int psize){
     int counter = 0 ;
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

/////////////   RECEPTIONIST

// Patients

void recP (string patient[] ,int ageP[], bool pFlag[] , int idP[] ,int &dectorID,bool bed[],string gender[],string disease[], int psize) {
     int input , counter = 0 ;
     string name ;
     cout<<'\n' ;
     cout<<" ====================="  <<endl ;
     cout<<"     Receptionist         "  <<endl ;
     cout<<" ====================="  <<endl ; 
     cout<<'\n' ;
     
     do{
     cout<<"Choose the Option : " <<endl ;
     cout<<"1. Add New Patient " <<endl ; 
     cout<<"2. Delete Patient Record" <<endl ; 
     cout<<"3. Update Patient Record " <<endl ;
     cout<<"4. Patient's List " <<endl ;
     cout<<"0. Exit  " <<endl ;
     cout<<'\n' ;

     cout<<"Choose an option : " <<endl ;
     input = getValidinput05() ;

     switch(input){
        case 1 :{  // adding data of ne patient
            bool found = false ;
            for(int i = 0 ; i<psize ; i++){
                if(pFlag[i] == false){
                  cout<<"Enter Patient's Name : " ;
                  //cin.ignore() ;
                  getline(cin,patient[i]) ;

                  cout<<"Enter Patient's age :  " ;
                  ageP[i] = validAge() ;

                  cout<<"Enter Gender(male/female) : " ;
                  gender[i] = validGen() ;

                  cout<<"Enter Disease : " ;
                  cin>> disease[i] ;

                  idP[i] = i + 1 ;
                  pFlag[i] = true ;
                  bed[i] = true ;
                  found = true ;
                  counter++ ;
                  break ; 
                }
            }
            savePatientData(patient,ageP,pFlag,idP,gender,disease,psize) ;
            found ? cout<<"Succesfully Added " : cout<<"There is no space to add more Patients " ;
            cout<<endl ;
            cout<<endl ;
               
          break ;
        }
        case 2 :{
          // Delete data of patients
          bool found = false ;
          int id ;
          cout<<"Enter Patient's ID to delete his/her record : " ;
          id = getInt() ;

            for(int i = 0; i< psize ; i++){
              if(id == idP[i] && pFlag[i] == true){
                patient[i] = "NV" ;
                pFlag[i] = false ;
                idP[i] = -1 ;
                ageP[i] = 0 ;
                bed[i] = false ;
                gender[i] = "NV" ;
                disease[i] = "NV" ;
                found = true ; 
                counter-- ;
                break;
              }
            }
            savePatientData(patient,ageP,pFlag,idP,gender,disease,psize) ;
            found ? cout<<"Deleted Successfully!" : cout<<"Name not Found !" ;
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
              if(id == idP[i] && pFlag[i] == true) {
                cout<<"Enter Updated Name : " ;
                cin.ignore() ;
                getline(cin,patient[i]) ;

                cout<<"Enter Patient's age : " ;
                ageP[i] = validAge() ;

                cout<<"Enter Gender (male/female):" ;
                gender[i] = validGen() ;

                cout<<"Enter Disease : " ;
                cin>> disease[i] ;

                found = true ;
                break;
              }
            }
           savePatientData(patient,ageP,pFlag,idP,gender,disease,psize) ; 
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
             if(pFlag[i]){
              cout<<left ;  
              cout<< setw(10)<< j << setw(20) <<idP[i] << setw(30) << patient[i] << setw(20) <<ageP[i] <<setw(16) <<gender[i]<< setw(30)<<disease[i]<<endl ;
              found = true ;
              j++ ;   
             }
          }
          if(!found)
             cout<<"No Patients Available in Hospital . " <<endl; 
             cout<<endl ;
          break ;
        }
       
        case 0 :{
          cout<<"Exiting From Patient's Section ." <<endl ;
          cout<<endl ;
          savePatientData(patient,ageP,pFlag,idP,gender,disease,psize) ;
          break ;
        }
         default :{
           cout<<"Invalid Input . Pleae Enter Valid Input (0-4)" <<endl ;
           break ;       
           }
     }
     }while(input !=0) ;

}

// Appointments 
void recA(string appoPatient[][5],bool appoPFlag[][5],string appoDate[][5],bool appoDFlag[][5],string doctorName[],int idD[],bool docFlag[] ,string  appoGender[][5] ,string  appoDisease[][5] , int appoAge[][5] , int dsize , int maxAppointments ,int appoPatientId[][5],bool &msg ) {
     int input , inputIdD;
     string name ;
     cout<<'\n' ; 
     cout<<" ====================="  <<endl ;
     cout<<"     Receptionist         "  <<endl ;
     cout<<" ====================="  <<endl ; 
     cout<<'\n' ;

     if(msg){
         cout<<"Doctor's Record have been updated. So Update the appointments "<<endl <<endl ;
     } 
      do{
      cout<<"Choose the Option : " <<endl ;
      cout<<"1. New Appointment  : " <<endl ;
      cout<<"2. Delete Appointment  : " <<endl ;
      cout<<"3. Update Appointment : " <<endl ;
      cout<<"4. Appointments List   : " <<endl ;
      cout<<"5. Doctor's List  : "   <<endl ;
      cout<<"0. Exit   : " <<endl ;
      cout<<'\n' ;

      cout<<"Choose an option : " <<endl ;
      input = getValidinput05() ;
       cout<<endl ; 
       
       cout<<endl ;
       switch(input){
        case 1 :{ //New Appointment 
          bool found = false ;
          docListA(doctorName ,idD, docFlag,dsize) ;
          cout<<endl ;
          cout<<endl ;

          cout<<"Enter the id of the Doctor You want to select for Appointmemt :" ;
          inputIdD = getValidinput123() ;  // Get the id of data
          inputIdD = inputIdD - 1 ;   // substracting the Id by -1 to get the row of 2d array               
          cout<<endl ;
                     
          
          for(int j=0 ; j<maxAppointments ;j++){
                 // Add the appointment in specific row   
              if(appoPFlag[inputIdD][j] == false && appoDFlag[inputIdD][j] == false ){
                 cout<<"Enter Patient  Name : " ;
                 //cin.ignore() ;
                 getline(cin,appoPatient[inputIdD][j] );

                 cout<<"Enter Patient's Age : ";
                 appoAge[inputIdD][j] = validAge() ;

                 cout<<"Enter Gender :" ;
                 appoGender[inputIdD][j] = validGen() ;

                  cout<<"Enter Disease : " ;
                  cin.ignore() ;
                 getline(cin,appoDisease[inputIdD][j]) ;

                 cout <<"Enter appointment date (dd-mm-yyyy): ";
                 appoDate[inputIdD][j] = validDate(appoDate,inputIdD,maxAppointments) ;

                 appoPatientId[inputIdD][j]  = j + 1 ;
                 appoPFlag[inputIdD][j] = true ;
                 appoDFlag[inputIdD][j] = true ;
                 found = true ; 
                 break ;

              }
          }
          if(!found){
             cout<<"Appointments are full . Cannot Set New Appointments " <<endl ;
             cout<<endl ;
          }
          saveAppointments(appoPatient,appoPFlag,appoDate,appoDFlag,doctorName,appoGender,appoDisease,appoAge,maxAppointments,dsize,appoPatientId);
          break ;
        }
        case 2 :{  // Delete Appointments
          bool found = false ;
          int id ;
          cout<<"Enter Patient Id to Delete His/Her Appointment : " ;
          // cin.ignore() ;
          id = getInt() ;

          cout<<"Enter Doctor's Id : " ;
          inputIdD = getValidinput123() ;
          inputIdD = inputIdD - 1 ;

          for(int j = 0; j<maxAppointments ;j++ ){
              if(id == appoPatientId[inputIdD][j] && appoPFlag[inputIdD][j] == true){
                appoPatient[inputIdD][j] = "NV" ;
                appoPatientId[inputIdD][j] = -1 ;
                appoAge[inputIdD][j] = -1 ;
                appoPFlag[inputIdD][j] = false ;
                appoDate[inputIdD][j] = "NV" ;
                appoDFlag[inputIdD][j] = false ;
                appoGender[inputIdD][j] = "NV" ;
                appoDisease[inputIdD][j] = "NV" ;
                cout<<endl ;
                cout<<"Patient Appointment Deleted Successfully . " <<endl <<endl ;
                found = true ;
              }
          }
          if(!found){
            cout<<"Patient Name in Doctor's List with id "<< inputIdD + 1 <<" cannot be found " <<endl <<endl; 
          }  
          saveAppointments(appoPatient,appoPFlag,appoDate,appoDFlag,doctorName,appoGender,appoDisease,appoAge,maxAppointments,dsize,appoPatientId);
          break ;
        }
        case 3 :{ // Update Appointments
          bool found = false ;
          int id ;
          cout<<"Enter Patient Id to Update His/Her Appointment : " ;
          id = getInt() ;

          cout<<"Enter Doctor's Id : " ;
         inputIdD = getValidinput123() ;
          inputIdD = inputIdD - 1 ; // doctor id to specify row in 2d array 

          for(int j = 0 ; j<maxAppointments ; j++){
             if(id == appoPatientId[inputIdD][j] && appoPFlag[inputIdD][j] == true){
               cout<<"Enter Updated Name : ";
               //cin.ignore() ;
               getline(cin,appoPatient[inputIdD][j]); 
               cout<<endl ;
               
               cout<<"Enter Patient's Age : ";
               appoAge[inputIdD][j] = validAge();

               cout<<"Enter Gender :" ;
               appoGender[inputIdD][j] = validGen() ;

               cout<<"Enter Disease : " ;
               cin.ignore() ;
               getline(cin,appoDisease[inputIdD][j]) ;
               
               cout<<"Already Selected Date is :" ;
               cout<< appoDate[inputIdD][j] <<endl ;

               cout<<"Enter Updated Date : " ;
               appoDate[inputIdD][j] = validDate(appoDate,inputIdD,maxAppointments) ;
               found = true ;
             }
          }
          if(!found){
             cout<<"Patient Name in Doctor's List with id "<< inputIdD + 1 <<" cannot be found " <<endl <<endl; 
          } 
         saveAppointments(appoPatient,appoPFlag,appoDate,appoDFlag,doctorName,appoGender,appoDisease,appoAge,maxAppointments,dsize,appoPatientId);
          break ;
        }
        case 4 :{  // List  
          bool found1 = false ;
          bool found2 = false ;
          cout<<" Enter Doctor's ID to check thier list " ;
          inputIdD = getValidinput123() ;
          inputIdD = inputIdD -1 ;

          cout<<"==============================================" <<endl ; 
          cout<< " Doctor's ID\t\t"<< "Doctor's Name  " <<endl  ;
          cout<<"==============================================" <<endl ;
      
             if(docFlag[inputIdD] == true ){             
             cout<<idD[inputIdD] <<"\t\t\t" << doctorName[inputIdD] << endl ; 
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
             if(appoPFlag[inputIdD][j] == true){
             cout<<left ; 
             cout<<setw(20)<< appoPatientId[inputIdD][j] <<setw(30) <<appoPatient[inputIdD][j] << appoDate[inputIdD][j] <<endl;
             found2 = true ;
             }
            }
            }

           if(!found1){
              cout<<"No Doctors Have been added yet By Admin ! "<<endl ;
              cout<<endl ;
           }
           if(found1){
           if(!found2){
              cout<<"This Doctor has no appointments Scheduled.!" <<endl ;
              cout<<endl ;
           }
           }
          break ;
        }
        case 5 : {
           docListA(doctorName ,idD, docFlag,dsize) ;
          break ;
        }
        case 0 :{
          cout<<"Exiting Appointment Section ." <<endl ;
           saveAppointments(appoPatient,appoPFlag,appoDate,appoDFlag,doctorName,appoGender,appoDisease,appoAge,maxAppointments,dsize,appoPatientId);
          cout<<endl ;
          break ;
        }
       }


      }while(input !=0 );
}     

// Bills 
void recB(string patient[], bool bed[], int idP[], int ageP[], int psize,  string appoPatient[][5], bool appoPFlag[][5], int dsize,int oneDay, int appointment , int appoPatientId[][5]){
     int input , bill ,days , id , idD;
     
     cout<<'\n' ;
     cout<<" ====================="  <<endl ;
     cout<<"     Receptionist         "  <<endl ;
     cout<<" ====================="  <<endl ; 
     cout<<'\n' ; 
    
    do{
    cout<<"=========================================="<<endl ;
    cout<<"        Receptionist Billing Menu:" <<endl  ;
    cout<<"=========================================="<<endl ;
    cout << "1. Bill for Admitted Patients" << endl ;
    cout << "2. Bill for Appointment Patients" << endl;
    cout << "0. Exit "                          <<endl ;
    cout << "Enter your choice: ";
    input = getValidinput012();

    switch(input){
       case 1 : {
              bool found1 = false ;
             // Billing for Admitted Patients
            cout << "Enter Patient Id  for Admitted Patient Billing: ";
            cin >> id; 

            for (int i = 0 ; i < psize; i++) {
                if (idP[i] == id  && bed[i]) {
                    cout << "Enter number of days patient stayed: ";
                    days = getInt() ;
                    bill = days * oneDay;
                    cout << "Patient Name: " << patient[i] << endl;
                    cout << "Number of Days: " << days << endl;
                    cout << "Total Bill (Admitted): " << bill << " Rs" << endl;
                    found1 = true;
                    break;
                }
            }

            if (!found1) {
                cout << "Patient not found or not admitted." << endl <<endl ;
            }
            break;
       }            
             case 2:{
             bool found2 = false ; 
            // Billing for Appointment Patients
            cout << "Enter Patient Id  for Appointment Billing: ";
            cin >> id ;
            cout<<"Enter Patient's Doctor Id (1-3)  : " ;
            idD = getValidinput123() ;
            idD = idD - 1 ;
            
            
                for (int j = 0; j < 5; j++) {
                    if (appoPFlag[idD][j] == true && id == appoPatientId[idD][j]) {
                        bill = appointment; 
                        cout << "Patient Name: " << appoPatient[idD][j] << endl;
                        cout << "Total Bill (Appointment): " << bill << " Rs" << endl;
                        found2 = true;
                        break;
                    }
                }
          
            if (!found2) {
                cout << "Patient not found or no appointment record." << endl <<endl ;
            }
            break;
            }
            case 0 :{
              cout<<"Exiting from Billing Section .." <<endl <<endl ;
              break ;
            }

    }
     

}while(input != 0 ) ;
}


// Doctor  1  Patients Details

void docP1(string appoPatient[][5],bool appoPFlag[][5],string  appoGender[][5] ,string  appoDisease[][5] , int appoAge[][5],int maxAppointments,int appoPatientId[][5]){
      string name ;
      bool found = false ; 
      int docID = 0 ,id ;
      cout<<'\n' ; 
      cout<<" ====================="  <<endl ;
      cout<<"        DOCTOR        "  <<endl ;
      cout<<" ====================="  <<endl ;
      cout<<'\n' ; 
      cout<<"Enter Patient ID to see thier details : "  ;
      id =getInt() ;   

      cout<<"======================================================================================================="<<endl ; 
      cout<<"Patient's Id \t"<<" Patient's Name \t\t"<<"  Patient's Age\t\t"<<"Gender\t\t"<<" Disease" <<endl;
      cout<<"======================================================================================================="<<endl ; 
      for(int j= 0 ;j<maxAppointments ;j++){
         if(appoPFlag[docID][j] == true && id == appoPatientId[docID][j]){
          cout<<left ;  
          cout<<setw(20)<<appoPatientId[docID][j] <<setw(30) <<appoPatient[docID][j]<<setw(20)<<appoAge[docID][j]<<setw(20)<<appoGender[docID][j]<<setw(30)<<appoDisease[docID][j]  <<endl ;
          found = true ;
         }
      }   
      if(!found){
        cout<<"No Data!!" <<endl <<endl ;
      }

      
}
// Doctor  1  Appointments lista
void docA1(string appoPatient[][5],bool appoPFlag[][5],string appoDate[][5],bool appoDFlag[][5],string doctor[],int idD[],bool docFlag[],int maxAppointments,int appoPatientId[][5]){
     cout<<'\n' ; 
     cout<<" ====================="  <<endl ;
     cout<<"        DOCTOR        "  <<endl ;
     cout<<" ====================="  <<endl ;
     cout<<'\n' ;      
     
     bool found1 = false ;
     bool found2 = false ;
     
     cout<<"==============================================" <<endl ; 
     cout<<"Doctor's ID\t\t"<< "Doctor' Name \t" <<endl  ;
     cout<<"==============================================" <<endl ;
   
     if(docFlag[0] == true ){
             
     cout<<idD[0] <<"\t\t\t" << "Dr. "<< doctor[0] << endl ; 
            
     found1 = true ;
     }
     if(found1){
        cout<<"=====================================================================" <<endl ;
        cout<<"Patient's Id \t"<<"Patient's Name \t\t"<< "          Appointments" <<endl ;
        cout<<"=====================================================================" <<endl ;
        }
             
      for(int j= 0 ;j<maxAppointments ; j++){
         if(appoPFlag[0][j] == true){
            cout<<left ;
            cout<<setw(20)<<appoPatientId[0][j]<< setw(30) <<appoPatient[0][j] <<appoDate[0][j] <<endl;
            found2 = true ;
            }
          }
          if(!found1){
              cout<<"No Doctors Have been added yet By Admin ! "<<endl <<endl ;
          }
          if(!found2){
              cout<<"This Doctor has no appointments Scheduled.!" <<endl  <<endl ;
         }
    

}

// Doctor  1  Patients Details
void docP2(string appoPatient[][5],bool appoPFlag[][5],string  appoGender[][5] ,string  appoDisease[][5] , int appoAge[][5],int maxAppointments,int appoPatientId[][5]){
      bool found = false ; 
      int docID = 1 , id ;
      cout<<'\n' ; 
      cout<<" ====================="  <<endl ;
      cout<<"        DOCTOR        "  <<endl ;
      cout<<" ====================="  <<endl ;
      cout<<'\n' ;      

      cout<<"Enter Patient Id to see thier details : "  ;
      id = getInt() ;   

      cout<<"====================================================================================================="<<endl ; 
      cout<<"Patient's Id \t"<<"  Patient's Name \t\t"<<"  Patient's Age\t\t"<<"Gender\t\t"<<" Disease" <<endl;
      cout<<"======================================================================================================"<<endl ; 
      for(int j= 0 ;j<maxAppointments ;j++){
         if(appoPFlag[docID][j] == true && id == appoPatientId[docID][j]){
          cout<<left ;  
          cout<<setw(20)<<appoPatientId[docID][j]<<setw(30) <<appoPatient[docID][j]<<setw(20)<<appoAge[docID][j]<<setw(20)<<appoGender[docID][j]<<setw(30)<<appoDisease[docID][j]  <<endl ;
          found = true ;
         }
      }   
      if(!found){
        cout<<"No Data!!" <<endl <<endl ;
      }
} 
// Doctor  2  Appointments lists 

void docA2(string appoPatient[][5],bool appoPFlag[][5],string appoDate[][5],bool appoDFlag[][5],string doctor[],int idD[],bool docFlag[],int maxAppointments,int appoPatientId[][5]){
     cout<<'\n' ; 
     cout<<" ====================="  <<endl ;
     cout<<"        DOCTOR        "  <<endl ;
     cout<<" ====================="  <<endl ;
     cout<<'\n' ;      
     
     bool found1 = false ;
     bool found2 = false ;
     
     cout<<"==============================================" <<endl ; 
     cout<<"Doctor's ID\t\t"<< "Doctor' Name \t" <<endl  ;
     cout<<"==============================================" <<endl ;
   
     if(docFlag[1] == true ){
             
     cout<<idD[1] <<"\t\t\t" << doctor[1] << endl ; 
            
     found1 = true ;
     }
     if(found1){
      cout<<"==========================================================================" <<endl ;
      cout<<left ;
      cout<<setw(20) <<"Patient's Id "<<setw(30) <<"Patient's Name "<< "Appointments" <<endl ;
      cout<<"===========================================================================" <<endl ;
      }
             
      for(int j= 0 ;j<maxAppointments ; j++){
         if(appoPFlag[1][j] == true){
            cout<<setw(20)<<appoPatientId[1][j]<< setw(30) <<appoPatient[1][j] <<appoDate[1][j] <<endl;
            found2 = true ;
            }
          }
          if(!found1){
              cout<<"No Doctors Have been added yet By Admin ! "<<endl <<endl  ;
          }
          if(!found2){
              cout<<"This Doctor has no appointments Scheduled.!" <<endl <<endl  ;
         }

}

// Doctor  1  Patients Details

void docP3(string appoPatient[][5],bool appoPFlag[][5],string  appoGender[][5] ,string  appoDisease[][5] , int appoAge[][5],int maxAppointments,int appoPatientId[][5]){
  
      bool found = false ; 
      int docID = 2 , id;
      cout<<'\n' ; 
      cout<<" ====================="  <<endl ;
      cout<<"        DOCTOR        "  <<endl ;
      cout<<" ====================="  <<endl ;
      cout<<'\n' ; 
      cout<<"Enter Patient Id to see thier details : "  ;
      id = getInt() ;   

      cout<<"=================================================================================================="<<endl ; 
      cout<<"Patient's Name \t"<<"  Patient's Name \t\t"<<"  Patient's Age\t\t"<<"Gender\t\t"<<"Disease" <<endl;
      cout<<"=================================================================================================="<<endl ; 
      for(int j= 0 ;j<maxAppointments ;j++){
         if(appoPFlag[docID][j] == true && id == appoPatientId[docID][j]){
          cout<<left ;  
          cout<<setw(20)<< appoPatientId[docID][j] <<setw(30) <<appoPatient[docID][j]<<setw(20)<<appoAge[docID][j]<<setw(20)<<appoGender[docID][j]<<setw(30)<<appoDisease[docID][j]  <<endl ;
          found = true ;
         }
      }   
      if(!found){
        cout<<"No Data!!" <<endl <<endl ;
      }
}
// Doctor  3  Appointments lists
void docA3(string appoPatient[][5],bool appoPFlag[][5],string appoDate[][5],bool appoDFlag[][5],string doctor[],int idD[],bool docFlag[],int maxAppointments,int appoPatientId[][5]){
     cout<<'\n' ; 
     cout<<" ====================="  <<endl ;
     cout<<"        DOCTOR        "  <<endl ;
     cout<<" ====================="  <<endl ;
     cout<<'\n' ;      
     
    bool found1 = false ;
     bool found2 = false ;
     
     cout<<"==============================================" <<endl ; 
     cout<<"Doctor's ID\t\t"<< "Doctor' Name \t" <<endl  ;
     cout<<"==============================================" <<endl ;
   
     if(docFlag[2] == true ){
             
     cout<<idD[2] <<"\t\t\t" << doctor[2] << endl ; 
            
     found1 = true ;
     }
     if(found1){
        cout<<"=============================================================" <<endl ;
        cout<<"Patient's ID \t\t"<<"Patient's Name \t\t"<< "Appointments" <<endl ;
        cout<<"=============================================================" <<endl ;
        }
             
      for(int j= 0 ;j<maxAppointments ; j++){
         if(appoPFlag[2][j] == true){
            cout<<setw(20)<< appoPatientId[2][j]<<setw(30) <<appoPatient[2][j] <<appoDate[2][j] <<endl;
            found2 = true ;
            }
          }
          if(!found1){
              cout<<"No Doctors Have been added yet By Admin ! "<<endl <<endl ;
          }
          if(!found2){
              cout<<"This Doctor has no appointments Scheduled.!" <<endl <<endl  ;
         }

}

// Doctors List 
void docList(string doctor[],string pwdD[],int idD[],bool docFlag[] ,string doctorName [] ,int doctorAge[], string doctorGender[],int dsize){
     bool found = false ;
     cout<<"==========================================================================================================================================================" <<endl ;
     cout<<"No.of \t"<<"Doctor's id \t" << " Doctor's Name \t\t\t" <<"  Doctor's Age \t\t" << "Doctor's Gender\t\t " << "Doctor's UserName \t\t"<<"Doctor's Password " <<endl ; 
     cout<<"==========================================================================================================================================================" <<endl ;
          
     for(int i = 0 , j= 1 ; i<dsize ;i++){
         if(docFlag[i]){
         cout<<left ;   
         cout<<setw(10) << j << setw(15) <<idD[i] <<setw(32)<< doctorName[i] << setw(25) << doctorAge[i] <<setw(25) << doctorGender[i] <<setw(30) <<doctor[i]<< setw(25)<< pwdD[i] <<endl ;
         found = true ;   
         j++ ;
         }
      }
     if(!found)
     cout<<"No Doctors Available in Hospital . " <<endl <<endl ;  
}

//Doctors to be represented in Appointments Section
void docListA(string doctorName[],int idD[] ,bool docFlag[] , int dsize ){
     bool found = false ;
     cout<<"=======================================================" <<endl ;
     cout<<"No.of \t"<<"Doctor's id \t" << "     Doctor's UserName \t"   <<endl ; 
     cout<<"=======================================================" <<endl ;
          
     for(int i = 0 , j= 1 ; i<dsize ;i++){
         if(docFlag[i]){
         cout<<left ;
         cout<<setw(10) << j <<setw(20) <<idD[i]  <<"Dr. "<< doctorName[i]   <<endl ;
         found = true ;   
         j++ ;
         }
      }
     if(!found)
     cout<<"No Doctors Available in Hospital . " <<endl <<endl  ;  
}

void appoinList(string appoPatient[][5],bool appoPFlag[][5],string appoDate[][5],bool appoDFlag[][5],string doctor[],int idD[],bool docFlag[],int dsize){

     int inputIdD ;
     bool found1 = false ;
     bool found2 = false ;
     cout<<" Enter Doctor's ID to check thier list " ;
     inputIdD =  getValidinput123() ;
     inputIdD = inputIdD -1 ;

     cout<<"==============================================" <<endl ; 
     cout<<"Doctor's ID\t\t"<< "Doctor' Name \t" <<endl  ;
     cout<<"==============================================" <<endl ;

          
          
     if(docFlag[inputIdD] == true ){
             
     cout<<idD[inputIdD] <<"\t\t\t" << doctor[inputIdD] << endl ; 
            
     found1 = true ;
     }
     if(found1){
        cout<<"==============================================" <<endl ;
        cout<<"Patient's Name \t\t"<< "Appointments" <<endl ;
        cout<<"==============================================" <<endl ;
        }
             
      for(int j= 0 ;j<dsize ; j++){
         if(appoPFlag[inputIdD][j] == true){
            cout<<appoPatient[inputIdD][j] <<"\t\t\t"<<appoDate[inputIdD][j] <<endl;
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
string validDate(string appoDate[][5], int inputidD,int maxAppointments){
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
             for(int j =0; j<maxAppointments ; j++){
                if(date == appoDate[inputidD][j]){
                  cout<<"This date is already scheduled . So please select other date ." <<endl ;
                  dateFound = true ;
                  break;                
                  }
             }  
             if(dateFound) continue; 

             return date ;
       }
} 

// Save Patient Data
void savePatientData(string patient[] ,int ageP[] , bool pFlag[] , int idP[],string gender[],string disease[] , int psize){

     ofstream data ;
     data.open("patients.txt") ;   
     if(data.is_open()){
       for(int i= 0 ; i<psize ; i++){
           if(pFlag[i] == true){
              data<< idP[i] << "," << patient[i] << "," << ageP[i] << "," << gender[i] << "," <<disease[i] <<endl ; 
           }
       }
       data.close() ;
     }
     else {
       cout<<"Failed to open Patients Files !! " <<endl ;
     }   

}
// Save Appointments
void saveAppointments(string appoPatient[][5],bool appoPFlag[][5],string appoDate[][5],bool appoDFlag[][5],string doctor[],string  appoGender[][5] ,string  appoDisease[][5] , int appoAge[][5] , int maxAppointments,int dsize,int appoPatientId[][5] ){

     ofstream data ;
     data.open("appointments.txt") ;
     if(data.is_open()){
      for(int i = 0 ; i<dsize ; i++){
        for(int j = 0 ; j< maxAppointments ; j++){
          if(appoPFlag[i][j] && appoDFlag[i][j] )
            data << i+1 << "," << doctor[i] <<","<<appoPatientId[i][j] <<"," <<appoPatient[i][j] << "," << appoAge[i][j] <<","<<appoGender[i][j] <<"," <<appoDisease[i][j]  << ","<<appoDate[i][j]  <<endl ; 
           }
      } 
           data.close() ;
      }
     else{
      cout<<"Failed to open appointments file !! " <<endl ;
     }

}
// save Doctors data
void saveDoctorsData(string doctor[],string pwdD[],int idD[],bool docFlag[] ,string doctorName [] ,int doctorAge[], string doctorGender[],int dsize ){
      ofstream data ;
      data.open("doctor.txt") ;
      if(data.is_open()){
        for(int i = 0 ; i< dsize ; i++){
           if(docFlag[i]  == true){
             data<< idD[i] <<"," << doctorName[i] <<","<< doctorAge[i]<<","<<doctorGender[i]<<","<<doctor[i]<<"," <<pwdD[i] <<endl ;
           } 
        }
        data.close() ;
      }
      else{
        cout<<"Unable to open receptionist file. "<<endl ;
      }
}
// save receptionist data
void saveReceptionist(string receptionist[] , string pwdR[],int idR[] ,bool recFlag[] ,string receptionistName[],int receptionistAge[], string receptionistGender[], int rsize){
    ofstream data ;
    data.open("receptionist.txt") ;
    if(data.is_open()){
      for(int i= 0; i<rsize ; i++){
         if(recFlag[i]){
          data<< idR[i] <<","<< receptionistName[i] <<","<<receptionistAge[i]<<","<<receptionistGender[i]<<","<<receptionist[i]<<","<<pwdR[i] <<endl ;
         }
      }
      data.close() ; 
    }
    else{
      cout<<"Unable to open Receptionist File. "<<endl ;
    }
}
// load receptionist data

void loadReceptionistData(string receptionist[] , string pwdR[],int idR[] ,bool recFlag[] ,string receptionistName[],int receptionistAge[], string receptionistGender[], int rsize){
     ifstream load ;
     load.open("receptionist.txt") ;
     if(load.is_open()){
     for(int i = 0 ;i< rsize ; i++){

        load>> idR[i] ;
        load.ignore() ;
        if( getline(load,receptionistName[i],',') 
            && load >> receptionistAge[i] 
            && load.ignore() 
            && getline(load,receptionistGender[i] , ',')
            && getline(load,receptionist[i],',' )
            && getline(load,pwdR[i])){

            recFlag[i] = true ;
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

void loadDoctorData(string doctor[],string pwdD[],int idD[],bool docFlag[] ,string doctorName [] ,int doctorAge[], string doctorGender[],int dsize){
     ifstream load ;
     load.open("doctor.txt") ;
     if(load.is_open()){
     for(int i = 0 ;i< dsize ; i++){

        load>> idD[i] ;
        load.ignore() ;

        if( getline(load,doctorName[i],',') 
            && load >> doctorAge[i]
            && load.ignore() 
            && getline(load,doctorGender[i] ,',') 
            && getline(load,doctor[i],',') 
            && getline(load,pwdD[i] ) ){

            docFlag[i] = true ;

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

// load receptionist data
void loadPatientData(string patient[],int idP[],bool pFlag[] , int ageP[],string gender[] , string disease[] , int psize,bool bed[]){
    ifstream load ;
    load.open("patients.txt") ;
    if(load.is_open()){
      for(int i = 0; i<psize ; i++){
         load>>idP[i]  ;
         load.ignore() ;

         if(
         getline(load,patient[i],',') && 
         load>>ageP[i]  &&
         load.ignore()  && 
         getline(load,gender[i],',') && 
         getline(load,disease[i]) ){
           pFlag[i] = true ;
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

void loadAppointments(string appoPatient[][5], int appoAge[][5], bool appoPFlag[][5], string appoDate[][5], bool appoDFlag[][5], string appoGender[][5],string appoDisease[][5], int dsize, int maxAppointments,int appoPatientId[][5]) {
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
                if (!appoPFlag[Id][j] && !appoDFlag[Id][j]) {
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
                        
                        appoPatientId[Id][j] = patientId ;
                        appoPatient[Id][j] = patient ;
                        appoAge[Id][j] = age ;
                        appoGender[Id][j] = gender ;
                        appoDisease[Id][j] = disease ;
                        appoDate[Id][j] = date ;

                        appoPFlag[Id][j] = true;
                        appoDFlag[Id][j] = true;
                    }
                }
            }
        }
        load.close();
    } else {
        cout << "Failed to load Appointments!!" << endl;
    }
}

// This Function will ensure that that receptionist userName is specific

string uniqueRecUser(string receptionist[],int rsize  ){
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

      for(int i = 0 ; i<rsize ; i++){
        if(userName == receptionist[i]){
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
    
}

// This Function will ensure that that Doctor userName is specific

string uniqueDocUser(string doctor[] , int dsize ){
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

      for(int i = 0 ; i<dsize ; i++){
        if(userName == doctor[i]){
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
