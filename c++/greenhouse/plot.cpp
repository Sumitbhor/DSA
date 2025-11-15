#include"climate.cpp"
class plot
{
    public:
        climate climate ;
        int plot_id;
        string name ;
        
        void display(){
            
            cout<<"Plot ID: "<<plot_id<<endl;
            cout<<"Crop Name: "<<name<<endl;
            climate.display() ;

        }
        
};