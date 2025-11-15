#include"plot.cpp"
class farm
{
   public:
        static const int length=2 ;
        static const int width= 5;
        plot plot[length][width];
        void assignplot(){
            plot[0][0].plot_id = 1;
            plot[0][0].name="tomato";
            plot[0][1].plot_id = 2;
            plot[0][1].name="potato";
            plot[0][2].plot_id = 3;
            plot[0][2].name="onion";
            plot[0][3].plot_id = 4;
            plot[0][3].name="bringal";  
            plot[0][4].plot_id = 5;
            plot[0][4].name="cabbage";
            plot[1][0].plot_id = 6;
            plot[1][0].name="carrot";
            plot[1][1].plot_id = 7;
            plot[1][1].name="spinach";
            plot[1][2].plot_id = 8;
            plot[1][2].name="lettuce";
            plot[1][3].plot_id = 9;
            plot[1][3].name="cucumber";
            plot[1][4].plot_id = 10;
            plot[1][4].name="pepper";
            
            for (int i = 0; i < length; i++)
            {
                for (int j = 0; j < width; j++){
                    
                    plot[i][j].climate.temperature=rand()%45;
                    plot[i][j].climate.humidity=rand()%101;
                    plot[i][j].climate.co2_level=(rand() % 2000) + 300;
                    plot[i][j].climate.light_intensity=(rand() % 10000); 
                    plot[i][j].climate.soil_moisture=(rand() % 101);
                }
            }
        }
        
        void display(){
            for (int i = 0; i < length; i++)
            {
                for (int j = 0; j < width; j++)
                { 
                    plot[i][j].display();
                }
                 cout<<"\n***************************************************\n"<<endl;
            }
            
        }
        
        
};