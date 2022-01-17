#pragma once

// general purpose default values in centimeters
#define GH_DEFAULT_WIDTH 				1000
#define GH_DEFAULT_LENGTH 				4800
#define GH_DEFAULT_VRAMP_WIDTH 			60
#define GH_DEFAULT_VRAMP_LWIDTH 		80
#define GH_DEFAULT_VRAMP_RWIDTH 		100
#define GH_DEFAULT_VRAMP_AMNT 			4
#define GH_DEFAULT_VRAMP_SPACING 		1500
#define GH_DEFAULT_HRAMP_AMNT 			5
#define GH_DEFAULT_HRAMP_WIDTH 			75
#define GH_DEFAULT_HRAMP_BWIDTH 		50
#define GH_DEFAULT_HRAMP_SPACING 		170

typedef struct {
	int iWidth;
	int iLength;
	int iVRampSpacing;
	int iHRampSpacing;
} tRealValues;

typedef struct {
	int iWidth;
	int iLength;
	int iVRampSpacing;
	int iHRampSpacing;
} tPixelValues;
