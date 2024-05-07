#include<bits/stdc++.h>

using namespace std;

class Person
{
    string name;
    int age;
    int id;
public:

Person()
{

}
    Person(string name ,int age ):name(name),age(age)
    {

    }

    void Display_person()
    {
        cout <<"Name: "<< name << ' ' << "Age: "<<age << ' ';
    }
};

class Patient :public Person
{
    string diagnosis;
public:
    int patient_id;

Patient()
{

}
    Patient(int patient_id,string diagnosis,int age, string name):patient_id(patient_id),diagnosis(diagnosis),Person(name,age)
    {

    }
    int Get_patientid()
    {
        return patient_id;

    }


   void Display_patient()
   {

    cout <<"Patient_ID: " <<patient_id<< ' ' ;
    Patient::Display_person();
    cout  << "Diagnosis: "<<diagnosis <<endl ;
   }

};

class Doctor:public Person
{
    string specialization;

    public:
    int doctor_id;
    Doctor()
    {

    }
    Doctor(int doctor_id,string specialization,int age,string name):doctor_id(doctor_id),specialization(specialization),Person(name,age)
    {

    }

    int Get_doctorid()
    {
        return doctor_id;

    }
    void Display_doctor()
    {
        cout << "Doctor_ID: "<< doctor_id << ' '  ;
         Doctor::Display_person();
        cout <<"Specialization: " <<specialization << endl;

    }
};
class Appointment
{
    Patient p;
    Doctor d;
    string appointment_date;
public:
    Appointment()
    {

    }

    Appointment(string appointment_date,int patient_id,string diagnosis,int age_patient,string name_patient,int doctor_id,string specialization,int age_doctor,string name_doctor):appointment_date(appointment_date),p(patient_id,diagnosis,age_patient,name_patient),d(doctor_id,specialization,age_doctor,name_doctor)
    {

    }
    void Display_appointment()
    {
        cout << "Appointment_Date: " << appointment_date << endl  ;
        cout << "\n";
        p.Display_patient();
        cout << endl;
        d.Display_doctor();
        cout << endl;
    }

};

 class Hospital
{
Patient patient[100] ;
Doctor doctor[100];
Appointment appointment[200];
static int cont_patient;
 static int cont_doctor;
static int cont_appointment;

public:
Hospital()
{

}
   void Add_patient(Patient pa)
    {
        if(cont_patient<100)
        {
        patient[cont_patient]=pa;
        cont_patient++;
        }

        else
        {
            cout << "The patient IS Fully\n";
        }

    }

    void Add_doctor(Doctor doc)
    {
        if(cont_doctor<100)
        {
        doctor[cont_doctor]=doc;
        cont_doctor++;
        }


        else
        {
            cout << "The Doctor IS Fully\n";

        }
    }

    void scheduale_appointment(Appointment apo)
    {
        if(cont_appointment<200)
        {
        appointment[cont_appointment]= apo;
        cont_appointment++;
        }

        else
        {
         cout << "The Appointment Is Fully\n";
        }

    }

    void Display_appointment()
    {

    cout <<"Scheduled Appointments:"<<endl;
    for( static int i = 0 ; i <cont_appointment;i++)
    {
        cout << "Appointment: "<< i+1 << endl;
        appointment[i].Display_appointment();
        cout << endl;
    }


    }

    void find_patient(int id_patient)
    {
        for(int i =0 ; i < cont_patient; i++)
        {
            if(patient[i].patient_id==id_patient)
            {
                cout << "The Patient Is Found:\n";
            patient[i].Display_patient();
            cout << endl;
            return;
            }
        }

        {
        cout << "The Patient IS Not There Is\n";
        }
    }

    void find_doctor(int id_doctor)
    {

        for(int i =0 ;i < cont_doctor; i++)
        {
                if(doctor[i].doctor_id==id_doctor)
                {
                    cout << "The Doctor IS Found:\n";
                doctor[i].Display_doctor();
                cout <<endl;
                return;
                }


        }
                {
                    cout << "The Doctor IS Not There Is\n";
                }
    }

};

int Hospital::cont_patient=0;
int Hospital::cont_doctor=0;
int Hospital::cont_appointment=0;

int main()
{
Hospital h1;
Patient p1(1,"Erythema",78,"Ahmed");
h1.Add_patient(p1);
Doctor d1(1,"Skin",33,"Mohamed");
h1.Add_doctor(d1);
Appointment ap1("Sunday",1,"Erythema",78,"Ahmed",1,"Skin",33,"Mohamed");
h1.scheduale_appointment(ap1);
h1.Display_appointment();

Hospital h2;
Patient p2(2,"Cancer",44,"Salim");
h2.Add_patient(p2);
Doctor d2(2,"Colon Cancer",55,"Omar");
h2.Add_doctor(d2);
Appointment ap2("Monday",2,"Cancer",44,"Salim",2,"Colon Cancer",55,"Omar");
h2.scheduale_appointment(ap2);
h2.Display_appointment();

Hospital h3;
Patient p3(3,"Cancer",22,"Sam");
h3.Add_patient(p3);
Doctor d3(3,"Colon Cancer",33,"islam");
h3.Add_doctor(d3);
Appointment ap3("Tuesday",3,"Cancer",22,"Sam",3,"Colon Cancer",33,"islam");
h3.scheduale_appointment(ap3);
h3.Display_appointment();

Patient p4(4,"Erythema",23,"Ayman");
h3.Add_patient(p4);
 Doctor d4(4,"Skin",67,"Seif");
h3.Add_doctor(d4);
Appointment ap4("Friday",4,"Erythema",23,"Ayman",4,"Skin",67,"Seif");
h1.scheduale_appointment(ap4);
h1.Display_appointment();


h1.find_doctor(1);
h1.find_patient(1);

h2.find_doctor(2);
h2.find_patient(2);

h3.find_doctor(3);
h3.find_patient(3);

h3.find_doctor(4);
h3.find_patient(4);

}