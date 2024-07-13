#include "graphic.h"

DWORD WINAPI graphic1()
{
	HDC dc = GetDC(NULL);
	HDC dcCopy = CreateCompatibleDC(dc);
	int w = GetSystemMetrics(0);
	int h = GetSystemMetrics(1);
	BITMAPINFO bmpi = { 0 };
	HBITMAP bmp;

	bmpi.bmiHeader.biSize = sizeof(bmpi);
	bmpi.bmiHeader.biWidth = w;
	bmpi.bmiHeader.biHeight = h;
	bmpi.bmiHeader.biPlanes = 1;
	bmpi.bmiHeader.biBitCount = 32;
	bmpi.bmiHeader.biCompression = BI_RGB;
	HSL hslcolor;
	RGBQUAD* rgbquad = NULL;

	bmp = CreateDIBSection(dc, &bmpi, DIB_RGB_COLORS, (void**)&rgbquad, NULL, 0);
	SelectObject(dcCopy, bmp);

	INT i = 0;

	while (1)
	{
		StretchBlt(dcCopy, 0, 0, w, h, dc, 0, 0, w, h, SRCCOPY);

		RGBQUAD rgbquadCopy;

		for (int x = 0; x < w; x++)
		{
			for (int y = 0; y < h; y++)
			{
				int index = y * w + x;

				double fractalX = (2.5f / w);
				double fractalY = (1.90f / h);

				double cx = x * fractalX - 2.f;
				double cy = y * fractalY - 0.95f;

				double zx = 0;
				double zy = 0;

				int fx = 0;

				while (((zx * zx) + (zy * zy)) < 10 && fx < 50)
				{
					double fczx = zx * zx - zy * zy + cx;
					double fczy = 2 * zx * zy + cy;

					zx = fczx;
					zy = fczy;
					fx++;

					rgbquad[index].rgbRed += fx;
					rgbquad[index].rgbGreen += fx;
					rgbquad[index].rgbBlue += fx;
				}
			}
		}

		i++;
		StretchBlt(dc, 0, 0, w, h, dcCopy, 0, 0, w, h, SRCCOPY);
	}
}

DWORD WINAPI graphic2()
{
	HDC hdc = GetDC(NULL);
	HDC hdcC = CreateCompatibleDC(hdc);
	int sw = GetSystemMetrics(0), sh = GetSystemMetrics(1);
	BITMAPINFO bmpi = { 0 };
	HBITMAP bmp;
	bmpi.bmiHeader.biSize = sizeof(bmpi);
	bmpi.bmiHeader.biWidth = sw;
	bmpi.bmiHeader.biHeight = sh;
	bmpi.bmiHeader.biPlanes = 1;
	bmpi.bmiHeader.biBitCount = 32;
	bmpi.bmiHeader.biCompression = BI_RGB;
	RGBQUAD* rgbquad = NULL;
	HSL hslcolor;
	bmp = CreateDIBSection(hdc, &bmpi, DIB_RGB_COLORS, (void**)&rgbquad, NULL, 0);
	SelectObject(hdcC, bmp);
	INT i = 0;
	while (1)
	{
		hdc = GetDC(NULL);
		StretchBlt(hdcC, 0, 0, sw, sh, hdc, 0, 0, sw, sh, SRCCOPY);
		RGBQUAD rgbquadCopy;

		for (int x = 0; x < sw; x++)
		{
			for (int y = 0; y < sh; y++)
			{
				int index = y * sw + x;
				int j = 6 * i;

				int fx = (int)(j + (j * sin(x / 20.0)) + j + (j * sin(y / 10.0)) + j + (j * sin((x + y) / 20.0)) + j + (j * sin(sqrt((double)(x * x + y * y)) / 10.0))) / 4;

				rgbquadCopy = rgbquad[fx];

				hslcolor = rgb2hsl(rgbquadCopy);
				hslcolor.h = fmod(fx / 300.f + y / sh * .1f, 1.f);

				rgbquad[index] = hsl2rgb(hslcolor);
			}
		}

		i++;

		StretchBlt(hdc, 0, 0, sw, sh, hdcC, 0, 0, sw, sh, SRCCOPY);
	}
}

DWORD WINAPI graphic3() {
	HDC hdc = GetDC(NULL);
	HDC hdcC = CreateCompatibleDC(hdc);
	int sw = GetSystemMetrics(0), sh = GetSystemMetrics(1);
	BITMAPINFO bmpi = { 0 };
	HBITMAP bmp;
	bmpi.bmiHeader.biSize = sizeof(bmpi);
	bmpi.bmiHeader.biWidth = sw;
	bmpi.bmiHeader.biHeight = sh;
	bmpi.bmiHeader.biPlanes = 1;
	bmpi.bmiHeader.biBitCount = 32;
	bmpi.bmiHeader.biCompression = BI_RGB;
	RGBQUAD* rgbquad = NULL;
	HSL hslcolor;
	bmp = CreateDIBSection(hdc, &bmpi, DIB_RGB_COLORS, (void**)&rgbquad, NULL, 0);
	SelectObject(hdcC, bmp);
	INT i = 0;
	while (1)
	{
		hdc = GetDC(NULL);
		StretchBlt(hdcC, 0, 0, sw, sh, hdc, 0, 0, sw, sh, SRCCOPY);
		RGBQUAD rgbquadCopy;

		for (int x = 0; x < sw; x++)
		{
			for (int y = 0; y < sh; y++)
			{
				int index = y * sw + x;
				int j = 6 * i;

				int fx = (int)(j + (j * sin(x / 20.0))) / 4 + i;

				rgbquadCopy = rgbquad[fx];

				hslcolor = rgb2hsl(rgbquadCopy);
				hslcolor.h = fmod(fx / 300.f + y / sh * .1f, 1.f);

				rgbquad[index] = hsl2rgb(hslcolor);
			}
		}

		i++;

		StretchBlt(hdc, 0, 0, sw, sh, hdcC, 0, 0, sw, sh, SRCCOPY);
	}
}

DWORD WINAPI graphic4()
{
	HDC hdc = GetDC(NULL);
	HDC hdcC = CreateCompatibleDC(hdc);
	int sw = GetSystemMetrics(0), sh = GetSystemMetrics(1);
	BITMAPINFO bmpi = { 0 };
	HBITMAP bmp;

	bmpi.bmiHeader.biSize = sizeof(bmpi);
	bmpi.bmiHeader.biWidth = sw;
	bmpi.bmiHeader.biHeight = sh;
	bmpi.bmiHeader.biPlanes = 1;
	bmpi.bmiHeader.biBitCount = 32;
	bmpi.bmiHeader.biCompression = BI_RGB;

	RGBQUAD* rgbquad = NULL;
	HSL hslcolor;

	bmp = CreateDIBSection(hdc, &bmpi, DIB_RGB_COLORS, (void**)&rgbquad, NULL, 0);
	SelectObject(hdcC, bmp);
	INT i = 0;

	while (1)
	{
		StretchBlt(hdcC, 0, 0, sw, sh, hdc, 0, 0, sw, sh, SRCCOPY);

		RGBQUAD rgbquadCopy;

		for (int x = 0; x < sw; x++)
		{
			for (int y = 0; y < sh; y++)
			{
				int index = y * sw + x;


				INT fx = (x + i) ^ (y + i);

				rgbquadCopy = rgbquad[fx];

				hslcolor = rgb2hsl(rgbquadCopy);
				hslcolor.h = fmod(fx / 300.f + y / sh * .1f, 1.f);

				rgbquad[index] = hsl2rgb(hslcolor);
			}
		}

		i++;
		StretchBlt(hdc, 0, 0, sw, sh, hdcC, 0, 0, sw, sh, SRCCOPY);
	}

}

DWORD WINAPI graphic5()
{
	HDC hdc = GetDC(NULL);
	HDC hdcC = CreateCompatibleDC(hdc);
	int sw = GetSystemMetrics(0), sh = GetSystemMetrics(1);
	BITMAPINFO bmpi = { 0 };
	HBITMAP bmp;

	bmpi.bmiHeader.biSize = sizeof(bmpi);
	bmpi.bmiHeader.biWidth = sw;
	bmpi.bmiHeader.biHeight = sh;
	bmpi.bmiHeader.biPlanes = 1;
	bmpi.bmiHeader.biBitCount = 32;
	bmpi.bmiHeader.biCompression = BI_RGB;

	RGBQUAD* rgbquad = NULL;
	HSL hslcolor;

	bmp = CreateDIBSection(hdc, &bmpi, DIB_RGB_COLORS, (void**)&rgbquad, NULL, 0);
	SelectObject(hdcC, bmp);
	INT i = 0;
	while (1)
	{
		StretchBlt(hdcC, 0, 0, sw, sh, hdc, 0, 0, sw, sh, SRCCOPY);

		RGBQUAD rgbquadCopy;

		for (int x = 0; x < sw; x++)
		{
			for (int y = 0; y < sh; y++)
			{
				INT index = y * sw + x;
				INT j = 6 * i;
				INT fx = (x + i) ? j : (y + i);

				rgbquadCopy = rgbquad[fx];

				hslcolor = rgb2hsl(rgbquadCopy);
				hslcolor.h = fmod(fx / 300.f + y / sh * .1f, 1.f);

				rgbquad[index] = hsl2rgb(hslcolor);
			}
		}

		i++;
		StretchBlt(hdc, 0, 0, sw, sh, hdcC, 0, 0, sw, sh, SRCCOPY);
	}

}