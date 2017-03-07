#include<stdio.h>
#include<stdlib.h>

/*
 *
 * Copyright (C) ZeroInfinity@XDA 2017
 * Author: ZeroInfinity <infinitezero345@gmail.com>
 * 
 */
int main(){
	int bitshift = 0, freqTotal = 0, freq = 0, shift = 0;
	float percentage = 0, tippingPoint = 0;
	printf("enter max freq: ");
	scanf("%d",&freq);
	while (freq != 0) {
		printf("enter bit shift value: ");
		scanf("%d",&shift);
		bitshift = freq >> shift;
		freqTotal = freq + bitshift;
		percentage = (float)freqTotal / (float)freq;
		tippingPoint = (float)freq / (float)freqTotal;
		printf("bitshift Total: %d\nfreqTotal: %d\nC: %f\nTipping Point: %f\n\n", bitshift, freqTotal, percentage, tippingPoint);
		printf("enter max freq: ");
		scanf("%d",&freq);
	}
}

