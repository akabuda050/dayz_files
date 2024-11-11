class CfgPatches
{
	class IVB_Clothing
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Characters","DZ_Characters_Tops"};
	};
};
class CfgVehicles
{
	class TShirt_ColorBase;
	class TShirt_Black: TShirt_ColorBase
	{
		weight = 270;
		itemSize[] = {2,2};
		itemsCargoSize[] = {10,10};
	};
};