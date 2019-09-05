#include <iostream>
#include <fstream> 
#include <cstdlib> 
#include <ctime> 
#include <iostream>
using namespace std;

int X = 537.2;
int main(){
	float x,y;
	float r2 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/X));
	for(int i = 0; i < 2083; ++i){
		ifstream infile;
		string file = "input4.txt"; 
		infile.open(file);
		while(infile >> x >> y ) cout << x + r2 << " " << y + r2 << endl;
	}
}