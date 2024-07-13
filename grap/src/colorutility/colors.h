#pragma once
#include "grap.h"
typedef struct
{
	FLOAT h;
	FLOAT s;
	FLOAT l;
} HSL;
typedef union _RGBQUAD {
	COLORREF rgb;
	struct {
		BYTE b;
		BYTE g;
		BYTE r;
		BYTE Reserved;
	};
}_RGBQUAD, * PRGBQUAD;

HSL rgb2hsl(RGBQUAD rgb);
RGBQUAD hsl2rgb(HSL hsl);