Mission CreateCustomMission(string path)
{
	return new MissionGameplay();
}

void SpawnObject( string type, vector position, vector orientation )
{
    auto obj = GetGame().CreateObject( type, position );
    obj.SetPosition( position );
    obj.SetOrientation( orientation );
    obj.SetOrientation( obj.GetOrientation() ); //Collision fix
    obj.Update();
    obj.SetAffectPathgraph( true, false );
    if( obj.CanAffectPathgraph() ) GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( GetGame().UpdatePathgraphRegionByObject, 100, false, obj );
}

void main()
{
	PlayerBase player;
	ItemBase item;

	// Create player
	player = PlayerBase.Cast( GetGame().CreatePlayer(NULL, "SurvivorF_Linda", "8489.2 105.518 12744", 0, "NONE") );

	// Spawn a black t-shirt
	item = player.GetInventory().CreateInInventory("TShirt_Black");

	// Spawn a green short jeans
	item = player.GetInventory().CreateInInventory("ShortJeans_Green");

	// Spawn a brown working boots
	item = player.GetInventory().CreateInInventory("WorkingBoots_Brown");

	// Spawn an apple in the t-shirt, don't redefine 'item' so we can still spawn other items in the t-shirt
	item.GetInventory().CreateInInventory("Apple");

	// Select player the client will be controlling
	GetGame().SelectPlayer(NULL, player);
	
	//array<Object> objectsInVicinity 	= new array<Object>();
	//array<CargoBase> proxyCargos 		= new array<CargoBase>();
    //GetGame().GetObjectsAtPosition3D("8468.029297 110.002853 12756.749023", 2.0, objectsInVicinity, proxyCargos);
	//	
	//foreach (Object objectClose: objectsInVicinity)
	//{
	//	objectClose.ToDelete();
	//	objectClose.Delete();
	//	objectClose.CreateDynamicPhysics(PhxInteractionLayers.NOCOLLISION);
	//}
	//
	//SpawnObject("Land_Village_Pub", "8468.029297 110.002853 12756.749023", "161.429153 -0.026519 -0.008910");
}