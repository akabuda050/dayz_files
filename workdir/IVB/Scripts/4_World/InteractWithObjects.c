class InteractWithObjects: ActionInteractBase
{
	void InteractWithObjects()
	{
		m_CommandUID        = DayZPlayerConstants.CMD_ACTIONMOD_PICKUP_HANDS;
		m_CommandUIDProne	= DayZPlayerConstants.CMD_ACTIONFB_PICKUP_HANDS;
		
		m_Text 			= "#take_to_hands";
	}
	
	override bool HasTarget()
	{
		return false;
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTCursor(UAMaxDistances.DEFAULT);
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (!target.GetObject())
			return false;
		
		if (target.GetObject().GetShapeName().Contains("workbench_dz.p3d"))						
			return true;
		
		return false;
	}
	
	override void OnExecuteServer( ActionData action_data )
	{
		
	}
	
	override void CreateAndSetupActionCallback( ActionData action_data )
	{
		super.CreateAndSetupActionCallback(action_data);
	}
}