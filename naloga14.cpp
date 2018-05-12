#include <iostream>
#include <string>
#include <fstream> 
#include <list> 

int main()
{
	int x=1;
	int i=2;
    std::list<std::string> myList;

    std::fstream myFile("evidenca.txt");	
    std::ofstream outFile("katalog.txt");			
    if (!myFile)
    {
        std::cout << "Odpiranje evidenca.txt ni uspelo" << std::endl;
    }
    else
    {
        std::string line;
        while (std::getline(myFile, line))
        {
            myList.push_back(line);
        }
    }
    myFile.close();

    std::string * myArray = new std::string[myList.size()];
    int count = 0;

    std::list<std::string>::iterator iter;
    iter = myList.begin();
    while (iter != myList.end())    
    {
        std::string myString = *iter;
     
        if (!myString.find("Primer"))									//Poisce besede in celotno vrstico prepise
        {	while(x!=0){												
            myArray[count] = myString;
            count++;
            x--;
		};
        }else if(!myString.find(" Koli"))
        {
			myArray[count] = myString;
            count++;
		}else if(!myString.find("Zaporedna"))
        {
			myArray[count] = myString;
            count++;
		}else if(!myString.find(" Cena"))
        {
			myArray[count] = myString;
            count++;
		}else if(!myString.find("Skupna"))
        {
			myArray[count] = myString;
            count++;
		}else if(!myString.find(" Naziv"))
        {
			myArray[count] = myString;
            count++;
		}else if(!myString.find(" Skupna"))
        {	i--;
			if(i==0){
			myArray[count] = myString;
            count++;}
		}
		
        iter++;
    }

    if (count == 0)
    {
        std::cout << "Ni najslo besed." << std::endl;
    }
    else
    {
        
        std::ofstream outFile("katalog.txt", std::ios::app);			//izpis rezultatov v katalog.txt
        if (!outFile)
        {
            std::cout << "Odpiranje datoteke ni uspelo." << std::endl;
        }
        else
        {
            for (int i = 0; i < count; i++)								//z for zanko prepisavljemo.
            {															//presledek se doda tukaj.
				if(i==5){
				outFile << "\n";
				std::cout<< "\n";}
                outFile << myArray[i] << std::endl;						//izpisuje na terminalsko okno ter v datoteko.
                std::cout<< myArray[i] <<std::endl;
            }
        }
        std::cout<< "\n";
        std::cout << "Poiskano in zapisano v novo datoteko, katalog.txt. Hooray :)" << std::endl;		
    }
    delete[] myArray;
    return 0;
}

