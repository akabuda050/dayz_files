class CfgPatches
{
	class IVB_Storage
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Gear_Camping"};
	};
};
class CfgVehicles
{
	class WoodenCrate;
	class StaticObj_Furniture_workbench_DZ: WoodenCrate
	{
		scope=2;
		displayName="Workbench";
		descriptionShort="Simple workbench storage";
		model="\DZ\structures\Furniture\Various\workbench_DZ.p3d";
	
		weight = 10;
		itemSize[] = {2,2};
		inventorySlot[]=
		{
			"Truck_01_WoodenCrate1",
		};
		class Cargo
		{
			itemsCargoSize[] = {12,20};
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
};