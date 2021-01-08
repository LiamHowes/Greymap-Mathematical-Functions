#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

void promptScript(){
	std::cerr<<"Function: cos z*(1/2*sin(x)+(1/2*cos(y)))"<<std::endl;
	std::cerr<<"How many levels of precision? ";
}

void do_stuff(int grads){
       	ofstream fout;
    	fout.open("file0001.pgm");
	// set the header //
    	fout.put(80); // P
	fout.put(50); // 2
    	fout.put(10); // LF
   	fout<<grads; //width
    	fout.put(0); // space
    	fout<<grads; //height
    	fout.put(10); // LF
    	fout<<255; // max value
    	fout.put(10); // LF

	double data[grads][grads];
    	double xincrement, yincrement;
    	int z = 0;

    	xincrement = (11)/(double)grads;
    	yincrement = (18)/(double)grads;

    	for(int i=0; i<grads; i++){
        	double  y;
		y = -12 + (double)((i)*yincrement);
        	for(int j=0; j<grads; j++){
            		double x;
                	x = -4 + (double)((j)*xincrement);
                	double value;
                	double half = (double)1/(double)2;
                	value = cos(z)*((half*sin(x))+(half*cos(y))) + 1; // +1 to scale range to 0..2
                	data[i][j] = value * 127.5; 
                	fout<<(int)data[i][j];
                	fout.put(0);
        	}
        	fout.put(10); // LF
    	}
}

int main(){
	int graduations;
	promptScript();
	std::cin>>graduations;
	do_stuff(graduations);
	return 0;
}
