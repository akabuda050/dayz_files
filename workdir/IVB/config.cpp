class CfgPatches
{
	class IVB
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data"
		};
	};
};

class CfgMods
{
	class IVB
	{
		dir = "IVB";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "Interactive Vanilla Buildings";
		credits = "";
		author = "JsonBaby";
		authorID = "";
		version = "0.3";
		extra = 0;
		type = "mod";
		dependencies[] = {
			"Game",
			"World",
			"Mission"
		};

		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = {"IVB/Scripts/4_World"};
			};

			class missionScriptModule
			{
				value = "";
				files[] = {"IVB/Scripts/5_Mission"};
			};
		};
	};
};