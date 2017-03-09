#include<stdio.h>
#include<stdlib.h>

/*
 *
 * Copyright (C) ZeroInfinity@XDA 2017
 * Author: ZeroInfinity <infinitezero345@gmail.com>
 * 
 */
int main(){
	int bitshift = 0, freqTotal = 0, freq = 1, shift = 0, util = 0, max = 0;
	float percentage = 0, tippingPoint = 0, load = 0, nextFreq = 0, loadperc = 0;
	printf("enter max freq: ");
	scanf("%d",&freq);
	while (freq != 0) {
		printf("enter bit shift value: ");
		scanf("%d",&shift);
		printf("enter max capacity of CPU: ");
		scanf("%d",&max);
		printf("enter CPU utilisation: ");
		scanf("%d",&util);
		bitshift = freq >> shift;
		freqTotal = freq + bitshift;
		percentage = (float)freqTotal / (float)freq;
		tippingPoint = (float)freq / (float)freqTotal;
		load = (float)util / (float)max;
		loadperc = load * 100;
		nextFreq = freqTotal * load;
		printf("bitshift Total: %d\nfreqTotal: %d\nC: %f\nTipping Point: %f\n", bitshift, freqTotal, percentage, tippingPoint);
		printf("CPU Load: %f\nnextFreq: %f\n\n", loadperc, nextFreq);
		printf("enter max freq: ");
		scanf("%d",&freq);
	}
}

