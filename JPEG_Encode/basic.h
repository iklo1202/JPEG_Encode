#ifndef __BASIC__
#define __BASIC__

#include <cstdlib>
#include <iostream>
using namespace std;

class kentImg
{
public:
	kentImg(int width, int height);
	kentImg(int width, int height, unsigned char* data);
	~kentImg();

	int width;
	int height;
	unsigned char* data;
};







#endif