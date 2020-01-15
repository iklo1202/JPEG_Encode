#include "jpegEncoder.h"


JPEG_Encoder::JPEG_Encoder(int width, int height)
{
	this->width = width;
	this->height = height;

	this->yImg = new kentImg(width, height);
	this->uImg = new kentImg(width, height);
	this->vImg = new kentImg(width, height);
}

JPEG_Encoder::~JPEG_Encoder()
{
	delete yImg;
	delete uImg;
	delete vImg;
}

void JPEG_Encoder::Encode(kentImg* bImg, kentImg* gImg, kentImg* rImg)
{
	cvtYUV(bImg, gImg, rImg);


}



void JPEG_Encoder::cvtYUV(kentImg* bImg, kentImg* gImg, kentImg* rImg)
{

	unsigned char* pB = bImg->data;
	unsigned char* pG = gImg->data;
	unsigned char* pR = rImg->data;
	unsigned char* pY = this->yImg->data;
	unsigned char* pU = this->uImg->data;
	unsigned char* pV = this->vImg->data;

	for (int i = 0; i < this->height; ++i)
	{
		for (int j = 0; j < this->width; ++j)
		{
			*pY = 0.2990* (*pR - *pG) + *pG + 0.1140 * (*pB - *pG);
			*pU = 0.5643 * (*pB - *pY);
			*pV = 0.7133 * (*pR - *pY);

			pB++; pG++; pR++;
			pY++; pU++; pV++;
		}
	}
}


