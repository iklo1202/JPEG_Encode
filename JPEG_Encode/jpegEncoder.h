#ifndef __JPEG_ENCODER__
#define __JPEF_ENCODER_

#include "basic.h"


class JPEG_Encoder
{
public:
	JPEG_Encoder(int width, int height);
	~JPEG_Encoder();
	
	void Encode(kentImg* bImg, kentImg* gImg, kentImg* rImg);
	
	
	
	
//private:
	int width;
	int height;
	kentImg* yImg;
	kentImg* uImg;
	kentImg* vImg;

	void cvtYUV(kentImg* bImg, kentImg* gImg, kentImg* rImg);

};




#endif

