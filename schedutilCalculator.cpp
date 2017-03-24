#include<stdio.h>
#include<stdlib.h>

/*
 *
 * Copyright (C) ZeroInfinity@XDA 2017
 * Author: ZeroInfinity <infinitezero345@gmail.com>
 * 
 */
void OneFreqCalc();
void FreqTableCalc();

int bitshift = 0, bitshiftAddFreqTotal = 0, maxFreq = 0, shift = 0, util = 0, max = 0, load = 0, nextFreq = 0;
float C = 0, tippingPoint = 0;

int bigFreq[25] = {
		307200,
		403200,
		480000, 
		556800, 
		652800, 
		729600, 
		806400, 
		883200, 
		940800, 
		1036800, 
		1113600, 
		1190400, 
		1248000, 
		1324800, 
		1401600, 
		1478400,
		1555200, 
		1632000,
		1708800, 
		1785600, 
		1824000, 
		1920000, 
		1996800, 
		2073600, 
		2150400 
};

int littleFreq[16] = {
		307200,
		422400, 
		480000, 
		556800, 
		652800, 
		729600, 
		844800, 
		960000, 
		1036800, 
		1113600, 
		1190400, 
		1228800, 
		1324800, 
		1401600, 
		1478400, 
		1593600 
};
 
int main(){
	int choice = 0;
	printf("1) Calculate one frequency\n2) Calculate a whole frequency table\n3) Exit");
	printf("\nEnter choice: ");
	scanf("%d",&choice);
	while(choice !=3){
		switch(choice){
			case 1:
				OneFreqCalc();
				break;
			case 2:
				FreqTableCalc();
				break;
			case 3:
				break;
			default:
				printf("\nInvalid input, try again.\n");
				system("pause");
				break;
		}
		system("cls");
		printf("1) Calculate one frequency\n2) Calculate a whole frequency table\n3) Exit");
		printf("\nEnter choice: ");
		scanf("%d",&choice);
	}
}

void OneFreqCalc(){
	system("cls");
	
	printf("enter max freq (input 0 to exit): ");
	scanf("%d",&maxFreq);
	while (maxFreq != 0) {
		printf("enter bit shift value: ");
		scanf("%d",&shift);
		printf("enter max capacity of CPU: ");
		scanf("%d",&max);
		printf("enter CPU load in percentage: ");
		scanf("%d",&load);
		
		bitshift = maxFreq >> shift;
		bitshiftAddFreqTotal = maxFreq + bitshift;
		C = 100 * (float)bitshiftAddFreqTotal / (float)maxFreq;
		tippingPoint = 100 * (float)maxFreq / (float)bitshiftAddFreqTotal;
		util = max * load/100;
		nextFreq = bitshiftAddFreqTotal * load/100;
		if(shift == 0){
			nextFreq = maxFreq * load/100;
		}
		printf("Maximum CPU Frequency: %d\n", maxFreq);
		printf("Bitshifted frequency: %d\n",bitshift);
		printf("Total Frequency After Bitshift Frequency Add: %d\n", bitshiftAddFreqTotal);
		printf("Next Frequency: %d\n\n", nextFreq);
		printf("\nPercentage Of C: %f\n", C);
		printf("Percentage Of Tipping Point: %f\n",tippingPoint);
		printf("CPU Load: %d\n", load);
		printf("CPU utilisation: %d/%d\n", util, max);
		
		system("pause");
		system("cls");
		
		printf("enter max freq (input 0 to exit)): ");
		scanf("%d",&maxFreq);
	}
}

void FreqTableCalc(){
	int tablechoice = 0;
	
	system("cls");
	
	printf("Choose 1) little or 2) big frequency table (input 0 to exit): ");
	scanf("%d",&tablechoice);
	while (tablechoice != 0) {
		printf("enter bit shift value: ");
		scanf("%d",&shift);
		printf("enter max capacity of CPU: ");
		scanf("%d",&max);
		printf("enter CPU load in percentage: ");
		scanf("%d",&load);
		
		if(tablechoice == 2){
			for(int i = 0; i <= 24; i++){
				bitshift = bigFreq[i] >> shift;
				bitshiftAddFreqTotal = bigFreq[i] + bitshift;
				C = 100 * (float)bitshiftAddFreqTotal / (float)bigFreq[i];
				tippingPoint = 100 * (float)bigFreq[i] / (float)bitshiftAddFreqTotal;
				util = max * load/100;
				nextFreq = bitshiftAddFreqTotal * load/100;
				if(shift == 0){
					nextFreq = bigFreq[i] * load/100;
				}
				printf("Maximum CPU Frequency: %d\n", bigFreq[i]);
				printf("Bitshifted frequency: %d\n",bitshift);
				printf("Total Frequency After Bitshift Frequency Add: %d\n", bitshiftAddFreqTotal);
				printf("Next Frequency: %d\n\n", nextFreq);
				printf("\nPercentage Of C: %f\n", C);
				printf("Percentage Of Tipping Point: %f\n",tippingPoint);
				printf("CPU Load: %d\n", load);
				printf("CPU utilisation: %d/%d\n", util, max);
			}
		} else if (tablechoice == 1){
			for(int i = 0; i <= 15; i++){
				bitshift = littleFreq[i] >> shift;
				bitshiftAddFreqTotal = littleFreq[i] + bitshift;
				C = 100 * (float)bitshiftAddFreqTotal / (float)littleFreq[i];
				tippingPoint = 100 * (float)littleFreq[i] / (float)bitshiftAddFreqTotal;
				util = max * load/100;
				nextFreq = bitshiftAddFreqTotal * load/100;
				if(shift == 0){
					nextFreq = littleFreq[i] * load/100;
				}
				printf("Maximum CPU Frequency: %d\n", littleFreq[i]);
				printf("Bitshifted frequency: %d\n",bitshift);
				printf("Total Frequency After Bitshift Frequency Add: %d\n", bitshiftAddFreqTotal);
				printf("Next Frequency: %d\n\n", nextFreq);
				printf("\nPercentage Of C: %f\n", C);
				printf("Percentage Of Tipping Point: %f\n",tippingPoint);
				printf("CPU Load: %d\n", load);
				printf("CPU utilisation: %d/%d\n", util, max);
			}
		} else {
			printf("Invalid input, try again.");
		}
		
		system("pause");
		system("cls");
			
		printf("Choose 1) little or 2) big frequency table (input 0 to exit): ");
		scanf("%d",&tablechoice);
	}
}
