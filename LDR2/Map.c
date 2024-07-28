#include "STD_TYPES.h"
#include "Map.h"




sint32 Map(sint32 InputRangMin,sint32 InputRangMax,sint32 OutputRangMin,sint32 OutputRangMax,sint32 InputVal)
{
	sint32 OutputVal= (InputVal-InputRangMin)*((OutputRangMax-OutputRangMin)/(InputRangMax-InputRangMin))+OutputRangMin;
	
	
return OutputVal;
	
	
}