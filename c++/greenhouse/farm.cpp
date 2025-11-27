#include"greenhouse.cpp"
class farm
{
   public:
        static const int row=2 ;
        static const int column= 5;
        Greenhouse greenhouse[row][column];
        void assignplot(){
            greenhouse[0][0].greenhouse_id = 1;
            greenhouse[0][0].name="tomato";
            greenhouse[0][1].greenhouse_id = 2;
            greenhouse[0][1].name="potato";
            greenhouse[0][2].greenhouse_id = 3;
            greenhouse[0][2].name="onion";
            greenhouse[0][3].greenhouse_id = 4;
            greenhouse[0][3].name="bringal";  
            greenhouse[0][4].greenhouse_id = 5;
            greenhouse[0][4].name="cabbage";
            greenhouse[1][0].greenhouse_id = 6;
            greenhouse[1][0].name="carrot";
            greenhouse[1][1].greenhouse_id = 7;
            greenhouse[1][1].name="spinach";
            greenhouse[1][2].greenhouse_id = 8;
            greenhouse[1][2].name="lettuce";
            greenhouse[1][3].greenhouse_id = 9;
            greenhouse[1][3].name="cucumber";
            greenhouse[1][4].greenhouse_id = 10;
            greenhouse[1][4].name="pepper";
            
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < column; j++){
                    
                    greenhouse[i][j].climate.temperature=rand()%45;
                    greenhouse[i][j].climate.humidity=rand()%101;
                    greenhouse[i][j].climate.co2_level=(rand() % 2000) + 300;
                    greenhouse[i][j].climate.light_intensity=(rand() % 10000); 
                    greenhouse[i][j].climate.soil_moisture=(rand() % 101);
                }
            }
        }
        
        void display(){
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < column; j++)
                { 
                    greenhouse[i][j].display();
                }
                 cout<<"\n***************************************************\n"<<endl;
            }
            
        }
        
        
};