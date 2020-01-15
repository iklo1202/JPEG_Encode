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


class ImageNode
{
public:
	ImageNode(kentImg* img)
	{
		this->img = new	kentImg(img->width, img->height);
		memcpy(this->img->data, img->data, img->width*img->height);
		this->next = NULL; 

	};

	~ImageNode()
	{
		delete img;
		img = NULL;
		next = NULL;

	}


	kentImg* img;
	ImageNode* next;
};


class ImageList
{
public:
	ImageList()
	{
		this->pHead = NULL;
		this->pTail = NULL;

	};

	void Add(ImageNode* node)
	{
		if (pHead == NULL)
		{
			pHead = node;
			pTail = node;
			pTail->next = NULL;
		}
		else
		{
			pTail->next = node;
			pTail = pTail->next;
			pTail->next = NULL;
		}



	}

	~ImageList()
	{
		ImageNode* pDel = pHead;
		while (pDel != NULL)
		{
			pHead = pHead->next;
			delete pDel;
			pDel = pHead;
		}

		pHead = NULL;
		pTail = NULL;
	}


	ImageNode* pHead = NULL;
	ImageNode* pTail = NULL;

};




#endif