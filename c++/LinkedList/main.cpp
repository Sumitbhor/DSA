 #include"uimanager.cpp"
int main (){
    LinkedList list ;
    uimanager ui ;
    int choice ;
    while (true)
    {
        ui.menu();
        choice = ui.getchoice(choice);
        switch (choice) {
            case 1:
                list = ui.insertNode(list);
                break;
            case 2:
                ui.searchNode(list);
                break;
            case 3:
                ui.displayNodes(list);
                break;
            case 4:
                list = ui.removeNode(list);
                break;
            case 5:
                ui.exitProgram();
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    
}
//g++ Node.cpp LinkedList.cpp uimanager.cpp main.cpp -o main.exe