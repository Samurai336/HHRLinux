#include "MainApp.h"



int main(int argc, char* argv[])
{


    //printf("I Started!\n");

    //run forever
    while(MainApp::Instance()->OnExecute())

    //clearn up memory
    delete MainApp::Instance();


    //DOne
    return 0;
}
