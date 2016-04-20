//
//  main.cpp
//  stat_database
//
//  Created by Guillaume Hajek on 7/15/14.
//  Copyright (c) 2014 Wharton. All rights reserved.
//

#include <iostream>
#include <string>
#include <math.h>
#include <cmath>
#include <fstream>
#include <vector>
#include <numeric>




void trucks_input();
void show_all();
void data();
void graph();
void edit();
void quit();



int main()
{

    int choice; 
    
    std::cout<< "Press 1 to input data"<<"\n";
    
    std::cout<< "Press 2 to view all data"<<"\n";
    
    std::cout<< "Press 3 to view statistical results"<<"\n";
    
    std::cout<< "Press 4 to graph the results"<<"\n";
    
    std::cout<< "Press 5 to edit the text file"<<"\n";
    
    std::cout<< "Press 6 to quit the software"<<"\n";
    
    std::cin>> choice;
    
    
    
    switch (choice){
            
        case 1:
            
          trucks_input();
            
            break;
        
            
            
        case 2: 
            
          show_all();
            
           break;
            
            
        case 3:
            
            data();
            
            break;
            
            
        case 4:
            
            graph();
            
            break;
            
            
        case 5:
            
            edit();
            
            break;
            
            
        case 6:
            
            quit();
            
            break;
            
        std::cin.get();
            
    } 
    

}

//input data in file 

void trucks_input(){
    
    int number_of_trucks;
    
    std::ofstream truck_data;
    
    truck_data.open("truck_data.txt", std::ofstream::out|std::ofstream::app);
    
    std::cout<< "Enter # of trucks"<<"\n";
    std::cin>> number_of_trucks;
    
    truck_data<<number_of_trucks<<"\n";
    
    
    
    truck_data.close();
    
    main();
    

}

// show all data in file 

void show_all(){


    int number_of_trucks;
    int i=0;
    
    std::ifstream truck_data("truck_data.txt");
    
    while(!truck_data.eof()){
        
        truck_data>>number_of_trucks;
        
        i++;
        
        if(truck_data.eof()){
            
            break;
        }
        
        std::cout<<" # of trucks data"<<" "<< i <<":"<<"\n";
        std::cout<<number_of_trucks<<"\n";
        
        
    }
    
    main();

}
//store data in a vector that can resize automatically and perform stats on data stored 

void data(){
    
    int number_of_trucks;

    
    std::vector<int> trucks;
    
    
    
    std::ifstream truck_data("truck_data.txt");

    while(!truck_data.eof()){
        
                    
        truck_data>>number_of_trucks;
        
        
         trucks.push_back(number_of_trucks); 
           
        
        if(truck_data.eof()){
            
         break;
          
       }
        
    }
        
// sum all the elements of the array when you get to the end of the file to get all the data in one shot
    
//Average
    
    for(int i=0;i<trucks.size()-1;i++){
        
        std::cout<<" # of trucks data"<<" "<< i <<":"<<"\n";
        std::cout<<trucks[i]<<"\n";
        std::cout<<"       "<<"\n";
        
        
    }
    
  int sum = std::accumulate(trucks.begin(), trucks.end(), 0);
    
    
    std::cout<<"The sum of the data sample is:"<<"\n";  
    std::cout<<sum<<"\n";
    
    int i = trucks.size()-1;
    
    float average = sum/i;
    
    std::cout<<"The average of the data sample is:"<<"\n";
    
    std::cout<< average<<"\n";
    
    //Variance
    
    int sum_var = 0;
    
    for (int i = 0; i<trucks.size()-1;i++){
        
    
        sum_var += (trucks[i]-average)*(trucks[i]-average);
        
        
    }
    
    
    float variance = sum_var/(i-1);
    
    float std_dev = sqrt(variance);
    
    std::cout<<"The variance of the data sample is:"<<"\n";
    std::cout<< variance<<"\n";
    std::cout<<"The standard deviation of the data sample is:"<<"\n";
    std::cout<< std_dev<<"\n";
        
  //Median  
    
    int temp=0;
    
    
    for (int i=1; i<trucks.size()-1;i++){

        
        for (int j=0; j<trucks.size()-2;j++){
            
            if(trucks[i]>trucks[i+1]){
                
                trucks[i]=temp;
                trucks[i]=trucks[i+1];
                trucks[i+1]=temp;
                
            }
            
        }
        
    }
    
   
    int median_spot= (trucks.size())/2;
    
    int median = trucks[median_spot];
    
    std::cout<<"The median of the data sample is:"<<"\n";
    std::cout<< median<<"\n";
    
         main();
    
}







void quit(){
    
    
    
    std::cout<<"You have succesfully exited the software"<<"\n"; 
    
}
    
    
    

    


  
    
    
    
    
    
    
    
    
    
    
    
    
    

