/*
 * Plant_Config.h
 *
 * Created: 6/3/2026 8:24:51 AM
 *  Author: Cascoo
 */ 


#ifndef PLANT_CONFIG_H_
#define PLANT_CONFIG_H_

		/////Locations Section///////
#define Current_Days_Counter_Location				0x0000
#define Current_Stage_Location						0x0001
#define WATER_TANK_Least_Level_Location				0x0002

#define PLANT_Harvest_Days_Location					0x0003
#define PLANT_Max_temp_Compare_Location				0x0004
#define PLANT_Least_temp_Compare_Location			0x0005
#define PLANT_Max_Soil_Mois_Compare_Location		0x0006
#define PLANT_Least_Soil_Mois_Compare_Location		0x0007
#define PLANT_Max_Air_Humidity_Compare_Location		0x0008
#define PLANT_Least_Air_Humidity_Compare_Location	0x0009
		
//For Tomatoes
#define Tomatoes_Harvest_Days_Location				0x0010
#define Tomatoes_Max_temp_Location					0x0011
#define Tomatoes_Least_temp_Location				0x0012
#define Tomatoes_Max_Soil_Mois_Location				0x0013
#define Tomatoes_Least_Soil_Mois_Location			0x0014
#define Tomatoes_Max_Air_Humidity_Location			0x0015
#define Tomatoes_Least_Air_Humidity_Location		0x0016

//For Potatoes
#define Potatoes_Harvest_Days_Location				0x0020
#define Potatoes_Max_temp_Location					0x0021
#define Potatoes_Least_temp_Location				0x0022
#define Potatoes_Max_Soil_Mois_Location				0x0023
#define Potatoes_Least_Soil_Mois_Location			0x0024
#define Potatoes_Max_Air_Humidity_Location			0x0025
#define Potatoes_Least_Air_Humidity_Location		0x0026

//For Wheat
#define Wheat_Harvest_Days_Location					0x0030
#define Wheat_Max_temp_Location						0x0031
#define Wheat_Least_temp_Location					0x0032
#define Wheat_Max_Soil_Mois_Location				0x0033
#define Wheat_Least_Soil_Mois_Location				0x0034
#define Wheat_Max_Air_Humidity_Location				0x0035
#define Wheat_Least_Air_Humidity_Location			0x0036

//For Onions
#define Onions_Harvest_Days_Location				0x0040
#define Onions_Max_temp_Location					0x0041
#define Onions_Least_temp_Location					0x0042
#define Onions_Max_Soil_Mois_Location				0x0043
#define Onions_Least_Soil_Mois_Location				0x0044
#define Onions_Max_Air_Humidity_Location			0x0045
#define Onions_Least_Air_Humidity_Location			0x0046

//For Garlic
#define Garlic_Harvest_Days_Location				0x0050
#define Garlic_Max_temp_Location					0x0051
#define Garlic_Least_temp_Location					0x0052
#define Garlic_Max_Soil_Mois_Location				0x0053
#define Garlic_Least_Soil_Mois_Location				0x0054
#define Garlic_Max_Air_Humidity_Location			0x0055
#define Garlic_Least_Air_Humidity_Location			0x0056

//For Cucumber
#define Cucumber_Harvest_Days_Location				0x0060
#define Cucumber_Max_temp_Location					0x0061
#define Cucumber_Least_temp_Location				0x0062
#define Cucumber_Max_Soil_Mois_Location				0x0063
#define Cucumber_Least_Soil_Mois_Location			0x0064
#define Cucumber_Max_Air_Humidity_Location			0x0065
#define Cucumber_Least_Air_Humidity_Location		0x0066

//For Peppers
#define Peppers_Harvest_Days_Location				0x0070
#define Peppers_Max_temp_Location					0x0071
#define Peppers_Least_temp_Location					0x0072
#define Peppers_Max_Soil_Mois_Location				0x0073
#define Peppers_Least_Soil_Mois_Location			0x0074
#define Peppers_Max_Air_Humidity_Location			0x0075
#define Peppers_Least_Air_Humidity_Location			0x0076

//For Lettuce
#define Lettuce_Harvest_Days_Location				0x0080
#define Lettuce_Max_temp_Location					0x0081
#define Lettuce_Least_temp_Location					0x0082
#define Lettuce_Max_Soil_Mois_Location				0x0083
#define Lettuce_Least_Soil_Mois_Location			0x0084
#define Lettuce_Max_Air_Humidity_Location			0x0085
#define Lettuce_Least_Air_Humidity_Location			0x0086

//For Corn
#define Corn_Harvest_Days_Location					0x0090
#define Corn_Max_temp_Location						0x0091
#define Corn_Least_temp_Location					0x0092
#define Corn_Max_Soil_Mois_Location					0x0093
#define Corn_Least_Soil_Mois_Location				0x0094
#define Corn_Max_Air_Humidity_Location				0x0095
#define Corn_Least_Air_Humidity_Location			0x0096


	////Plants Data Section/////
//For Tomatoes	 
#define Tomatoes_Harvest_Days			120
#define Tomatoes_Max_temp				28
#define Tomatoes_Least_temp				18
#define Tomatoes_Max_Soil_Mois			80
#define Tomatoes_Least_Soil_Mois		60
#define Tomatoes_Max_Air_Humidity		70
#define Tomatoes_Least_Air_Humidity		60

//For Potatoes	 
#define Potatoes_Harvest_Days			120
#define Potatoes_Max_temp				22
#define Potatoes_Least_temp				15
#define Potatoes_Max_Soil_Mois			80
#define Potatoes_Least_Soil_Mois		65
#define Potatoes_Max_Air_Humidity		80
#define Potatoes_Least_Air_Humidity		70

//For Wheat	
#define Wheat_Harvest_Days				150
#define Wheat_Max_temp					25
#define Wheat_Least_temp				15
#define Wheat_Max_Soil_Mois				70
#define Wheat_Least_Soil_Mois			50
#define Wheat_Max_Air_Humidity			70
#define Wheat_Least_Air_Humidity		50
		
//For Onions
#define Onions_Harvest_Days				150
#define Onions_Max_temp					24
#define Onions_Least_temp				13
#define Onions_Max_Soil_Mois			70
#define Onions_Least_Soil_Mois			50
#define Onions_Max_Air_Humidity			70
#define Onions_Least_Air_Humidity		50

//For Garlic	
#define Garlic_Harvest_Days				210
#define Garlic_Max_temp					24
#define Garlic_Least_temp				13
#define Garlic_Max_Soil_Mois			70
#define Garlic_Least_Soil_Mois			50
#define Garlic_Max_Air_Humidity			70
#define Garlic_Least_Air_Humidity		50

//For Cucumber		 
#define Cucumber_Harvest_Days			60
#define Cucumber_Max_temp				30
#define Cucumber_Least_temp				20
#define Cucumber_Max_Soil_Mois			85
#define Cucumber_Least_Soil_Mois		70
#define Cucumber_Max_Air_Humidity		90
#define Cucumber_Least_Air_Humidity		70

//For Peppers	
#define Peppers_Harvest_Days			100
#define Peppers_Max_temp				28
#define Peppers_Least_temp				20
#define Peppers_Max_Soil_Mois			80
#define Peppers_Least_Soil_Mois			60
#define Peppers_Max_Air_Humidity		70
#define Peppers_Least_Air_Humidity		60

//For Lettuce	
#define Lettuce_Harvest_Days			60
#define Lettuce_Max_temp				22
#define Lettuce_Least_temp				10
#define Lettuce_Max_Soil_Mois			90
#define Lettuce_Least_Soil_Mois			70
#define Lettuce_Max_Air_Humidity		80
#define Lettuce_Least_Air_Humidity		60

//For Corn		
#define Corn_Harvest_Days				120
#define Corn_Max_temp					30	
#define Corn_Least_temp					20
#define Corn_Max_Soil_Mois				80
#define Corn_Least_Soil_Mois			60
#define Corn_Max_Air_Humidity			70
#define Corn_Least_Air_Humidity			50


void Plants_init(void);
void Tomatoes(void);
void Potatoes(void);
void Wheat(void);
void Onions(void);
void Garlic(void);
void Cucumber(void);
void Peppers(void);
void Corn(void);
void Lettuce(void);

#endif /* PLANT CONFIG_H_ */