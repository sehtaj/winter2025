/*
 * CS106L Assignment 3: Make a Class
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */

 #include "class.h"
 #include <iostream>
 using namespace std;
 
 void sandbox() {
     // STUDENT TODO: Construct an instance of your class!
     
     Student student1;
     cout<<"Student Name: "<< student1.getName()<< "\n";
 
     Student student2("Sehtaj", 8.5);
     cout<<"Student Name: "<< student2.getName()<< "\n";
 
     student1.setName("Jashan");
     cout<<"Updated Student Name: "<< student1.getName()<< "\n";
 }
 