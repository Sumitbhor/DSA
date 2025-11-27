#include"climate.cpp"
class Greenhouse    
{
    public:
        climate climate ;
        int greenhouse_id;
        string name ;
        
        void display(){
            
            cout<<"Plot ID: "<<greenhouse_id<<endl;
            cout<<"Crop Name: "<<name<<endl;
            climate.display() ;

        }
        
};