modded class VicinityItemManager
{
    override void RefreshVicinityItems()
    {
        super.RefreshVicinityItems();
		PlayerBase player = GetGame().GetPlayer();
		
        array<Object> objectsInVicinity 	= new array<Object>();
		array<CargoBase> proxyCargos 		= new array<CargoBase>();
        GetGame().GetObjectsAtPosition3D(player.GetPosition(), VICINITY_ACTOR_DISTANCE * 3, objectsInVicinity, proxyCargos);
		
		foreach (Object objectClose: objectsInVicinity)
		{
			TStringArray full_path = new TStringArray;
			//GetGame().ConfigGetFullPath("CfgVehicles " + objectClose.ClassName(), full_path);
			//Debug.GetFiltredConfigClasses("", full_path, false);
			//Print(full_path);
			
			//foreach (string classs: full_path)
			//{
			//	Print(classs);
			//} 
			Land_Village_Pub buildingWfp;
			string shapeName = objectClose.GetShapeName();
			if (objectClose.GetShapeName().Contains("workbench"))
			{
				Object proxy = objectClose;	
			}

			Class.CastTo(buildingWfp, objectClose);
			
			if (!buildingWfp) {
				continue;
			}
			//buildingWfp.CreateDynamicPhysics(PhxInteractionLayers.BUILDING);
			BuildingInventory buildingInv = buildingWfp.GetInventory();
			//Print(buildingInv.GetCargo());
			//InventoryLocation src = new InventoryLocation;
	       	//buildingInv.GetCurrentInventoryLocation(src);
			//buildingWfp.SetInvisible(false);
			//Print(buildingInv.IsInventoryLocked()); // Null here
			
			vector player_pos = GetGame().GetPlayer().GetPosition();
			vector fence_pos = buildingWfp.GetPosition();
			vector ref_dir = buildingWfp.GetDirection();
			ref_dir[1] = 0;
			ref_dir.Normalize();
			 
			vector x[2];
			vector b1,b2;
			buildingWfp.GetCollisionBox(x);
			b1 = x[0];
			b2 = x[1];
	
			vector dir_to_fence = fence_pos - player_pos;
			dir_to_fence[1] = 0;
			float len = dir_to_fence.Length();
	
			dir_to_fence.Normalize();
			
			vector ref_dir_angle = ref_dir.VectorToAngles();
			vector dir_to_fence_angle = dir_to_fence.VectorToAngles();
			vector test_angles = dir_to_fence_angle - ref_dir_angle;
			
			vector test_position = test_angles.AnglesToVector() * len;
			
			if(test_position[0] < b1[0] || test_position[0] > b2[0] || test_position[2] < 0.2 || test_position[2] > 5.2 )
			{
				continue;
			}
			
			AddVicinityItems(buildingWfp);
		}	
    }
}