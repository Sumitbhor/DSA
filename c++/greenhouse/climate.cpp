#include <iostream>
#include <string>
using namespace std;
class climate
{
    public :
        float temperature ;
        float humidity;
        float co2_level;
        float light_intensity;
        float soil_moisture;

    climate(){
        temperature=10;
        humidity=50;
        co2_level=400;
        light_intensity=300;
        soil_moisture=30;
        
    }
   // display climate function 
    void display(){
        cout<<"temperature: "<<temperature<<endl;
        cout<<"humidity: "<<humidity<<endl;
        cout<<"co2_level: "<<co2_level<<endl;
        cout<<"light_intensity: "<<light_intensity<<endl;
        cout<<"soil_moisture: "<<soil_moisture<<endl;
        
       cout<<"\n***************************************************\n"<<endl;
    }
};