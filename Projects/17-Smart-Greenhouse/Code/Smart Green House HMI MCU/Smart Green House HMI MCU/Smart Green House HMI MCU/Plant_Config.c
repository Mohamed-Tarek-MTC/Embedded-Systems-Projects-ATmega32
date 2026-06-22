/*
 * Plant_Config.c
 *
 * Created: 6/3/2026 11:32:22 AM
 *  Author: Cascoo
 */ 

#include "EEPROM.h"
#include "Plant_Config.h"

void Plants_init(void)
{
	//i used if statement to prevent overwrite same data in same location to save more life cycle for EEPROM 
	//so this will need some time for the first use to load values in EEPROM
	
	//selecting stage for first time of use 
	if ((EEPROM_read(Current_Stage_Location))==0xFF)
	{
		EEPROM_write(0,Current_Stage_Location);
	}
	//setting least water tank level to 10%
	if ((EEPROM_read(WATER_TANK_Least_Level_Location))!=10)
	{
		EEPROM_write(10,WATER_TANK_Least_Level_Location);
	}
	
	//For Tomatoes
	if ((EEPROM_read(Tomatoes_Harvest_Days_Location))!=Tomatoes_Harvest_Days)
	{
		EEPROM_write(Tomatoes_Harvest_Days,Tomatoes_Harvest_Days_Location);
	}
	if ((EEPROM_read(Tomatoes_Max_temp_Location))!=Tomatoes_Max_temp)
	{
		EEPROM_write(Tomatoes_Max_temp,Tomatoes_Max_temp_Location);
	}
	if ((EEPROM_read(Tomatoes_Least_temp_Location))!=Tomatoes_Least_temp)
	{
		EEPROM_write(Tomatoes_Least_temp,Tomatoes_Least_temp_Location);
	}
	if ((EEPROM_read(Tomatoes_Max_Soil_Mois_Location))!=Tomatoes_Max_Soil_Mois)
	{
		EEPROM_write(Tomatoes_Max_Soil_Mois,Tomatoes_Max_Soil_Mois_Location);
	}
	if ((EEPROM_read(Tomatoes_Least_Soil_Mois_Location))!=Tomatoes_Least_Soil_Mois)
	{
		EEPROM_write(Tomatoes_Least_Soil_Mois,Tomatoes_Least_Soil_Mois_Location);
	}
	if ((EEPROM_read(Tomatoes_Max_Air_Humidity_Location))!=Tomatoes_Max_Air_Humidity)
	{
		EEPROM_write(Tomatoes_Max_Air_Humidity,Tomatoes_Max_Air_Humidity_Location);
	}
	if ((EEPROM_read(Tomatoes_Least_Air_Humidity_Location))!=Tomatoes_Least_Air_Humidity)
	{
		EEPROM_write(Tomatoes_Least_Air_Humidity,Tomatoes_Least_Air_Humidity_Location);
	}

	//For Potatoes
	if ((EEPROM_read(Potatoes_Harvest_Days_Location))!=Potatoes_Harvest_Days)
	{
		EEPROM_write(Potatoes_Harvest_Days,Potatoes_Harvest_Days_Location);
	}
	if ((EEPROM_read(Potatoes_Max_temp_Location))!=Potatoes_Max_temp)
	{
		EEPROM_write(Potatoes_Max_temp,Potatoes_Max_temp_Location);
	}
	if ((EEPROM_read(Potatoes_Least_temp_Location))!=Potatoes_Least_temp)
	{
		EEPROM_write(Potatoes_Least_temp,Potatoes_Least_temp_Location);
	}
	if ((EEPROM_read(Potatoes_Max_Soil_Mois_Location))!=Potatoes_Max_Soil_Mois)
	{
		EEPROM_write(Potatoes_Max_Soil_Mois,Potatoes_Max_Soil_Mois_Location);
	}
	if ((EEPROM_read(Potatoes_Least_Soil_Mois_Location))!=Potatoes_Least_Soil_Mois)
	{
		EEPROM_write(Potatoes_Least_Soil_Mois,Potatoes_Least_Soil_Mois_Location);
	}
	if ((EEPROM_read(Potatoes_Max_Air_Humidity_Location))!=Potatoes_Max_Air_Humidity)
	{
		EEPROM_write(Potatoes_Max_Air_Humidity,Potatoes_Max_Air_Humidity_Location);
	}
	if ((EEPROM_read(Potatoes_Least_Air_Humidity_Location))!=Potatoes_Least_Air_Humidity)
	{
		EEPROM_write(Potatoes_Least_Air_Humidity,Potatoes_Least_Air_Humidity_Location);
	}

	//For Wheat
	if ((EEPROM_read(Wheat_Harvest_Days_Location))!=Wheat_Harvest_Days)
	{
		EEPROM_write(Wheat_Harvest_Days,Wheat_Harvest_Days_Location);
	}
	if ((EEPROM_read(Wheat_Max_temp_Location))!=Wheat_Max_temp)
	{
		EEPROM_write(Wheat_Max_temp,Wheat_Max_temp_Location);
	}
	if ((EEPROM_read(Wheat_Least_temp_Location))!=Wheat_Least_temp)
	{
		EEPROM_write(Wheat_Least_temp,Wheat_Least_temp_Location);
	}
	if ((EEPROM_read(Wheat_Max_Soil_Mois_Location))!=Wheat_Max_Soil_Mois)
	{
		EEPROM_write(Wheat_Max_Soil_Mois,Wheat_Max_Soil_Mois_Location);
	}
	if ((EEPROM_read(Wheat_Least_Soil_Mois_Location))!=Wheat_Least_Soil_Mois)
	{
		EEPROM_write(Wheat_Least_Soil_Mois,Wheat_Least_Soil_Mois_Location);
	}
	if ((EEPROM_read(Wheat_Max_Air_Humidity_Location))!=Wheat_Max_Air_Humidity)
	{
		EEPROM_write(Wheat_Max_Air_Humidity,Wheat_Max_Air_Humidity_Location);
	}
	if ((EEPROM_read(Wheat_Least_Air_Humidity_Location))!=Wheat_Least_Air_Humidity)
	{
		EEPROM_write(Wheat_Least_Air_Humidity,Wheat_Least_Air_Humidity_Location);
	}

	//For Onions
	if ((EEPROM_read(Onions_Harvest_Days_Location))!=Onions_Harvest_Days)
	{
		EEPROM_write(Onions_Harvest_Days,Onions_Harvest_Days_Location);
	}
	if ((EEPROM_read(Onions_Max_temp_Location))!=Onions_Max_temp)
	{
		EEPROM_write(Onions_Max_temp,Onions_Max_temp_Location);
	}
	if ((EEPROM_read(Onions_Least_temp_Location))!=Onions_Least_temp)
	{
		EEPROM_write(Onions_Least_temp,Onions_Least_temp_Location);
	}
	if ((EEPROM_read(Onions_Max_Soil_Mois_Location))!=Onions_Max_Soil_Mois)
	{
		EEPROM_write(Onions_Max_Soil_Mois,Onions_Max_Soil_Mois_Location);
	}
	if ((EEPROM_read(Onions_Least_Soil_Mois_Location))!=Onions_Least_Soil_Mois)
	{
		EEPROM_write(Onions_Least_Soil_Mois,Onions_Least_Soil_Mois_Location);
	}
	if ((EEPROM_read(Onions_Max_Air_Humidity_Location))!=Onions_Max_Air_Humidity)
	{
		EEPROM_write(Onions_Max_Air_Humidity,Onions_Max_Air_Humidity_Location);
	}
	if ((EEPROM_read(Onions_Least_Air_Humidity_Location))!=Onions_Least_Air_Humidity)
	{
		EEPROM_write(Onions_Least_Air_Humidity,Onions_Least_Air_Humidity_Location);
	}

	//For Garlic
	if ((EEPROM_read(Garlic_Harvest_Days_Location))!=Garlic_Harvest_Days)
	{
		EEPROM_write(Garlic_Harvest_Days,Garlic_Harvest_Days_Location);
	}
	if ((EEPROM_read(Garlic_Max_temp_Location))!=Garlic_Max_temp)
	{
		EEPROM_write(Garlic_Max_temp,Garlic_Max_temp_Location);
	}
	if ((EEPROM_read(Garlic_Least_temp_Location))!=Garlic_Least_temp)
	{
		EEPROM_write(Garlic_Least_temp,Garlic_Least_temp_Location);
	}
	if ((EEPROM_read(Garlic_Max_Soil_Mois_Location))!=Garlic_Max_Soil_Mois)
	{
		EEPROM_write(Garlic_Max_Soil_Mois,Garlic_Max_Soil_Mois_Location);
	}
	if ((EEPROM_read(Garlic_Least_Soil_Mois_Location))!=Garlic_Least_Soil_Mois)
	{
		EEPROM_write(Garlic_Least_Soil_Mois,Garlic_Least_Soil_Mois_Location);
	}
	if ((EEPROM_read(Garlic_Max_Air_Humidity_Location))!=Garlic_Max_Air_Humidity)
	{
		EEPROM_write(Garlic_Max_Air_Humidity,Garlic_Max_Air_Humidity_Location);
	}
	if ((EEPROM_read(Garlic_Least_Air_Humidity_Location))!=Garlic_Least_Air_Humidity)
	{
		EEPROM_write(Garlic_Least_Air_Humidity,Garlic_Least_Air_Humidity_Location);
	}

	//For Cucumber
	if ((EEPROM_read(Cucumber_Harvest_Days_Location))!=Cucumber_Harvest_Days)
	{
		EEPROM_write(Cucumber_Harvest_Days,Cucumber_Harvest_Days_Location);
	}
	if ((EEPROM_read(Cucumber_Max_temp_Location))!=Cucumber_Max_temp)
	{
		EEPROM_write(Cucumber_Max_temp,Cucumber_Max_temp_Location);
	}
	if ((EEPROM_read(Cucumber_Least_temp_Location))!=Cucumber_Least_temp)
	{
		EEPROM_write(Cucumber_Least_temp,Cucumber_Least_temp_Location);
	}
	if ((EEPROM_read(Cucumber_Max_Soil_Mois_Location))!=Cucumber_Max_Soil_Mois)
	{
		EEPROM_write(Cucumber_Max_Soil_Mois,Cucumber_Max_Soil_Mois_Location);
	}
	if ((EEPROM_read(Cucumber_Least_Soil_Mois_Location))!=Cucumber_Least_Soil_Mois)
	{
		EEPROM_write(Cucumber_Least_Soil_Mois,Cucumber_Least_Soil_Mois_Location);
	}
	if ((EEPROM_read(Cucumber_Max_Air_Humidity_Location))!=Cucumber_Max_Air_Humidity)
	{
		EEPROM_write(Cucumber_Max_Air_Humidity,Cucumber_Max_Air_Humidity_Location);
	}
	if ((EEPROM_read(Cucumber_Least_Air_Humidity_Location))!=Cucumber_Least_Air_Humidity)
	{
		EEPROM_write(Cucumber_Least_Air_Humidity,Cucumber_Least_Air_Humidity_Location);
	}

	//For Peppers
	if ((EEPROM_read(Peppers_Harvest_Days_Location))!=Peppers_Harvest_Days)
	{
		EEPROM_write(Peppers_Harvest_Days,Peppers_Harvest_Days_Location);
	}
	if ((EEPROM_read(Peppers_Max_temp_Location))!=Peppers_Max_temp)
	{
		EEPROM_write(Peppers_Max_temp,Peppers_Max_temp_Location);
	}
	if ((EEPROM_read(Peppers_Least_temp_Location))!=Peppers_Least_temp)
	{
		EEPROM_write(Peppers_Least_temp,Peppers_Least_temp_Location);
	}
	if ((EEPROM_read(Peppers_Max_Soil_Mois_Location))!=Peppers_Max_Soil_Mois)
	{
		EEPROM_write(Peppers_Max_Soil_Mois,Peppers_Max_Soil_Mois_Location);
	}
	if ((EEPROM_read(Peppers_Least_Soil_Mois_Location))!=Peppers_Least_Soil_Mois)
	{
		EEPROM_write(Peppers_Least_Soil_Mois,Peppers_Least_Soil_Mois_Location);
	}
	if ((EEPROM_read(Peppers_Max_Air_Humidity_Location))!=Peppers_Max_Air_Humidity)
	{
		EEPROM_write(Peppers_Max_Air_Humidity,Peppers_Max_Air_Humidity_Location);
	}
	if ((EEPROM_read(Peppers_Least_Air_Humidity_Location))!=Peppers_Least_Air_Humidity)
	{
		EEPROM_write(Peppers_Least_Air_Humidity,Peppers_Least_Air_Humidity_Location);
	}

	//For Lettuce
	if ((EEPROM_read(Lettuce_Harvest_Days_Location))!=Lettuce_Harvest_Days)
	{
		EEPROM_write(Lettuce_Harvest_Days,Lettuce_Harvest_Days_Location);
	}
	if ((EEPROM_read(Lettuce_Max_temp_Location))!=Lettuce_Max_temp)
	{
		EEPROM_write(Lettuce_Max_temp,Lettuce_Max_temp_Location);
	}
	if ((EEPROM_read(Lettuce_Least_temp_Location))!=Lettuce_Least_temp)
	{
		EEPROM_write(Lettuce_Least_temp,Lettuce_Least_temp_Location);
	}
	if ((EEPROM_read(Lettuce_Max_Soil_Mois_Location))!=Lettuce_Max_Soil_Mois)
	{
		EEPROM_write(Lettuce_Max_Soil_Mois,Lettuce_Max_Soil_Mois_Location);
	}
	if ((EEPROM_read(Lettuce_Least_Soil_Mois_Location))!=Lettuce_Least_Soil_Mois)
	{
		EEPROM_write(Lettuce_Least_Soil_Mois,Lettuce_Least_Soil_Mois_Location);
	}
	if ((EEPROM_read(Lettuce_Max_Air_Humidity_Location))!=Lettuce_Max_Air_Humidity)
	{
		EEPROM_write(Lettuce_Max_Air_Humidity,Lettuce_Max_Air_Humidity_Location);
	}
	if ((EEPROM_read(Lettuce_Least_Air_Humidity_Location))!=Lettuce_Least_Air_Humidity)
	{
		EEPROM_write(Lettuce_Least_Air_Humidity,Lettuce_Least_Air_Humidity_Location);
	}

	//For Corn
	if ((EEPROM_read(Corn_Harvest_Days_Location))!=Corn_Harvest_Days)
	{
		EEPROM_write(Corn_Harvest_Days,Corn_Harvest_Days_Location);
	}
	if ((EEPROM_read(Corn_Max_temp_Location))!=Corn_Max_temp)
	{
		EEPROM_write(Corn_Max_temp,Corn_Max_temp_Location);
	}
	if ((EEPROM_read(Corn_Least_temp_Location))!=Corn_Least_temp)
	{
		EEPROM_write(Corn_Least_temp,Corn_Least_temp_Location);
	}
	if ((EEPROM_read(Corn_Max_Soil_Mois_Location))!=Corn_Max_Soil_Mois)
	{
		EEPROM_write(Corn_Max_Soil_Mois,Corn_Max_Soil_Mois_Location);
	}
	if ((EEPROM_read(Corn_Least_Soil_Mois_Location))!=Corn_Least_Soil_Mois)
	{
		EEPROM_write(Corn_Least_Soil_Mois,Corn_Least_Soil_Mois_Location);
	}
	if ((EEPROM_read(Corn_Max_Air_Humidity_Location))!=Corn_Max_Air_Humidity)
	{
		EEPROM_write(Corn_Max_Air_Humidity,Corn_Max_Air_Humidity_Location);
	}
	if ((EEPROM_read(Corn_Least_Air_Humidity_Location))!=Corn_Least_Air_Humidity)
	{
		EEPROM_write(Corn_Least_Air_Humidity,Corn_Least_Air_Humidity_Location);
	}
}

void Tomatoes(void)
{
	EEPROM_write(Tomatoes_Harvest_Days,PLANT_Harvest_Days_Location);
	EEPROM_write(Tomatoes_Max_temp,PLANT_Max_temp_Compare_Location);
	EEPROM_write(Tomatoes_Least_temp,PLANT_Least_temp_Compare_Location);
	EEPROM_write(Tomatoes_Max_Soil_Mois,PLANT_Max_Soil_Mois_Compare_Location);
	EEPROM_write(Tomatoes_Least_Soil_Mois,PLANT_Least_Soil_Mois_Compare_Location);
	EEPROM_write(Tomatoes_Max_Air_Humidity,PLANT_Max_Air_Humidity_Compare_Location);
	EEPROM_write(Tomatoes_Least_Air_Humidity,PLANT_Least_Air_Humidity_Compare_Location);

}

void Potatoes(void)
{
	EEPROM_write(Potatoes_Harvest_Days,PLANT_Harvest_Days_Location);
	EEPROM_write(Potatoes_Max_temp,PLANT_Max_temp_Compare_Location);
	EEPROM_write(Potatoes_Least_temp,PLANT_Least_temp_Compare_Location);
	EEPROM_write(Potatoes_Max_Soil_Mois,PLANT_Max_Soil_Mois_Compare_Location);
	EEPROM_write(Potatoes_Least_Soil_Mois,PLANT_Least_Soil_Mois_Compare_Location);
	EEPROM_write(Potatoes_Max_Air_Humidity,PLANT_Max_Air_Humidity_Compare_Location);
	EEPROM_write(Potatoes_Least_Air_Humidity,PLANT_Least_Air_Humidity_Compare_Location);
}

void Wheat(void)
{
	EEPROM_write(Wheat_Harvest_Days,PLANT_Harvest_Days_Location);
	EEPROM_write(Wheat_Max_temp,PLANT_Max_temp_Compare_Location);
	EEPROM_write(Wheat_Least_temp,PLANT_Least_temp_Compare_Location);
	EEPROM_write(Wheat_Max_Soil_Mois,PLANT_Max_Soil_Mois_Compare_Location);
	EEPROM_write(Wheat_Least_Soil_Mois,PLANT_Least_Soil_Mois_Compare_Location);
	EEPROM_write(Wheat_Max_Air_Humidity,PLANT_Max_Air_Humidity_Compare_Location);
	EEPROM_write(Wheat_Least_Air_Humidity,PLANT_Least_Air_Humidity_Compare_Location);
}

void Onions(void)
{
	EEPROM_write(Onions_Harvest_Days,PLANT_Harvest_Days_Location);
	EEPROM_write(Onions_Max_temp,PLANT_Max_temp_Compare_Location);
	EEPROM_write(Onions_Least_temp,PLANT_Least_temp_Compare_Location);
	EEPROM_write(Onions_Max_Soil_Mois,PLANT_Max_Soil_Mois_Compare_Location);
	EEPROM_write(Onions_Least_Soil_Mois,PLANT_Least_Soil_Mois_Compare_Location);
	EEPROM_write(Onions_Max_Air_Humidity,PLANT_Max_Air_Humidity_Compare_Location);
	EEPROM_write(Onions_Least_Air_Humidity,PLANT_Least_Air_Humidity_Compare_Location);
}

void Garlic(void)
{
	EEPROM_write(Garlic_Harvest_Days,PLANT_Harvest_Days_Location);
	EEPROM_write(Garlic_Max_temp,PLANT_Max_temp_Compare_Location);
	EEPROM_write(Garlic_Least_temp,PLANT_Least_temp_Compare_Location);
	EEPROM_write(Garlic_Max_Soil_Mois,PLANT_Max_Soil_Mois_Compare_Location);
	EEPROM_write(Garlic_Least_Soil_Mois,PLANT_Least_Soil_Mois_Compare_Location);
	EEPROM_write(Garlic_Max_Air_Humidity,PLANT_Max_Air_Humidity_Compare_Location);
	EEPROM_write(Garlic_Least_Air_Humidity,PLANT_Least_Air_Humidity_Compare_Location);
}

void Cucumber(void)
{
	EEPROM_write(Cucumber_Harvest_Days,PLANT_Harvest_Days_Location);
	EEPROM_write(Cucumber_Max_temp,PLANT_Max_temp_Compare_Location);
	EEPROM_write(Cucumber_Least_temp,PLANT_Least_temp_Compare_Location);
	EEPROM_write(Cucumber_Max_Soil_Mois,PLANT_Max_Soil_Mois_Compare_Location);
	EEPROM_write(Cucumber_Least_Soil_Mois,PLANT_Least_Soil_Mois_Compare_Location);
	EEPROM_write(Cucumber_Max_Air_Humidity,PLANT_Max_Air_Humidity_Compare_Location);
	EEPROM_write(Cucumber_Least_Air_Humidity,PLANT_Least_Air_Humidity_Compare_Location);
}

void Peppers(void)
{
	EEPROM_write(Peppers_Harvest_Days,PLANT_Harvest_Days_Location);
	EEPROM_write(Peppers_Max_temp,PLANT_Max_temp_Compare_Location);
	EEPROM_write(Peppers_Least_temp,PLANT_Least_temp_Compare_Location);
	EEPROM_write(Peppers_Max_Soil_Mois,PLANT_Max_Soil_Mois_Compare_Location);
	EEPROM_write(Peppers_Least_Soil_Mois,PLANT_Least_Soil_Mois_Compare_Location);
	EEPROM_write(Peppers_Max_Air_Humidity,PLANT_Max_Air_Humidity_Compare_Location);
	EEPROM_write(Peppers_Least_Air_Humidity,PLANT_Least_Air_Humidity_Compare_Location);
}

void Corn(void)
{
	EEPROM_write(Corn_Harvest_Days,PLANT_Harvest_Days_Location);
	EEPROM_write(Corn_Max_temp,PLANT_Max_temp_Compare_Location);
	EEPROM_write(Corn_Least_temp,PLANT_Least_temp_Compare_Location);
	EEPROM_write(Corn_Max_Soil_Mois,PLANT_Max_Soil_Mois_Compare_Location);
	EEPROM_write(Corn_Least_Soil_Mois,PLANT_Least_Soil_Mois_Compare_Location);
	EEPROM_write(Corn_Max_Air_Humidity,PLANT_Max_Air_Humidity_Compare_Location);
	EEPROM_write(Corn_Least_Air_Humidity,PLANT_Least_Air_Humidity_Compare_Location);
}

void Lettuce(void)
{
	EEPROM_write(Lettuce_Harvest_Days,PLANT_Harvest_Days_Location);
	EEPROM_write(Lettuce_Max_temp,PLANT_Max_temp_Compare_Location);
	EEPROM_write(Lettuce_Least_temp,PLANT_Least_temp_Compare_Location);
	EEPROM_write(Lettuce_Max_Soil_Mois,PLANT_Max_Soil_Mois_Compare_Location);
	EEPROM_write(Lettuce_Least_Soil_Mois,PLANT_Least_Soil_Mois_Compare_Location);
	EEPROM_write(Lettuce_Max_Air_Humidity,PLANT_Max_Air_Humidity_Compare_Location);
	EEPROM_write(Lettuce_Least_Air_Humidity,PLANT_Least_Air_Humidity_Compare_Location);
}