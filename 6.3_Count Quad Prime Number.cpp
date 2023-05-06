// 6.3_Count Quad Prime Number.cpp: главный файл проекта.

// ReadNumberOfFile.cpp: главный файл проекта.

#include "stdafx.h"
#include <ctime>
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

const unsigned int n = 999;

bool prime(int p){
	if ( p < 2 ) return false;
    if ( p == 2 ) return true;
    if ( p%2 == 0 ) return false;

	double limit = sqrt((double)p);
    
	for (unsigned i=3; i<=limit; i+=2) {
        if ( (p % i) == 0 ) return false;
    }
	
	return true;
}


int main(array<System::String ^> ^args)
{
	srand(time(NULL));


	ofstream FILE1;					
	FILE1.open("file.txt");			
	if ( FILE1 == NULL ) return 0;	

	int x, count1 = 0;
	for (int i=1; i<=n; i++) {
		x = rand();
		if ((sqrt((double)x)-(int)sqrt((double)x))!=0) { 
			if (prime(x)) {					 
				if ( (rand() % 10) < 5 ){	
					x = x*x;				
					count1 += 1;
				}
			}
		FILE1 << x << "\n";
		}
		else { 
		FILE1 << x+1 << "\n";
		}
	}
	FILE1.close();
	
	cout << "Counter1 prime number = "<< count1 <<  endl <<  endl;
	cout << "========================================" <<  endl;

	ifstream FILE2;					
	FILE2.open("file.txt");			
	if ( FILE2 == NULL ) return 0;	

	int y, count2=0;
	double var;
	while (true) {					
		FILE2 >> y;					
		if (FILE2.eof()) break;		
		
		var = sqrt((double)y);		
		
		cout << y;					
		if ( ((var - (int)var)==0) && (prime((int)var) ) ) { 
			count2 += 1;
			cout << "  " << var << " <- found number"; 
		}
		cout <<  endl;			

	}
	cout << "Counter1 prime number = "<< count1 <<  endl <<  endl;
	cout << endl << "Counter2 prime number = " << count2 << endl << endl;
	FILE2.close();

system("pause");
return 0;

}
