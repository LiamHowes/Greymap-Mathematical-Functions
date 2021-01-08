#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

void promptScript(){
	cerr<<"Function: cos z*(1/2*sin(x)+(1/2*cos(y)))"<<endl;
	cerr<<"How many levels of precision? ";
}

void numFrames(){
    	cerr<<"How many frames? (1-9999) ";
}

void do_stuff(int grads, int frames){
    double xincrement, yincrement, zincrement;

    xincrement = (11)/(double)grads;
    yincrement = (18)/(double)grads;
    zincrement = (6.28318530718)/(double)frames;
    
    for(int t=0; t<frames; t++){\
	int a = t+1;
	stringstream ss;
	ss<<a;
        string framenumber = ss.str();
        int len = framenumber.length();
        char temp[len];
        for(int w=0; w<sizeof(temp);w++){
		temp[w] = framenumber[w];
	}

        char number[4];
        if(len==4){
            number[0] = temp[0];
            number[1] = temp[1];
            number[2] = temp[2];
            number[3] = temp[3];}
        else if(len==3){
            number[0] = '0';
            number[1] = temp[0];
            number[2] = temp[1];
            number[3] = temp[2];}
        else if(len==2){
            number[0] = '0';
            number[1] = '0';
            number[2] = temp[0];
            number[3] = temp[1];}
        else if(len==1){
            number[0] = '0';
            number[1] = '0';
            number[2] = '0';
            number[3] = temp[0];}

        char filename[19];
        filename[0] = 'f';
        filename[1] = 'r';
        filename[2] = 'a';
        filename[3] = 'm';
        filename[4] = 'e';
        filename[5] = 's';
        filename[6] = '/';
        filename[7] = 'a';
        filename[8] = 'n';
        filename[9] = 'i';
        filename[10] = 'm';
        filename[11] = number[0];
        filename[12] = number[1];
        filename[13] = number[2];
        filename[14] = number[3];
        filename[15] = '.';
        filename[16] = 'p';
        filename[17] = 'g';
        filename[18] = 'm';

        ofstream fout;
        fout.open(filename);
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
        int z = 0 + (double)(t*zincrement);

        for(int i=0; i<grads; i++){
            double  y;
            y = -12 + (double)((i)*yincrement);
            for(int j=0; j<grads; j++){
                double x;
                x= -4 + (double)((j)*xincrement);
                double value;   
                double half = (double)1/(double)2;
                value = ((cos(z))*(half*sin(x))+(half*cos(y))) + 1; // +1 to scale range to 0..2
                data[i][j] = value * 127.5; 
                fout<<(int)data[i][j];
                fout.put(0); // space
            }
            fout.put(10); // LF
        }
    }
}

int main(){
	int graduations;
    	int frames;
	promptScript();
    	cin>>graduations;
    	numFrames();
    	cin>>frames;
    	do_stuff(graduations, frames);
	return 0;
}
