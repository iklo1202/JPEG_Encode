#include "basic.h"


kentImg::kentImg(int width, int height)
{
	this->width = width;
	this->height = height;
	this->data = new unsigned char[width*height];
}


kentImg::kentImg(int width, int height, unsigned char* data)
{
	this->width = width;
	this->height = height;
	int len = width * height;
	this->data = new unsigned char[width*height];
	memcpy(this->data, data, len);
}

kentImg::~kentImg()
{
	delete[] data;
	data = NULL;
}


